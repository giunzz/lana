#include <bits/stdc++.h>
#define ii pair<long long,int>
using namespace std;
const int MAXN=1e5+3;
int n;
long long a[MAXN],P,b[MAXN];
#define filename "ARRANGE"
void io()
{
    freopen(filename".INP","r",stdin);
    freopen(filename".OUT","w",stdout);
}
priority_queue< ii,vector<ii> > qu;
int cnt=0;
long long H;
long long ans,l,r;
long long res;
void proc()
{
    ans=0,l=0,r=0;
    for(int i=1;i<=n;++i)
    {
        if(a[i]>P)
        {
            qu.push(ii(a[i]-P-1,i));
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(a[i]>=P)
            continue;
        H=P-1-a[i];
        ans+=H;
        while(H and !qu.empty())
        {
            if(H>=qu.top().first)
            {
                H-=qu.top().first;
                a[qu.top().second]=P+1;
                qu.pop();
            }
            else
            {
                a[qu.top().second]-=qu.top().first-H;
                qu.push(ii(a[qu.top().second]-P-1,qu.top().second));
                qu.pop();
            }
        }
    }
    //cout<<ans<<'\n';
    for(int i=1;i<=n;++i)
    {
        if(a[i]<P)
            l++;
        if(a[i]>P)
            r++;
    }
    while(!qu.empty())
    {
        ans+=qu.top().first;
        l-=qu.top().first;
        qu.pop();
    }
    if(l>0)
        ans+=min(l,r);
}
main()
{
    io();
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&b[i]);
        P+=b[i];
        a[i]=b[i];
    }
    P/=n;
    proc();
    res=ans;
    P++;
    for(int i=1;i<=n;++i)
        a[i]=b[i];
    proc();
    res=min(res,ans);
    cout<<res;
}
