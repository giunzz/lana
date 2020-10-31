#include <bits/stdc++.h>
#define task "modulo"
#define int int64_t
using namespace std;
template <typename T> inline void R(T &x)
{
    bool neg=false;
    register int c;
    x=0;
    c=getchar();
    if (c=='-')
    {
        neg=true;
        c=getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        x=(x>>1)+(x>>3)+c-48;
    if (neg) x=-x;
}
int get(int x, int i)
{
    return (x>>i)&1;
}
int a,b,n,k,m1[1<<21],m2[1<<21],tmp1,tmp2,f;
int power(int a, int b)
{
    int ret=1;
    for (int i=1; i<=b; ++i)
        ret*=a;
    return ret;
}
int powmod(int a, int b, int p)
{
    if (b==0) return 1%p;
    int tmp=powmod(a,b/2,p);
    if (b%2==0)
        return (tmp*tmp) % p;
    else
        return (tmp*tmp*a) % p;
}
void sub1()
{
    f=1<<n;
    for (int x=0; x<(1<<n); ++x)
    {
        tmp1=tmp2=0;
        for (int i=1; i<=n/2; ++i)
        {
            if (!get(x,i-1))
                tmp1=tmp1*10+a;
            else
                tmp1=tmp1*10+b;
        }
        for (int i=n/2+1; i<=n; ++i)
        {
            if (!get(x,i-1))
                tmp2=tmp2*10+a;
            else
                tmp2=tmp2*10+b;
        }
        int c=tmp1%f;
        int dd=n-n/2;
        int d=power(10,dd);
        int d1=powmod(10,dd,f);
        int e=tmp2%f;
        if (((c*d1)%f + e)%f==k)
        {
            //cout<<d1<<" "<<tmp1<<" "<<tmp2<<endl;
            for (int i=1; i<=n; ++i)
                if (!(get(x,i-1)))
                    cout<<a; else cout<<b;
            break;
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>a>>b>>n>>k;
    //if (n<=20)
       sub1();
    return 0;
}
