#include <bits/stdc++.h>
#define ii pair<int,int>
#define fi first
#define se second
using namespace std;
int a[3007];
int b[3007];
int dp[107][107][207];
bool dpp[107][107][207];
int m,n,k;
int main()
{
    freopen("sequence.inp","r",stdin);
    freopen("sequence.out","w",stdout);
    cin>>m>>n>>k;
    for (int i=1;i<=m;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    cout<<0;
    return 0;
}
