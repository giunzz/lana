#include <bits/stdc++.h>
using namespace std;
const int maxn=3002;
int n,m,k,a[maxn],b[maxn];
int c[maxn*2],cc;
main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    freopen("SEQUENCE.INP","r",stdin);
    freopen("SEQUENCE.OUT","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=m;++i) cin>>b[i];
    if(k==1)
    {
        int mn=INT_MAX;
        for(int i=1;i<=n;++i) mn=min(mn,a[i]);
        for(int i=1;i<=m;++i) mn=min(mn,b[i]);
        cout<<mn;
        return 0;
    }
    for(int i=1;i<=n;++i) c[++cc]=a[i];
    for(int i=1;i<=m;++i) c[++cc]=b[i];
    sort(c+1,c+cc+1);
    for(int i=1;i<=k;++i) cout<<c[i]<<' ';
}
