#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
const int nmax=1e6+10;
int a[nmax];
ll sum=0;
int k,s[3],d[3];
int x[nmax],b[nmax];
ll res;

void sub1()
{
    res=0;
    ll gt=sum/n;
    for (int i=1;i<=n;i++)
    {
        res=res+abs(gt-a[i]);
        a[i+1]-=(gt-a[i]);
    }
    cout<<res;
}
void xuli()
{
    ll gt=0;
    for (int i=1;i<=n;i++) b[i]=a[i];
    for (int i=1;i<=n;i++)
    {
        gt+=abs(x[i]-b[i]);
        b[i+1]-=(x[i]-b[i]);
    }
    res=min(res,gt);
}
void Try(int i)
{
    for (int j=0;j<=1;j++) if (d[j]<s[j])
    {
        x[i]=k+j;
        d[j]++;
        if (i==n) xuli();
        else if (i<n) Try(i+1);
        d[j]--;
    }
}
void sub2()
{
    k=sum/n;
    s[1]=sum-1ll*k*n;
    s[0]=n-s[1];
    res=LLONG_MAX;
    Try(1);
    cout<<res;
}
void sub3()
{
    k=sum/n;
    int s1,s2;
    s2=sum-1ll*k*n;
    s1=n-s2;
    ll res=0;
    for (int i=1;i<=n;i++)
    {
        if (s1>0)
        {
            s1--;
            res+=abs(a[i]-k);
            a[i+1]-=(k-a[i]);
        }
        else
        {
            s2--;
            res+=abs(a[i]-k-1);
            a[i+1]-=(k+1-a[i]);
        }
    }
    cout<<res;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("arrange.inp","r",stdin);
    freopen("arrange.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if (sum%n==0) sub1();
    else if (n<=100) sub2();
    else sub3();
    return 0;
}
