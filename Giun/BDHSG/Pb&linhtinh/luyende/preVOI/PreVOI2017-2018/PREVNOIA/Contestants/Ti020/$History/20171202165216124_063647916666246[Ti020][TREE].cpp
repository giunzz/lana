#include <iostream>
#include<bits/stdc++.h>
#define LL long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define filename "TREE."
using namespace std;
typedef pair<LL,LL> ii;
const int maxN=32;
vector<int> G[maxN];
vector<LL> La;
int A[maxN],B[maxN];
int n;
LL res=1e14;
void io()
{
    freopen(filename"INP","r",stdin);
    freopen(filename"OUT","w",stdout);
}
int getbit(int x,int k)
{
    return (x>>(k-1))&1;
}
LL cal(int x)
{
    int ans=0;
    if(G[x].size()==0) return abs(A[x]-B[x]);
    else
    {
        for(int u:G[x]) ans+=cal(u);
    }
    B[x]=ans;
    return abs(A[x]-ans);
}
main()
{
    io();
    cin>>n;
   if(n<31)
   {
    FOR(i,1,n) cin>>A[i];
    FOR(i,1,n-1)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
    }
    for(int i=1;i<=n;i++) if(G[i].size()==0) La.push_back(i);
    LL sz=La.size();
    LL sl=(1<<sz)-1;
    for(int x=0;x<=sl;x++)
    {
        FOR(i,1,n) B[i]=0;
        LL ans=0;
        for(int i=1;i<=sz;i++)
            B[La[i-1]]=(getbit(x,i));
        FOR(i,1,n)
         ans+=cal(x);
         res=min(res,ans);
    }
    cout<<res;
   }
   else cout<<0;
}
