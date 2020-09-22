#include <bits/stdc++.h>

using namespace std;

int main(){
    set<int> a;
    a.insert(1);
    a.insert(2);
    a.insert(3);
    vector<int> b(a.begin(), a.end());
    for(int v : b) cerr << v << ' ';
}