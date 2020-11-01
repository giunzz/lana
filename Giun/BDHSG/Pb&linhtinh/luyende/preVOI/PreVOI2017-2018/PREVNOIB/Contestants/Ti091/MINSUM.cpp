#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORE(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int T,snt[1000],dem=0,s[1000],sa[1000],sb[1000];
long long a,b;
void sang(int n)
{
    snt[1]=0;
    FOR(i,2,n) snt[i]=1;
    FOR(i,2,n)
    if(snt[i])
    {
        dem++;
        s[dem]=i;
        int j=i*i;
        while(j<=n)
        {
            snt[j]=0;
            j=j+i;
        }
    }
}
void nhap()
{
    cin>>T;
    sang(1000);
    while(T)
    {
        T--;
        cin>>a>>b;
            int aa=a,bb=b;
            FOR(i,1,dem)
            {
                while(aa%s[i]==0)
                {
                    sa[i]++;
                    aa=aa/s[i];
                }
                while(bb%s[i]==0)
                {
                    sb[i]++;
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
            FOR(i,1,dem)
            if(sa[i])
            {
                if(a/s[i]+b*s[i]<a+b) a=a/s[i],b=b*s[i];
                sa[i]=0;
                sb[i]=0;
            }
            else
            if(sb[i])
            {
                if(b/s[i]+a*s[i]<a+b) b=b/s[i],a=a*s[i];
                sa[i]=0;
                sb[i]=0;
            }
        cout<<a<<" "<<b<<'\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MINSUM.inp","r",stdin);
    freopen("MINSUM.out","w",stdout);
    nhap();
    return 0;
}
