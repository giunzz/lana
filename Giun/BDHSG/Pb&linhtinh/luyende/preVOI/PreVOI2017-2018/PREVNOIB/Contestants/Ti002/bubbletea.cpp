#include <bits/stdc++.h>
#define forr(i, a, b) for(long i= a; i<= b; i++)
#define pb push_back
#define ft first
#define se second
#define mn 50001
using namespace std;
typedef pair< long, long long> ii;
long n, k, p[mn][20], L[mn], R[mn], h[mn], sel[mn];
long long f[mn], dis[1001][1001];
long long res= 1e18;
bool av[mn];
vector< ii> a[mn];
vector< long> need;
void dfs(long u)
{
    for(int i= 0; i< a[u].size(); i++)
    {
        long v= a[u][i].ft;
        if(p[u][0]!= v){
            p[v][0]= u;
            h[v]= h[u]+ 1;
            f[v]= f[u]+ a[u][i].se;
            dfs(v);
        }
    }
}
void rmq()
{
    forr(k, 1, 19)
    forr(i, 1, n)
    p[i][k]= p[p[i][k- 1]][k- 1];
}
long lca(long u, long v)
{
    if(h[u]< h[v]) swap(u, v);
    long del= h[u]- h[v];
    forr(i, 0, 19) if(((del>> i)& 1)== 1) u= p[u][i];
    if(u== v) return v;
    for(int k= 19; k>= 0; k--)
    {
        if(p[u][k]!= p[v][k]){
            u= p[u][k];
            v= p[v][k];
        }
    }
    return p[u][0];
}
void inkq()
{
    long long ans= 0;
    forr(i, 1, k/ 2)
    ans= max(ans, dis[L[i]][R[sel[i]]]);
    res= min(res, ans);
}
void xuly(int sl)
{
    if(sl== k/ 2+ 1){
        inkq();
        return;
    }
    forr(i, 1, k/ 2)
    {
        if(!av[i]){
            sel[sl]= i;
            av[i]= 1;
            xuly(sl+ 1);
            av[i]= 0;
        }
    }

}
void lm(long x)
{
    int sl= 0, cnt= 0, _cnt= 0;
    forr(i, 0, k- 1)
    {
        if(((x>> i)& 1)== 1) sl++;
    }
    if(sl!= (k/ 2)) return;
    forr(i, 0, k- 1)
    {
        if(((x>> i)& 1)== 1) L[++cnt]= i;
        else R[++_cnt]= i;
    }
    xuly(1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("bubbletea.inp", "r", stdin);
    freopen("bubbletea.out", "w", stdout);
    cin>> n>> k;
    forr(i, 1, k){
        long u;
        cin>> u;
        need.pb(u);
    }
    forr(i, 1, n- 1)
    {
        long u, v, w;
        cin>> u>> v>> w;
        a[u].pb(ii(v, w));
        a[v].pb(ii(u, w));
    }
    h[1]= 1;
    dfs(1);
    rmq();
    forr(i, 0, k- 2)
    forr(j, i+ 1, k- 1)
    {
        long dad= lca(need[i], need[j]);
        dis[i][j]= dis[j][i]= f[need[i]]+ f[need[j]]- 2* f[dad];
    }
    forr(i, 1, (1<< k)- 1){
        lm(i);
    }
    cout<< res;
    return 0;
}
