#include<bits/stdc++.h>
#define mn 100005
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORE(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
long long n,a[mn],b[mn],kq=0,tam=0,ss=0,s,u,v;
void nhap()
{
    cin>>n;
    FOR(i,1,n)
    {
        cin>>a[i];
        ss+=a[i];
        b[i]=a[i];
    }
    if(ss%n==0)
    {
        ss=ss/n;
        FOR(i,1,n)
        {
           kq+=abs(s-a[i]);
           a[i+1]=a[i+1]+(a[i]-s);
        }
    }
    else
    {
        u=ss/n;
        v=ss-u*n;
        u=n-v;
        s=ss/n;
        FOR(i,1,n)
        if(u==0)
        {
            kq+=abs(s+1-a[i]);
            a[i+1]=a[i+1]+(a[i]-s-1);
            a[i]=s+1;
            v--;
        }
        else
        {
            kq+=abs(s-a[i]);
            a[i+1]=a[i+1]+(a[i]-s);
            a[i]=s;
            u--;
        }
        u=ss/n;
        v=ss-u*n;
        u=n-v;
        s=ss/n;
        FORE(i,n,1)
        if(u==0)
        {
            tam+=abs(s+1-b[i]);
            b[i-1]=b[i-1]+(b[i]-s-1);
            b[i]=s+1;
            v--;
        }
        else
        {
            tam+=abs(s-b[i]);
            b[i-1]=b[i-1]+(b[i]-s);
            b[i]=s;
            u--;
        }
        kq=min(kq,tam);
    }
    cout<<kq;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ARRANGE.inp","r",stdin);
    freopen("ARRANGE.out","w",stdout);
    nhap();
    return 0;
}

