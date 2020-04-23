#include <bits/stdc++.h> 

using namespace std;

int test; 
string s; 

bool check(string st) {
  for (int i = (int) st.size() - 1, j = (int) s.size() - 1; i >= 0; i--, j--) {
    if (st[i] != s[j]) {
      return false;
    }
  }
  return true; 
}

int main () {
  freopen("SC1.INP", "r", stdin);
  freopen("SC1.OUT", "w", stdout);
  cin >> test;
  for (int tt = 1; tt <= test; tt++) {
    bool found = false; 
    string res = "NONE"; 
    cin >> s; 
    for (int i = 1; i <= 9; i++) {
      string name, st;
      cin >> name >> st; 
      if (found == false && check(st) == true) {
        found = true;
        res = name;   
      }
    }
    if (res[(int) res.size() - 1] == ':') {
      res = res.substr(0, (int) res.size() - 1); 
    }                                    
    cout << res << endl; 
  }
  return 0; 
}