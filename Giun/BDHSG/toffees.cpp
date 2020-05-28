#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define lpdk(a, b, c, d) for(ll a = b; c; d) 
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define vecite(a) vector<a>::iterator
#define fi first
#define se second
using namespace std;
cll MOD = 1e9 + 7;
const string tenfile = "toffees";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

ll n;
string s;

struct rg{
    char c;
    ii cnt;
};

vec(rg) a;
vec(ii) ans;

int main(){
    opt;
    file;
    cin >> n >> s;
    a.push_back({s[0], 1});
    lp(i, 1, s.size() - 1){
        if(s[i] == a.back().c) ++a.back().cnt;
        else a.push_back({s[i], 1});
    }
    ans.resize(a.size() + 1);
    ans[0] = 1;
    lp(i, 0, a.size() - 1){
        if(a[i].c == '=') ans[i + 1] = a[i];
        else if (a[i].c == 'R') ans[i + 1] = ans[i] + a[i].cnt;
        else {
            if(ans[i] - a[i].cnt >= 1) ans[i + 1] = ans[i] - a[i].cnt;
            else{
                ans[i + 1] = 1;
                ii j = i;
                while(j >= 0 && a[j].c != 'R'){
                    if(a[j].c == '=') ans[j] = ans[j + 1] 
                }
            }
        } 
    }
}
