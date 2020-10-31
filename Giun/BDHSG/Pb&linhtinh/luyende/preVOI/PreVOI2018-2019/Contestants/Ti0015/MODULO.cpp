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

int A,B,n,p[46],str,endd,na,nb;
long long mod = 1,gt[45],k;
pair< long long , int > a[(1 << 20) + 5],b[(1 << 20) + 5];

void solve( int h )
{
        if( h > endd )
        {
              long long cur = 0;
              int id = 0;
              FOR( i , str , endd )
              {
                   if( p[i] ) cur = (cur*10+B)%mod,id += (1 << (i - str));
                   else cur = (cur*10+A)%mod;
              }
              if( str > 1 ) b[++nb] = mp( cur , id );
              else a[++na] = mp( cur*gt[n-n/2]%mod , id );
              return;
        }
        p[h] = 0;
        solve( h + 1 );
        p[h] = 1;
        solve( h + 1 );
}

main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        freopen( "MODULO.inp" , "r" , stdin );
        freopen( "MODULO.out" , "w" , stdout );
        cin >> A >> B >> n >> k;
        FOR( i , 1 , n ) mod = mod*2;
        gt[0] = 1;
        FOR( i , 1 , n ) gt[i] = gt[i-1]*10%mod;
        str = 1,endd = n/2;
        solve( 1 );
        str = n/2+1,endd = n;
        solve( str );
        sort( b + 1 ,b + nb + 1 );
        long long cur;
        int u;
        FOR( i , 1 , na )
        {
             cur = (k - a[i].f + mod)%mod;
             u = lower_bound( b + 1 , b + nb + 1 , mp( cur , 0 ) ) - b;
             if( b[u].f == cur )
             {
                  FOR( j , 0 , n/2 - 1 )
                  {
                      if( ((a[i].s >> j) & 1) == 1 ) cout << B;
                      else cout << A;
                  }
                  FOR( j , 0 , n/2 + n%2 - 1 )
                  {
                       if( (( b[u].s >> j ) & 1 ) == 1 ) cout << B;
                       else cout << A;
                  }
                  exit(0);
             }
        }
        cout << -1;
}
