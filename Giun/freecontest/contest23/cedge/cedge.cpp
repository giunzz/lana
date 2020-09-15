#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for (ll a  =b; a <= c; a++)
#define lpd(a, b, c) for (ll a  =b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

void File(const string ff){
    freopen((ff + ".inp").c_str(), "r", stdin);
    freopen((ff + ".out").c_str(), "w", stdout);
}

cll maxn = 1e5 + 7;
ll n, ans[maxn] = {0}, cnt = -1;
vec(ll) g[maxn];
map<pp(ll, ll), ll> id;
bool d[maxn] = {0};

void init(){
    ll u,v;
    lp(i, 1, n - 1){
        cin >> u >> v;
        id[{u, v}] = i;
        id[{v, u}] = i;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void bfs(){
    queue<ll> q;
    q.push(1);
    ll u, c, color, tmp = 1;
    while(q.size()){
        color = 0, tmp = 1;
        u = q.front();
        d[u] = 1;
        q.pop();
        for(ll v : g[u]){
            if(ans[id[{u, v}]]) {color = ans[id[{u, v}]]; break;}
        }
        for(ll v : g[u]){
            if(!d[v]) {
                d[v] = 1;
                if(tmp == color) ++tmp;
                cnt = max(tmp, cnt);
                ans[id[{u, v}]] = tmp++;
                q.push(v);
            } 
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // File("cedge");
    cin >> n;
    init();
    bfs();
    cout << cnt << '\n';
    lp(i, 1, n - 1){
        cout << ans[i] << '\n';
    }
}