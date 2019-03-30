#include<iostream>
#include<assert.h>
#include<mutex>
#include<memory>
using namespace std;
//资源独占，资源只能被一个对象来管理
/*
template<class T>
class UniquePtr
{
public:
	UniquePtr(T* ptr = nullptr)
		:_ptr(ptr)
	{}
	~UniquePtr()
	{
		if (_ptr)
			delete _ptr;
	}
	T* operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
private:
	UniquePtr(const UniquePtr<T>&);
	UniquePtr<T>& operator=(const UniquePtr<T>&);
	T* _ptr;
};
void TestUniquePtr()
{
	UniquePtr<int> up1(new int);
}
//为了让大家共用同一块资源而不被多次释放的问题，给智能中加入一个计数器，当计数器的数为1时，最后一个使用这
//块资源的用户进行释放。
template<class T>
class SharePtr
{
public:
   SharePtr(T* ptr = nullptr)
		:_ptr(ptr)
		, _pCount(nullptr)
   {
	   if (_ptr){
		   _pCount = new int(1);
		   _pm = new mutex;
	   }
   }
   ~SharePtr()
   {
	   if (_ptr == nullptr && 0 == SubRefCount()){
		   delete _ptr;
		   delete _pCount;
		   delete _pm;
	   }
   }
   SharePtr(const SharePtr<T>& sp)
	   :_ptr(sp._ptr)
	   , _pCount(sp._pCount)
	   , _pm(sp._pm)
   {
	   if (_ptr)
		   AddRefCount();
   }
   SharePtr<T>& operator=(const SharePtr<T>& sp)
   {
	   if (this != &sp){
		   if (_ptr && 0 == SubRefCount()){
			   delete _ptr;
			   delete _pCount;
			   delete _pm;
		   }
		   _ptr = sp._ptr;
		   _pCount = sp._pCount;
		   if (_ptr)
			   AddRefCount();
	   }
	   return *this;
   }
   T* operator*()
   {
	   return *_ptr;
   } 
   T* operator->()
   {
	   return _ptr;
   }
   int GetCount()
   {
	   assert(_pCount);
	   return *_pCount;
   }
   int  AddRefCount()
   {
	   _pm->lock();
	   ++(*_pCount);
	   _pm->unlock();
	   return *_pCount;
   }
   int  SubRefCount()
   {
	   _pm->lock();
	   --(*_pCount);
	   _pm->unlock();
	   return *_pCount;
   }
private:
	T* _ptr;
	int* _pCount;
	mutex* _pm;
};
void TestSharePtr()
{
	SharePtr<int> pb1(new int);
	SharePtr<int> pb2(pb1);
	SharePtr<int> pb3(new int);
	pb2 = pb3;
	cout << pb1.GetCount() << endl;
}
int main()
{
	TestSharePtr();
	return 0;
}
class Data
{
public:
	Data()
	{}
	~Data()
	{}
	int _year;
};
template<class T>
class AutoPtr
{
public:
	AutoPtr(T* ptr = nullptr)
		:_ptr(ptr)
	{}
	AutoPtr(AutoPtr<T>& sp)
		:_ptr(sp._ptr)
	{
		sp._ptr = nullptr;
	}
	~AutoPtr()
	{
		if (_ptr)
			delete _ptr;
	}
	AutoPtr<T>& operator=(AutoPtr<T>& sp)
	{
		if (this != &sp){
			if (_ptr)
				delete _ptr;
			_ptr = sp._ptr;
			sp._ptr = nullptr;
		}
		return *this;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
private:
	T *_ptr;
};
int main()
{
	auto_ptr<Data> ap(new Data);
	auto_ptr<Data> ap1(ap);
	//ap->_year = 2019;
	//AutoPtr<Data> ap(new Data);
	//AutoPtr<Data> ap1(ap);
	//ap->_year = 2019;
	return 0;
}
struct ListNode
{
	int _data;
	weak_ptr<ListNode> _pre;
	weak_ptr<ListNode> _pNext;
	~ListNode()
	{
		cout << " ~ListNode()" << endl;
	}
};
int main()
{
	shared_ptr<ListNode> n1(new ListNode);
	shared_ptr<ListNode> n2(new ListNode);
	cout << n1.use_count() << endl;
	cout << n2.use_count() << endl;
	n1->_pNext = n2;
	n2->_pre = n1;
	cout << n1.use_count() << endl;
	cout << n2.use_count() << endl;
	return 0;
}
*/
template<class T>
class FreeFunc
{
public:
	void operator()(T* ptr)
	{
		cout << "free :" << ptr << endl;
		free(ptr);
	}
};
template<class T>
class DeleteArrayFunc
{
public:
	void operator()(T* ptr)
	{
		cout << "Delete[]:" << ptr << endl;
		delete[] ptr;
	}
};
int main()
{
	FreeFunc<int> f;
	shared_ptr<int> sp1((int*)malloc(4),f);
	DeleteArrayFunc<int> d;
	shared_ptr<int> sp2(new int[3], d);
 	return 0;
}