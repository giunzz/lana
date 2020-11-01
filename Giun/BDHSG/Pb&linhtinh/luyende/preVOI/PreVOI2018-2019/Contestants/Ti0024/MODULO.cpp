#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
#define pb push_back
#define mp make_pair
#define int long long
#define pii pair<int,int>
int n,a,b,k,mu2[100],mu10[100],st[100],n1,kq[100];
map<long long,long long> dd,dd1;
void pre()
{
    mu2[0]=1;
    mu10[0]=1;
    for(int i=1; i<=n; ++i)
        mu2[i]=mu2[i-1]*2;
    for(int i=1; i<=n; ++i)
    {
        mu10[i]=(mu10[i-1]*10) % mu2[n];
    }
}
void cal()
{
    int s=0;
    for(int i=1; i<=n; ++i)
    {
        if(st[i])
            s=(s+b*mu10[i-1]) % mu2[n];
        else
            s=(s+a*mu10[i-1]) % mu2[n];
    }
    if(s % mu2[n]==k)
    {
        for(int i=n; i>=1; --i)
            if(st[i])
                cout<<b;
            else
                cout<<a;
        exit(0);
    }
}
void DQ(int i)
{
    if(i==n+1)
    {
        cal();
        return;
    }
    for(int j=0; j<=1; ++j)
    {
        st[i]=j;
        DQ(i+1);
    }
}
void cal1()
{
    int s=0,x=0;
    for(int i=1; i<=n1; ++i)
    {
        if(st[i])
        {
            s=(s+b*mu10[i-1]) % mu2[n];
            x+=1<<(i-1);
        }
        else
            s=(s+a*mu10[i-1]) % mu2[n];
    }
    dd[s % mu2[n]]=1;
    dd1[s % mu2[n]]=x;
}
void DQ1(int i)
{
    if(i==n1+1)
    {
        cal1();
        return;
    }
    for(int j=0; j<=1; ++j)
    {
        st[i]=j;
        DQ1(i+1);
    }
}
void cal2()
{
    int s=0,dem=0;
    for(int i=n1+1; i<=n; ++i)
    {
        if(st[i])
            s=(s+b*mu10[i-1]) % mu2[n];
        else
            s=(s+a*mu10[i-1]) % mu2[n];
    }
    int x= s % mu2[n];
    if(dd[(mu2[n]+k - x) % mu2[n]]==1)
    {
        int u=dd1[(mu2[n]+k - x) % mu2[n]];
        for(int i=n; i>=n1+1; --i)
            if(st[i])
                cout<<b;
            else
                cout<<a;
        while(u > 0)
        {
            if(u%2==1)
                kq[++dem]=b;
            else
                kq[++dem]=a;
            u/=2;
        }
        for(int i=dem+1; i<=n1; ++i)
            cout<<a;
        for(int i=dem; i>=1; --i)
            cout<<kq[i];
        exit(0);
    }
}
void DQ2(int i)
{
    if(i==n+1)
    {
        cal2();
        return;
    }
    for(int j=0; j<=1; ++j)
    {
        st[i]=j;
        DQ2(i+1);
    }
}
main()
{
    freopen("MODULO.inp","r",stdin);
    freopen("MODULO.out","w",stdout);
    cin >> a >> b >> n >> k;
    if(a%2!=k%2 && b%2!=k%2)
    {
        cout<<"-1";
    }
    else
    {
        if(n<=20)
        {
            pre();
            DQ(1);
            cout<<"-1";
        }
        else
        {
            n1=n/2;
            pre();
            DQ1(1);
            DQ2(n1+1);
            cout<<"-1";
        }
    }
}
