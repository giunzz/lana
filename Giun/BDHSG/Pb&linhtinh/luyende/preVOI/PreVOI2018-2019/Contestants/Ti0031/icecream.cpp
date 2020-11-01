#include <bits/stdc++.h>
#define mod 1000000009
using namespace std;
long n,mmax,m50,m1,m2;
long p[20],ans;
long gb(long x,long i)
{
    return (x/p[i])%3;
}
void kt(long s)
{
    long a,b,c,k;
    a=m50,b=m1,c=m2;
    for(long i=0;i<n;++i)
    {
        if(a>mmax||b>mmax||c>mmax)return;
        k=gb(s,i);
        if(k==0)
        {
            a++;
            continue;
        }
        if(k==1)
        {
            if(a==0)return;
            a--;
            b++;
        }
        if(k==2)
        {
            if(b>=1&&a>=1)
            {
                a--;
                b--;
                c++;
                continue;
            }
            if(a>=3)
            {
                a-=3;
                c++;
                continue;
            }
            return ;
        }
    }
    if(a>mmax||b>mmax||c>mmax)return;
    ans++;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("icecream.inp","r",stdin);
    freopen("icecream.out","w",stdout);
    cin>>n>>mmax;
    cin>>m50>>m1>>m2;
    p[0]=1;
    for(long i=1;i<=n;++i)
        p[i]=p[i-1]*3;
    for(long s=0;s<p[n];++s)
        kt(s);
    cout<<ans;
    return 0;
}
