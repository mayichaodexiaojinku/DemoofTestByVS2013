#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
/*
int main()
{
	string str;
	getline(cin, str);
	reverse(str.begin(), str.end());
	auto begin = str.begin();
	while (begin != str.end()){
		auto end = begin;
		if (end != str.end() && *end != ' ')
			end++;
		reverse(begin, end);
		if (end != str.end())
			begin = end++;
		else
			begin = end;
	}
	cout << str << endl;
	return 0;
}
#include<stdio.h>
#include<windows.h>

int main()
{
	//char str1[] = "abc";
	//char str2[100] = { 'a', 'b', 'c' };
	//printf("%d ", sizeof(str1));
	//printf("%d ", sizeof(str2));
	struct s1
	{
		double c1;
		char c2;
		int i;
	};
	struct s2
	{
		char c1;
		struct s1 s;
		double i;
	};
	struct s3
	{
		int a:2;
		int b:5;
		int c : 10;
		int d:30;
	};
	struct A{
		unsigned a : 19;
		unsigned b : 11;
		unsigned c : 4;
		unsigned d : 29;
		char index;
	};
	printf("%d",sizeof(unsigned));
	system("pause");
	return 0;
}
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string str;
	cin >> str;
	string res;
	vector<string> v;
	for (int i = 0; i < str.size(); i++){
		if (str[i] >= 0 && str[i] <= 9 &&
			str[i + 1] > str[i]){
			res += str[i];
		}
		if (str[i + 1] >= 'a' &&str[i + 1] <= 'z' &&
			str[i] >= 0 && str[i] <= 9){
			v.push_back(res);
			res = '\0';
		}
	}
	for (int i = 0; i < v.size(); i++){
		if (v[0].size() < v[i].size()){
			v[0].swap(v[i]);
		}
	}
	cout << v[0] << endl;
	return 0;
}
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int hash[100] = { 0 };
	int num = 0;
	int n;z
	while (cin >> n){
		hash[n]++;
		num++;
	}
	for (int i = 0; i<sizeof(hash); i++){
		if (hash[i] >= num / 2){
			cout << i << endl;
			return 0;
		}
	}
	system("pause");
	return 0;
	
}
#include<stdio.h>
int count = 0;
int fib(int i)
{
	count++;
	if (i == 1)
		return 1;
	if (i == 2)
		return 2;
	else
		return fib(i-1) + fib(i-2);
}
int main()
{
	fib(8);
	printf("%d",count);
	return 0;
}
void  fun(char **p)
{
	*p = (char*)malloc(100);
}
int main()
{
	char * str = NULL;
	fun(&str);
	strcpy(str,"asda");
	cout << str << endl;
	return 0;
}
int main()
{
	int b = 1;
	int c = 2;
	int a = b++,c++;
	cout << a << endl;
	return 0;
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2){
		vector<vector<int>> v(s1.size() + 1, vector<int>(s2.size() + 1,0));
		for (int i = 0; i <= s1.size(); i++)
			v[i][0] = i;
		for (int i = 0; i <= s2.size(); i++)
			v[0][i] = i;
		for (int i = 1; i <= s1.size(); i++){
			for (int j = 1; i <= s2.size(); j++){
				if (s1[i - 1] == s2[j - 1])
					v[i][j] = v[i - 1][j - 1];
				else
					v[i][j] = min(min(v[i - 1][j] + 1, v[i][j - 1] + 1), v[i - 1][j - 1] + 1);
			}
		}
		cout << v[s1.size()][s2.size()] << endl;
	}
	return 0;
}