#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
int n,m,k,a[maxn];
main()
{
    freopen("SEQUENCE.inp","r",stdin);
    freopen("SEQUENCE.out","w",stdout);
    cin >> m >> n >> k;
    for(int i=1; i<=m; ++i)
        cin >> a[i];
    for(int i=m+1; i<=m+n; ++i)
        cin >> a[i];
    sort(a+1,a+1+m+n);
    for(int i=1; i<=k; ++i) cout<<a[i]<<" ";
}
