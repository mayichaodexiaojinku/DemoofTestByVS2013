#include<iostream>
using namespace std;
class Date
{
	//输出运算符重载
	friend ostream& operator<<(ostream& _cout, const Date d)

	{

		_cout << d._year << "-" << d._month << "-" << d._day;

		return _cout;

	}
public:
	//构造函数
	Date(int year = 2000, int month = 1, int day = 1)
		:_year(year)
		,_month(month)
		,_day(day)
	{    
		_year = year;
		_month = month;
		_day = day;
	}
	//拷贝构造函数
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//运算符重载
	Date& operator=(const Date& d)
	{
		if (this !=  &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	Date& operator++()
	{
		_day += 1;
		return *this;
	}
	Date& operator--()
	{
		_day -= 1;
		return *this;
	}
	Date operator++(int)
	{
		Date temp(*this);
		_day += 1;
		return temp;
	}
	Date operator--(int)
	{
		Date temp(*this);
		_day -= 1;
		return temp;
	}
	//实现日期与天数的相加
	Date operator+(int days)
	{
		if (days < 0)
		{
			return *this - (0 - days);
		}
		Date temp(*this);
		temp._day += days;
		int daysInMonth = temp.GetMonthDays(temp._year,temp._month);
		while (temp._day > daysInMonth)
		{
			temp._day -= temp.GetMonthDays(temp._year, temp._month);
			temp._month += 1;
			if (temp._month > 12)
			{
				temp._year += 1;
				temp._month = 1;
			}
		}
		return temp;
	}
	//实现日期与天数的相减
	Date operator-(int days)
	{
		if (days < 0)
		{
			return *this + (0 - days);
		}
		Date temp(*this);
		temp._day -= days;
		while (temp._day <=  0)
		{
			temp._month--;
			if (temp._month <= 0)
			{
				temp._year--;
				temp._month = 12;
			}
			temp._day += temp.GetMonthDays(temp._year,temp._month);
		}
		return temp;
	}
	bool operator==(const Date& d)
	{
		if ((_year == d._year) && (_month == d._month) && (_day == d._day))
			return true;
		return false;
	}
	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}
	bool operator>(const Date& d)
	{
		if ((_year > d._year) ||
			((_year == d._year) && (_month > d._month)) ||
			((_year == d._year) && (_month == d._month) && (_day > d._day))
			)
			return true;
		return false;
	}
	bool operator<(const Date& d)
	{
		return !(*this > d || *this == d);
	}
	bool operator<=(const Date& d)
	{
		return !(*this > d);
	}
	bool operator>=(const Date& d)
	{
		return !(*this < d);
	}
	int operator-(const Date& d)
	{
		Date maxdate(*this);
		Date mindate(d);
		if (maxdate < mindate)
		{
			maxdate = mindate;
			mindate = *this;
		}
		int count = 0;
		while (mindate < maxdate)
		{
			mindate = mindate + 1;
			++count;
		}
		return count;
	}
	//判断是否闰年
	bool IsLeapyear(int year)
	{
		if ((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0))
			return true;
		return false;
	}
private:
	int GetMonthDays(int year,int month)
	{
		int day[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (IsLeapyear(year) && (month == 2))
		{
			day[month] += 1;
        }
		return day[month];
	}
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1(2000, 2, 28);	
	cout << ++d1 << endl;	
	cout << --d1 << endl;	
	cout << d1 << endl; 	
	cout << d1-- << endl;	
	cout << d1++ << endl;	
	cout << d1 << endl; 	
	Date d2(1999, 1, 1);	
	cout << d2 + 999 << endl;	
	Date d3(2001, 1, 1);	
	cout << d3 - 999<< endl; 	
	cout << boolalpha << (Date(2016, 10, 1) < d1) << endl;	
	Date d4(2000, 1, 1);
	Date d5(2018, 11, 4);
	cout << d4 - d5 << endl;
	
	return 0;
}
