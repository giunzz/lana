#include <bits/stdc++.h>
#define forinc(i,a,b) for(int i=a , _b=b ; i<=_b ; ++i)
#define fordec(i,a,b) for(int i=a , _b=b ; i>=_b ; --i)
#define task "MODULO"
#define getbit(x,i) ((x>>(i-1))&1)
#define onbit(x,i) (x|(1<<(i-1)))
#define N 100
#define ll long long
#define pii pair<ll,ll>
#define fi first
#define se second
using namespace std;
int a,b,n,m=0;
ll k,M,pw[N];
pii f[1500000];
bool ok=false;
void ktao()
{
    M=1; forinc(i,1,n) M*=2;
    pw[0]=1; forinc(i,1,n) pw[i]=(pw[i-1]*10)%M;
}
void duyet1(int s,ll val,ll tt)
{
    if(s==n/2+1)
    {
        f[++m]={val,tt};
        return;
    }
    duyet1(s+1,(val+a*pw[s-1]%M)%M,tt);
    ll tt2=onbit(tt,s);
    duyet1(s+1,(val+b*pw[s-1]%M)%M,tt2);
}
void ghi(ll tt,int len)
{
    fordec(i,len,1) if(getbit(tt,i)==0) cout<<a;else cout<<b;
}
void kt(ll val,ll tt)
{
    val = (k-val+M)%M;
    int l=1,r=m,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(f[mid].fi==val)
        {
            ok=true;
            ghi(tt,(n+1)/2); ghi(f[mid].se,n/2);
            return;
        }
        if(f[mid].fi<val) l=mid+1; else r=mid-1;
    }
}
void duyet(int s,ll val,ll tt)
{
    if(s==n+1) {kt(val,tt); return;}
    if(ok) return;
    duyet(s+1,(val+a*pw[s-1]%M)%M,tt);
    if(ok) return;
    ll tt2=onbit(tt,s-n/2);
    duyet(s+1,(val+b*pw[s-1]%M)%M,tt2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
    cin>>a>>b>>n>>k; ktao();
    duyet1(1,0,0);
    sort(f+1,f+m+1);
    duyet(n/2+1,0,0);
    if(!ok) cout<<-1;
}
