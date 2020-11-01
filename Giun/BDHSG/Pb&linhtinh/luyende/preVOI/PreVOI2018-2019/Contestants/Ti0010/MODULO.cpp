#include<bits/stdc++.h>
using namespace std;
#define int long long
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(a,b) for(auto &a:b)
#define pii pair<int,int>
#define fi first
#define se second
#define bit(x,i) (1ll&(x>>(i-1)))
#define onbit(x,i) (x|(1ll<<(i-1)))
int a,b,n,k,mod,pw=1,ok,top;
pii sv[1050000];
void ktra(int s,int tt)
{
    forinc(i,n/2+1,n) s=(s*10)%mod;
    int p=((k-s)%mod+mod)%mod;
    int l=1,r=top,o=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(sv[mid].fi==p) {o=mid;break;}
        if(sv[mid].fi>p) r=mid-1;
        else l=mid+1;
    }
    if(o==-1) return;
    ok=1;
    forinc(i,1,n/2) if(bit(tt,i)) cout<<b;else cout<<a;
    forinc(i,n/2+1,n) if(bit(sv[o].se,i)) cout<<b;else cout<<a;
}
void duyet2(int i,int s,int tt)
{
    if(ok) return;
    if(i==n/2+1) ktra(s,tt);
    else
    {
        duyet2(i+1,(s*10+a)%mod,tt);
        duyet2(i+1,(s*10+b)%mod,onbit(tt,i));
    }
}
void duyet1(int i,int s,int tt)
{
    if(i==n+1) sv[++top]={s,tt};
    else
    {
        duyet1(i+1,(s*10+a)%mod,tt);
        duyet1(i+1,(s*10+b)%mod,onbit(tt,i));
    }
}
main()
{
    freopen("MODULO.inp","r",stdin);
    freopen("MODULO.out","w",stdout);
    cin>>a>>b>>n>>k;
    mod=(1ll<<n);
    if(n==1)
    {
        if(a%mod==k) cout<<a;
        else if(b%mod==k) cout<<b;
        else cout<<-1;
        return 0;
    }
    if(n>40) {cout<<-1;return 0;}
    duyet1(n/2+1,0,0);
    sort(sv+1,sv+top+1);
    duyet2(1,0,0);
    if(!ok) cout<<-1;
}
