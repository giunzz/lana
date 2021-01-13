#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "f"
using namespace std;

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

ll sign(ll u){
    if(u < 0) return -1;
    else if(u) return 1;
    return 0;
}

void sol(){
    ll n = read(), cnt = 0;
    vec(ll) a(n + 1);
    lp(i, 1, n) cin >> a[i];
    if(n <= 3){
        cout << "0\n";
        return;
    }
    lp(i, 2, n - 1) if((a[i - 1] > a[i] && a[i] < a[i + 1]) || (a[i - 1] < a[i] && a[i] > a[i + 1])) ++cnt;
    ll ans = cnt;
    lp(i, 3, n - 2){
        ll tmp = 0;
        lp(j, -1, 1) if((a[i + j] > a[i + j - 1] && a[i + j] > a[i + j + 1]) || (a[i + j] < a[i + j - 1] && a[i + j] < a[i + j + 1])) ++ tmp;
        if(a[i - 2] > a[i - 1]){
            if(a[i + 1] <= a[i + 2]) ans = min(cnt - tmp, ans);
            else{
                if(a[i - 1] >= a[i + 1]) ans = min(cnt - tmp, ans);
                else ans = min(cnt - tmp + 1, ans); 
            }
        }
        else if(a[i - 2] == a[i - 1]) ans = min(cnt - tmp, ans);
        else{
            if(a[i + 1] >= a[i + 2]) ans = min(cnt - tmp, ans);
            else {
                if(a[i - 1] <= a[i + 1]) ans = min(cnt - tmp, ans);
                else ans = min(cnt - tmp + 1, ans);
            }
        }
    }
    if((a[2] > a[1] && a[2] > a[3]) || (a[2] < a[1] && a[2] < a[3]) ||
        (a[n - 1] < a[n - 2] && a[n - 1] < a[n]) || (a[n - 1] > a[n - 2] && a[n - 1] > a[n])) ans = min(cnt - 1, ans);
    ll tmp = 0;
    lp(i, 0, 1) if((a[2 + i] < a[2 + i - 1] && a[2 + i] < a[2 + i + 1]) || (a[2 + i] > a[2 + i - 1] && a[2 + i] > a[2 + i + 1])) ++ tmp;
    ans = min(cnt - tmp, ans);
    tmp = 0;
    lp(i, -1, 0) if((a[n - 1 + i] < a[n - 1 + i - 1] && a[n - 1 + i] < a[n - 1 + i + 1]) || (a[n - 1 + i] > a[n - 1 + i - 1] && a[n - 1 + i] > a[n - 1 + i + 1])) ++ tmp;
    ans = min(cnt - tmp, ans);
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    EACHCASE sol();
}