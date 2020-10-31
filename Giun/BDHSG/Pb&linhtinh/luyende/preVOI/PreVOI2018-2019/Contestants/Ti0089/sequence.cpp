#include <bits/stdc++.h>
#define maxn 150
#define base 1000000007
#define oo 30000000
using namespace std;
int m,n,k,a[maxn],b[maxn],f[111][111][111];
int t1[111][maxn][maxn],t2[111][maxn][maxn],k1[maxn],k2[maxn];
void xl(int u,int v){
    int kk=k;
    while (kk){
        k2[kk]=f[kk][u][v];
        int uu=t1[kk][u][v];
        int vv=t2[kk][u][v];
        u=uu;v=vv;kk--;
    }
    for (int i=1;i<=k;i++) if (k1[i]<k2[i]) return;
    for (int i=1;i<=k;i++) k1[i]=k2[i];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("sequence.inp","r",stdin);
    freopen("sequence.out","w",stdout);
    cin>>m>>n>>k;
    for (int i=1;i<=m;i++) cin>>a[i];
    for (int j=1;j<=n;j++) cin>>b[j];
    for (int t=1;t<=k;t++)
        for (int i=0;i<=m;i++)
            for (int j=0;j<=n;j++) f[t][i][j]=oo;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++) f[1][i][j]=min(a[i],b[j]);
    for (int t=1;t<=k;t++)
    for (int i=1;i<=m;i++)
    for (int j=1;j<=n;j++){
        f[t][i][j]=f[t-1][i-1][j-1];
        t1[t][i][j]=i-1;
        t2[t][i][j]=j-1;
        if (a[i]<=f[t][i][j])
        for (int j1=0;j1<j;j1++)
        if (f[t-1][t1[t][i][j]][t2[t][i][j]]<f[t-1][i-1][j1])
            {
            f[t][i][j]=a[i];
            t1[t][i][j]=i-1;
            t2[t][i][j]=j1;
        }
        if (b[j]<=f[t][i][j])for (int i1=0;i1<i;i1++)
        if (f[t-1][t1[t][i][j]][t2[t][i][j]]<f[t-1][i1][j-1])
            {
            f[t][i][j]=b[j];
            t1[t][i][j]=i1;
            t2[t][i][j]=j-1;
        }
    }
    for (int i=1;i<=k;i++) k1[i]=oo;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++) if (f[k][i][j]<oo) xl(i,j);
    for (int i=1;i<=k;i++) cout<<k1[i]<<" ";
    return 0;
}
