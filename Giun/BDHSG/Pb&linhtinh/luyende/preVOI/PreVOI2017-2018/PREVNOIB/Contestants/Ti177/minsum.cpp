#include <bits/stdc++.h>
#define nmax 10000007
#define vc 999999999999

using namespace std;

long long t,a,b,yc[nmax],d1,x[nmax],tong,ans1,ans2;

void kt()
{
    long long s1=1,s2=1;
    for (long i=1; i<=d1; i++)
      if (x[i]==0) s1*=yc[i];
    else s2*=yc[i];
    if (tong>s1+s2)
    {
        tong=s1+s2;
        ans1=s1;
        ans2=s2;
    }
}

void tryy_(long i)
{
    for (long j=0; j<=1; j++)
    {
        x[i]=j;
        if (i==d1) kt();
        else tryy_(i+1);
    }
}

void sub1()
{
    long long x=__gcd(a,b);
    a/=x; b/=x;
    for (long i=2; i<=a; i++)
    {
        if (a<i) break;
        long long dem=0,a1=a;
        while (a1%i==0)
        {
            dem++;
            a1=a1/i;
        }
        if (dem%2==1) dem--;
        for (long j=1; j<=dem; j++) a/=i;
    }
    for (long i=2; i<=b; i++)
    {
        if (b<i) break;
        long long dem=0,a1=b;
        while (a1%i==0)
        {
            dem++;
            a1=a1/i;
        }
        if (dem%2==1) dem--;
        for (long j=1; j<=dem; j++) b/=i;
    }
    d1=0;
    for (long i=2; i<=a; i++)
      if (a%i==0)
       {
           yc[++d1]=i;
           a/=i;
           if (a==1) break;
       }
    for (long i=2; i<=b; i++)
      if (b%i==0)
       {
           yc[++d1]=i;
           b/=i;
           if (b==1) break;
       }
    tong=vc;
    /*for (long i=1; i<=d1; i++) cout << yc[i] << " "; cout << endl;
    cout << a << " " << b << '\n';*/
    tryy_(1);
    if (ans1>ans2) swap(ans1,ans2);
    cout << ans1 << " " << ans2 << '\n';
}

void sub2()
{
    long long x=__gcd(a,b);
    a/=x; b/=x;
    long long ss=10000000;
    for (long i=2; i<=min(ss,a); i++)
    {
        if (a<i) break;
        long long dem=0,a1=a;
        while (a1%i==0)
        {
            dem++;
            a1=a1/i;
        }
        if (dem%2==1) dem--;
        for (long j=1; j<=dem; j++) a/=i;
    }
    for (long i=2; i<=min(ss,b); i++)
    {
        if (b<i) break;
        long long dem=0,a1=b;
        while (a1%i==0)
        {
            dem++;
            a1=a1/i;
        }
        if (dem%2==1) dem--;
        for (long j=1; j<=dem; j++) b/=i;
    }
    d1=0;
    long long aa=a,bb=b;
    for (long i=2; i<=min(ss,a); i++)
      if (a%i==0)
       {
           yc[++d1]=i;
           a/=i;
           if (a==1) break;
       }

    for (long i=1; i<=d1; i++) aa/=yc[i];
    if (aa!=1)  yc[++d1]=aa;

    long d2=d1;
    for (long i=2; i<=min(ss,b); i++)
      if (b%i==0)
       {
           yc[++d1]=i;
           b/=i;
           if (b==1) break;
       }
    for (long i=d2+1; i<=d1; i++) bb/=yc[i];
    if (bb!=1)  yc[++d1]=bb;
    sort(yc+1,yc+d1+1);

    tong=vc;
    if (d1<=15)
    {
        tryy_(1);
    }
    else
    {
        long long s1=1, s2=1;
        for (long i=1; i<=d1; i++)
            if (i%2==1) s1*=yc[i];
        else s2*=yc[i];

        if (tong>s1+s2)
         {
          tong=s1+s2;
          ans1=s1;
          ans2=s2;
         }

    }
    if (ans1>ans2) swap(ans1,ans2);
    cout << ans1 << " " << ans2 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("minsum.inp","r",stdin);
    freopen("minsum.out","w",stdout);
    scanf("%lld",&t);
    while (t--)
    {
        scanf("%lld%lld",&a,&b);
        if (a<=50 && b<=50) sub1();
        else sub2();
    }
}
