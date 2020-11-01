#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 5555 + 5 ;
const ll base = 1e15 + 7 ;
int n ;
ll a[N] ;
ll f[N][N] ;
vector<int> g[N] ;

ll find_ans(int u , int cha , int gt) {
    if(f[u][gt] != -1) return f[u][gt];
    int sl_con = 0 ;
    int con[4] ;
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(v != cha) {
            sl_con++;
            con[sl_con] = v;
        }
    }
    if(sl_con == 0) { // nut la 0 or 1
        //cerr << " la " << u << endl ;
        if( gt != 0 && gt != 1) f[u][gt] = base ;
        else f[u][gt] = abs(a[u] - gt) ;
    }
    if(sl_con == 1) {
        //cerr << " 1 con " << u << " " << con[1] << endl ;
        f[u][gt] = find_ans( con[1] , u , gt ) + abs(gt - a[u]);
    }
    if(sl_con == 2) {
        //cerr << " 2 con " << u << " " << con[1] << " " << con[2] << endl ;
        f[u][gt] = base;
        for(int i = 0; i <= gt; i++) f[u][gt] = min(f[u][gt] , find_ans(con[1] , u , i) + find_ans(con[2] , u , gt-i) + abs(gt - a[u]) );
    }
    //cerr <<" -----" << u << " " << gt << " " << f[u][gt] << endl ;
    return f[u][gt] ;
}

int main() {
    freopen("TREE.inp" , "r" , stdin ) ; freopen("TREE.out" , "w" , stdout ) ;
    //freopen("xx.inp" , "r" , stdin ) ; freopen("xx.out" , "w" , stdout ) ;
    //ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;
    scanf("%d" , &n);
    for(int i = 1; i <= n; i++) scanf("%lld" , &a[i]);
    int u , v;
    for(int i = 1; i <= n-1; i++) {
        scanf("%d%d" , &u , &v);
        g[u].push_back(v);
        g[v].push_back(u);
        //cerr << u <<  " " << v << endl ;
    }
    memset(f , -1 , sizeof(f));
    ll ans = base;
    for(int i = 0; i <= n; i++) ans = min( ans , find_ans(1 , 1 , i) ) ;//, cerr << f[1][i] << endl ;
    printf("%lld" , ans);
    return 0 ;
}
