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
void exam(char a[])
{
	printf("%d",sizeof(a));
	return;
}
int main()
{
	char a[] = "dsadasdasd";
	exam(a);
	return 0;
}
#include<iostream>
#include<vector>
using namespace std;
int N, M;
vector<vector<int>> maze;
vector<vector<int>> path_temp;
vector<vector<int>> path_best;
void MazeTrack(int i, int j)
{
	maze[i][j] = 1;
	path_temp.push_back({ i, j });
	if (i == N - 1 && j == M - 1)
	if (path_best.empty() || path_temp.size() < path_best.size())
		path_best = path_temp;
	if (i - 1 > 0 && maze[i - 1][j] == 0)
		MazeTrack(i - 1, j);
	if (i + 1 < N && maze[i + 1][j] == 0)
		MazeTrack(i + 1, j);
	if (j - 1 > 0 && maze[i][j - 1] == 0)
		MazeTrack(i, j - 1);
	if (j + 1 < M && maze[i][j + 1] == 0)
		MazeTrack(i, j + 1);
	maze[i][j] = 0;
	path_temp.pop_back();
}
int main()
{
	while (cin >> N >> M){
		maze = vector<vector<int>>(N, vector<int>(M, 0));
		path_temp.clear();
		path_best.clear();
		for (auto &i : maze)
		for (auto&j : i)
			cin >> j;
		MazeTrack(0, 0);
		for (auto i : path_best)
			cout << '(' << i[0] << ',' << i[1] << ')' << endl;
	}
	return 0;
}
#include<vector>
void oddInOddEvenInEven(vector<int>& arr, int len) 
{
	int odd = 0;
	int even = 1;
	while (odd < len && even <len){
		if (arr[odd] % 2 == 0){
			odd += 2;
		}
		if (arr[even] % 2 == 1){
			even += 2;
		}
		if (odd < len && even < len){
			if (arr[odd] % 2 == 1 && arr[even] % 2 == 0){
				int temp = arr[odd];
				arr[odd] = arr[even];
				arr[even] = temp;
			}
		}
	}
}
int main()
{
	vector<int> v;
	for (int i = 1; i < 10; i++)
		v.push_back(i);
	oddInOddEvenInEven(v, 9);
	for (int i = 0; i < 9; i++)
		cout << v[i] << " ";
	return 0;
}
bool isPalindrome(int x) {
	if (x < 0)
		return false;
	string s;
	if (s.size() == 1)
		return true;
	int left = 0;
	int right = s.size() - 1;
	while (left < right){
		if (s[left] == s[right]){
			left++;
			right--;
		}
		else
			return false;

	}
	return true;
}
int main()
{
	//cout << isPalindrome(1234321) << endl;
	cout << 'A'+'5' << endl;
	return 0;
}
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
bool Isprime(int n)
{
	for (int i = 2; i < n; i++){
		if (n%i == 0)
			return false;
	}
	return true;
}
int main()
{
	int a;
	while (cin >> a){
		int b = a;
		vector<int> v;
		cout << a << " = ";
		if (Isprime(a)){
			cout << 1 << " * " << a << endl;
		}
		else{
			for (int i = 2; i <= a / 2; i++){
				if (Isprime(i) && (a%i == 0)){
					while (Isprime(i) && (b%i == 0)){
						v.push_back(i);
						b = b / i;
					}
				}
			}
			for (int i = 0; i < v.size() - 1; i++)
				cout << v[i] << " * ";
			cout << v[v.size() - 1] << endl;
		}
	}
	return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	string s;
	getline(cin, s);
	int k;
	cin >> k;
	string s1;
	for (int i = 1; i < s.size(); i = i + 2){
		s1 += s[i];
	}
	for (int i = 0; i < s1.size()-k; i = i + k){
		reverse(s1.begin() + i, s1.begin() + i + k);
	}
	return 0;
}
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int n;
	while (cin >> n){
		cin.get();
		vector<string> v(n);
		for (int i = 0; i < n; i++)
			getline(cin,v[i]);
		for (int i = 0; i < n; i++){
			if ((v[i].find(' ') == string::npos) && (v[i].find(',') == string::npos)){
				if (i == n)
					cout << v[i] << endl;
				else
					cout << v[i] << ',';
			}
			else{
				if (i == n)
					cout <<'"' << v[i] << '"' << endl;
				else
					cout << '"' << v[i] << '"' << ',';
			}
		}
	}
	return 0;
}
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1, s2;
	while (1){
		getline(cin, s1);
		while (s1.size() != 0){
			getline(cin, s2);
			for (int i = 0; i <s1.size(); i++){
				int j;
				for (j = 0; j < s2.size(); j++){
					if (s1[i] == '"')
						i++;
					if (s1[i] != s2[j])
						break;
					else
						i++;
				}
				if (j == s2.size())
					cout << "Improtant!" << endl;
			}
			cout << "Ignore" << endl;
		}
	}
	return 0;
}
#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n){
		float res = 0;
		res = (1.00 / n) * 100;
		printf("%.2f", res);
		cout << '%' << endl;
	}
}
*/
#include<vector>
int findMaxGap(vector<int> A, int n) {
	int res = 0;
	for (int i = 0; i <= n - 2; i++){
		auto maxleft = max(A.begin(), A.begin()+i);
		auto maxright = max((A.begin()+i+1), A.end());
		int num = abs(*maxleft - *maxright);
		if (num > res)
			res = num;
	}
	return res;
}
int main()
{
	vector<int> v = {28,75,38,44,66,1};
	cout << findMaxGap(v, 6) << endl;
	return 0;
}






























