#include <bits/stdc++.h>
#define f first
#define s second
#define il pair<int,int>
#define FOR(i,m,n) for( int i = m; i <= n; ++ i)
#define FORN(i,m,n) for( int i = m; i >= n; -- i)
#define mem(i,n) memset(i,n,sizeof(i))
#define mp make_pair<int,int>
#define pb push_back
#define MOD 1000000007
#define maxn 1000005
using namespace std;

int n,k,a[maxn];
long long suml[maxn],sumr[maxn],maxl[maxn],maxr[maxn];

main()
{
       ios_base::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
        freopen("GIFTS.inp","r",stdin);
        freopen("GIFTS.out","w",stdout);
       cin >> n >> k;
       FOR( i , 1 , n ) cin >> a[i],suml[i] = suml[i-1] + a[i];
       FORN( i , n , 1 ) sumr[i] = sumr[i+1] + a[i];
       FOR( i , 1 , n )
       {
           if( i >= k ) maxl[i] = max( maxl[i-1] , suml[i] - suml[i-k] );
       }
       FORN( i , n , 1 )
       {
           if( n - i + 1 >= k ) maxr[i] = max( maxr[i+1] , sumr[i] - sumr[i + k] );
       }
       long long res = 1e15;
       FOR( i , 1 , n - k )
       {
           res = min(  res , max( maxl[i-1] , maxr[i+k-1] ) );
       }
       cout << res;

}
