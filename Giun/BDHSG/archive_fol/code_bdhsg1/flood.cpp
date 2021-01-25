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
ll n, m, k, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, dp[maxn][maxn] = {{0}};// opt[maxn][maxn] =  {{0}};
pp(ll, ll) s, t;
vec(pp(ll, ll)) tg;

bool sol(ll time){
    vec(vec(ll)) opt(n + 2, vec(ll)(m + 2, LLONG_MAX));
    queue<pp(ll, ll)> q;
    q.push(s);
    opt[s.first][s.second] = 0;
    while(q.size()){
        ll x = q.front().first, y = q.front().second;
        q.pop();
        lp(i, 0, 3){
            ll nx = x + dx[i], ny = y + dy[i], value = opt[x][y] + (dp[nx][ny] <= time);
            if(!nx || !ny || nx > n || ny > m || value >= opt[nx][ny]) continue;
            opt[nx][ny] = value;
            q.push({nx, ny});
        }
    }
    return opt[t.first][t.second] <= k;
}

void loang(){
    ll time = 1;
    queue<pp(ll, ll)> q[2];
    for(pp(ll, ll) i : tg){
        dp[i.first][i.second] = time;
        q[0].push(i);
    }
    dp[s.first][s.second] = dp[t.first][t.second] = LLONG_MAX;
    while(q[0].size()){
        ++time;
        while(q[0].size()){
            ll x = q[0].front().first, y = q[0].front().second;
            q[0].pop();
            lp(i, 0, 3){
                ll nx = x + dx[i], ny = y + dy[i];
                if(!nx || !ny || nx > n || ny > m || dp[nx][ny]) continue;
                dp[nx][ny] = time;
                q[1].push({nx, ny});
            }
        }
        swap(q[1], q[0]);
    }
    if(k >= abs(s.first - t.first) + abs(s.second - t.second)){
        cout << -1;
        return;
    }
    ll l = 0, r = time - 1, ans = 0;
    while(l <= r){
        ll mid = (l + r) >> 1;
        if(sol(mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m >> k;
    lp(i, 1, n) lp(j, 1, m){
        char c;
        cin >> c;
        if(c == 'H') s = {i, j};
        else if(c == 'G') t = {i, j};
        else if(c == 'S') tg.push_back(make_pair(i, j));
    }
    loang();
}