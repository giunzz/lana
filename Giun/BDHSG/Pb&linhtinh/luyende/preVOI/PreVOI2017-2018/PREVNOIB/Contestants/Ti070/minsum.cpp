#include <bits/stdc++.h>
#define vc 2000000000
using namespace std;
long long a,b,ans1,ans2;
void ad(long long pos1,long long pos2)
{
    long long d;
    d=__gcd(pos1,pos2);
    pos1/=d;
    pos2/=d;
    if(ans1+ans2>pos1+pos2)
    {
        ans1=pos1;
        ans2=pos2;
    }
}
void lam()
{
    ans1=ans2=vc;
    long long pos1,pos2,d,j;
    for(long long i=1;i<=sqrt(a);++i)
    {
        if(a%i)continue;
        pos1=a/i;
        pos2=b*i;
        ad(pos1,pos2);
        j=a/i;
        pos1=a/j;
        pos2=b*j;
        ad(pos1,pos2);
    }
    for(long long i=1;i<=sqrt(b);++i)
    {
        if(b%i)continue;
        pos1=a*i;
        pos2=b/i;
        d=__gcd(pos1,pos2);
        ad(pos1,pos2);
        j=b/i;
        pos1=a*j;
        pos2=b/j;
        ad(pos1,pos2);
    }
    cout<<ans1<<" "<<ans2<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("minsum.inp","r",stdin);
    freopen("minsum.out","w",stdout);
    long t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        lam();
    }
    return 0;
}
