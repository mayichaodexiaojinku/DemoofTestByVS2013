#program once
#include<iostream>
typedef bool(*headle_func)();
template<int inst>
//一级空间配置器，对malloc与free进行了封装，并增加了C++的set_new_headle的思想
//“无型别参数”inst完全没有用
class MallocAllocTemplate
{
private:
	static headle_func _malloc_alloc_oom_headler;
	//以下函数来处理内存不足的情况
	static void *OomMalloc(size_t);
	static void *OomRealloc(void *, size_t);
public:
	//对malloc进行封装
	static void* Allocate(size_t n)
	{
		void *result = malloc(n);
		if (result == 0)
			result = OomMalloc(n);
		return result;
	}
	//对free进行封装
	static void* Deallocate(void* p ,size_t)//为什么要传进来一个size_t，是因为在二级空间配置器中要使用
	{
		free(p);
	}
	//对realloc进行封装，该函数基本不用。
	static void* Reallocate(void* p, size_t, size_t nz)
	{
		void *result = realloc(p, nz);
		if (0 == result)
			result = OomRealloc(p,nz);
		return result;
	}
	static headle_func SetMallocHeadler(headle_func f)
	{
		headle_func old = _malloc_alloc_oom_headler;
		_malloc_alloc_oom_headler = f;
		return old;
	}
};
//molloc_alloc out-of-memory handling
//初值为0，有待客户
template <int inst>
void* MallocAllocTemplate<inst>::_malloc_alloc_oom_headler = 0;
//malloc申请空间失败的代用函数
template <int inst>
void* MallocAllocTemplate<inst>::OomMalloc(size_t n)
{
	headle_func my_malloc_headler();
	void *result;
	for (;;){
		//检测用户是否设置空间不足应对措施， 如果没有设置，抛异常，模式new的方式。
		my_malloc_header = _malloc_alloc_oom_headler;
		if (0 == my_malloc_handler)
		{
			_THROW_BAD_ALLOC;
		}
		//如果用户设置，执行用户提供的空间不足应对措施
		(*my_malloc_headler)();
		//继续申请空间可能就会申请成功。
		result = malloc(n);
		if (result)
			return result;
	}
}
//和malloc类似。
template <int inst>
void* MallocAllocTemplate<inst>::OomRealloc(void* p,size_t n)
{
	headle_func my_malloc_headler();
	void *result;
	for (;;){
		//检测用户是否设置空间不足应对措施，如果没有设置，抛异常，模式new的方式。
		my_malloc_header = _malloc_alloc_oom_headler;
		if (0 == my_malloc_handler)
		{
			_THROW_BAD_ALLOC;
		}
		//如果用户设置，执行用户提供的空间不足应对措施
		(*my_malloc_headler)();
		//继续申请空间可能就会申请成功。
		result = realloc(p,n);
		if (result)
			return result;
	}
}
typedef MallocAllocTemplate<0> malloc_alloc;
//二级空间配置器，采用内存池技术，专门负责小于128字节的小内存块，减少额外空间浪费，采用哈希桶的方式来提高用户获取空间的速度与高效管理
template<int inst>
class DefaultAllocTemplate
{
private:
	enum{ALIGN = 8}; //如果用户所需内存不是8的整数倍，向上对齐到8的整数倍
	enum{MAX_BYTE = 128}; //大小内存的分界点。
	enum{NFREELIST = MAX_BYTE / ALIGN}; //free-list个数
	//如果用户所需内存块不是8的整数倍，就向上对齐到8的整数倍。
	static size_t Round_Up(size_t bytes)
	{
		return ((bytes + (ALIGN - 1))&~(ALIGN - 1));
	}
private:
	//用联合体来维护链表，更节省空间
	union Obj
	{
		union Obj* FreeListLink;
		char data[1];
	};
private:
	static Obj* volatile free_list[NFREELIST];
	//哈希函数，根据用户提供的字节数找到桶号
	static size_t FreeList_Index(size_t bytes)
	{
		return ((bytes + (ALIGN - 1))/(ALIGN - 1));
	}
	//向哈希桶中补充空间
	static void* Refill(size_t n)
	{
		int nobjs = 20;
		char * chunk = Chunk_alloc(n, nobjs);
		Obj *volatile* my_free_list;
		Obj *result;
		Obj *cur_obj, *next_obj;
		int i;
		//如果只要了一块就直接返回
		if (1 == nobjs){
			return chunk;
		}
		//先找到对应的桶
		my_free_list = free_list + FreeList_Index(n);
		result = (Obj*)chunk; //将这一块返回给客户端
		my_free_list = next_obj = (obj *)(chunk + n);
		//剩下的挂接到哈希桶中
		for (int i = 1;; i++){
			cur_obj = next_obj;
			next_obj = (Obj*)((char*)next_obj +n);
			if (nobjs - 1 == i){
				cur_obj->FreeListLink = 0;
				break;
			}
			else
				cur_obj->FreeListLink = next_obj;
		}
		return result;
	}

