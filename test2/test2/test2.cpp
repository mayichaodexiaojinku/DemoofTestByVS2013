// test2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

/*
class Volume{
private:
	double length;
	double width;
	double height;
public:
	void Scan()
	{
		double l, w, h;
		cout << "�����볤����ĳ� :";
		cin >> l;
		length = l;
		cout << "�����볤����Ŀ� :";
		cin >> w;
		width = w;
		cout << "�����볤����ĸ� :";
		cin >> h;
		height = h;
	}
	double result()
	{
		return length*width*height;
	}
	void Print()
	{
		cout <<"����������Ϊ��"<< result() << endl;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Volume v1,v2,v3;
	cout << "�����1��������ĳ�������" << endl;
	v1.Scan();
	v1.Print();
	cout << "�����2��������ĳ�������" << endl;
	v2.Scan();
	v2.Print();
	cout << "�����3��������ĳ�������" << endl;
	v3.Scan();
	v3.Print();
	return 0;
}
class Building{
private:
	int floor;
	int count;
	int area;
public:
	Building(int f,int c,int a)
		:floor(f)
		, count(c)
		, area(a)
	{}
	void print(){
		cout << "¥������" << floor << endl;
		cout << "��������" << count << endl;
		cout << "�������" << area << endl;
	}
};
class Home_Arch :public Building{
private:
	int bedroomCount;
	int livingroomCount;
	int toiletCount;
	int cookhouse;
public:
	Home_Arch(int f ,int count,int a,int b,int l,int t,int c)
		:Building(f,count,a)
		,bedroomCount(b)
	    ,livingroomCount(l)
	    ,toiletCount(t)
		,cookhouse(c)
	{}
	void print1(){
		cout << "��������" << bedroomCount << endl;
		cout << "��������" << livingroomCount << endl;
		cout << "����������" << toiletCount << endl;
		cout << "��������" << cookhouse << endl;
	}
};
class Office_Building :public Building{
private:
	int officeCount;
	int meetingCount;
public:
	Office_Building(int f, int count, int a,int o, int m)
		:Building(f, count, a)
		,officeCount(o)
		, meetingCount(m)
	{}
	void print1(){
		cout << "�칫������" << officeCount << endl;
		cout << "����������" << meetingCount << endl;
	}
};
class Hospital :public Building{
private:
	int roomCount;
	int operatingCount;
public:
	Hospital(int f, int count, int a, int r, int o)
		:Building(f, count, a)
		,roomCount(r)
		, operatingCount(o)
	{}
	void print1(){
		cout << "��������" << roomCount << endl;
		cout << "����������" << operatingCount << endl;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Home_Arch *h = new Home_Arch(1, 8, 120, 3, 2, 2, 1);
	h->print();
	h->print1();
	cout << endl;
	Office_Building *o = new Office_Building(2,6,500,3,3);
	o->print();
	o->print1();
	cout << endl;
	Hospital *ho = new Hospital(3,20,600,15,5);
	ho->print();
	ho->print1();
	return 0;
}
*/
/*
class Teacher{
private:
	string name;
	int salary;
	int classHour;
public:
	Teacher(string _n,int ch)
		:name(_n)
		, classHour(ch)
	{}
	void print(){
		cout << "������" << name << endl;
		cout << "�ڿ�ʱ����" << classHour << endl;
	}
	int TimeofClass(){
		return classHour;
	}
};
class Professor :public Teacher{
private:
	int classpay = 30;
	int basepay = 6000;
public:
	Professor(string name,int ch)
		:Teacher(name,ch)
	{}
	int CountOfMoney(){
		return basepay + classpay*TimeofClass();
	}
	void ShowMoney(){
		cout <<"����Ϊ��" << CountOfMoney() << endl;
	}
};
class Lecturer :public Teacher{
private:
	int classpay = 20;
	int basepay = 4000;
public:
	Lecturer(string name, int ch)
		:Teacher(name, ch)
	{}
	int CountOfMoney(){
		return basepay + classpay*TimeofClass();
	}
	void ShowMoney(){
		cout << "����Ϊ��" << CountOfMoney() << endl;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Professor *p = new Professor("Peter", 10);
	p->print();
	p->ShowMoney();
	Lecturer *l = new Lecturer("Mark",10);
	l->print();
	l->ShowMoney();
}
*/
/*
class Amimal{
private:
	int age;
};
class Dog :public Amimal{
public:
	void SetAge(int n){
		age = n;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{ 
	Dog nova;
	nova.SetAge(10);
}
*/
/*
class vehicle{
public:
	int MaxSpeed;
	int Weight;
	void Run(){
		cout << MaxSpeed << endl;
	}
	void Stop(){
		cout << Weight << endl;
	}
};
class bicycle :public vehicle{
private:
	int height;
};
class motorcar :public vehicle{
private:
	int SeatNum;
};
class motorcycle :public bicycle, public motorcar{
};
int _tmain(int argc, _TCHAR* argv[])
{
	motorcycle m;
	m.MaxSpeed = 100;
}
*/
class Square{
private:
	double length;
public:
	Square(double l)
		:length(l)
	{}
	virtual double perimeter(){
		return 4 * length;
	}
	virtual void print(){
		cout << "�����ε��ܳ�Ϊ��" << perimeter() << endl;
	}
	double len()
	{
		return length;
	}
};
class Rectang:public Square{
private:
	double weight;
public:
	Rectang(int l,int w)
		:Square(l)
		,weight(w)
	{}
	virtual double perimeter(){
		return 2 * (weight + len());
	}
	virtual void print(){
		cout << "�����ε��ܳ�Ϊ��" << perimeter() << endl;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Square *s;
	Rectang r(10, 20);
	s = &r;
	s->print();
	return 0;
}