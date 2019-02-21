#include"textsimilarity.h"
/*
void testWordFreq()
{
	TextSimilarity ts("../dict");
	unordered_map<string, int> wf = ts.GetWordFerq("yaowen.txt");
	for (const auto& w : wf)
	{
		cout << ts.UTF8ToGBK(w.first) << ": " << w.second << endl;
	}
	vector<pair<string, int>> wfvector = ts.SortByValueReverse(wf);
	for (const auto& w : wfvector)
	{
		cout << ts.UTF8ToGBK(w.first) << ": " << w.second << endl;
	}
}
void testOneHot()
{
	TextSimilarity ts("../dict");
	unordered_map<string, int> wf = ts.GetWordFerq("yaowen.txt");
	unordered_map<string, int> wf2 = ts.GetWordFerq("yaowen1.txt");
	unordered_set<string> wset;
	//用排序好的词频挑选前N个候选词
	vector<pair<string, int>> wfvec = ts.SortByValueReverse(wf);
	vector<pair<string, int>> wfvec2 = ts.SortByValueReverse(wf2);
	cout << "wfvec :" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << ts.UTF8ToGBK(wfvec[i].first) << ":" << wfvec[i].second << " ";
	}
	cout << endl;
	cout << "wfvec2 :" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << ts.UTF8ToGBK(wfvec2[i].first) << ":" << wfvec2[i].second << " ";
	}
	cout << endl;
	ts.selectAimWords(wfvec, wset);
    ts.selectAimWords(wfvec2, wset);
	cout << "wset :" << endl;
	for (const auto& e : wset)
	{
		cout << ts.UTF8ToGBK(e) << " ";
	}
	cout << endl;
	vector<double> oneHot = ts.GetOneHot(wset, wf);
	vector<double> oneHot2 = ts.GetOneHot(wset, wf2);
	cout << "oneHot :" << endl;
	for (const auto& w : oneHot)
	{
		cout << w << " " ;
	}
	cout << endl;
	cout << "oneHot2 :" << endl;
	for (const auto& w : oneHot2)
	{
		cout << w << " ";
	}
	cout << endl;
	cout << "cosine :" << ts.consine(oneHot, oneHot2) << endl;
}
int main()
{
	testWordFreq();
	testOneHot();
	return 0;
}
*/
void TextSimilarity::textsimilarityofmain(const char* filename1, const char* filename2)
{
	unordered_map<string, int> wf = GetWordFerq(filename1);
	unordered_map<string, int> wf2 = GetWordFerq(filename2);
	unordered_set<string> wset;
	//用排序好的词频挑选前N个候选词
	vector<pair<string, int>> wfvec = SortByValueReverse(wf);
	vector<pair<string, int>> wfvec2 = SortByValueReverse(wf2);
	cout << "wfvec :" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << UTF8ToGBK(wfvec[i].first) << ":" << wfvec[i].second << " ";
	}
	cout << endl;
	cout << "wfvec2 :" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << UTF8ToGBK(wfvec2[i].first) << ":" << wfvec2[i].second << " ";
	}
	cout << endl;
	selectAimWords(wfvec, wset);
	selectAimWords(wfvec2, wset);
	cout << "wset :" << endl;
	for (const auto& e : wset)
	{
		cout << UTF8ToGBK(e) << " ";
	}
	cout << endl;
	vector<double> oneHot = GetOneHot(wset, wf);
	vector<double> oneHot2 = GetOneHot(wset, wf2);
	cout << "oneHot :" << endl;
	for (const auto& w : oneHot)
	{
		cout << w << " ";
	}
	cout << endl;
	cout << "oneHot2 :" << endl;
	for (const auto& w : oneHot2)
	{
		cout << w << " ";
	}
	cout << endl;
	cout << "cosine :" << consine(oneHot, oneHot2) << endl;
}
int main(int argc,char* argv[])
{
	if (argc != 4)
	{
		cout << "Usage:" << argv[0]  << "dict" << endl;
		return 1;
	}
	TextSimilarity ts(argv[1]);
	ts.textsimilarityofmain(argv[2], argv[3]);
	return 0;
}