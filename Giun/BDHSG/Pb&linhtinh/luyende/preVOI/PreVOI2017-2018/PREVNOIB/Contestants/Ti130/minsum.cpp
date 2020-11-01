#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
long long ti;
long long a,b,dem,dem1;
long long g[5000];
long long f[1000010];
long long t[100];
void khoitao()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("minsum.inp","r",stdin);
    freopen("minsum.out","w",stdout);
}
void tinh()
{
    memset(f,0,sizeof(f));
    dem=0;
    for (long long i=2;i*i<=32000;i++)
    {
        if (f[i]==0)
        {
            dem++;
            g[dem]=i;
            for (long long j=2;j*i<=32000;j++)
            {
                f[i*j]=1;
            }
        }
    }
    for (long long i=317;i<=32000;i++)
    {
        if (f[i]==0)
            {dem++;
            g[dem]=i;
            }
    }
}
void pcal()
{
    long long l=a,r=b,d;
    while (r!=0)
    {
        d=r;
        r=l%d;
        l=d;
    }
    a=a/l;
    b=b/l;
}
void nhiphan()
{
    long long l=1;
    long long r=1;
    long long lu1=1000000000000,lu2=1000000000000;
    for (long long i=1;i<(1<<dem1);i++)
    {
        l=1;
        r=1;
        for (long long j=0;j<dem1;j++)
            {
                if ((i&(1<<j))!=0)
                {
                    l=l*t[j+1];
                }
                else
                {
                    r=r*t[j+1];
                }
            }
            if (l+r< lu1+lu2)
            {
                lu1=l;
                lu2=r;
            }
    }
    if (lu1>lu2) swap(lu1,lu2);
    cout<<lu1<<" "<<lu2<<"\n";
}
void tham()
{
    sort(t+1,t+dem1+1);
    long long d=dem1/4;
    long long p=dem1%4;
    long long l=1;
    long long r=1;
    for (long long i=0;i<d;i++)
    {
        if (l>r) swap(l,r);
        l=l*t[1+(i*2)];
        l=l*t[dem1-(i*2)];
        r=r*t[1+(i*2)+1];
        r=r*t[dem1-(i*2)-1];
    }
      if (l>r) swap(l,r);
    if (p==0) {cout<<l<<" "<<r<<"\n";return;}
    if (p==1)
    {
        l=l*t[(dem1+1)/2];
        cout<<l<<" "<<r<<"\n";
        return;
    }
    if (p==2)
    {
        l=l*t[(dem1/2)+1];
        r=r*t[(dem1/2)];
        if (l>r) swap(l,r);
        cout<<l<<" "<<r<<"\n";
        return;
    }
    if (p==3)
    {
        l=l*t[(dem1/2)];
        r=r*t[(dem1/2)+2];
        if (l>r) swap(l,r);
        l=l*t[(dem1/2)+1];
        if (l>r) swap(l,r);
        cout<<l<<" "<<r<<"\n";
        return;
    }
}
void tienxuly()
{
    long long gt=1;
    dem1=0;
    long long l=a,d;
    while (1)
    {
       d=0;
       while ((l%g[gt])==0)
       {
           l=l/g[gt];
           d++;
       }
       d=d%2;
       if (d==1) {dem1++;t[dem1]=g[gt];}
       gt++;
       if (g[gt]>l || g[gt]*g[gt]>a) break;
    }
    if (l!=1) {dem1++;t[dem1]=l;}
    l=b;
    gt=1;
    while (1)
    {
       d=0;
       while ((l%g[gt])==0)
       {
           l=l/g[gt];
           d++;
       }
       d=d%2;
       if (d==1) {dem1++;t[dem1]=g[gt];}
       gt++;
       if (g[gt]>l || g[gt]*g[gt]>b) break;
    }
    if (l!=1) {dem1++;t[dem1]=l;}
    if (dem1==1) {cout<<1<<" "<<t[1]<<"\n";return;}
    if (dem1==2) {cout<<t[1]<<" "<<t[2]<<"\n";return;}
    if (dem1<=8)
    {
        nhiphan();
        return;
    }
    tham();
}
void nhap()
{
    cin>>ti;
    for (long long i=1;i<=ti;i++)
    {cin>>a>>b;
     pcal();
     tienxuly();
    }
}
int main()
{
    khoitao();
    tinh();
    nhap();
    return 0;
}
