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

cll mxn = 57;
ll n, k, ans;
pp(ll, ll) a[mxn];
queue<pp(ll, ll)> can;

void sol(){
    cin >> n >> k;
    lp(i, 1, n) cin >> a[i].second >> a[i].first;
    sort(a + 1, a + 1 + n, greater<pp(ll, ll)>());
    while(can.size()) can.pop();
    ans = 0;
    lp(i, 1, n){
        ll col = a[i].second, val = a[i].first;
        if(can.empty() || can.front().second == col) can.push(a[i]);
        else{
            ans += val + can.front().first;
            can.pop();
            --k;
        }
        if(!k) break;
    }
    if(k) cout << "-1\n";
    else cout << ans << '\n';
}

int main(){
    giuncute();
    EACHCASE sol();
}