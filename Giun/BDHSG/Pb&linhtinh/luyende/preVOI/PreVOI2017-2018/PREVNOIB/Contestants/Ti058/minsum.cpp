#include<bits/stdc++.h>
using namespace std;
const int base=32000;
bool prime[base];
int num[3500], d[3500], trace[3500];
int t, n;
void prepare()
{
    memset(prime, 0, sizeof(prime));
    for ( int i=2; i<base; i++ )
        if ( prime[i]==0 )
        {
            long long j=i*i;
            while ( j<base )
                prime[j]=1, j+=i;
        }
    n=0;
    for ( int i=2; i<base; i++ )
        if ( prime[i]==0 )  n++, d[n]=i;
}
int main()
{
    freopen("minsum.inp","r",stdin);
    freopen("minsum.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;   prepare();
    while ( t-- )
    {
        int x, y, k=0;
        long long c1, c2, res=1;
        cin >> x >> y;
        memset(num, 0, sizeof(num));
        for ( int i=1; i<=n; i++ )
            while ( x%d[i]==0 )
                num[i]++, x=x/d[i];
        for ( int i=1; i<=n; i++ )
            while ( y%d[i]==0 )
                num[i]++, y=y/d[i];
        for ( int i=1; i<=n; i++ )
        {
            num[i]=num[i]%2;
            if ( num[i]==1 )
            {
                k++; res=res*d[i]; trace[k]=d[i];
            }
        }
        res++; c1=1; c2=res-1;
        for ( int mask=0; mask<(1<<k); mask++ )
        {
            long long a=1, b=1;
            for ( int i=1; i<=k; i++ )
            {
                if ( mask&(1<<(i-1)) ) a=a*trace[i];
                else b=b*trace[i];
            }
            if ( a+b<res )
            {
                res=a+b; c1=a, c2=b;
            }
        }
        cout << c1 << ' ' << c2 << '\n';
    }
}
