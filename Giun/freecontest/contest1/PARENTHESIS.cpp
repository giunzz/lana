#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(obj1, obj2, obj3) for(ll obj1 = obj2; obj1 <= obj3; obj1++)
#define lpd(obj1, obj2, obj3) for(ll obj1 = obj2; obj1 >= obj3; obj1--)
#define lpdk(obj1, obj2, obj3, obj4) for(ll obj1 = obj2; obj3; obj4) 
#define pp(obj1, obj2) pair<obj1, obj2>
#define vec(obj1) vector<obj1>
#define vecite(obj1) vector<obj1>::iterator
#define fi first
#define se second
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "f";
// #define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

ll t;
string st;
stack<ll> m, q;
queue<ll> s;

int main(){
    opt;
    // file;
    cin >> t;
    cin.ignore();
    while(t--){
        bool c = 1;
        while(!m.empty()) m.pop();
        while(!q.empty()) q.pop();
        while(!s.empty()) s.pop();
        getline(cin, st);
        if(st.empty()) {cout << "YES\n"; continue;}
        lp(i, 0, st.length() - 1){
            if(st[i] == '(') m.push(i);
            if(st[i] == '*') s.push(i);
            if(st[i] == ')'){
                if(!m.empty()) m.pop();
                else{
                    if(!s.empty()) s.pop();
                    else {c = 0; break;}
                }
            }
        }
        while(!s.empty()){q.push(s.back()); s.pop();}
        while(!m.empty() && !q.empty() && m.top() < q.top()) {m.pop(); q.pop();}
        if(m.empty() && q.empty() && c) cout << "YES\n";
        else if(m.empty() && !q.empty()){
            ll dem = 0;
            while(!q.empty()) {++dem; q.pop();}
            if(!(dem % 2)) cout << "YES\n";
            else cout << "NO\n";
        }
        else cout << "NO\n";
    }
}
