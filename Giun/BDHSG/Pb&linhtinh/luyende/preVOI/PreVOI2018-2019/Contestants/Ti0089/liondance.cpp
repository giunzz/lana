#include <bits/stdc++.h>
#define maxn 500
#define base 1000000007
#define oo 1000000000
using namespace std;
int n,m,a[maxn],b[maxn],f[maxn][maxn],g[maxn][maxn];
int k1[maxn],k2[maxn],t1[maxn][maxn],t2[maxn][maxn],kq;
void xl(int u,int v){
    int k=kq;
    while (k){
        k2[k]=g[u][v];
        int uu=t1[u][v];
        int vv=t2[u][v];
        u=uu;v=vv;k--;
    }
    for (int i=1;i<=kq;i++) if (k1[i]>k2[i]) return;
    for (int i=1;i<=kq;i++) k1[i]=k2[i];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("liondance.inp","r",stdin);
    freopen("liondance.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    f[0][0]=0;
    g[0][0]=-1;
    kq=0;
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++){
        for (int i1=0;i1<=i;i1++)
        for (int j1=0;j1<=j;j1++)
        if (f[i][j]==f[i1][j1]){
            if (g[i][j]<g[i1][j1]){
                g[i][j]=g[i1][j1];
                t1[i][j]=t1[i1][j1];
                t2[i][j]=t2[i1][j1];
            }
        }
        else if (f[i][j]<f[i1][j1]){
            f[i][j]=f[i1][j1];
            g[i][j]=g[i1][j1];
            t1[i][j]=t1[i1][j1];
            t2[i][j]=t2[i1][j1];
        }
        if (a[i]==b[j]){
        for (int i1=0;i1<=i-1;i1++)
        for (int j1=0;j1<=j-1;j1++)
        if (abs(a[i]-g[i1][j1])<=m || g[i1][j1]<0)
        if (f[i][j]==f[i1][j1]+1){
            if (g[t1[i][j]][t2[i][j]]<g[i1][j1]){
                t1[i][j]=i1;
                t2[i][j]=j1;
            }
        }
        else if (f[i][j]<f[i1][j1]+1){
            f[i][j]=f[i1][j1]+1;
            g[i][j]=a[i];
            t1[i][j]=i1;
            t2[i][j]=j1;
        }
        }
        kq=max(kq,f[i][j]);
    }
    cout<<kq<<endl;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) if (f[i][j]==kq) xl(i,j);
    for (int i=1;i<=kq;i++) cout<<k1[i]<<" ";
    return 0;
}
