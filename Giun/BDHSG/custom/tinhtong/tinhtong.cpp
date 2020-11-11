#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "tinhtong"
// #define Fname "aliceadd"
using namespace std;

ofstream co(Fname".out");
ifstream ci(Fname".inp");

vec(ll) a, b, ans;

int main(){
    ll cs;
    ci >> cs;
    string t;
    while(cs--){
        a.clear(); b.clear(); ans.clear();
        ci >> t;
        while(t.size()) a.push_back(t.back() - '0'), t.pop_back();
        a.push_back(0);
        ci >> t;
        while(t.size()) b.push_back(t.back() - '0'), t.pop_back();
        b.push_back(0);
        while(a.size() < b.size()) a.push_back(0);
        while(b.size() < a.size()) b.push_back(0);
        ans.resize(a.size());
        ll m = 0;
        lp(i, 0, a.size() - 1){
            ll tmp = a[i] + b[i] + m;
            m = tmp / 10;
            ans[i] = tmp % 10;
        }
        while(ans.size() && ans.back() == 0) ans.pop_back();
        if(ans.empty()) co << 0;
        else{
            lpd(i, ans.size() - 1, 0) co << ans[i];
        }
        co << '\n';
    }
}