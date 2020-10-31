    /*Design by Dinh Viet Anh(JOKER)*/
//___________________________________$$$$$$$$$
//___________________________________$$$___$
//___________________________$$$____$$$$
//_________________________$$$$$$$__$$$$$$$$$$$
//_______________________$$$$$$$$$___$$$$$$$$$$$
//_______________________$$$___$______$$$$$$$$$$
//________________$$$$__$$$$_________________$$$
//_____________$__$$$$__$$$$$$$$$$$_____$____$$$
//__________$$$___$$$$___$$$$$$$$$$$__$$$$__$$$$
//_________$$$$___$$$$$___$$$$$$$$$$__$$$$$$$$$
//____$____$$$_____$$$$__________$$$___$$$$$$$
//__$$$$__$$$$_____$$$$_____$____$$$_____$
//__$$$$__$$$_______$$$$__$$$$$$$$$$
//___$$$$$$$$$______$$$$__$$$$$$$$$
//___$$$$$$$$$$_____$$$$___$$$$$$
//___$$$$$$$$$$$_____$$$
//____$$$$$$$$$$$____$$$$
//____$$$$$__$$$$$___$$$
//____$$$$$___$$$$$$
//____$$$$$____$$$
//_____$$$$
//_____$$$$
//_____$$$$
#include <bits/stdc++.h>
#define maxn 5005
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define pii pair<int, int>
#define fort(i, a, b) for(int i = (a); i <= (b); i++)
#define ford(i, a, b) for(int i = (a); i >= (b); i--)
#define Task "tree"
#define stop1 {cout << "-1\n"; return;}
#define stop2 {cout << "NO\n"; return;}
#define stop3 {cout << "YES\n"; return;}
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long

using namespace std;

int n, a[maxn], in[maxn];
ll f[maxn][maxn];
vector<int> ke[maxn];

void dfs(int u, int par)
{
    int id1 = -1, id2 = -1;
    fort(i, 0, int(ke[u].size())-1)
    {
        int v = ke[u][i];
        if(v == par) continue;
        if(id1 < 0) id1 = i;
        else id2 = i;
        dfs(v, u);
        in[u] += in[v];
    }
    if(id1 < 0)
    {
        f[u][0] = a[u];
        f[u][1] = abs(a[u] - 1);
        in[u] ++ ;
        return;
    }
    if(id2 < 0)
    {
        fort(i, 0, in[ke[u][id1]])
            f[u][i] = f[ke[u][id1]][i] + abs(a[u] - i);
    }
    else
    {
        int ch = ke[u][id1];
        int ck = ke[u][id2];
        fort(i, 0, in[ch])
            fort(j, 0, in[ck])
                f[u][i+j] = min(f[u][i+j], abs(a[u] - i - j) + f[ch][i] + f[ck][j]);
    }
}

void setup()
{
    cin >> n;
    fort(i, 1, n) cin >> a[i];
    fort(i, 1, n-1)
    {
        int u, v;
        cin >> u >> v;
        ke[u].pb(v);
        ke[v].pb(u);
    }
}

void work()
{
    memset(f, 60, sizeof(f));
    dfs(1, 0);
    ll ans = 50000ll*50000;
    fort(i, 0, in[1])
        ans = min(ans, f[1][i]);
    cout << ans;
}

int main()
{
    fast
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    setup();
    work();
    return 0;
}
