#include <bits/stdc++.h>
using namespace std;
long long a,b,n;
long long k;
long long MOD;
long long m[64];
bool bb[64];
    long long ma=0;
ofstream out("MODULO.out");
void xuat()
{
    for(int i(n-1);i>=0;--i)
    {if(bb[i]==1) out<<a;
    else out<<b;}
}
void duyet(int d,long long sum)
{
    sum%=MOD;
    if(((ma-sum)+MOD)%MOD==k) {
            xuat();exit(0);}
    for(int i(1);i>=0;--i)
    {
        if(d==n) break;
        if(i==1){bb[d]=1;duyet(d+1,sum+m[d]*(b-a));}
        else {bb[d]=0;duyet(d+1,sum);}
    }
}
int main()
{
    ifstream cin("MODULO.inp");
    cin>>a>>b>>n>>k;
    MOD=(1<<n);
    for(int i(0),j=1;i<n;++i)
    {
        m[i]=j%MOD;j*=10;
    }
    if(b<a) swap(a,b);
    if(b%2==a%2&&b%2!=k) {out<<-1;return 0;}
    int i=1;
    while(i<=n){ma=ma*10+b;++i;}
    if(ma%MOD==k) {out<<ma;return 0;}
    ma=ma%MOD;
    duyet(0,0);
    out<<-1;
}
