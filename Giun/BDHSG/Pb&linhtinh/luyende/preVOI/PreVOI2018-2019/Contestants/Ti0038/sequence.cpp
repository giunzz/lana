#include <bits/stdc++.h>

using namespace std;
int n,m,k,a[10005],b[10005],j=0;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("sequence.inp","r",stdin);
     freopen("sequence.out","w",stdout);
     cin>>n>>m>>k;
     for (int i=1;i<=n;i++) cin>>a[i];
     for (int i=1;i<=m;i++) cin>>b[i];
    for (int i=1;i<=m;i++)
        if (j==k-1) {cout<<a[i]<<" ";break;} else if (j<k) cout<<a[i]<<" "<<b[i]<<" ";j+=2;
}
