#include <bits/stdc++.h>
#define f first
#define s second
#define FOR(i,m,n) for( int i = m ; i <= n ; ++ i )
#define FORN(i,m,n) for( int i = m ; i >= n ; -- i )
#define mem(m,n) memset( m , n , sizeof(m) )
#define il pair<int,int>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define maxn 100005
using namespace std;

int n,m,k,a[85][85],trace[305][305];
long long dp[305][305],ndp[305][305];
vector<il> In;

main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        freopen( "TABLE.inp" , "r" , stdin );
        freopen( "TABLE.out" , "w" , stdout );
        cin >> n >> m >> k;
        FOR( i , 1 , n )
        FOR( j , 1 , m ) cin >> a[i][j];
        il str,endd;
        int l,r;
        FOR( q , 1 , k )
        {
             In.clear();
             cin >> str.f >> str.s >> endd.f >> endd.s;
             FOR( i , str.f , endd.f ) dp[i][str.s-1] = -MOD;
             FOR( i , str.s , endd.s ) dp[str.f-1][i] = -MOD;
             dp[str.f-1][str.s] = dp[str.f][str.s-1] = 0;
             FOR( i , str.f , endd.f )
             FOR( j , str.s , endd.s )
             {
                  if( dp[i-1][j] > dp[i][j-1] )
                  {
                       dp[i][j] = dp[i-1][j] + a[i][j];
                       trace[i][j] = 1;
                  }
                  else
                  {
                      dp[i][j] = dp[i][j-1] + a[i][j];
                      trace[i][j] = 2;
                  }
             }
             l = endd.f,r = endd.s;
             if( trace[l][r] == 1 ) l--;
             else r--;
             while( l != str.f || r != str.s )
             {
                  In.pb( mp( l , r ) );
                  if( trace[l][r] == 1 ) l--;
                  else r--;
             }
             long long res = 1e18;
             FOR( k , 0 , (int)In.size() - 1 )
             {
                   FOR( i , In[k].f , endd.f ) ndp[i][In[k].s-1] = dp[i][In[k].s-1];
                   FOR( j , In[k].s , endd.s ) ndp[In[k].f-1][j] = dp[In[k].f-1][j];
                   FOR( i , In[k].f , endd.f )
                   FOR( j , In[k].s , endd.s )
                   {
                             ndp[i][j] = max( ndp[i-1][j] , ndp[i][j-1] ) + a[i][j]*( i != In[k].f || j != In[k].s );
                   }
                   res = min( res , ndp[endd.f][endd.s] );
             }
             cout << res << '\n';
        }
}
