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

cll maxn = 1e3 + 7;
ll m, n, a[maxn][maxn], b[maxn][maxn] = {0}, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, cnt[maxn*maxn] = {0};

void fillNum(){
    ll tot = 0;
    queue<pp(ll, ll)> q;
    lp(i, 1, m) lp(j, 1, n){
        if(!(a[i][j] || b[i][j])){
            q.push({i, j});
            ++tot;
            b[i][j] = tot, cnt[tot] = 1;
            while(q.size()){
                ll u = q.front().first, v = q.front().second;
                q.pop();
                lp(k, 0, 3){
                    ll nu = u + dx[k], nv = v + dy[k];
                    if(a[nu][nv] || b[nu][nv]) continue;
                    b[nu][nv] = tot, ++cnt[tot];
                    q.push({nu, nv});
                }
            }
        }
    }
    ll ans = 0;
    lp(i, 2, m - 1) lp(j, 2, n - 1){
        if(a[i][j]){
            set<ll> s;
            lp(k, 0, 3){
                ll nu = i + dx[k], nv = j + dy[k];
                if(b[nu][nv]) s.insert(b[nu][nv]);
            }
            ll c = 1;
            for(auto q : s){
                c += cnt[q];
            }
            ans = max(ans, c);
        }
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> m >> n;
    lp(i, 0, 1e3) a[i][0] = a[0][i] = 1;
    lp(i, 1, m) lp(j, 1, n) {char c; cin >> c; a[i][j] = c - '0';}
    fillNum();
}