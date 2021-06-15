#include "drill.h"
#include <string>
#include<bits/stdc++.h>
using namespace std;
map <string , string > d;
void drill(std::string question, std::string answer) 
{
	d[question] = answer;
}

std::string query(std::string question) {
	
	std::string  ans = d[question];
	return ans;
}
