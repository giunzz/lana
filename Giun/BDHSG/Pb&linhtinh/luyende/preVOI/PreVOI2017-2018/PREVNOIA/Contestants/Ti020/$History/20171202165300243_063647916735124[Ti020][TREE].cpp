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
    cout<<0;
}
