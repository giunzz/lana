#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define F first
#define S second
#define mp make_pair
#define LL long long
#define fort(i,a,b) for(LL i=(a); i<=(b); i++)
#define ford(i,a,b) for(LL i=(a); i>=(b); i--)

using namespace std;
LL n,k;
LL x[100005];
vector< LL > a[100005];
map< pair<LL,LL>,LL > Map;
void Karl_Heinrich_Marx()
{
    #ifndef ONLINE_JUDGE
    freopen("bubbletea.inp","r",stdin);
    freopen("bubbletea.out","w",stdout);
    #endif // ONLINE_JUDGE
}

LL h[100005];
LL f[100005][17];
LL ok[100005];
map< pair<LL,LL>,LL > kc;
void dfs (LL u, LL par)
{

    LL v;
    for(LL i = 0 ; i<a[u].size(); i++) {
        v = a[u][i];
        if(  v!= par) {
            f[v][0] = u;
            ok[v] = ok[u] + Map[ mp(u,v) ];
            h[v] = h[u] + 1;
            fort(j,1,17) {
                f[v][j] = f[ f[v][j-1] ][j-1];
            }
            dfs(v,u);
        }
    }
}

LL LCA( LL u, LL v )
{
    if( h[u] > h[v] ) swap(u,v);
    LL d = h[v] - h[u];
    fort(i,0,17) {
        if( (d>>i) & 1 ) v = f[v][i];
    }
    if( u == v)
    {
        return u;
    }
    ford(i,17,0)
    {
        if( f[u][i] != f[v][i] )
            {
                u = f[u][i];
                v = f[v][i];
            }
    }
    return f[u][0];
}
map< pair<LL,LL>, set< pair<LL,LL> > > limit;
map< pair<LL,LL>,LL > okc;

bool vis[1000005];
bool DFS( LL u, LL v, LL s, LL par ) {
    if( s == v ) return true;
    for(LL j = 0 ; j<a[s].size(); j++) {
        if( a[s][j] != par ) {
            if( DFS( u,v,a[s][j],s ) == true ) {
              //  if(u==1&&v==7)cerr<<u<<" "<<v<<" "<<a[s][j]<<" "<<s<<endl;
                okc[ mp( s, a[s][j] ) ] = 1;
                okc[ mp( a[s][j], s ) ] = 1;
                return 1;
            }
        }
    }
    return false;
}

bool KT( LL u, LL v, LL s, LL par )
{

    if( s == v ) return false;
    for(LL j = 0 ; j<a[s].size(); j++ ){
        if( a[s][j] != par ) {
            if( okc.find( mp(s, a[s][j] )) == okc.end() )
            if( KT(u,v,a[s][j],s) == false ) return false;
        }
    }
    return true;
}
void xuly( LL u, LL v )
{
    okc.clear();
    //cerr<<u<<" "<<v<<endl;
    DFS( u,v,u,0 );
    fort(i,1,k)
    {
        fort(j,i+1,k)
        {
            if( (x[i] == u && x[j] == v) || ( x[j] == u && x[i] == v ) ) continue;
            if( KT( x[i], x[j], x[i],0 ) ) {

                    limit[ mp(u,v) ].insert( mp(x[i],x[j]) );
                    limit[ mp(u,v) ].insert( mp(x[j],x[i]) );
                   // cout<<u<<" "<<v<<" "<<x[i]<<" "<<x[j]<<endl;
            }
        }
    }

    limit[ mp(v,u) ] = limit[ mp(u,v) ];

}

LL u, v, w;
void Vladimir_Ilyich_Lenin()
{
    scanf("%lld %lld",&n,&k);
    fort(i,1,k) {
        scanf("%lld",&x[i]);
    }
    fort(i,1,n-1) {
        scanf("%lld %lld %lld",&u,&v,&w);
        a[u].pb( v );
        a[v].pb(u);
        Map[ mp(u,v) ] = w;
        Map[ mp(v,u) ] = w;
    }
    dfs(1,0);
    LL tmp, tam;
    fort(i,1,k) {
        fort(j,i+1,k)
        {
            tmp = LCA( x[i], x[j] );
            tam = ok[ x[i] ] + ok[ x[j] ] - 2*ok[ tmp ];

            kc[ mp( x[i], x[j] ) ] = kc[ mp(  x[j], x[i]) ] = tam;
        }
    }

    fort(i,1,k) {
        fort(j,i+1,k) {
            xuly( x[i], x[j] );
           // cerr<<x[i]<<" "<<x[j]<<endl;
        }
    }
    LL ans = 1e18;

    sort( x+1,x+k+1 );
    do {
        tmp = 0;
        for(LL i = 1; i<k; i+=2)
        {
            for(LL j=i+2; j<k; j+=2)
            {
                if( limit[ mp( x[i], x[i+1] ) ].find( mp( x[j], x[j+1] ) ) != limit[ mp( x[i], x[i+1] ) ].end() ) goto out;
                tmp = max( tmp, kc[ mp(x[i], x[i+1]) ] );
            }
        }
     //   cerr<<tmp<<endl;
        ans = min( ans, tmp );
        out:;
    } while( next_permutation( x+1,x+k+1 ) );
    printf("%lld",ans);

}
int main()
{
    Karl_Heinrich_Marx();
    Vladimir_Ilyich_Lenin();
    return 0;
}
