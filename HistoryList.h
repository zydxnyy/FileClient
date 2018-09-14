#pragma once
#include <vector>
#include <iostream>
using namespace std;
#pragma execution_character_set("utf-8")

class HistoryList
{
public:
	HistoryList();
	~HistoryList();

	void push(const string&);
	string pop();

	string previous();
	string next();

	bool hasNext();
	bool hasPrevious();

	void clearHistory();
private:
	int pos, end;
	vector<string> vec;
};

