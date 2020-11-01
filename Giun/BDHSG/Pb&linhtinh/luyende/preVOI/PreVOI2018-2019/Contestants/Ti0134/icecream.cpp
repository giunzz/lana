#include<bits/stdc++.h>
long long n,i,j,h,k,kk,t,d,m,f[71][71][71][71],a[100],b[100],base=1e9+9;
using namespace std;
bool kt(long long i,long long j,long long k,long long kk)
{
    if ((i-j-3*k+a[1]-kk)<0) return false;
    if ((i-j-3*k+a[1]-kk)>m) return false;
    if ((j-kk+a[2])<0) return false;
    if ((j-kk+a[2])>m) return false;
    if ((k+kk+a[3])>m) return false;
    return true;
}
void update(long long &a,long long b)
{
    a=(a+b)%base;
}
int main()
{
    freopen("icecream.inp","r",stdin);
    freopen("icecream.out","w",stdout);
    cin>>n>>m;
    cin>>a[1]>>a[2]>>a[3];
    f[0][0][0][0]=1;
    for(h=0;h<=n;h++)
    for(i=0;i<=h;i++) for(j=0;i+j<=h;j++)
    for(kk=0;kk<=h-i-j;kk++) if (f[h][i][j][kk]!=0) if (h==n) d=(d+f[h][i][j][kk])%base; else
        {
            k=h-i-j-kk;
            if (kt(i,j,k,kk))
            {
                if (kt(i+1,j,k,kk)) update(f[h+1][i+1][j][kk],f[h][i][j][kk]);
                if (kt(i,j+1,k,kk)) update(f[h+1][i][j+1][kk],f[h][i][j][kk]);
                if (kt(i,j,k,kk+1)) update(f[h+1][i][j][kk+1],f[h][i][j][kk]);
                else if (kt(i,j,k+1,kk)) update(f[h+1][i][j][kk],f[h][i][j][kk]);
            }
        }
    cout<<d;
}
