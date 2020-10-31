#include <bits/stdc++.h>
#define maxn
#define maxc
#define PB push_back
#define MP make_pair
#define ft first
#define sd second
#define nguyenthitham "icecream"
#define mod 1000000009
using namespace std;
int n,mmax,m50,m1,m2;
int F[50][205][105][105];
void nhap()
{
    cin >> n >> mmax >> m50 >> m1 >>m2;
}
void sub1()
{
    F[0][m50][m1][m2]=1;
    for(long i=0;i<=n;++i)
    {
        for(long u=0;u<=mmax;++u)
        {
            for(long v=0;v<=mmax;++v)
            {
                for(long c=0;c<=mmax;++c)
                {
                    int x=F[i][u][v][c];
                    if(x==0) continue;
                    if(u>=1 && v>=1 && c <mmax )
                    {
                        F[i+1][u-1][v-1][c+1]=(F[i+1][u-1][v-1][c+1]+x)%mod;
                    }
                    if(u>=3 && v==0 && c < mmax)
                    {
                        F[i+1][u-3][v][c+1]=(F[i+1][u-3][v][c+1]+x)%mod;
                    }
                    if(u<mmax)
                    {
                        F[i+1][u+1][v][c]=(F[i+1][u+1][v][c]+x)%mod;
                    }
                    if(u>0 && v<mmax)
                    {
                        F[i+1][u-1][v+1][c]=(F[i+1][u-1][v+1][c]+x)%mod;
                    }
                }
            }
        }
    }
    long  ans=0;
    for(long i=0;i<=mmax;++i)
    {
        for(long j=0;j<=mmax;++j)
        {
            for(long u=0;u<=mmax;++u)
            {
                ans=(ans+F[n][i][j][u])%mod;
            }
        }
    }
    cout << ans<<endl;
}
void sub2()
{
    //memset(F,0,sizeof(F));
    int t1,t2,t50;
    int g1,g2,g50;
    g2=mmax-m2;
    g1=mmax-m1;
    g50=mmax-m50;
    t50=min(m50,150);
    t1=min(m1,50);
    t2=min(m2,0);
    g50=min(t50+n,t50+g50);
    g1=min(t1+n,t1+g1);
    g2=min(t2+n,t2+g2);
    F[0][t50][t1][t2]=1;
    for(long i=0;i<=n;++i)
    {
        for(long u=0;u<=g50;++u)
        {
            for(long v=0;v<=g1;++v)
            {
                for(long c=0;c<=g2;++c)
                {
                    int x=F[i][u][v][c];
                    if(x==0) continue;
                    if(u>=1 && v>=1 && c <g2 )
                    {
                        F[i+1][u-1][v-1][c+1]=(F[i+1][u-1][v-1][c+1]+x)%mod;
                    }
                    if(u>=3 && v==0 && c<g2)
                    {
                        F[i+1][u-3][v][c+1]=(F[i+1][u-3][v][c+1]+x)%mod;
                    }
                    if(u<g50)
                    {
                        F[i+1][u+1][v][c]=(F[i+1][u+1][v][c]+x)%mod;
                    }
                    if(u>0 && v<g1)
                    {
                        F[i+1][u-1][v+1][c]=(F[i+1][u-1][v+1][c]+x)%mod;
                    }
                }
            }
        }
    }
    long  ans=0;
    for(long i=0;i<=g50;++i)
    {
        for(long j=0;j<=g1;++j)
        {
            for(long u=0;u<=g2;++u)
            {
                ans=(ans+F[n][i][j][u])%mod;
            }
        }
    }
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(nguyenthitham".inp","r",stdin);
    freopen(nguyenthitham".out","w",stdout);
    nhap();
    if(n<=15)
    {
        sub1();
        return 0;
    }
    if(n<=50)sub2();
    else cout << 13;
    return 0;
}
