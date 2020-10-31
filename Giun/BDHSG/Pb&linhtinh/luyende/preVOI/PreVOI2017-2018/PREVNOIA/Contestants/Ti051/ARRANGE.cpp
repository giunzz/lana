#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define maxn 1000005
#define mp make_pair

using namespace std;

pii f[maxn];
int a[maxn],n, cp = 0,sum = 0;


main()
{
    ios_base::sync_with_stdio(0);
    freopen("ARRANGE.inp","r",stdin);
    freopen("ARRANGE.out","w",stdout);
    cin >> n;
    for ( int i = 1 ; i<=n ; i++ )
    {
        cin >> a[i];
        sum += a[i];
    }
    int x  = sum / n ;
    for ( int i = 1 ; i<=n ; i++ )
    {
        if ( a[i] > x ) f[i].fi = 1, f[i].se = i;
        if ( a[i] == x ) f[i].fi = 2, f[i].se = i;
        if ( a[i] < x ) f[i].fi = 0, f[i].se = i;
    }
    sort ( f  + 1, f + n + 1 );
    int moc = lower_bound( f + 1,f + n + 1, mp(1,0) ) - f;
    int r = moc;
    for ( int i = 1 ; i<=moc ; i++ )
    {
        for ( int j = r ; j<=n ; j++ )
        {
            if ( f[j].fi == 2 ) break;
            int p = x - a[f[i].se];
            int q =  a[f[j].se] - x;
            int sl = min( q,p );
            if ( sl == p )
            {
                //i ++;
                a[f[j].se] -= sl;
                a[f[i].se] += sl;
                cp += sl*abs(f[j].se - f[i].se);
                if ( sl == q ) j++;
                break;
            }
            else
            {
                if ( sl == q )
                {
                    r ++;
                    a[f[j].se] -= sl;
                    a[f[i].se] += sl;
                    cp += sl*abs(f[j].se - f[i].se);
                }
            }
        }

    }
    cout << cp;

}
