#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

void OF(const string f){
    freopen((f + ".inp").c_str(), "r", stdin);
    freopen((f + ".out").c_str(), "w", stdout);
}

cll maxn = 12;
ll n, a[maxn], res[maxn] = {0};
string s;
bool d[maxn]  = {0};

void sub1(){
    ll m = s.size();
    lp(i, 0, m - 1){
        lp(j, i + 1, m - 1){
            ll diff = j - i, cnt = 0;
            if(j + diff > m) break;
            lp(w, 0, diff - 1){
                if(s[i + w] != s[j + w]){
                    ++cnt;
                }
            }
            lp(i, cnt, 10) res[i] = max(res[i], diff);
        }
    }
    lp(i, 1, n){
        cout << res[a[i]] << "\n";
    }
}

cll MOD = 1e9 + 7;
ll hs[3007][3007] = {{0}}, p31[3007];

void sub2(){
    ll ans = 0;
    p31[0] = 1;
    lp(i, 1, 3001) p31[i] = (p31[i - 1] * 31) % MOD; 
    ll m = s.size();
    lp(i, 0, m - 1){
        ll ha = 0, t = 0;
        lp(j, i, m - 1){
            (ha += (s[j] - 'a' + 1) * p31[t++]) %= MOD;
            hs[i][j] = ha;
        }
    }
    lp(i, 0, m - 1){
        lp(j, i + 1, m - 1){
            ll ii = j - 1, jj = j + (j - i - 1);
            if(hs[i][ii] == hs[j][jj]) ans = max(ans, j - i);
        }
    }
    lp(i, 1, n) cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF("virus");
    cin >> n >> s;
    lp(i, 1, n){
        cin >> a[i];
        d[a[i]] = 1;
    }
    if(n <= 300) sub1();
    else sub2();
}