#include<bits/stdc++.h>
using namespace std;
int n,k;
const int maxn=1e6+5;
long long a[maxn];
long long sum[maxn];
long long res=LLONG_MAX,ans;
long long b[maxn];
int t=0;
bool kt;
void nhap()
{
    cin>>n>>k;
    sum[0]=0;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
}
void sub2()
{
    long long st;
    for(int j=1;j<=n-k+1;++j)
    {
        ans=LLONG_MIN;
    if(j>k)
    {
        kt=true;
    for(int i=1;i<=j-k;++i)
    {
         st=sum[i+k-1]-sum[i-1];
         ans=max(ans,st);
    }
    }
    if(j+k<=n-k+1)
    {
        kt=true;
    for(int i=j+k;i<=n-k+1;++i)
    {
         st=sum[i+k-1]-sum[i-1];
         ans=max(ans,st);
    }
         res=min(res,ans);
    }
    }
    if(kt)
   cout<<res;
   else cout<<0;
}
void sub3()
{
 for(int i=k;i<=n;++i)
    b[++t]=sum[i]-sum[i-k];
    sort(b+1,b+1+t);
    for(int i=t-1;i>=1;--i)
    {
        if(b[i]!=b[i+1]) {cout<<b[i];break;}
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("GIFTS.INP","r",stdin);
    freopen("GIFTS.OUT","w",stdout);
    nhap();
    if(n<=5000) sub2();
        else sub3();
}
