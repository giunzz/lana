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

int T,a,b,d[105],cnt = 0,dd[105],k,p[maxn],pp[maxn],res;
il result;

void Init()
{
    int x;
    FOR( i , 2 , 55 )
    {
         if( !dd[i] )
            {
                x = 2;
                while( x*i <= 50 ) dd[x*i] = 1,x++;
            }
    }
    FOR(i , 2 , 55 )
    {
        if( !dd[i] ) d[++cnt] = i;
    }
}

void check( int h )
{
    if( h > k )
    {
        int res1 = 1,res2 = 1;
         FOR( i , 1 , k )
         {
               if( pp[i] == 0 ) res1 = res1*p[i];
               else res2 = res2*p[i];
         }
         if( res > res1 + res2 )
         {
             res = res1 + res2;
             result.f = res1; result.s = res2;
         }
         return;
    }
    pp[h] = 0;
    check( h + 1);
    pp[h] = 1;
    check( h + 1);
}

main()
{
       ios_base::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
        freopen("MINSUM.inp","r",stdin);
        freopen("MINSUM.out","w",stdout);
       cin >> T;
       Init();
       while( T )
       {
            cin >> a >> b;
            mem( dd, 0 );
            int dem = 0;
            k = 0;
            FOR( i , 1 , cnt)
            {
                 if( a%d[i] == 0 )
                 {
                     dem = 0;
                     while( a%d[i] == 0 ) a/=d[i],dem++;
                     if( dem % 2 == 1 ) dd[d[i]] = 1;
                 }
            }
            FOR( i , 1 , cnt )
            {
                 if( b%d[i] == 0 )
                 {
                     dem = 0;
                     while( b%d[i] == 0 ) b/=d[i],dem++;
                     if( dem % 2 == 1 ) dd[d[i]] ++;
                 }
            }
            FOR( i , 1 , 50 )
            {
                if( dd[i] == 1 ) p[++k] = i;
            }
            if( k == 0 ) { cout << 1 << " " << 1 << "\n"; T--; continue; }
            if( k == 1 ) { cout << p[1] << " " << 1 << "\n"; T--; continue; }
            res = INT_MAX;
            check( 2 );
            cout << result.f << " " << result.s << "\n";
            T--;
       }
}
