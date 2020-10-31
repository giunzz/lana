#include<bits/stdc++.h>
using namespace std;
ifstream fi("ARRANGE.INP");
ofstream fo("ARRANGE.out");
#define int long long
int tg=0,a[100001],x,n,ans=0;
signed main()
{
    fi>>n;
    for(int i=1;i<=n;++i)
    {
        fi>>a[i];
        tg+=a[i];
    }
    x=tg/n;
    tg=0;
    for(int i=1;i<=n;++i)
    {
        tg+=a[i];
        ans+=abs(x*i-tg);
    }
    fo<<ans;
}
