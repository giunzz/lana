#include "drill.h"
#include <string>
#include <map>

using namespace std;
map<string, string> mp;

void drill(string question, string answer) {
	mp[question] = answer;
}

string query(string question) {
	return mp[question];
}
