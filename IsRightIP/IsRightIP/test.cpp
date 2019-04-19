#include<iostream>
#include<string>
using namespace std;
bool Isrightip(const string s)
{
	int len = s.length();
	int stage = 0;//IP���м�����
	int val = 0;//ÿ���ֵ�IPֵ
	int is_stage = 0;//��һ�����Ƿ���ֵ
	if (!isdigit(s[0]))
		return false;
	for (int i = 0; i < len; i++){
		if (isdigit(s[i])){
			val = val * 10 + (s[i] - '0');
			++is_stage;
		}
		else if (s[i] == '.'){
			if (s[i + 1] == 0 && s[i + 2] != '.')
				return false;
			if (val <= 255 && is_stage > 0){
				++stage;
			}
			else
				return false;
			val = 0;
			is_stage = 0;
		}
	}
	if (val <= 255 && is_stage > 0)
		++stage;
	if (stage == 4)
		return true;
	else
		return false;

}
int main()
{
	if (Isrightip("192.168.9.1"))
		cout << true << endl;
	else
		cout << false << endl;
	return 0;
}