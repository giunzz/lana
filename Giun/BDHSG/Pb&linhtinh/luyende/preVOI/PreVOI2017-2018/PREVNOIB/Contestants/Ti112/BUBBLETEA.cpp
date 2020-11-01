#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mk make_pair
#define pii pair<int,int>
#define ooll (long long) 1e15
#define ooit (int) 2e9

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

#define maxN 50005

int n , k , a[maxN] , L = 0 ;
vector<pii> ke[maxN] ;

void enter () {
    scanf("%d%d" , &n , &k) ; L = log2(n) ;
    forinc(i,1,k) scanf("%d" , &a[i]) ; sort(a + 1 , a + 1 + k) ;
    forinc(i,1,n-1) {
        int u , v , c  ; scanf("%d%d%d" , &u , &v , &c) ;
        ke[u].push_back({v,c}) ; ke[v].push_back({u,c}) ;
    }
}

int cnt = 0 , stin[maxN] , stout[maxN] , f[maxN][20] , par[maxN] ;
long long d[maxN] ;

void visit(int u , int p) {
    stin[u] = ++cnt ;
    forinc(i,1,L) f[u][i] = f[f[u][i-1]][i-1] ;
    for (auto v : ke[u]) if (v.fi != p) f[v.fi][0] = u , par[v.fi] = u , d[v.fi] = d[u] + v.se ,  visit(v.fi,u) ;
    stout[u] = ++cnt ;
}

bool anc(int u , int v) {return stin[u] <= stin[v] && stout[u] >= stout[v] ; }

int LCA(int u , int v) {
    if (anc(u,v)) return u ;
    if (anc(v,u)) return v ;
    fordec(i,L,0) if (!anc(f[u][i],v)) u = f[u][i] ;
    return f[u][0] ;
}

long long solve() {
    long long res = 0 ;
    forinc(i,1,k) if (i % 2 != 0) {
        int p = LCA(a[i],a[i+1]) ;
        maximize(res,d[a[i]]  + d[a[i+1]] - 2 * d[p]) ;
    }
    return res ;
}

void process () {
    f[1][0] = 1 ;
    visit(1,-1) ;
    long long res = ooll ;
    do {
        minimize(res,solve()) ;
    } while (next_permutation(a + 1 , a + 1 + k)) ;
    cout << res << endl ;
}

int main () {
    freopen("BUBBLETEA.inp" , "r" , stdin) ;
    freopen("BUBBLETEA.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
