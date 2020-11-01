#include<bits/stdc++.h>
long long n,i,j,h,k,t,d,m,a,b,aa=0,bb=0,p[100],f[100],base;
bool kt=false;
using namespace std;
void xl(long long i)
{
    if (i==n+1)
    {
        if ((a*aa%base+b*bb%base)%base==k)
        {
            kt=true;
            for(i=n;i>=1;i--) cout<<f[i];
        }
        return;
    }
    aa=(aa+p[i-1])%base;
    f[i]=a;
    xl(i+1);
    if (kt) return;
    f[i]=b;
    aa=((aa-p[i-1])%base+base)%base;
    bb=(bb+p[i-1])%base;
    xl(i+1);
    bb=((bb-p[i-1])%base+base)%base;
}
int main()
{
    freopen("modulo.inp","r",stdin);
    freopen("modulo.out","w",stdout);
    cin>>a>>b;
    base=1;
    cin>>n>>k;
    if (n<=25)
    {
    for(i=1;i<=n;i++) base*=2;
    p[0]=1;
    for(i=1;i<n;i++) p[i]=p[i-1]*10%base;
    xl(1);
    if (kt==false) cout<<-1;
    }
    else cout<<-1;
}
