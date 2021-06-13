#include "drill.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string question;
		string answer;
		cin >> question >> answer;
		drill(question, answer);
	}
	
	for (int i = 0; i < m; i++) {
		string question;
		cin >> question;
		string answer = query(question);
		cout << answer << '\n';
	}

	return 0;
}
