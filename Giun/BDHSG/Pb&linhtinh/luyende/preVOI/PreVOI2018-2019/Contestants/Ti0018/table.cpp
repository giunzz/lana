#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define in() ({ll x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
#define inchar() ({char c=getchar();while(c==' '||c=='\n') c=getchar();c;})
#define pc putchar
inline void cc(ll x)
{
    if(x<0) pc('-'),x=-x;
    if(x>9) cc(x/10);
    pc(x%10+'0');
}
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=b;a<=i;i--)
#define VEC(i,a) for(auto&i:a)
#define rr(x) " "<<#x<<'='<<x<<" "
#define pb push_back
#define mt make_tuple
#define pi pair<int,int>
#define fi first
#define se second
/////////////////////////////////// PXH612
#define Max(a,b) ((a<b)?b:a)
#define Min(a,b) ((a<b)?a:b)
const int N=305;
int m,n,k;
ll f[N][N],g[N][N];
ll a[N][N];
void SOLVE()
{
   // cout<<"========================\n";
    int u=in(),v=in(),p=in(),q=in();
    FOR(i,u,p) FOR(j,v,q)
    {
        f[i][j]=0;
        if(i>u) f[i][j]=Max(f[i][j],f[i-1][j]);
        if(j>v) f[i][j]=Max(f[i][j],f[i][j-1]);
        f[i][j]+=a[i][j];

      //  cout<<f[i][j]<<" ";
     //   if(j==q) cout<<"\n";
    }
   // cout<<"\n";
    FOR(i,u,p) FOR(j,v,q)
    {
        g[i][j]=f[i][j];
        if(i>u&&j>v)
        {
            g[i][j]=Min(g[i][j],f[i-1][j]+a[i][j]);
            g[i][j]=Min(g[i][j],f[i][j-1]+a[i][j]);
            g[i][j]=Min(g[i][j],Max(g[i-1][j],g[i][j-1])+a[i][j]);
        }
     //   cout<<g[i][j]<<" ";
     //   if(j==q) cout<<"\n";
    }
    cout<<g[p][q]<<"\n";
}
main()
{
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);
    m=in(),n=in(),k=in();
    FOR(i,1,m) FOR(j,1,n) a[i][j]=in();
    while(k--) SOLVE();
}
