#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "seq3n"
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

cll mxn = 3e5 + 4;
ll n, dpl[mxn], dpr[mxn], a[mxn], sum = 0;

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, 3 * n) cin >> a[i];
    priority_queue<ll, vec(ll), greater<ll>> q;
    lp(i, 1, n){
        q.push(a[i]);
        sum += a[i];
    }
    dpl[n] = sum;
    lp(i, n + 1, 2 * n){
        if(q.top() < a[i]){
            sum = sum - q.top() + a[i];
            q.pop();
            q.push(a[i]);
        }
        dpl[i] = sum;
    }
    priority_queue<ll> qq;
    sum = 0;
    lpd(i, 3 * n, 2 * n + 1){
        qq.push(a[i]);
        sum += a[i];
    }
    dpr[2 * n + 1] = sum;
    lpd(i, 2 * n, n + 1){
        if(qq.top() > a[i]){
            sum = sum - qq.top() + a[i];
            qq.pop();
            qq.push(a[i]);
        }
        dpr[i] = sum;
    }
    ll ans = -1e18;
    lp(i, n, 2 * n) ans = max(ans, dpl[i] - dpr[i + 1]);
    cout << ans;
}