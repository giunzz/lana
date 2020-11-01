#include <bits/stdc++.h>

using namespace std;

int n,dt,L[4001],R[4001],f[4001][4001],kq[4001];

int main()
{
    freopen("LIONDANCE.inp","r",stdin);
    freopen("LIONDANCE.out","w",stdout);
    scanf("%d %d",&n,&dt);
    for (int i=1; i<=n; i++) scanf("%d",&L[i]);
    for (int i=1; i<=n; i++) scanf("%d",&R[i]);
    for (int i=1; i<=n; i++) f[0][i]=0, f[i][0]=0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
           if (L[i]==R[j]) f[i][j]=f[i-1][j-1]+1;
           else f[i][j]=max(f[i-1][j],f[i][j-1]);
    int i=n, j=n; int d=f[n][n];
    while (d>0)
    {
        if (f[i][j]==f[i-1][j-1]+1 && L[i]==R[j]) kq[d]=max(kq[d],L[i]),i--,j--,d--;
        else if (f[i][j]==f[i-1][j]) i--; else j--;
    }
    d=f[n][n];
    cout<<d<<"\n";
    for (int i=1; i<=d; i++) cout<<kq[i]<<" ";
}
