#include <iostream>
#include<bits/stdc++.h>
#define LL long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define filename "ARRANGE."
using namespace std;
typedef pair<LL,LL> ii;
const int maxN=1e5+3;
LL n;
LL A[maxN];
LL sums;
void io()
{
    freopen(filename"INP","r",stdin);
    freopen(filename"OUT","w",stdout);
}
main()
{
    io();
    cin>>n;
    FOR(i,1,n) {
        cin>>A[i];
        sums+=A[i];
    }
    if(sums%n==0)
    {
        LL ans=0;
        int sl=sums/n;
        for(int i=1;i<=n;i++) if(A[i]>sl) ans+=A[i]-sl;
        cout<<ans<<endl;
        return 0;
    }
    else
    {
        LL ans=0;
        int my=sums%n;
        int sl=sums/n;
        for(int i=1;i<n;i++) if(A[i]<sl+1)
        {
            A[i]=sl+1;
            A[i+1]=A[i+1]-sl-1+A[i];
            ans+=A[i]-sl;
        }
        cout<<ans-1<<endl;
        return 0;
    }
}