	static char* Chunk_alloc(size_t size,int& nobjs);
	//用strat、end标记内存池的始末位置
	static char* start;
	static char* end;
	//用来标记该空间配置器向系统索要了多少的空间
	static size_t size_heap;
public:
	static void* Allocate(size_t n)
	{
		Obj * volatile * my_free_list;
		Obj * result;
		//不是小内存块就用一级空间配置器
		if (n > (size_t)MAX_BYTE){
			return (malloc_alloc::Allocate(n));
		}
		//
		my_free_list = free_list + FreeList_Index(n);
		result = *my_free_list;
		if (result == 0){
			void *r = refill(Round_Up(n));
			return r;
		}
		*free_list = result->FreeListLink;
		return result;
	}
	//将内存块还原到哈希桶中,p不可以为0
	static void* Deallocate(void* p, size_t n)
	{
		Obj *q = (Obj*)p;
		Obj * volatile  *my_free_list;
		if (n > (size_t)MAX_BYTE){
			malloc_alloc::Deallocate(p,n);
			return;
		}
		my_free_list = free_list + FreeList_Index(n);
		q->FreeListLink = *my_free_list;
		*my_free_list = q;
	}
};
template <bool threads,int inst>
char* DefaultAllocTemplate<inst>::Chunk_alloc(size_t size, int &nobjs)
{
	char* result;
	size_t total_bytes = size*nobjs;
	size_t bytes_left = end - start;//内存池剩余空间
	//内存池剩余完全满足需求量
	if (bytes_left >= total_bytes){
		result = start;
		start += total_bytes;
		return result;
	}
	//内存池剩余空间不能完全满足要求，但可以提供一个以上的内存（尽可能多的提供）
	else if(bytes_left >= size){
		nobjs = bytes_left / size;
		total_bytes = size*nobjs;
		result = start;
		start += total_bytes;
		return result;
	}
	else{
		//内存空间不足，连一块内存都无法申请，向系统堆中补充大小：本次空间总大小两倍+向系统申请总大小。
		size_t bytes_to_get = 2 * total_bytes + Round_Up(size_heap);
		//如果内存池中有剩余空间，将其挂到对应的哈希桶中
		if (bytes_left > 0){
			//首先找到合适的free_list
			Obj* volatile* my_free_list = free_list + FreeList_Index(bytes_left);
			//调整free_list，将内存池中的参与空间编入
			((Obj*)start)->FreeListLink = *my_free_list;
			*my_free_list = (Obj*)start;
		}
		start = (char*)malloc(bytes_to_get);
		if (0 == start){
			//通过系统堆补充空间失败，在哈系统中找一找是否有较大的内存块
			int i;
			Obj* volatile* my_free_list, *p;
			for (i = size; i <= MAX_BYTE; i += ALIGN){
				my_free_list = free_list + FreeList_Index(i);
				p = *my_free_list;
				if (0 != p){ //free_list 内尚有未用区块
					// 调整free_list以解释未用区块
					*my_free_list = p->free_list_link;
					start = (char*)p;
					end = strat + i;
					//  递归调用自己，为了修正nobjs
					return (chunk_alloc(size, nobjs));
					//注意，任何残余零头终将被编入适当的free_list中备用
				}
			}
		}
		end = 0;//如果出现意外（山穷水尽，到处都没内存可用了）
	    // 调用一级空间配置器，看看out_of_memory机制能否尽点力
		star = (char*)malloc_alloc::Allocate(bytes_to_get);
		//这会导致抛出异常，或内存不足的情况获得改善
		heap_size += bytes_to_get;
		end = start + bytes_to_get;
		//递归调用自己，为了修正nobjs
		return(chunk_alloc(size,nobjs)); 

	}
}
