#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#if 0
char fun(char x ,char y)
{
	return x;
}
int main()
{
	int i = '1', j = '2';;
	cout << fun(i,j);
	return 0;
}
class Test{
public:
	int a;
	int b;
	virtual void fun() {}
	Test(int temp1 = 0, int temp2 = 0)
	{
		a=temp1 ;
		b=temp2 ;
	}
	int getA()
	{
		return a;
	}
	int getB()
	{
		return b;
	}
};
int main()
{
	Test obj(5, 10);
	int* pInt = (int*)&obj;
	*(pInt + 0) = 100;//指向虚函数指针表
	*(pInt + 1) = 200;//*(pInt+1)、*(pInt+2)指向a和b；
	cout << "a = " << obj.getA() << endl;
	cout << "b = " << obj.getB() << endl;
	return 0;
}
int main()
{
	int x = 9999;
	int count = 0;
	while (x){
		count++;
		x = x&(x - 1);
	}
	cout << count << endl;
	return 0;
//}
int main()
{
	int n[][3] = { 10, 20, 30, 40, 50, 60 };
	int(*p)[3];
	p = n;
	cout << p[0][0] << *(p[0] + 1) << (*p)[2] << endl;
	return 0;
}
void func(const int& v1, const int &v2)
{
	cout << v1 << ' ';
	cout << v2 << ' ';
}
int main()
{
	int i = 0;
	func(++i,i++);
	return 0;
//}
int binInsert(int n, int m, int j, int i) {
	int x = 0;
	while (i >= j){
		if (m & (1<<x++)){
			n = n | (1 << j);
		}
		j++;
	}
	return n;
}
int main()
{
	int a = binInsert(1024,19,2,6);
	cout << a << endl;
	return 0;
}
int main()
{
	string x = "asdfas";
	string y = "werasdfaswer";
	int count = 0;
	int res = 0;
    for (int i = 0; i < y.size(); i++){
			count = 0;
			int n = i;
		for (int j = 0; j < x.size(); j++){
			if (y[n] == x[j]){
					n++;
					count++;
			}
			if (res < count)
				res = count;
		}
	}
	cout << res << endl;
	return 0;
}
int main()
{
	int i = 0;
	if (i <= 0)
		printf("******\n");
	else
		printf("%%%%%%\n");
	return 0;
}
class A
{
public:
	void func()
	{
		cout << "dasda" << endl;
	}
};
class B :public A
{
public:
	void func()
	{
		A::func();
		cout << "myv" << endl;
	}
};
int main()
{
	B b;
	b.func();
}
class Base
{
public:
	virtual void Func1() 
	{ 
		cout << "Base::Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}
	void Func3()
	{
		cout << "Base::Func3()" << endl;
	}
private: 
	int _b = 1; 
};
class Derive : public Base
{
public: 
	virtual void Func1()
	{
		cout << "Derive::Func1()" << endl;
	}
private: 
	int _d = 2; 
};
int main()
{
	Base b; 
	Derive d;
	return 0;
}
int main()
{
	int i = 0, a = 1, b = 2, c = 3;
	i = ++a || ++b || ++c;
	printf("%d %d %d %d",i,a,b,c);
	return 0;
}
using namespace std;
int main()
{ 
	string str;
	getline(cin, str);
	vector<string> v;
	string res;
	for (int i = 0; i < str.size(); i++){
		if (str[i] == '"'){
			if (str[i + 1] != '"')
				res += str[i + 1];
			else{
				v.push_back(res);
				res.clear();
			}
		}
		if (str[i] != ' ')
			res += str[i];
		else{
			v.push_back(res);
			res.clear();
		}
	}
	v.push_back(res);
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << endl;
	}
	return 0;
}
static int a = 1;
void fun()
{
	a = 2;
}
int main()
{
	printf("%d",a);
	fun();
	printf("%d", a);
}
class A
{
public:
	A()
	{
		printf("a");
	}
	~A()
	{
		printf("da");
	}
};
class B
{
public:
	B()
	{
		printf("B");
	}
	~B()
	{
		printf("dB");
	}
};
class C : public A,public B
{
public:
	 C()
	{ 
		printf("C");
	 }
	 ~C()
	 {
		 printf("DC");
	 }
};
int main()
{
	A *a = new C();	
	delete a;
	return 0;
}
struct test{
	test(int){
		cout << "dsadas" << endl;
	 }
	test() {}
	void fun(){}
};
int main()
{
	test a(1);
	a.fun();
	return 0;

}
class Base
{
public:
	virtual int foo(int x)
	{
		return x * 10;
	}
	int foo(char x[14])
	{
		return  sizeof(x)+10;
	}
};
class Derivd:public Base
{
public:
	int foo(int x)
	{
		return x * 20;
	}
    virtual	int foo(char x[10])
	{
		return  sizeof(x)+20;
	}
};
int main()
{
	Derivd D;
	Base *b = &D;
	char x[10];
	printf("%d\n",b->foo(100)+b->foo(x));
	return 0;
}
int main()
{
	const int a = 10;
	int *pa = (int *)&a;
	*pa = 20;
	cout << a << *pa << endl;
	return 0;
}
class A
{
public:
	void FuncA()
	{
		cout << "FuncA" << endl;
	}
	virtual void FuncB()
	{
		cout << "FuncAB" << endl;
	}
};
class B :public A
{
public:
	void FuncA()
	{
		A::FuncA();
		cout << "FuncAb" << endl;
	}
	virtual void  FuncB()
	{
		cout << "FuncBB" << endl;
	}
};
int main()
{
	B b;
	A *pa;
	pa = &b;
	pa->FuncA();
	pa->FuncB();
	return 0;

}
#include<iostream>
#include<vector>
using namespace std;
void Finddiv(int n, vector<int>& v)
{
	for (int i = 1; i <= n / 2; i++){
		if (n%i == 0)
			v.push_back(i);
	}
}
int main()
{
	int n;
	while (cin >> n){
		int count = 0;
		for (int i = 1; i < n; i++){
			int sum = 0;
			vector<int> v;
			Finddiv(i, v);
			for (int j = 0; j < v.size(); j++){
				sum += v[j];
			}
			if (sum == n)
				count++;
		}
		cout << count << endl;
	}
	return 0;
}
class A{
public:
	A()
	{
		p();
	}
	virtual void  p()
	{
		cout << " a ";
 	}
	virtual ~A()
	{
		p();
	}
};
class B:public A
{
public:
	B()
	{
		p();
	}
	virtual void  p()
	{
		cout << " B ";
	}
	virtual ~B()
	{
		p();
	}
};
int main()
{
	A* a = new B();
	delete a;
	return 0;
}

int main()
{
	long long a = 1, b = 2, c = 3;
	printf("%d %d %d\n",a,b,c);
	return 0;
}
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	while (cin >> n){
		int m = 2 * n - 1;
		vector<vector<int>> v(n, vector<int>(m, 0));
		v[0][0] = 1;
		for (int i = 1; i < n; i++){
			v[i][0] = v[i][2 * i] = 1;
			for (int j = 1; j < 2 * i; j++){
				if (j == 1)
					v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
				else
					v[i][j] = v[i - 1][j - 2] + v[i - 1][j - 1] + v[i - 1][j];
			}
		}
		for (int j = 0; j < m; j++){
			if (v[n - 1][j] % 2 == 0 && v[n - 1][j] != 0){
				cout << j + 1 << endl;
				break;
			}
		}
	}
	return 0;
}
#endif
#if 0
class A
{
public:
	void func()
	{
		cout << "aa" << endl;
	}
};
class B :private A
{
public:
	void func()
	{
		cout << "bb" << endl;
	}
};
class C :public B
{
public:
	void func()
	{
		A::func();
	}
};
int main()
{
	C b;
	b.func();
	return 0;
}
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int i = 0;
	int j = 0;
	while (i < s1.size() && j < s2.size()){
		if (s1[i] == s2[j]){
			i++;
			j++;
		}
		else if (s1[i] == '?'){
			i++;
			j++;
		}
		else if (s1[i] == '*'){
			while (s1[i++] != s2[j++]){
				if (j == s2.size()){
					cout << true << endl;
					return 0;
				}
			}
		}
		else{
			cout << false << endl;
			return 0;
		}
	}
	if (i == s1.size() && j == s1.size())
		cout << true << endl;
	return 0;
}
class A
{
public:
	void *p1;
private:
	void *p2;
protected:
	void *p3;
};
class B :public A
{

};
int main()
{
	cout << sizeof(B) << endl;
	return 0;
}
class Base
{
	int x;
public:
	Base(int b)
		:x(b)
	{}
	virtual void display()
	{
		cout << x << endl;
	}
};
class Derived:public Base
{
	int y;
public:
	Derived(int b)
		:Base(b)
		,y(b)
	{}
	void display()
	{
		cout << y << endl;
	}
};
int main()
{
	Base b(2);
	Derived d(3);
	b.display();
	d.display();
	Base *p = &b;
	p->display();
	return 0;
}
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);
	if (s1.size() > s2.size()){
		s1.swap(s2);
	}
	vector<vector<int>> v(s1.size() + 1, vector<int>(s2.size() + 1, 0));
	int start = 0;
	int max = 0;
	for (int i = 1; i <= s1.size(); i++)
	for (int j = 1; j <= s2.size(); j++){
		if (s1[i - 1] == s2[j - 1]){
			v[i][j] = v[i - 1][j - 1] + 1;
		}
		if (max < v[i][j]){
			max = v[i][j];
			start = i - max;
		}
	}
	cout << s1.substr(start, max) << endl;
	return 0;
}
#include<stdio.h>
#include<string.h>
int fun(unsigned int x)
{
	int n = 0;
	while ((x + 1)){
		n++;
		x = x | (x + 1);
	}
	return n;
}
class A
{
};
int main()
{
	cout << sizeof(A);
	return 0;
}
int main()
{
	int n;
	char y[10] = "ntse";
	char *x = y;
	n = strlen(x);
	*x = x[n];
	x++;
	printf("x = %s\n", x);
	printf("y = %s\n", y);
	cout << -6 * 4 << endl;
	return 0;
}
#endif
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string s;
	while (cin >> s){
		int i;
		for (i = 0; i < s.size(); i++){
			if (1 == count(s.begin(), s.end(), s[i])){
				cout << s[i] << endl;
				return 0;
			}
		}
		cout << -1 << endl;
	}
	return 0;
}