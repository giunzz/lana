#include<bits/stdc++.h>

using namespace std;
#define brokenheart "TABLE"
#define pb	push_back
typedef long double ld;
typedef long long ll;

const int maxn = 305;
const int inf = 2e9;

int m , n , k , a[maxn][maxn];
vector<int> f[101][101][101];
int g[maxn][maxn] , g1[maxn][maxn];
int u , v , p , q;
void enter()
{
    cin >> m >> n >> k;
    for(int i = 1 ; i <= m ; ++i)
        for(int j = 1 ; j <= n ; ++j)cin >> a[i][j];
}

void sub3()
{
    while(k--)
    {
        int res = inf;
        cin >> u >> v >> p >> q;
        for(int i = u ; i <= p ; ++i)
            for(int j = v ; j <= q ; ++j)
                {
                    g[i][j] = -inf;
                    if(i == u && j == v)g[i][j] = a[i][j];
                    if(i > u)g[i][j] = max(g[i][j],g[i-1][j] + a[i][j]);
                    if(j > v)g[i][j] = max(g[i][j],g[i][j - 1] + a[i][j]);
                }
        for(int i = p ; i >= u ; --i)
            for(int j = q ; j >= v ; --j)
                {
                    g1[i][j] = -inf;
                    if(i == p && j == q)g1[i][j] = a[i][j];
                    if(i < p)g1[i][j] = max(g1[i][j],g1[i+1][j] + a[i][j]);
                    if(j < q)g1[i][j] = max(g1[i][j],g1[i][j + 1] + a[i][j]);
                }
        for(int i = u ; i <= p ; ++i)
            for(int j = v ; j <= q ; ++j)
        {
            if(i == u && j == v)continue;
            if(i == p && j == q)continue;
            int tmpres = -inf;
            if(i > u && j < q)tmpres = max(tmpres , g[i - 1][j + 1] + g1[i][j + 1]);
            if(i < p && j > v)tmpres = max(tmpres , g[i + 1][j - 1] + g1[i + 1][j]);
            res = min(res , tmpres);
        }
        cout << res << '\n';
    }
}

void sub12()
{
    for(int u = 1 ; u <= m ; ++u)
        for(int v = 1 ; v <= n ; ++v)
            for(int i = u ; i <= m ; ++i){
                f[u][v][i].resize(n - v + 1);
                for(int j = v ; j <= n ; ++j)
                {
                    int & res = f[u][v][i][j - v];
                    res = -inf;
                    if(i == u && j == v)
                        res = a[u][v];
                    if(i > u)res = max(res , f[u][v][i - 1][j - v] + a[i][j]);
                    if(j > v)res = max(res , f[u][v][i][j - 1 - v] + a[i][j]);
//                    cout << f[1][1][1][1] << endl;
                }
            }
//    cout << f[1][1][1][1];
    while(k--)
    {
        int res = inf;
        cin >> u >> v >> p >> q;
        for(int i = u ; i <= p ; ++i)
            for(int j = v ; j <= q ; ++j)
        {
            if(i == u && j == v)continue;
            if(i == p && j == q)continue;
            int tmpres = -inf;
//            tmpres = max(tmpres , f[u][v][i - 1][j]);
//            tmpres = max(tmpres , f[u][v][i][j - 1]);
            if(i > u && j < q)tmpres = max(tmpres , f[u][v][i - 1][j + 1 - v] + f[i][j + 1][p][q - j - 1]);
            if(i < p && j > v)tmpres = max(tmpres , f[u][v][i + 1][j - 1 - v] + f[i + 1][j][p][q - j]);
            res = min(res , tmpres);
        }
        cout << res << '\n';
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if(fopen(brokenheart".INP","r"))
        freopen(brokenheart".INP", "r",stdin) ,
        freopen(brokenheart".OUT", "w",stdout);
    enter();
    if(n <= 100)sub12();
    else sub3();
}
