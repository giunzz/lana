#include <iostream>
#include<bits/stdc++.h>
#define LL long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define filename "GIFTS."
using namespace std;
typedef pair<LL,LL> ii;
const int maxN=1e6+3;
int n,k;
int A[maxN];
LL sum[maxN];
vector<ii> B;
void io()
{
    freopen(filename"INP","r",stdin);
    freopen(filename"OUT","w",stdout);
}
bool cmp(ii a,ii b)
{
    return a.first>=b.first;
}
main()
{
    io();
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",&A[i]);
    sum[0]=0;
    FOR(i,1,n) sum[i]=A[i]+sum[i-1];
    FOR(i,k,n)
    {
        LL my=sum[i]-sum[i-k];
        B.push_back(ii(my,i));
    }
    sort(B.begin(),B.end(),cmp);
    LL ans=1e13;
    for(int i=0;i<B.size();i++)
    {
        LL R=0;
        LL cam=B[i].first;
        while(B[R].second==B[i].second+1||B[R].second==B[i].second+1||R==i) R++;
        if(B[R].first<=cam) ans=min(ans,B[R].first);
    }
    cout<<ans;
}
