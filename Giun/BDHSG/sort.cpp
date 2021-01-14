#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "sort"
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

cll maxn = 1e4 + 7;
ll n, a[3][maxn], cnt[3][maxn] = {{0}}, pos[maxn];
bool del[maxn] = {0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(j, 0, 2) lp(i, 1, n){
        cin >> a[j][i];
        ++cnt[j][a[j][i]];
    }
    queue<ll> q;
    lp(i, 1, n){
        pos[a[0][i]] = i;
        lp(j, 1, 2) if(!cnt[j][a[0][i]]) q.push(i);
    }
    while(q.size()){
        ll col = q.front();
        q.pop();
        if(del[col]) continue;
        del[col] = 1;
        lp(i, 0, 2) --cnt[i][a[i][col]];
        lp(i, 1, 2) if(!(cnt[i][a[i][col]] || del[pos[a[i][col]]])) q.push(pos[a[i][col]]);
    }
    ll ans = 0;
    lp(i, 1, n) ans += del[i];
    cout << ans;
}