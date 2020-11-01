#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define maxn 1000005
#define mp make_pair

using namespace std;
const long long oo = 1000000000000005;
int n,k,a[maxn],pos;
long long res = oo , s[maxn] , t1[4*maxn] , sum[maxn];
void Init( int node, int l, int r )
{
    if ( l==r )
    {
        t1[node] = sum[l];
        return;
    }
    int g = ( l + r )/2;
    Init( node*2, l, g );
    Init( node*2 + 1, g + 1, r );
    t1[node] = max( t1[node*2], t1[node*2 + 1]);
}

long long Gett( int node, int l, int r, int u, int v )
{
    if ( u > r || v < l ) return 0;
    if ( u <= l && v >= r ) return t1[node];
    int g = ( l + r )/2;
    long long trai = Gett( node*2, l, g, u, v);
    long long phai = Gett( node*2+1, g+1, r, u, v );
    return max(trai,phai);

}
void s1()
{
    for ( int i = 1 ; i<=n ; i++ ) s[i] = s[i-1] + a[i];
    for ( int i = 1 ; i<=n - k + 1 ; i++ )
    {
        long long maxx = 0;
        for ( int j = 1 ; j<=n - k + 1 ; j++ )
        {
            if ( j + k - 1 >= i && j + k -1 <= i + k ) continue;
            else
            {
                long long sl = s[j + k -1 ] - s[j - 1];
                maxx = max( sl,maxx  );
            }
        }
        if ( res < maxx ) pos = i;
        res = min( res, maxx );
    }
    cout << res ;
}


main()
{
    ios_base::sync_with_stdio(0);
    freopen("GIFTS.inp","r",stdin);
    freopen("GIFTS.inp","r",stdin);
    cin >> n >> k;
    for ( int i = 1 ; i<=n ; i++ ) cin >> a[i];
    if ( n <= 5000 ) s1();
    //s1();
    else
    {
        for ( int i = 1 ; i<=k ; i++ ) sum[1] += a[i];
        int cnt = 1;
        for ( int i = k + 1 ; i<=n ; i++ )
        {
            sum[++cnt] = sum[cnt-1] + ( a[i] - a[i-k] );
        }
        Init(1,1,n-k+1);
        res = INT_MAX;
        for ( int j = 1 ; j<=n - k + 1 ; j++ )
        {
            long long maxx = 0;
            //int val1 = Gett(1,1,n-k+1,)
            if ( j >= k + 1 && j <= n - k - 1)
            {
                long long val1 = Gett(1,1,n-k+1,1,j - 2);
                long long val2 = Gett(1,1,n-k+1,j + k,n);
                maxx = max(val1, val2);
                res = min( res, maxx );
            }
            if ( j<=k )
            {
                long long val = Gett(1,1,n-k+1,j+k,n);
                res = min( res, val );
            }
            if ( j >= n - k  )
            {
                long long val = Gett(1,1,n-k+1,1,j-2);
                res = min( res, val );
            }
        }
        cout << res;
    }
}
