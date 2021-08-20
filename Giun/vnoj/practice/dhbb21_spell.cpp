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

cll mxn = 303, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
ll n, m, tot, dp[mxn][mxn][mxn];
string s;
char a[mxn][mxn];
vec(pp(ll, ll)) pos[mxn];

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m >> tot >> s;
    s = '.' + s;
    lp(i, 1, n) lp(j, 1, m){
        cin >> a[i][j];
        pos[a[i][j]].push_back({i, j});
    }
    lp(i, 0, tot + 1) lp(j, 0, n + 1) lp(k, 0, m + 1) dp[i][j][k] = 1e17;
    for(pp(ll, ll) i : pos[s[1]]) dp[1][i.first][i.second] = 1;
    lp(i, 1, tot){
        queue<pp(ll, ll)> q;
        for(pp(ll, ll) j : pos[s[i]]) {
            lp(k, 0, 3) 
                dp[i][j.first][j.second] = min(dp[i][j.first][j.second], dp[i - 1][j.first + dx[k]][j.second + dy[k]] + 1);
            q.push(j);
        }
        while(q.size()){
            ll u = q.front().first, v = q.front().second;
            q.pop();
            lp(k, 0, 3)
                if(dp[i][u + dx[k]][v + dy[k]] > dp[i][u][v] + 1){
                    dp[i][u + dx[k]][v + dy[k]] = dp[i][u][v] + 1;
                    q.push({u + dx[k], v + dy[k]});
                }
        }
    }
    ll ans = 1e18;
    lp(i, 1, n) lp(j, 1, m) ans = min(ans, dp[tot][i][j]);
    cout << ans;
}

// #include <bits/stdc++.h>
// #define ll long long
// #define cll const ll
// #define lp(a, b, c) for(ll a = b; a <= c; ++a)
// #define lpd(a, b, c) for(ll a = b; a >= c; --a)
// #define vec(a) vector<a>
// #define pp(a, b) pair<a, b>
// #define EACHCASE lpd(cs, read(), 1)
// #define Fname "f"
// using namespace std;

// template <typename T> inline void Read(T &x){
//     x = 0; char c;
//     while(!isdigit(c = getchar()));
//     do
//     {
//         x = x * 10 + c - '0';
//     } while (isdigit(c = getchar()));
// }

// ll read(){
//     ll tmp;
//     cin >> tmp;
//     return tmp;
// }

// void giuncute(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
// }

// void OF(){
//     freopen(Fname".inp", "r", stdin);
//     freopen(Fname".out", "w", stdout);
// }

// cll mxn = 303, mxchar = 'Z' - 'A' + 1;
// ll n, m, k, a[mxn][mxn];
// vec(ll) dp[mxn], px[mxchar], _nxt_pos[mxchar];
// vec(pp(ll, ll)) posc[mxchar];
// string s;

// ll dis(pp(ll, ll) &u, pp(ll, ll) &v){return abs(u.first - v.first) + abs(u.second - v.second);}

// ll sol(ll id, ll pos){
//     if(~dp[id][pos]) return dp[id][pos];
//     ll &cur = dp[id][pos];
//     if(id == s.size() - 1) return cur = 0;
//     cur = 1e18;
//     ll c = s[id] - 'A', nc = s[id + 1] - 'A', nid = id + 1, npos, cur_pos = 0;
//     pp(ll, ll) coor = posc[c][pos];
//     coor.first = 0;
//     // dm cnp roi ko ac :<
//     while(cur_pos < px[nc].size()){
//         coor.first = px[nc][cur_pos];
//         cur_pos = lower_bound(posc[nc].begin() + cur_pos, posc[nc].begin() + _nxt_pos[nc][cur_pos] + 1, coor) - posc[nc].begin();
//         if(cur_pos != posc[nc].size()){
//             if(posc[nc][cur_pos] == posc[c][pos]){
//                 cur = min(cur, sol(nid, cur_pos) + 2);
//                 if(cur_pos + 1 != posc[nc].size()) cur = min(cur, sol(nid, cur_pos + 1) + dis(posc[c][pos], posc[nc][cur_pos + 1]));
//             }
//             else cur = min(cur, sol(nid, cur_pos) + dis(posc[c][pos], posc[nc][cur_pos]));
//         }
//         if(cur_pos != 0 && posc[c][pos] != posc[nc][cur_pos - 1]) cur = min(cur, sol(nid, cur_pos - 1) + dis(posc[c][pos], posc[nc][cur_pos - 1]));
//         if(cur_pos < _nxt_pos[nc].size()) cur_pos = _nxt_pos[nc][cur_pos] + 1;
//         // if(id == 0) cerr << px[nc][cur_pos] << ' ' << coor.first << '\n';
//     }
//     // lp(i, 0, posc[nc].size() - 1){
//     //     npos = i;
//     //     if(s[id] == s[id + 1] && i == pos){ 
//     //         cur = min(cur, sol(nid, npos) + dis(posc[c][pos], posc[nc][npos]) + 2);
//     //         continue;
//     //     }
//     //     cur = min(cur, sol(nid, npos) + dis(posc[c][pos], posc[nc][npos]));
//     // }
//     return cur;
// }

// int main(){
//     giuncute();
//     #ifndef ONLINE_JUDGE
//     OF();
//     #endif
//     cin >> n >> m >> k >> s;
//     lp(i, 1, n) lp(j, 1, m){
//         char c;
//         cin >> c;
//         a[i][j] = c - 'A';
//         posc[c - 'A'].push_back({i, j});
//         px[c - 'A'].push_back(i);
//     }
//     lp(i, 0, mxchar - 1){
//         // cerr << i << ' ' << px[i].size() << '\n';
//         _nxt_pos[i].resize(px[i].size());
//         if(_nxt_pos[i].size()) _nxt_pos[i].back() = _nxt_pos[i].size() - 1;
//         lpd(j, (ll)_nxt_pos[i].size() - 2, 0) 
//             if(px[i][j] != px[i][j + 1]) _nxt_pos[i][j] = j;
//             else _nxt_pos[i][j] = _nxt_pos[i][j + 1];
//     }
//     // for(auto i : px['D' - 'A']) cerr << i << ' ';
//     lp(i, 0, s.size() - 1)
//         dp[i].assign(posc[s[i] - 'A'].size(), -1);
//     ll ans = 1e18;
//     lp(i, 0, posc[s[0] - 'A'].size() - 1) ans = min(ans, sol(0, i));
//     // cerr << sol(0, 0);
//     cout << ans + 1;
//     // cerr << clock();
// }