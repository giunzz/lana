#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T,a,b,m=0,q;
ll tsnt[1000],temp,nt[10000],mul,res,tp,d[1000]={},p[1000];
bool prime[40000];
void sangnt(int n)
{
    fill (prime+1,prime+n+1,true);
    int i=2;
    prime[1]=false;
    while (i*i<=n)
    {
        if (prime[i])
        for (int j=i*i;j<=n;j+=i) prime[j]=false;
        i++;
    }
    for (int i=2;i<=n;i++)
        if (prime[i]) nt[++m]=i;
}
void traubo(int i)
{
    for (int j=0;j<=1;j++)
    {
        if (j==1) mul*=tsnt[i];
        if (i==q) {if (mul<=tp) res=max(res,mul);}
        else if (mul<tp) traubo(i+1);
        if (j==1) mul/=tsnt[i];
    }
}
void ptsnt(ll x)
{
    int i=1,r=0;
    fill(d,d+100,0);
    while (nt[i]*nt[i]<=x)
    {
        if (x%nt[i]==0)
        {
            p[++r]=nt[i];
            while (x%nt[i]==0) {++d[r];x/=nt[i];}
        }
        i++;
    }
    if (prime[x]) {p[++r]=x;d[r]++;}
    for (int i=1;i<=r;i++) if (d[i]&1) tsnt[++q]=p[i];
}
void xuly(int a,int b)
{
    int i=1;temp=1;q=0;res=1;mul=1;
    ptsnt(a);
    ptsnt(b);
    for (int i=1;i<=q;i++) temp*=tsnt[i];
    tp=sqrt(temp);
    sort(tsnt+1,tsnt+q+1,greater<ll>());
    if (q==0) cout<<1<<' '<<1<<'\n';
    else
    {
        traubo(1);
        cout<<res<<' '<<temp/res<<'\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("MINSUM.INP","r",stdin);
    freopen("MINSUM.OUT","w",stdout);
    cin>>T;
    sangnt(40000);
    for (int i=1;i<=T;i++)
    {
        cin>>a>>b;
        temp=__gcd(a,b);
        a/=temp;
        b/=temp;
        xuly(a,b);
    }
    return 0;
}
