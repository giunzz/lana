#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 3e3 + 10;
LL it[4*N], a[2][N], hs[2][N], ss[2*N], res[2*N], Pow[2*N], ts, n, m, k, cmp, sz, ok, tmp, f[N], g[N];
set<int> st[2][N];

void built(LL x, LL l, LL r, LL typ) {
    if( l == r ) {
        it[x] = l; return;
    }
    LL mid = (l + r) / 2;
    built(2*x,l,mid,typ);
    built(2*x + 1,mid + 1, r, typ);
    if( a[typ][ it[2*x] ] <= a[ typ ][ it[2*x + 1] ] ) it[x] = it[2*x];
    else it[x] = it[2*x + 1];
}

LL get(LL x, LL l, LL r, LL i, LL j, LL typ) {
    if( l > j || r < i ) return 0;
    if( i <= l && r <= j ) return it[x];
    LL mid = (l + r) / 2;
    LL tmp1 = get(2*x, l, mid, i, j, typ);
    LL tmp2 = get(2*x + 1, mid + 1, r, i, j, typ);
    if( a[typ][tmp1] <= a[typ][tmp2] ) return tmp1;
    return tmp2;
}

LL geth( LL typ, LL l, LL r ) {
    return ( hs[typ][r] - hs[typ][l - 1]*Pow[r - l + 1] );
}

int main() {
    freopen("SEQUENCE.inp","r",stdin);
    freopen("SEQUENCE.out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for(LL i = 1; i <= n; ++ i)
        cin >> a[0][i], ts = max( ts, a[0][i] );
    for(LL j = 1; j <= m; ++ j)
        cin >> a[1][j], ts = max( ts, a[1][j] );
    ++ ts;
    Pow[0] = 1;
    for(LL i = 1; i <= k; ++ i) Pow[i] = Pow[i-1] * ts;
    a[0][0] = ts;
    a[1][0] = ts;
    built(1,1,n,0);
    st[0][0].insert(0); st[0][0].insert(n + 1);
    set<int>::iterator it, it1;
    for(LL i = 1; i <= n; ++ i) {
        st[0][i] = st[0][i-1];
        it = st[0][i].end();
        -- it;
        while( it != st[0][i].begin() ) {
            it1 = it; -- it1;
            if( (*it1 + 1) != (*it) ) break;
            -- it;
        }
        it1 = it; -- it1;
        tmp = get( 1, 1, n, (*it1) + 1, (*it) - 1, 0 );
        st[0][i].insert(tmp);
    }
    built(1,1,m,1);
    st[1][0].insert(0); st[1][0].insert(m + 1);
    for(LL i = 1; i <= m; ++ i) {
        st[1][i] = st[1][i-1];
        it = st[1][i].end();
        -- it;
        while( it != st[1][i].begin() ) {
            it1 = it; -- it1;
            if( (*it1 + 1) != (*it) ) break;
            -- it;
        }
        it1 = it; -- it1;
        tmp = get( 1, 1, m, (*it1) + 1, (*it) - 1, 1 );
        st[1][i].insert(tmp);
    }

    for(LL i = 0; i <= n; ++ i) st[0][i].erase(0), st[0][i].erase(n + 1);
    for(LL i = 0; i <= m; ++ i) st[1][i].erase(0), st[1][i].erase(m + 1);
    LL x,y,cnta,cntb,_x,_y,d,c,mid;
    ok = 0;
    for(LL i = 0; i <= min(k,n); ++ i) {
        x = i; y = k - i; sz = 0;
        if( y > m ) continue;
        cnta = 0;
        for(LL i: st[0][x]) f[++ cnta] = i;
        cntb = 0;
        for(LL i: st[1][y]) g[++ cntb] = i;
        f[++ cnta] = 0;
        g[++ cntb] = 0;
        for(LL i = 1; i <= cnta; ++ i) hs[0][i] = hs[0][i-1]*ts + a[0][ f[i] ];
        for(LL i = 1; i <= cntb; ++ i) hs[1][i] = hs[1][i-1]*ts + a[1][ g[i] ];
        _x = 1; _y = 1;
        while( _x < cnta && _y < cntb ) {
            d = 1, c = min( cnta - _x, cntb - _y );
            while(d < c) {
                mid = (d + c) / 2;
                if( geth(0, _x, _x + mid - 1) != geth(1, _y, _y + mid - 1) ) c = mid;
                else d = mid + 1;
            }
            if( a[0][ f[ _x + d - 1 ] ] <= a[1][ g[_y + d - 1] ] ) ss[++ sz] = a[0][ f[_x] ], ++ _x;
            else ss[ ++ sz ] = a[1][ g[_y] ], ++ _y;
        }
        while(_x < cnta) {
            ss[++ sz] = a[0][ f[_x] ]; ++ _x;
        }
        while(_y < cntb) {
            ss[++ sz] = a[1][ g[_y] ]; ++ _y;
        }

        if( ok == 0 ) {
            for(LL i = 1; i <= sz; ++ i) res[i] = ss[i];
            ok = 1;
        }
        else {
            cmp = 0;
            for(LL i = 1; i <= sz; ++ i) {
                if( res[i] < ss[i] ) {
                    cmp = 0; break;
                }
                if( res[i] > ss[i] ) {
                    cmp = 1; break;
                }
            }

            if( cmp ) {
                for(LL i = 1; i <= sz; ++ i) res[i] = ss[i];
            }

        }

    }


    for(LL i = 1; i <= k; ++ i) {
        cout << res[i] << " ";
    }
    return 0;
}
