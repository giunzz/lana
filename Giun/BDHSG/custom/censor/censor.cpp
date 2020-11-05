#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define vecite(a) vector<a>::iterator
#define fi first
#define se second
#define mp(a, b) map<a, b>
#define st(a) system((a).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "censor";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

string s, t;
vector<char> st;

int main(){
    opt;
    file;
    cin >> s >> t;
    //stack
    string tmp;
    lp(i, 0, t.size() - 2){
        tmp.push_back(s[i]);
    }
    reverse(t.begin(), t.end());
    reverse(tmp.begin(), tmp.end());
    lp(i, t.size() - 1, s.size() - 1){
        tmp = s[i] + tmp;
        if(tmp.size() < t.size()) continue;
        if(tmp == t){
            tmp.clear();
            while(st.size() && tmp.size() != t.size() - 1) {tmp.push_back(st.back()); st.pop_back();}
            continue;
        }
        st.push_back(tmp.back());
        tmp.pop_back();
    }
    while(st.size()) tmp += st.back(), st.pop_back();
    reverse(tmp.begin(), tmp.end());
    cout << tmp;
}
