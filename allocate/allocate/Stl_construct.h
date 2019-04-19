#include<new.h>
template<class T1,class T2>
inline void construct(T1* p, const T2& value){
	new (p)T1(value); //定位new表达式
}
template<class T>
inline void destroy(T* pointer){
	pointer->~T();
}
//以下是destroy第二版，接收两个迭代器。此函数设法找出元素的数值型别，进而利用_type_traits<>求取最适当措施
template<class ForwardIterator>
inline void destroy(ForwardIterator first,ForwardIterator last,T*){
	__destroy(first,last,value_type(first));
}
//判断元素的数值型别是否有trivial destructor
template<class ForwardIterator,class T>
inline void __destroy(ForwardIterator first, , ForwardIterator last, T*)
{
	typedef typename __type_traits<T>::has_trivial_destructor trivial_destructor;
	__destroy_aux(first, last, trivial_destructor);
}
//如果元素的数值型别（value type）有non_trivial destructor...
template<class ForwardIterator>
inline void __destroy_aux(ForwardIterator first, ForwardIterator last, __false_type){
	for (; first < last; ++first)
		destroy(&*first);
}
//如果元素的数值型别（value type）有 trivial destructor...
template<class ForwardIterator>
inline void __destroy_aux(ForwardIterator first, ForwardIterator last, __true_type){}
inline void destroy(char*, char*){}
inline void destroy(wchar_t*, wchar_t*){}
