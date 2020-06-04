#include <bits/stdc++.h>

using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> a;
    a.push(3); a.push(2); a.push(100);
    cerr << a.top();
}
