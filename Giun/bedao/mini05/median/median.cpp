#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for (ll a  =b; a <= c; a++)
#define lpd(a, b, c) for (ll a  =b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

void File(const string ff){
    freopen((ff + ".inp").c_str(), "r", stdin);
    freopen((ff + ".out").c_str(), "w", stdout);
}

ll n, x, cnt[3] = {0};

inline bool check(ll a, ll b, ll c){
    ll mid = (a + b + c + 1) / 2, l = a + 1, r = b + a;
    // if((a + b + c) % 2){
    //     return (a <= c and (a + b) > c) or (a >= c and (c + b) >= a);
    // }
    // else{
    //     return (a + b == c) or ();
    // }
    return l <= mid and mid <= r;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    File("median");
    cin >> n >> x;
    ll tmp;
    lp(i, 1, n){
        cin >> tmp;
        if(tmp < x) ++cnt[0];
        else if(tmp > x) ++cnt[2];
        else ++cnt[1];
    }
    // if(cnt[0] < cnt[2]){
    //     if(n%2){
    //         // cnt[0] += min(cnt[1] - 1, cnt[2] - cnt[0]);
    //         // cnt[1] = max(1LL, cnt[1] - (cnt[2] - cnt[0]));
    //         cout << max(0LL, cnt[2] - (cnt[0] + cnt[1] - 1));
    //     }
    //     else{

    //     }
    // }
    // bool ok = 0;
    // if(!cnt[1]) cnt[1] = 1, ok = 1;
    // cout << (max(0LL, cnt[0] + cnt[2] - cnt[1]) + ok);
    ll ans = 0;
    if(!cnt[1]) ++ans, cnt[1] = 1;
    // ll l = cnt[0] + 1, r = cnt[0] + cnt[1];
    // if(l > (cnt[0] + cnt[1] + cnt[2] + 1) / 2)   
    while(!check(cnt[0], cnt[1], cnt[2])){
        ++cnt[1], ++ans;
    }
    cout << ans;
}