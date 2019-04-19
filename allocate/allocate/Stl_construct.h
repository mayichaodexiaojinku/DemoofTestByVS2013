#include<new.h>
template<class T1,class T2>
inline void construct(T1* p, const T2& value){
	new (p)T1(value); //��λnew���ʽ
}
template<class T>
inline void destroy(T* pointer){
	pointer->~T();
}
//������destroy�ڶ��棬�����������������˺����跨�ҳ�Ԫ�ص���ֵ�ͱ𣬽�������_type_traits<>��ȡ���ʵ���ʩ
template<class ForwardIterator>
inline void destroy(ForwardIterator first,ForwardIterator last,T*){
	__destroy(first,last,value_type(first));
}
//�ж�Ԫ�ص���ֵ�ͱ��Ƿ���trivial destructor
template<class ForwardIterator,class T>
inline void __destroy(ForwardIterator first, , ForwardIterator last, T*)
{
	typedef typename __type_traits<T>::has_trivial_destructor trivial_destructor;
	__destroy_aux(first, last, trivial_destructor);
}
//���Ԫ�ص���ֵ�ͱ�value type����non_trivial destructor...
template<class ForwardIterator>
inline void __destroy_aux(ForwardIterator first, ForwardIterator last, __false_type){
	for (; first < last; ++first)
		destroy(&*first);
}
//���Ԫ�ص���ֵ�ͱ�value type���� trivial destructor...
template<class ForwardIterator>
inline void __destroy_aux(ForwardIterator first, ForwardIterator last, __true_type){}
inline void destroy(char*, char*){}
inline void destroy(wchar_t*, wchar_t*){}
