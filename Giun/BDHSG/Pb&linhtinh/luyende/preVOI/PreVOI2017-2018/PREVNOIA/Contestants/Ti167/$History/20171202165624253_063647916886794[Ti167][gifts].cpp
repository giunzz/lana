#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,k;
int m=0;
const int nmax=1e6+10;
int a[nmax];
ll s[nmax],b[nmax];
ll f[nmax][33];
ll res=LLONG_MAX;
int id[nmax];

ll get(int u,int v)
{
    int t=log2(v-u+1);
    return max(f[u][t],f[v-(1<<t)+1][t]);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("gifts.inp","r",stdin);
    freopen("gifts.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for (int i=k;i<=n;i++)
    {
        b[++m]=s[i]-s[i-k];
        id[i]=m;
    }
    for (int i=1;i<=m;i++) f[i][0]=b[i];
    int t=log2(m);
    for (int j=1;j<(1<<t);j++)
        for (int i=1;i<=m;i++) if (i+(1<<j)-1<=m)
    {
        f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    }
    res=min(res,get(id[k+1],m));
    res=min(res,get(1,id[n-k]));
    for (int i=k+1;i<=n-k;i++)
    {
        int j1=id[i-k];
        int j2=id[i+k];
        res=min(res,max(get(1,j1),get(j2,m)));
    }
    cout<<res;
    return 0;
}
