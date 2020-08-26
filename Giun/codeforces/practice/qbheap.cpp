#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int> a;
    int x;
    char stt;
    while(cin >> stt){
        if(stt == '+' && cin >> x && a.size() < 15000) a.push(x);
        else if(stt == '-' && a.size()) {
            int tmp = a.top();
            while(a.size() && tmp == a.top()) {a.pop();}
        }
    }
    vector<int> b;
    while(a.size()){
        b.push_back(a.top());
        int tmp = a.top();
        while(a.size() && tmp == a.top()) a.pop();
    }
    cout << b.size() << endl;
    for(auto i : b) {
        cout << i << endl;
    }
}