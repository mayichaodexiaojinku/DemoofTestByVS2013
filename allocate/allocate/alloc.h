#program once
#include<iostream>
typedef bool(*headle_func)();
template<int inst>
//һ���ռ�����������malloc��free�����˷�װ����������C++��set_new_headle��˼��
//�����ͱ������inst��ȫû����
class MallocAllocTemplate
{
private:
	static headle_func _malloc_alloc_oom_headler;
	//���º����������ڴ治������
	static void *OomMalloc(size_t);
	static void *OomRealloc(void *, size_t);
public:
	//��malloc���з�װ
	static void* Allocate(size_t n)
	{
		void *result = malloc(n);
		if (result == 0)
			result = OomMalloc(n);
		return result;
	}
	//��free���з�װ
	static void* Deallocate(void* p ,size_t)//ΪʲôҪ������һ��size_t������Ϊ�ڶ����ռ���������Ҫʹ��
	{
		free(p);
	}
	//��realloc���з�װ���ú����������á�
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
//��ֵΪ0���д��ͻ�
template <int inst>
void* MallocAllocTemplate<inst>::_malloc_alloc_oom_headler = 0;
//malloc����ռ�ʧ�ܵĴ��ú���
template <int inst>
void* MallocAllocTemplate<inst>::OomMalloc(size_t n)
{
	headle_func my_malloc_headler();
	void *result;
	for (;;){
		//����û��Ƿ����ÿռ䲻��Ӧ�Դ�ʩ�� ���û�����ã����쳣��ģʽnew�ķ�ʽ��
		my_malloc_header = _malloc_alloc_oom_headler;
		if (0 == my_malloc_handler)
		{
			_THROW_BAD_ALLOC;
		}
		//����û����ã�ִ���û��ṩ�Ŀռ䲻��Ӧ�Դ�ʩ
		(*my_malloc_headler)();
		//��������ռ���ܾͻ�����ɹ���
		result = malloc(n);
		if (result)
			return result;
	}
}
//��malloc���ơ�
template <int inst>
void* MallocAllocTemplate<inst>::OomRealloc(void* p,size_t n)
{
	headle_func my_malloc_headler();
	void *result;
	for (;;){
		//����û��Ƿ����ÿռ䲻��Ӧ�Դ�ʩ�����û�����ã����쳣��ģʽnew�ķ�ʽ��
		my_malloc_header = _malloc_alloc_oom_headler;
		if (0 == my_malloc_handler)
		{
			_THROW_BAD_ALLOC;
		}
		//����û����ã�ִ���û��ṩ�Ŀռ䲻��Ӧ�Դ�ʩ
		(*my_malloc_headler)();
		//��������ռ���ܾͻ�����ɹ���
		result = realloc(p,n);
		if (result)
			return result;
	}
}
typedef MallocAllocTemplate<0> malloc_alloc;
//�����ռ��������������ڴ�ؼ�����ר�Ÿ���С��128�ֽڵ�С�ڴ�飬���ٶ���ռ��˷ѣ����ù�ϣͰ�ķ�ʽ������û���ȡ�ռ���ٶ����Ч����
template<int inst>
class DefaultAllocTemplate
{
private:
	enum{ALIGN = 8}; //����û������ڴ治��8�������������϶��뵽8��������
	enum{MAX_BYTE = 128}; //��С�ڴ�ķֽ�㡣
	enum{NFREELIST = MAX_BYTE / ALIGN}; //free-list����
	//����û������ڴ�鲻��8���������������϶��뵽8����������
	static size_t Round_Up(size_t bytes)
	{
		return ((bytes + (ALIGN - 1))&~(ALIGN - 1));
	}
private:
	//����������ά����������ʡ�ռ�
	union Obj
	{
		union Obj* FreeListLink;
		char data[1];
	};
private:
	static Obj* volatile free_list[NFREELIST];
	//��ϣ�����������û��ṩ���ֽ����ҵ�Ͱ��
	static size_t FreeList_Index(size_t bytes)
	{
		return ((bytes + (ALIGN - 1))/(ALIGN - 1));
	}
	//���ϣͰ�в���ռ�
	static void* Refill(size_t n)
	{
		int nobjs = 20;
		char * chunk = Chunk_alloc(n, nobjs);
		Obj *volatile* my_free_list;
		Obj *result;
		Obj *cur_obj, *next_obj;
		int i;
		//���ֻҪ��һ���ֱ�ӷ���
		if (1 == nobjs){
			return chunk;
		}
		//���ҵ���Ӧ��Ͱ
		my_free_list = free_list + FreeList_Index(n);
		result = (Obj*)chunk; //����һ�鷵�ظ��ͻ���
		my_free_list = next_obj = (obj *)(chunk + n);
		//ʣ�µĹҽӵ���ϣͰ��
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
	//��strat��end����ڴ�ص�ʼĩλ��
	static char* start;
	static char* end;
	//������Ǹÿռ���������ϵͳ��Ҫ�˶��ٵĿռ�
	static size_t size_heap;
public:
	static void* Allocate(size_t n)
	{
		Obj * volatile * my_free_list;
		Obj * result;
		//����С�ڴ�����һ���ռ�������
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
	//���ڴ�黹ԭ����ϣͰ��,p������Ϊ0
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
	size_t bytes_left = end - start;//�ڴ��ʣ��ռ�
	//�ڴ��ʣ����ȫ����������
	if (bytes_left >= total_bytes){
		result = start;
		start += total_bytes;
		return result;
	}
	//�ڴ��ʣ��ռ䲻����ȫ����Ҫ�󣬵������ṩһ�����ϵ��ڴ棨�����ܶ���ṩ��
	else if(bytes_left >= size){
		nobjs = bytes_left / size;
		total_bytes = size*nobjs;
		result = start;
		start += total_bytes;
		return result;
	}
	else{
		//�ڴ�ռ䲻�㣬��һ���ڴ涼�޷����룬��ϵͳ���в����С�����οռ��ܴ�С����+��ϵͳ�����ܴ�С��
		size_t bytes_to_get = 2 * total_bytes + Round_Up(size_heap);
		//����ڴ������ʣ��ռ䣬����ҵ���Ӧ�Ĺ�ϣͰ��
		if (bytes_left > 0){
			//�����ҵ����ʵ�free_list
			Obj* volatile* my_free_list = free_list + FreeList_Index(bytes_left);
			//����free_list�����ڴ���еĲ���ռ����
			((Obj*)start)->FreeListLink = *my_free_list;
			*my_free_list = (Obj*)start;
		}
		start = (char*)malloc(bytes_to_get);
		if (0 == start){
			//ͨ��ϵͳ�Ѳ���ռ�ʧ�ܣ��ڹ�ϵͳ����һ���Ƿ��нϴ���ڴ��
			int i;
			Obj* volatile* my_free_list, *p;
			for (i = size; i <= MAX_BYTE; i += ALIGN){
				my_free_list = free_list + FreeList_Index(i);
				p = *my_free_list;
				if (0 != p){ //free_list ������δ������
					// ����free_list�Խ���δ������
					*my_free_list = p->free_list_link;
					start = (char*)p;
					end = strat + i;
					//  �ݹ�����Լ���Ϊ������nobjs
					return (chunk_alloc(size, nobjs));
					//ע�⣬�κβ�����ͷ�ս��������ʵ���free_list�б���
				}
			}
		}
		end = 0;//����������⣨ɽ��ˮ����������û�ڴ�����ˣ�
	    // ����һ���ռ�������������out_of_memory�����ܷ񾡵���
		star = (char*)malloc_alloc::Allocate(bytes_to_get);
		//��ᵼ���׳��쳣�����ڴ治��������ø���
		heap_size += bytes_to_get;
		end = start + bytes_to_get;
		//�ݹ�����Լ���Ϊ������nobjs
		return(chunk_alloc(size,nobjs)); 

	}
}
