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
#define maxn 100005
using namespace std;

int n,a[maxn],key = 0,b[maxn];
stack<int> big,small;

main()
{
       ios_base::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
        freopen("ARRANGE.inp","r",stdin);
        freopen("ARRANGE.out","w",stdout);
       cin >> n;
       FOR( i , 1 , n ) cin >> a[i],key += a[i],b[i] = a[i];
       double k = double(key)/n;
       key = key/n;
       int x,y,u;
       if( k == key)
       {
           int res = 0;
        FOR( i , 1 , n )
       {
            if( a[i] > key ) big.push( i );
            if( a[i] < key ) small.push( i );
       }
       while( !small.empty() && !big.empty() )
       {
             x = big.top();
             y = small.top();
             small.pop();
             big.pop();
             u = min( a[x] - key , key - a[y] );
             a[x] -= u;
             a[y] += u;
             res += u*abs( x - y );
             if( a[x] > key ) big.push( x );
             if( a[y] < key ) small.push( y );
       }
       cout << res;
       }
       else
       {
           int res = 0;
           FOR( i , 1 , n )
       {
            if( a[i] > key ) big.push( i );
            if( a[i] < key ) small.push( i );
       }
        while( !small.empty() && !big.empty() )
       {
             x = big.top();
             y = small.top();
             small.pop();
             big.pop();
             u = min( a[x] - key , key - a[y] );
             a[x] -= u;
             a[y] += u;
             res += u*abs( x - y );
             if( a[x] > key ) big.push( x );
             if( a[y] < key ) small.push( y );
       }
       int res1 = 0;
       key++;
       while( !big.empty() ) big.pop();
       while( !small.empty() ) small.pop();
       FOR( i , 1 , n )
       {
            if( b[i] > key ) big.push( i );
            if( b[i] < key ) small.push( i );
       }
        while( !small.empty() && !big.empty() )
       {
             x = big.top();
             y = small.top();
             small.pop();
             big.pop();
             u = min( b[x] - key, key - b[y] );
             b[x] -= u;
             b[y] += u;
             res1 += u*abs( x - y );
             if( b[x] > key ) big.push( x );
             if( b[y] < key ) small.push( y );
       }
       cout << min( res , res1 );
       }
}
