#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 1e2 + 7, oo = 1e16;
ll n, a[maxn][maxn] = {{0}}, k, m, lg[maxn][maxn];
pp(ll, ll) st[maxn];
ll dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

#define x first
#define y second

inline bool ck(const pp(ll, ll) &tt){
    return a[tt.x][tt.y];
}

void bfs(pp(ll, ll) &r){
    lp(i, 0, n + 1)
        lp(j, 0, m + 1) lg[i][j] = oo;
    if(ck(r)) return;
    queue<pp(ll, ll)> q;
    q.push(r);
    lg[r.x][r.y] = 0;
    while(q.size()){
        pp(ll, ll) u = q.front();
        q.pop();
        lp(i, 0, 3){
            pp(ll, ll) v = {u.x + dx[i], u.y + dy[i]};
            if(ck(v) && lg[u.x][u.y] + 1 < lg[v.x][v.y]){
                lg[v.x][v.y] = lg[u.x][u.y] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    char c;
    cin >> n >> m >> k;
    lp(i, 1, n){
        lp(j, 1, m){
            cin >>c;
            if(c != '#') a[i][j] = 1;
            // cerr << c << ' ';
            // else a[i][j] = 1;
            if(c == 'F') st[k + 1] = {i, j};
            else if(c == 'S') st[0] = {i, j};
        }
        // cerr << endl;
    }
    lp(i, 1, k){
        cin >> st[i].x >> st[i].y;
    }
    ll ans = 0, tmp;
    pp(ll, ll) r;
    // bool ok = 1;
    lp(i, 0, 3){
        tmp = oo;
        r = {st[1].y + dx[i], st[1].y + dy[i]};
        bfs(r);
        tmp =  min(lg[st[0].x][st[0].y], tmp);
        ans += tmp;
    }
    lp(i, 1, k - 1){
        tmp = oo;
        lp(j, 0, 3){
            r = {st[i + 1].x + dx[j], st[i + 1].y + dy[j]};
            bfs(r);
            lp(q, 0, 3){
                tmp  = min(lg[st[i].x + dx[q]][st[i].y + dy[q]], tmp);
            }
        }
        ans += tmp;
    }
    bfs(st[k + 1]);
    tmp = oo;
    lp(q, 0, 3){
        tmp  = min(lg[st[k].x + dx[q]][st[k].y + dy[q]], tmp);
    }
    ans += tmp;
    if(ans >= oo) cout << -1;
    else cout << ans;
}