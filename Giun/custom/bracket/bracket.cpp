#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(obj1, obj2, obj3) for(ll obj1 = obj2; obj1 <= obj3; obj1++)
#define lpd(obj1, obj2, obj3) for(ll obj1 = obj2; obj1 >= obj3; obj1--)
#define pp(obj1, obj2) pair<obj1, obj2>
#define vec(obj1) vector<obj1>
#define vecite(obj1) vector<obj1>::iterator
#define fi first
#define se second
#define mp(obj1, obj2) map<obj1, obj2>
#define st(obj) system((obj).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "bracket";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

string s;
cll maxn = 1e6 + 7;
stack<ll> a;
ll cnt = 0, cntd = 0, cnts[maxn] = {0}, anssl = -1, ansvt = -1, ri = 0;

ii main(){
    opt;
    file;
    cin >> s;
    s.push_back('(');
    //cerr << s;
    lp(i, 0, s,length()-1){
        if(s[i] == '(') {
            a.push(1);
        }
        else{
            if(a.empty()){
                ri = 0;
            }
            else{
                a.pop();
                ++ri;
                ++cnts[ri* 2];
            }
        }
    }
    lp(i,1, 1e6 + 2){

    }
    cout << ansvt << " " << anssl;
}
