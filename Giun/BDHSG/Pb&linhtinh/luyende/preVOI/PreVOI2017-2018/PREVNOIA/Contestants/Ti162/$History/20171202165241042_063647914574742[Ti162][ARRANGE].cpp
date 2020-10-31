#include<bits/stdc++.h>
using  namespace std;
const int maxn=1e5+5;
int n;
int a[maxn],b[maxn];
int t=0;
int amin,amax,sum,dmax,dmin;
int res=0;
void sub1()
{

}
void sub2()
{
    dmax=sum%n;
    dmin=n-dmax;
    amin=sum/n;
    amax=sum/n+1;
        for(int i=1;i<=n;++i)
    {
        if(a[i]==amax)
        {
            if(dmax>0)
            {
                --dmax;
                continue;
            }
        }
        if(a[i]==amin)
        {
            if(dmin>0)
            {
                --dmin;
                continue;
            }
        }
        b[++t]=a[i];
    }
    sort(b+1,b+1+t);
    for(int i=1;i<=t;++i)
    {
        if(dmin>0)
        {
            res+=abs(b[i]-amin);
        }
        else res+=abs(b[i]-amax);
    }
    cout<<res/2;
}
int main()
{
    freopen("ARRANGE.INP","r",stdin);
    freopen("ARRANGE.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sub2();

}
