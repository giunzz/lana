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

cll mxn = 1e3 + 3;
ll n, m, a[mxn][mxn], color[mxn];
map<ll, ll> num[2];
bool added[mxn][mxn][2] = {{{0}}}; 
vec(pp(ll, ll)) g[mxn];

bool dfs(ll u, ll col){
    bool ok = 1;
    for(pp(ll, ll) i : g[u]){
        ll v = i.first;
        bool need = i.second, ncol;
        if(color[v] == -1){
            if(need) ncol = !col;
            else ncol = col;
            color[v] = ncol;
            if(!dfs(v, ncol)) ok = 0;
        } else{
            if(need){
                if(color[v] == color[u]) ok = 0;
            } else{
                if(color[v] != color[u]) ok = 0;
            }
        } 
    }
    return ok;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m;
    lp(i, 1, n) lp(j, 1, m) cin >> a[i][j];
    if(m & 1){
        vec(ll) num;
        lp(i, 1, n) num.push_back(a[i][m / 2 + 1]);
        sort(num.begin(), num.end());
        lp(i, 1, num.size() - 1){
            if(num[i] == num[i - 1]){
                cout << "No\n";
                return 0;
            }
        }
    }
    memset(color, -1, sizeof color);
    lp(j, 1, m / 2){
        num[0].clear(); num[1].clear();
        ll fj = m - j + 1;
        lp(i, 1, n){
            if(a[i][j] == a[i][fj]){
                if(num[0][a[i][j]] || num[1][a[i][fj]]){cout << "No\n"; return 0;}
                num[0][a[i][j]] = num[1][a[i][fj]] = -1;
                continue;
            }

            if(num[1][a[i][j]] == -1 || num[0][a[i][j]] == -1){cout << "No\n"; return 0;}
            assert(!(num[1][a[i][j]] > 0 && num[0][a[i][j]] > 0));
            if(num[0][a[i][j]]){
                g[num[0][a[i][j]]].push_back({i, 1});
                g[i].push_back({num[0][a[i][j]], 1});
                num[0][a[i][j]] = num[1][a[i][j]] = -1;
            } else if(num[1][a[i][j]]){
                g[num[1][a[i][j]]].push_back({i, 0});
                g[i].push_back({num[1][a[i][j]], 0});
                num[0][a[i][j]] = num[1][a[i][j]] = -1;
            } else num[0][a[i][j]] = i;

            if(num[1][a[i][fj]] == -1 || num[0][a[i][fj]] == -1){cout << "No\n"; return 0;}
            assert(!(num[1][a[i][j]] > 0 && num[0][a[i][j]] > 0));
            if(num[0][a[i][fj]]){
                g[num[0][a[i][fj]]].push_back({i, 0});
                g[i].push_back({num[0][a[i][fj]], 0});
                num[0][a[i][fj]] = num[1][a[i][fj]] = -1;
            } else if(num[1][a[i][fj]]){
                g[num[1][a[i][fj]]].push_back({i, 1});
                g[i].push_back({num[1][a[i][fj]], 1});
                num[0][a[i][fj]] = num[1][a[i][fj]] = -1;
            } else num[1][a[i][fj]] = i;
        }
    }

    // color[1] = 1;
    bool ans = 1;
    lp(i, 1, n) if(color[i] == -1){
        color[i] = 1;
        if(!dfs(i, 1)) ans = 0;
    }
    if(ans){
        cout << "Yes\n" << count(color + 1, color + 1 + n, 1) << '\n';
        lp(i, 1, n) if(color[i] == 1) cout << i << ' ';
    } else{
        cout << "No\n";
    }
    // lp(i, 1, n) cerr << i << ' ' << color[i] << '\n';
    // lp(i, 1, n){
    //     for(auto j : g[i]) if(i < j.first) cerr << i << ' ' << j.first << ' ' << j.second << '\n';
    // }
    
}