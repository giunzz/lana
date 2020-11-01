#include <bits/stdc++.h>
#define f first
#define s second
#define il pair<int,int>
#define FOR(i,m,n) for( int i = m; i <= n; ++ i)
#define FORN(i,m,n) for( int i = m; i >= n; -- i)
#define mem(i,n) memset(i,n,sizeof(i))
#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define maxn 100005
using namespace std;

int n,k,p[maxn],cnt,dd[maxn],f1[maxn],pp[15];
long long res = 1e12,d[15][15];

vector<il> a[maxn];

void dfs( int h )
{
    dd[h] = cnt;
    int n = a[h].size() - 1;
    //cout << a[h][0].f << dd[2] << key << endl;
    FOR( i , 0 , n )
    {
        if( dd[a[h][i].f] < cnt )
        {
            d[cnt][a[h][i].f] = d[cnt][h] + a[h][i].s;
            dfs( a[h][i].f );
        }
    }
}

void check( int h )
{
    if( h > k )
    {
        long long x = 0;
        mem( pp , 0);
         FOR( i , 1 , k )
         {
             if( !pp[dd[i]] ) pp[dd[i]] = p[i];
             else x = max( x , d[pp[dd[i]]][p[i]] );
         }
         res = min( res , x );
         return;
    }
    FOR( i , 1 , k/2 )
    {
         if( f1[i] < 2 )
         {
             dd[h] = i;
             f1[i]++;
             check( h + 1 );
             f1[i]--;
         }
    }
}

main()
{
       ios_base::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
        freopen("BUBBLETEA.inp","r",stdin);
        freopen("BUBBLETEA.out","w",stdout);
       cin >> n >> k;
       FOR( i , 1 , k ) cin >> p[i];
       int x,y,v;
       FOR( i ,1 , n - 1 )
       {
           cin >> x >> y >> v;
           a[x].pb( il( y , v ) );
           a[y].pb( il( x , v ) );
       }
       FOR( i , 1 , n )
       {
            cnt = i;
            dfs( i );
       }
       mem( dd , 0 );
       dd[1] = 1;
       f1[1] = 1;
       check( 2 );
       cout << res;
}
