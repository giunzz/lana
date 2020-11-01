#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Forc(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
int F[4004][4004];
int n,k,a[3][4004],b[4004],m,res,f[4004],g[4004],cnt,c[4004],kq,ans[4004],dem;
void xl()
{
    For(i,1,n)
    if(a[1][i]==a[2][i])
        b[++m]=a[1][i];
    For(i,1,m)
    {
        f[i]=1;
        For(j,1,i-1)
        if(abs(b[j]-b[i])<=k)
        {
            f[i]=max(f[i],f[j]+1);
            res=max(res,f[i]);
        }
    }
    Forc(i,m,1)
    {
        g[i]=1;
        For(j,i+1,m)
        if(abs(b[j]-b[i])<=k)
            g[i]=max(g[i],g[j]+1);
    }
    For(i,1,m)
        if(f[i]+g[i]-1==res)
            c[f[i]]=max(c[f[i]],b[i]);

    For(i,1,res) cout<<c[i]<<" ";
}
void kt()
{
    dem=0;
    For(i,1,n)
    if(b[i])
        c[++dem]=a[1][i];
    int x=1;
    For(i,1,n)
    {
        if(a[2][i]==c[x]) x++;
    }
    if(x<=dem) return;
    if(dem>res)
    {
        For(i,1,dem) ans[i]=c[i];
        res=dem;
    }
    else if(dem==res)
    {
        For(i,1,dem)
        {
            if(c[i]<ans[i]) return;
            if(c[i]>ans[i])
            {
                For(j,1,dem) ans[i]=c[i];
                return;
            }
        }
    }

}
void duyet(int x)
{
    if(x>n)
    {
        kt();
        return;
    }
    For(i,0,1)
    {
        b[x]=i;
        duyet(x+1);
    }
}
void trau()
{
    duyet(1);
    For(i,1,res) cout<<ans[i]<<" ";
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    freopen("liondance.inp","r",stdin);
    freopen("liondance.out","w",stdout);
    cin>>n>>k;
    For(i,1,n) cin>>a[1][i];
    For(i,1,n) cin>>a[2][i];
    if(n<=20) trau();
    else
        xl();
}
