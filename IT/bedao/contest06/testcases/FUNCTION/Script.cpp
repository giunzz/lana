#include<bits/stdc++.h>

using namespace std;

const int from = 1;
const int to = 20;
const string TASKNAME = "function";

string itos(int id) {
  return string(1, char(id / 10 + '0')) + string(1, char(id % 10 + '0'));
}

void run(string s) {
  system(s.c_str());
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  freopen("script.txt", "r", stdin);

  run("g++ -std=c++11 gen.cpp -o gen");
  run("g++ -std=c++11 sol.cpp -o sol");

  for(int i = from; i <= to; ++i) {
    /// normalized
    string cur; while(cur.empty() ) getline(cin, cur);
    while(true) {
      if(cur.back() != '>') cur.erase(cur.size() - 1);
      else {
        cur.erase(cur.size() - 1);
        break;
      }
    }
    while(cur.back() == ' ') cur.erase(cur.size() - 1);
    cur += " > " + TASKNAME + ".inp";
    run(cur);
    run("sol < " + TASKNAME + ".inp > " + TASKNAME + ".out");
    run("md Test" + itos(i));
    run("move " + TASKNAME + ".inp Test" + itos(i));
    run("move " + TASKNAME + ".out Test" + itos(i));
  }

  return 0;
}
