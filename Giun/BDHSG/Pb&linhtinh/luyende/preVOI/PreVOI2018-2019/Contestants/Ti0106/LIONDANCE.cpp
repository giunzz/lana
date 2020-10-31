#include <bits/stdc++.h>
#define mn 4005
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORE(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int n,t;
int a[mn],b[mn],f[mn][mn],c[2*mn];
void nhap()
{
    cin>>n>>t;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n) cin>>b[i];
    FOR(i,1,n)
    FOR(j,1,n)
    {
        f[i][j]=max(f[i-1][j],f[i][j-1]);
        if(a[i]==b[j])
        {
            f[i][j]=max(f[i][j],1);
            FOR(k,1,i-1)
            if(abs(a[i]-a[k])<=t&&f[k][j-1]>f[k-1][j-1])
            {
                f[i][j]=max(f[i][j],f[k][j-1]+1);
            }
        }
    }
    cout<<f[n][n];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("LIONDANCE.inp","r",stdin);
    freopen("LIONDANCE.out","w",stdout);
    nhap();
    return 0;
}
