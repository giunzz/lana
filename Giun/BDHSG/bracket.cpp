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
ll anssl = -1, ansvt = -1;

void fML(string str){
    ll n = str.length();
    stack<ll> stk;
    stk.push(-1);
    ll res = 0;
    for (ll i=0; i<n; i++){
        if (str[i] == '(')
          stk.push(i);
        else {
            stk.pop();
            if (!stk.empty()){
                if(res == i-stk.top()) ++anssl;
                else if(res < i - stk.top()) res = i - stk.top(), ansvt = res, anssl = 1;
                //res = max(res, i - stk.top());
            }
            else stk.push(i);
        }
    }
}

ii main(){
    opt;
    file;
    cin >> s;
    fML(s);
    cout << ansvt << " " << anssl;
}
