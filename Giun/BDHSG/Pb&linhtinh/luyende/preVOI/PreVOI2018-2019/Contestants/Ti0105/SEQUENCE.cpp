#include <bits/stdc++.h>

using namespace std;

const int maxn=3011;

int n, m, k, a[maxn], b[maxn];

int main()
{
    freopen("SEQUENCE.INP", "r", stdin);
    freopen("SEQUENCE.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1; i<=n; i++) cin>>a[i];
    for (int i=1; i<=m; i++) cin>>b[i];
    sort(a+1, a+n+1);
    sort(b+1, b+m+1);
    for (int i=1; i<=min(n, k); i++) cout<<a[i]<<" ";
    if (n<k) for (int i=1; i<=k-n; i++) cout<<b[i]<<" ";
    return 0;
}
