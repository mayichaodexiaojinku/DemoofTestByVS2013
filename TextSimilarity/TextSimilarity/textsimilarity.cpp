#include"textsimilarity.h"
const char* const DICT_PATH = "dict/jieba.dict.utf8";
const char* const HMM_PATH = "dict/hmm_model.utf8";
const char* const USER_DICT_PATH = "dict/user.dict.utf8";
const char* const IDF_PATH = "dict/idf.utf8";
const char* const STOP_WORD_PATH = "dict/stop_words.utf8";
TextSimilarity::TextSimilarity(string dict)
      :DICT(dict)
      , DICT_PATH(dict + "/jieba.dict.utf8")
      , HMM_PATH(dict + "/hmm_model.utf8")
      , USER_DICT_PATH(dict + "/user.dict.utf8")
      , IDF_PATH(dict + "/idf.utf8")
      , STOP_WORD_PATH(dict + "/stop_words.utf8")
      , _jieba(DICT_PATH,
               HMM_PATH,
               USER_DICT_PATH,
               IDF_PATH,
               STOP_WORD_PATH)
               , _MaxWordNumber(10)
{
	GetStopWords(STOP_WORD_PATH.c_str());
}
unordered_map<string, int> TextSimilarity::GetWordFerq(const char* filename)
{
	ifstream fin(filename);//利用ifstream类的构造函数创建一个文件输入流对象
	if (!fin.is_open())
	{
		cout << "open file：" << filename << "failed !";
		return unordered_map<string, int>();
	}
	string line;
	unordered_map<string, int> wf;
	while (!fin.eof())
	{
		getline(fin, line);//GBK
		line = GBKToUTF8(line);
		vector<string> words;
		_jieba.Cut(line, words, true);//对当前文件分词
		for (const auto& e : words)
		{
			if (_StopWordSet.count(e)){
				continue;
			}
			else
			{
				if (wf.count(e))
					wf[e]++;
				else
					wf[e] = 1; 
			}
		}
	}
	return wf;
}
void TextSimilarity::GetStopWords(const char* stopwordfile)
{
	ifstream fin(stopwordfile);
	if (!fin.is_open())
	{
		cout << "open file :" << stopwordfile << "failed !!" << endl;
		return;
	}
	string line;
	while (!fin.eof())
	{
		getline(fin, line);//从输入流读取字符，如果不设第三个参数默认是回车
		_StopWordSet.insert(line);
	}
	fin.close();
}
string TextSimilarity::GBKToUTF8(string s)
{
	//获取buffer大小
	int len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), -1, NULL, 0);
	wchar_t *wstr = new wchar_t[len];
	//GBK-->UTF8
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), -1, wstr, len);
	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* utf8 = new char[len];
	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, utf8, len, NULL, NULL);
	string out(utf8);
	if (wstr){
		delete[] wstr;
		wstr = NULL;
	}
	if (utf8){
		delete[] utf8;
		utf8 = NULL;
	}
	return out;
}
string TextSimilarity::UTF8ToGBK(string s)
{
	//获取buffer大小
	int len = MultiByteToWideChar(CP_UTF8, 0, s.c_str(), -1, NULL, 0);
	wchar_t *wstr = new wchar_t[len];
	//GBK-->UTF8
	MultiByteToWideChar(CP_UTF8, 0, s.c_str(), -1, wstr, len);
	len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* gbk = new char[len];
	WideCharToMultiByte(CP_ACP, 0, wstr, -1, gbk, len, NULL, NULL);
	string out(gbk);
	if (wstr){
		delete[] wstr;
		wstr = NULL;
	}
	if (gbk){
		delete[] gbk;
		gbk = NULL;
	}
	return out;
}
bool cmpReverse(pair<string, int> lp, pair<string, int> rp)
{
	return lp.second > rp.second;
}
vector<pair<string, int>> TextSimilarity::SortByValueReverse(unordered_map<string, int>& wf)
{
	vector<pair<string, int>> wfvector(wf.begin(),wf.end());
	sort(wfvector.begin(), wfvector.end(), cmpReverse);
	return wfvector;
}
void TextSimilarity::selectAimWords(vector<pair<string, int>>& wfvec, unordered_set<string>& wset)
{
	int len = wfvec.size();
	int sz = len > _MaxWordNumber ? _MaxWordNumber : len;
	for (int i = 0; i < sz; i++)
	{
		wset.insert(wfvec[i].first);
	}
}
vector<double> TextSimilarity::GetOneHot(unordered_set<string>& wset, unordered_map<string, int>& wf)
{
	vector<double> oneHot;
	for (const auto& e : wset)
	{
		if (wf.count(e))
		{
			oneHot.push_back(wf[e]);//value
		}
		else
		{
			oneHot.push_back(0);
		}
	}
	return oneHot;
}
double TextSimilarity::consine(vector<double> oneHot1, vector<double> oneHot2)
{
	double modular1 = 0 , modular2 = 0;
	double products = 0;
	assert(oneHot1.size() == oneHot2. size());
	for (int i = 0; i < oneHot1.size(); i++)
	{
		products += oneHot1[i] * oneHot2[i];
		modular1 += pow(oneHot1[i], 2);
		modular2 += pow(oneHot2[i], 2);
	}
	return products / (sqrt(modular1)*sqrt(modular2));
}
