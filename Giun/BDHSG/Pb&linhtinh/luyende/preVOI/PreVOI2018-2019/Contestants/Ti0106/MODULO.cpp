#include <bits/stdc++.h>
#define mn 100
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
int n,n1,n2;
long long a,b,k,d=1,t[mn],mod;
map<long long,int> dd;
bool  laybit(int x,int i)
{
    return (x>>i)&1;
}
void sub12()
{
    t[0]=1;
    FOR(i,1,n) t[i]=t[i-1]*2;
    mod=t[n];
    n1=n/2;
    n2=n-n1;
    FOR(i,1,n1) d=(d*10)%mod;
    FOR(i,0,t[n1]-1)
    {
        long long s=0;
        FOR(j,0,n1-1)
        if(laybit(i,j)) s=(s*10+a)%mod;
        else s=(s*10+b)%mod;
        dd[s]=i;
    }
    FOR(i,0,t[n2]-1)
    {
        long long s=0;
        FOR(j,0,n2-1)
        if(laybit(i,j)) s=(s*10+a)%mod;
        else s=(s*10+b)%mod;
        s=(s*d)%mod;
        if(dd[k-s])
        {
             int p=dd[k-s];
             FOR(j,0,n2-1)
             if(laybit(i,j)) cout<<a;
             else cout<<b;
             FOR(j,0,n1-1)
             if(laybit(p,j)) cout<<a;
             else cout<<b;
             exit(0);
        }
        if(dd[k+mod-s])
        {
             int p=dd[k+mod-s];
             FOR(j,0,n2-1)
             if(laybit(i,j)) cout<<a;
             else cout<<b;
             FOR(j,0,n1-1)
             if(laybit(p,j)) cout<<a;
             else cout<<b;
             exit(0);
        }
    }
    cout<<-1;
}
void nhap()
{
    cin>>a>>b>>n>>k;
    if(a%2&&b%2&&k%2==0)
    {
        cout<<-1;
        exit(0);
    }
    if(a%2==0&&b%2==0&&k%2)
    {
        cout<<-1;
        exit(0);
    }
    if(n<=40) sub12();
    else cout<<-1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("MODULO.inp","r",stdin);
    freopen("MODULO.out","w",stdout);
    nhap();
    return 0;
}
