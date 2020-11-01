#include <bits/stdc++.h>

using namespace std;
long long kq,a,b,n,k,t,x[101],g[101];

void Try(int i)
{
    if (kq>0) return;
    if (i>n) { if (g[n]%t==k) {kq=g[n]; cout<<kq; return;}  }
    else for (int j=1;j<3;++j)
         if (j==1) { g[i]=g[i-1]*10+a; Try(i+1); g[i]=g[i-1];}
         else { g[i]=g[i-1]*10+b; Try(i+1); g[i]=g[i-1]; }
}

int main()
{
    freopen("MODULO.inp","r",stdin);
    freopen("MODULO.out","w",stdout);
    cin>> a >> b >> n >> k;
    t=1<<n;
    g[0]=0;
    Try(1);
    if (kq==0) cout<<-1;
}
