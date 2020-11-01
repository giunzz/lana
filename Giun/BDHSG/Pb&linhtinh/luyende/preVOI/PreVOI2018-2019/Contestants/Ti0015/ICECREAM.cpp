#include <bits/stdc++.h>
#define f first
#define s second
#define FOR(i,m,n) for( int i = m ; i <= n ; ++ i )
#define FORN(i,m,n) for( int i = m ; i >= n ; -- i )
#define mem(m,n) memset( m , n , sizeof(m) )
#define il pair<int,int>
#define pb push_back
#define mp make_pair
#define MOD 1000000009
#define maxn 100005
using namespace std;

int n,m;
long long dp[20][20][20][20];

main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        freopen( "ICECREAM.inp" , "r" , stdin );
        freopen( "ICECREAM.out" , "w" , stdout );
        cin >> n >> m;
        int a,b,c;
        cin >> a >> b >> c;
        dp[0][a][b][c] = 1;
        FOR( i , 1 , n)
        FOR( x , 0 , m)
        FOR( y , 0 , m )
        FOR( z , 0 , m)
        {
             if( x - 1 >= 0 )
             dp[i][x][y][z] += dp[i-1][x-1][y][z];
             if( y - 1 >= 0 )
             dp[i][x][y][z] += dp[i-1][x+1][y-1][z];
             if( z - 1 >= 0 )
             {
             dp[i][x][y][z] += dp[i-1][x+1][y+1][z-1];
             dp[i][x][y][z] += dp[i-1][x+3][y][z-1];
             }
        }
        long long res = 0;
        FOR( x , 0 , m )
        FOR( y , 0 , m )
        FOR( z , 0 , m ) res = (res + dp[n][x][y][z])%MOD;
        cout << res;
}
