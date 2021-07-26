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

template <typename T> inline void Read(T &x){
    x = 0; char c;
    while(!isdigit(c = getchar()));
    do
    {
        x = x * 10 + c - '0';
    } while (isdigit(c = getchar()));
}

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll mxn = 1e6 + 7;
ll n, cnt[5] = {0}, a[mxn];

int main(){
    giuncute();
    cin >> n;
    lp(i, 1, n) ++cnt[a[i] = read()];

    cnt[1] -= min(cnt[1], cnt[3]);

    cnt[2] *= 2;
    ll tmp = cnt[2] % 4;
    cnt[2] += min(tmp, cnt[1]);
    cnt[1] -= min(tmp, cnt[1]);

    cnt[2] = (cnt[2] + 3) / 4;
    cnt[1] = (cnt[1] + 3) / 4;
    
    cout << cnt[1] + cnt[2] + cnt[3] + cnt[4];
}