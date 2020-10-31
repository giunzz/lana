#include <bits/stdc++.h>
#define forr(i, a, b) for(long i= a; i<= b; i++)
#define mn 5001
using namespace std;
int n, a[mn], ms[30], vcl[mn], kt, dad[mn];
vector< int> vt[mn], ke[mn], leaf;
long long res= 1e9+ 7, ans= 0;
void dfs(int u)
{
    if(vt[u].size()== 1) leaf.push_back(u);
    for(int i= 0; i< vt[u].size(); i++)
    {
        int v= vt[u][i];
        if(dad[u]!= v){
            dad[v]= u;
            ke[u].push_back(v);
            dfs(v);
        }
    }
}
void dfss(int u)
{
    vcl[u]= ms[u];
    for(int i= 0; i< ke[u].size(); ++i){
        int v= ke[u][i];
        dfss(v);
        vcl[u]+= vcl[v];
    }
    ans+= abs(a[u]- vcl[u]);
}
void lm(long x)
{
    for(long i= 0; i< kt; i++)
    {
        if(((x>> i)& 1)== 1) ms[leaf[i]]= 1;
    }
    dfss(1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("tree.inp", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin>> n;
    forr(i, 1, n)
    cin>> a[i];
    forr(i, 1, n- 1)
    {
        int u, v;
        cin>> u>> v;
        vt[u].push_back(v);
        vt[v].push_back(u);
    }
    dfs(1);
    kt= leaf.size();
    forr(i, 0, (1<< kt)- 1)
    {
        memset(ms, 0, sizeof(ms));
        ans= 0;
        lm(i);
        res= min(res, ans);
    }
    cout<< res;
    return 0;
}
