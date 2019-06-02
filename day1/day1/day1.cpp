// day1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
void print()
{
	cout << "hello world!!!" << endl;
}
void maxNum()
{
	int a, b, c;
	int MaxNum;
	cin >> a >> b >> c;
	MaxNum = max(a, b);
	if (c > MaxNum)
		MaxNum = c;
	cout << "max of num ："<<MaxNum<<endl;

}
struct stu{
	int num;
	int computer;
	int english;
};
void PrintSetw()
{
	stu a, b, c, d;
	cin >> a.num >> a.computer >> a.english;
	cin >> b.num >> b.computer >> b.english;
	cin >> c.num >> c.computer >> c.english;
	cin >> d.num >> d.computer >> d.english;
	cout << a.num << setw(5) << a.computer << setw(5) << a.english << endl;
	cout << b.num << setw(5) << b.computer << setw(5) << b.english << endl;
	cout << c.num << setw(5) << c.computer << setw(5) << c.english << endl;
	cout << d.num << setw(5) << d.computer << setw(5) << d.english << endl;
}
struct complex{
	double  real;
	double  imag;
};
class comp{
	double  real;
	double  imag;
};
double abscomplex(complex c)
{
	return sqrt(c.real*c.real + c.imag*c.imag);
}
void AbsComplex(){
	complex c;
	cin >> c.real >> c.imag;
	cout << abscomplex(c) <<endl;
}
class Com
{
private:
	double  real;
	double  imag;
public:
	Com(double r, double i)
		:real(r)
		, imag(i)
	{}
	void abscomplex()
	{
		cout << sqrt(real*real + imag*imag)<<endl;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	//print();
	//maxNum();
	//PrintSetw();
	//AbsComplex();
	Com *c= new Com(3,4);
	c->abscomplex();
	return 0;
}


