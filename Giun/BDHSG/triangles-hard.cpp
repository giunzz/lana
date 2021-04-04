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

cll mxn = 2e3 + 7;
ll n, m;
vec(ll) g[mxn];
bitset<mxn> bit[mxn];
vec(pp(ll, ll)) e;

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m;
    lp(i, 1, m){
        ll u, v;
        cin >> u >> v;
        e.push_back({u, v});
        bit[u][v] = 1;
        bit[v][u] = 1;
    }
    ll ans = 0;
    for(pp(ll, ll) i : e){
        ll u = i.first, v = i.second;
        bitset<mxn> same = bit[u] & bit[v];
        ans += same.count();
    }
    cout << ans / 3;
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

// cll mxn = 2e3 + 7;
// ll n, m, tin[mxn] = {0}, tot = 0, ans = 0, p[mxn] = {0}, tin1[mxn] = {0}, tot1 = 0;
// vec(ll) g[mxn];
// unordered_map<ll, unordered_map<ll, ll>> d;

// int main(){
//     giuncute();
//     #ifndef ONLINE_JUDGE
//     OF();
//     #endif
//     cin >> n >> m;
//     lp(i, 1, m){
//         ll u, v;
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }
//     queue<ll> q[2], tmp;
//     lp(i, 1, n){
//         if(!tin[i]){
//             while(tmp.size()) tmp.pop();
//             q[0].push(i);
//             tin[i] = ++tot;
//             ++tot1;
//             while(q[0].size()){
//                 ++tot;
//                 while(q[0].size()){
//                     ll u = q[0].front();
//                     q[0].pop();
//                     ll cnt = 0;
//                     for(ll v : g[u]){
//                         if(tin[v]){
//                             if(tin[v] == tin[u] && !d[u][v] && p[v] == p[u]) ++ans, d[u][v] = d[v][u] = 1;
//                         }
//                         else tin[v] = tot, q[1].push(v), p[v] = u, ++cnt;
//                     }
//                     if(!cnt) tmp.push(u), tin1[u] = tot1;
//                 }
//                 swap(q[0], q[1]);
//             }
//             q[0] = tmp;
//             while(q[0].size()){
//                 ++tot1;
//                 while(q[0].size()){
//                     ll u = q[0].front();
//                     q[0].pop();
//                     ll cnt = 0;
//                     for(ll v : g[u]){
//                         if(tin1[v]){
//                             if(tin1[v] == tin1[u] && !d[u][v] && p[v] == p[u]) ++ans, d[u][v] = d[v][u] = 1;
//                         }
//                         else tin1[v] = tot1, q[1].push(v), p[v] = u;
//                     }
//                 }
//                 swap(q[0], q[1]);
//             }
//         }
//     }
//     cout << ans;
// }