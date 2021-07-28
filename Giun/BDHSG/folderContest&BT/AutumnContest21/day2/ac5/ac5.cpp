#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "ac5"

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}
#define EACHCASE lpd(__cs, read(), 1)

ll cnt[200] = {0};
string s, a;

ll dis(ll a, ll b){if(a > b) swap(a, b); return min(b - a, a - 'a' + 1 + 'z' - b);}

ll pro(){
    ll res = 0;
    lp(i, 0, a.size() / 2 - 1)
        res += dis(a[i * 2], a[i * 2 + 1]);
    return res;
}

ll makestr(){
    a.clear();
    lp(i, 'a', 'z') if(cnt[i]) a += i;
    if(a.empty()) return 0;
    ll tmp = pro();
    a.push_back(a[0]);
    a.erase(a.begin());
    return min(tmp, pro());
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
    EACHCASE{
        ll num = 0, ans = 1e18;
        memset(cnt, 0, sizeof cnt);
        cin >> s;
        for(char c : s) cnt[c] = !cnt[c];
        lp(i, 'a', 'z') num += cnt[i];
        if(num % 2){
            lp(i, 'a', 'z') if(cnt[i]){
                cnt[i] = 0;
                ans = min(ans, makestr());
                cnt[i] = 1;
            }
        } else{
            ans = min(ans, makestr());
        }
        cout << ans << '\n';
    }
}