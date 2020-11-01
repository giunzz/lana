#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define test "tree"
using namespace std;

void home(){
    #ifndef ONLINE_JUDGE
    freopen(test".inp","r",stdin);
    freopen(test".out","w",stdout);
    #endif // ONLINE_JUDGE
}

void in();
void sol();

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    home();
    in();
    sol();
}

const int N = 5e3 + 100;
int f[N][N];
int n;
int a[N];
int sl[N];
vector<int> w[N];

void in(){
    cin >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j <= n; ++j)
            f[i][j] = 1e9;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i < n; ++i){
        int x,y;
        cin >> x >> y;
        w[x].pb(y);
    }
}

void dfs(int u){
    if(w[u].empty()){
        sl[u] = 1;
        f[u][0] = a[u];
        f[u][1] = abs(a[u] - 1);
        return;
    }
    for(int i = 0; i < w[u].size(); ++i)
        dfs(w[u][i]),sl[u] += sl[w[u][i]];
    if(w[u].size() == 1){
        int v = w[u][0];
        for(int i = 0; i <= sl[u]; ++ i)
            f[u][i] = f[v][i] + abs(a[u] - i);
        return;
    }
    int x = w[u][0];
    int y = w[u][1];
    for(int i = 0; i <= sl[x]; ++i)
    for(int j = 0; j <= sl[y]; ++j)
        f[u][i+j] = min(f[u][i+j],f[x][i] + f[y][j] + abs(a[u] - i - j));
}

void sol(){
    dfs(1);
    int res = 1e9;
    for(int i = 0; i <= n; ++i)
        res = min(res,f[1][i]);
    cout << res;
}
