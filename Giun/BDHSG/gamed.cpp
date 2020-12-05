#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
// #define Fname "gamed"
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 1e3 + 7;
ll n, m, p, s[10], a[maxn][maxn] = {{0}}, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, res[10] = {0};
queue<pp(ll, ll)> q;
pp(ll, ll) t[10];

void bfs(){
    while(q.size()){
        ll rx = q.front().first, ry = q.front().second, stat = a[rx][ry];
        q.pop();
        queue<pp(ll, ll)> l[2];
        ll stt = 0;
        l[stt].push({rx, ry});
        lp(i, 1, s[stat]){
            ll nstt = (stt + 1) % 2, x, y;
            if(l[stt].empty()) break;
            while(l[stt].size()){
                x = l[stt].front().first, y = l[stt].front().second;
                l[stt].pop();
                lp(i, 0, 3) if(a[x + dx[i]][y + dy[i]] == -1)
                    a[x + dx[i]][y + dy[i]] = stat, l[nstt].push({x + dx[i], y + dy[i]});
            }
            stt = nstt;
        }
        while(l[stt].size()) {q.push(l[stt].front()); l[stt].pop();}
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n >> m >> p;
    lp(i, 1, p) cin >> s[i];
    lp(i, 1, n) lp(j, 1, m){
        char c;
        cin >> c;
        if(c == '.') a[i][j] = -1;
        else if(c == '#') a[i][j] = 0;
        else{
            a[i][j] = c - '0';
            t[c - '0'] = {i, j};
        }
    }
    // lp(i, 1, n){
    //     lp(j, 1, m) cerr << a[i][j] << ' ';
    //     cerr << '\n';
    // }
    lp(i, 1, p) q.push(t[i]);
    bfs();
    // lp(i, 1, n){
    //     lp(j, 1, m) cerr << a[i][j] << ' ';
    //     cerr << '\n';
    // }
    lp(i, 1, n) lp(j, 1, m) if(a[i][j] > 0) ++res[a[i][j]];
    lp(i, 1, p) cout << res[i] << ' ';
}