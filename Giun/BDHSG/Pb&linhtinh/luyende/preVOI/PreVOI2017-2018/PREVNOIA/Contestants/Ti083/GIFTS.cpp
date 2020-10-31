#include<bits/stdc++.h>
using namespace std;
int n,k;
long long a[1000006],s[1000006],res=1000000000012,temp=0;
long long f[1000006]={},g[1000006]={};
long long sum(int i)
{
    return s[i+k-1]-s[i-1];
}
void sub12()
{
    for (int i=1;i<=n-k+1;i++)
    {
        temp=0;
        for (int j=1;j<=n-k+1;j++)
        {
            if (i<=j+k-1&&j<=i+k-1) continue;
            temp=max(temp,sum(j));
        }
        res=min(res,temp);
    }
    cout<<res;
}
void sub3()
{
    for (int i=k;i<=n;i++)
        f[i]=max(f[i-1],sum(i-k+1));
    for (int i=n-k+1;i>=1;i--)
        g[i]=max(g[i+1],sum(i));
    for (int i=1;i<=n-k+1;i++)
        res=min(res,max(f[i-1],g[i+k]));
    cout<<res;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("GIFTS.INP","r",stdin);
    freopen("GIFTS.OUT","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];s[i]=s[i-1]+a[i];
    }
    if (n<=1000) sub12();
    else sub3();
    return 0;
}
