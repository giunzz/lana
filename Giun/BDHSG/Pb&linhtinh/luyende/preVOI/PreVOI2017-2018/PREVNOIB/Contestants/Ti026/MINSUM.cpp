#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORE(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int t,dem=0,s[105],sa[105],sb[105];
bool nt[1000005];
long long a,b;
void sang(int n)
{
    nt[1]=1;
    for(int i=2;i*i<=n;++i)
        if(!nt[i])
        {
            s[++dem]=i;
            int j=i*i;
            while(j<=n) {nt[j]=1; j+=i;}
        }
}
bool scp(long long n)
{
    long long t=sqrt(n);
    if(t*t==n) return 1;
    return 0;
}
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("MINSUM.INP","r",stdin);
    freopen("MINSUM.OUT","w",stdout);
    cin>>t;
    sang(70);
    while(t--)
    {
        cin>>a>>b;
        if(a==b) {cout<<1<<' '<<1<<'\n'; continue;}
        if(scp(a) && scp(b)) {cout<<1<<' '<<1<<'\n'; continue;}
        int aa=a,bb=b;
        for(int i=1;i<=dem;++i)
        {
            while(aa%s[i]==0)
            {
                ++sa[i];
                aa=aa/s[i];
            }
            while(bb%s[i]==0)
            {
                ++sb[i];
                bb=bb/s[i];
            }
            if(sa[i]>=sb[i])
            {
                a=a/pow(s[i],sb[i]);
                b=b/pow(s[i],sb[i]);
                sa[i]=sa[i]-sb[i];
                sb[i]=0;
            }
            else
            {
                a=a/pow(s[i],sa[i]);
                b=b/pow(s[i],sa[i]);
                sa[i]=0;
                sb[i]=sb[i]-sa[i];
            }
            if(sa[i]==0&&sb[i]>=2)
                b=b/pow(s[i],2*(sb[i]/2)),sb[i]=sb[i]%2;
            if(sb[i]==0&&sa[i]>=2)
                a=a/pow(s[i],2*(sa[i]/2)),sa[i]=sa[i]%2;
        }
        for(int i=1;i<=dem;++i)
            if(sa[i])
            {
                if(a/s[i]+b*s[i]<a+b) a=a/s[i],b=b*s[i];
                sa[i]=0;
                sb[i]=0;
            }
            else if(sb[i])
                 {
                    if(b/s[i]+a*s[i]<a+b) b=b/s[i],a=a*s[i];
                    sa[i]=0;
                    sb[i]=0;
                 }
        cout<<a<<' '<<b<<'\n';
    }
}
