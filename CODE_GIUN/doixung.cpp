#include <bits/stdc++.h>

using namespace std;
deque<string> d;
string s, s1, s2;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("doixung.inp", "r", stdin);
    freopen("doixung.out", "w", stdout);
    while(!cin.eof()){
        cin >> s;
        d.push_back(s);
    }
    while(d.size()!= 1 && s1 == s2){
        s1 = d.pop_front();
        s2 = d.pop_back();
        cerr << s1 << " " << s2 << endl;
        //d.pop_back();
        //d.pop_front();
    }
    if (d.empty() && s1 == s2) cout << "YES";
    else cout << "NO";
}
