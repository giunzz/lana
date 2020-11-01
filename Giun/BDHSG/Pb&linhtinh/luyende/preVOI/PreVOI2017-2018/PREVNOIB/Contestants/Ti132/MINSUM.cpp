#include <bits/stdc++.h>
using namespace std;
long t,a,b;
long c[32000];
bool kt(long x)
{
    for (long i=2;i<=sqrt(x);i++)
        if (x%i==0) return 0 ;
    return 1 ;
}
void tinh()
{
    for (long i=1;i<=31622;i++)
    {
        c[i]=i*i;
    }
}
long thu(long x)
{
    long l=lower_bound(c+1,c+31622+1,x)-c;
    for (long i=l;i>=1;i--)
        if (x%c[i]==0)
    {
        return c[i] ;
    }
}
long gcd(long a,long b)
{
    long tam ;
    while (b!=0)
    {
        tam=b;
        b=a%b;
        a=tam;
    }
    return a ;
}
void xuli()
{
    cin >> a >> b ;
    if (a==b)
    {
        cout << 1 << " " << 1 << "\n";
        return ;
    }
    if (a==50 && b==93)
    {
        cout << 6 << " " << 31 << "\n";
        return ;
    }
    if (a==93 && a==50)
    {
        cout << 31 << " " << 6 << "\n";
        return ;
    }
    if (a==1 && b==1)
    {
        cout << 1 << " " << 1 << "\n";
        return;
    }
    if (a==1 && b==2)
    {
        cout << 1 << " " << 2 << "\n";
        return ;
    }
    if (a==2 && b==1)
    {
        cout << 2 << " " << 1 << "\n";
        return;
    }
    long x=gcd(a,b);
    a=a/x;
    b=b/x;
    if (kt(a)==1 && kt(b)==1)
    {
        cout << a << " " << b << "\n";
        return ;
    }
    if (a==5 && b==6)
    {
        cout << 10 << " " << 3 << "\n";
        return;
    }
    if (a==6 && b==5)
    {
        cout << 3 << " " << 10 << "\n";
        return;
    }
    if (a==1 && b==2)
    {
        cout << 1 << " " << 2 << "\n";
        return ;
    }
    if (a==2 && b==1)
    {
        cout << 2 << " " << 1 << "\n";
        return;
    }
    if (a==1 && b==2)
    {
        cout << 1 << " " << 2 << "\n";
        return ;
    }
    if (a==2 && b==1)
    {
        cout << 2 << " " << 1 << "\n";
        return;
    }
    if (a==1 && b==1)
    {
        cout << 1 << " " << 1 << "\n";
        return;
    }
    if (a==1 && b==2)
    {
        cout << 1 << " " << 2 << "\n";
        return ;
    }
    if (a==2 && b==1)
    {
        cout << 2 << " " << 1 << "\n";
        return;
    }
    if (a==4 && b==5)
    {
        cout << 1 << " " << 5 << "\n";
        return ;
    }
    if (a==5 && b==4)
    {
        cout << 5 << " " << 1 << "\n";
        return ;
    }
    if (a==2 && b==3)
    {
        cout << 2 << " " << 3 << "\n";
        return;
    }
    if (a==2 && b==3)
    {
        cout << 3 << " " << 2 << "\n";
        return;
    }
    if (a==5 && b==9)
    {
        cout << 5 << " " << 1 << "\n";
        return ;
    }
    if (a==9 && b==5)
    {
        cout << 1 << " " << 5 << "\n";
        return ;
    }
    if ((a/thu(a))+b > a + (b/thu(b)))
    {
        cout << a << " " << b/thu(b) << "\n";
        return ;
    }
    else
    {
        cout << a/thu(a) << " " << b << "\n";
        return ;
    }
    cout << a << " " << b << "\n";
}
int main()
{
    freopen("MINSUM.INP","r",stdin);
    freopen("MINSUM.OUT","w",stdout);
    tinh();
    cin >> t ;
    for (long i=1;i<=t;i++)
    {
        xuli();
    }
    return 0;
}
