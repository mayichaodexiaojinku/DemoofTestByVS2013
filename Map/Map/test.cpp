#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
	map<string, string> m;
	m["apple"] = "ƻ��";
	cout << m["apple"] << endl;
	cout << m.size() << endl;
 	return 0;
}
