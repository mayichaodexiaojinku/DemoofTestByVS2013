#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<windows.h>
#include<vector>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<assert.h>
#include<cppjieba/jieba.hpp>
using namespace std;
class TextSimilarity
{
public:
	TextSimilarity(string dict);
	void textsimilarityofmain(const char* filename1,const char* filename2);
private:
	unordered_map<string, int> GetWordFerq(const char* filename);//获得词频
	//unordered_map<string, int> TF_IDFGetWordFerq(const char* filename);//TF—IDF词频
	vector<pair<string, int>> SortByValueReverse(unordered_map<string, int>& wf);//根据Value的值进行排序
	void TextSimilarity::selectAimWords(vector<pair<string, int>>& wfvec, unordered_set<string>& wset);//获取关键词
	vector<double> GetOneHot(unordered_set<string>& wset, unordered_map<string, int>& wf);//获得词频向量
	double consine(vector<double> oneHot1, vector<double> oneHot2);//计算余弦相似度
	string GBKToUTF8(string  s);
	string UTF8ToGBK(string s);
	void GetStopWords(const char* stopwords);
	string DICT;
	string DICT_PATH;
	string HMM_PATH;
	string USER_DICT_PATH;
	string IDF_PATH;
	string STOP_WORD_PATH;
	cppjieba::Jieba _jieba;
	unordered_set<string> _StopWordSet;
	int _MaxWordNumber;
};
