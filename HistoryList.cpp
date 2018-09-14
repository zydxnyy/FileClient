#include "HistoryList.h"

HistoryList::HistoryList()
{
	pos = end = -1;
}

HistoryList::~HistoryList()
{
}

void HistoryList::push(const string& var) {
	if (pos < end) {
		while (end != pos) {
			vec.pop_back();
			--end;
		}
		vec.push_back(var);
		++pos; ++end;
	}
	else {
		vec.push_back(var);
		++pos; ++end;
	}
}

string HistoryList::pop() {
	if (vec.size() <= 0) return "";
	if (pos == end) {
		--pos;
		--end;
	}
	else {
		--end;
	}
	string rtn = vec.back();
	vec.pop_back();
	return rtn;
}

string HistoryList::previous() {
	if (pos == 0) return "";
	return vec[--pos];
}

string HistoryList::next() {
	if (pos >= end) return "";
	return vec[++pos];
}

bool HistoryList::hasNext()
{
	return pos < end;
}

bool HistoryList::hasPrevious()
{
	return pos > 0;
}

void HistoryList::clearHistory()
{
	this->vec.clear();
	pos = end = -1;
}
