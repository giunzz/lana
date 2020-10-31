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
LL n, x[5005];
vector<LL> a[5005];
vector<LL> ed[5005];
vector<LL> la;
LL Time, h[5005],sl;
LL res = 1e18;
LL f[5005];
LL luu;
void Karl_Heinrich_Marx()
{
    freopen("tree.inp","r",stdin);
    freopen("tree.out","w",stdout);

}

void dfs( LL u, LL par )
{
    Time++;
    h[u] = Time;
    LL v;
    for(LL i = 0; i < a[u].size(); i++) {
        v = a[u][i];
        if( v != par ) {
            ed[u].pb(v);
            dfs(v,u);
        }
    }
}

void dfs2( LL u )
{
    LL v = 0;
    for(LL i = 0; i <ed[u].size(); i++) {
        v = ed[u][i];
        dfs2(v);
        f[u]+=f[v];
    }
}
void sub1()
{
    LL tam = 0;
    LL m = (1<<sl) - 1;
    fort(i,0,m) {
        tam = 0;
        fort(i,1,n) f[i] = 0;
        fort(j,0,sl-1) {
            if( (i>>j)&1 ) {
                f[ la[j] ] = 0;
            }
            else f[ la[j] ] = 1;
        }

        dfs2(1);
        fort(i,1,n) {
            tam = tam + abs( x[i] - f[i] );
        }
        if( tam < res ) {
            res = tam; luu = i;
        }
    }
    cout << res;
    /*fort(j,0,sl-1) {
        cerr<<la[j]<<" ";
        if( (luu>>j)&1 ) cerr<<0<<endl; else cerr<<1<<endl;
    }*/
    exit(0);
}

void sub2() {
    LL ans = 0;
    fort(j,0,sl-1) {
        f[ la[j] ] = 1;
    }
    dfs2( 1 );
    fort(i,1,n) {
        if( f[i] < x[i] ) {
            ans = ans + x[i] - f[i];
            x[i] = f[i];
        }
    }
    res = 1e18;
    LL temp = 0;
    srand(time(NULL));
    LL ook =1e6 / n;
    fort(ii,0,ook) {
        temp = 0;
        memset(f,0,sizeof(f));
        fort(j,0,sl-1) {
            f[ la[j] ] =rand()%2;

        }
        dfs2(1);
        fort(i,1,n) {
            temp = temp + abs( x[i] - f[i] );
        }
        res = min( res,temp );
    }

    cout << ans + res;

}

LL u,v;
void Vladimir_Ilyich_Lenin()
{
    cin >>n;
    fort(i,1,n) cin >>x[i];
    fort(i,1,n-1) {
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }

    dfs(1,0);
    fort(i,1,n) {
        if( ed[i].size() == 0 ) {
            sl++;
            la.pb(i);
        }
    }

    if( sl <= 20 ) sub1();
    if( n <= 300 )sub2();
}
int main()
{
    Karl_Heinrich_Marx();
    Vladimir_Ilyich_Lenin();
    return 0;
}
