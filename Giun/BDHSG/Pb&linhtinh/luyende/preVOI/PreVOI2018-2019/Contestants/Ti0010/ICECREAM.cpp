#include<bits/stdc++.h>
using namespace std;
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(a,b) for(auto &a:b)
#define pii pair<int,int>
#define fi first
#define se second
const int N=301,mod=1e9+9;
int n,A,B,C,ma,f[N][2*N][2*N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("ICECREAM.inp","r",stdin);
    freopen("ICECREAM.out","w",stdout);
    cin>>n>>ma>>A>>B>>C;
    f[0][n][n]=1;
    forinc(i,0,n-1) forinc(_a,0,2*n) forinc(_b,0,2*n) if(f[i][_a][_b])
    {
        int a=_a-n,b=_b-n;
        int c=(n-a-b*2)/4;
        if(A+a<ma) f[i+1][_a+1][_b]=(f[i+1][_a+1][_b]+f[i][_a][_b])%mod;
        if(A+a&&B+b<ma) f[i+1][_a-1][_b+1]=(f[i+1][_a-1][_b+1]+f[i][_a][_b])%mod;
        if(C+c<ma)
        {
            if(A+a&&B+b) f[i+1][_a-1][_b-1]=(f[i+1][_a-1][_b-1]+f[i][_a][_b])%mod;
            else if(A+a>2) f[i+1][_a-3][_b]=(f[i+1][_a-3][_b]+f[i][_a][_b])%mod;
        }
    }
    int kq=0;
    forinc(a,0,2*n) forinc(b,0,2*n) kq=(kq+f[n][a][b])%mod;
    cout<<kq;
}
