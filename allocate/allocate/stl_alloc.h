#include"alloc.h"
#ifdef __USE_MALLOC
typedef __malloc_alloc_template<0> malloc_alloc;
typedef malloc_alloc alloc;   //令alloc为第一级配置器

#else
typedef __default_alloc_template<__NODE_ALLOCATOR_THREADS, 0> alloc;
#endif
template<class T,class Alloc>
class simple_alloc{
public:
	static T *allocate(size_t n){
		return 0 == n ? 0 : Alloc::allocate(n*sizeof(T));
	}
	static T *allocate(void){
		return (T*)Alloc::allocate(sizeof(T));
	}
	static void deallocate(T* p, size_t n){
		if (0 != n)
			Alloc::deallocate(p, n*sizeof(T));
	}
	static void deallocate(T* p){
		if (0 != n)
			Alloc::deallocate(p, sizeof(T));
	}
};