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

#define maxN 5005

int n , a[maxN] ;
vector<int> ke[maxN] ;

void enter () {
    cin >> n ;
    forinc(i,1,n) cin >> a[i] ;
    forinc(i,1,n-1) {
        int u , v ; cin >> u >> v ;
        ke[u].push_back(v) ;
        ke[v].push_back(u) ;
    }
}

long long f[maxN][maxN] ;

void visit(int u , int p) {
    int cnt = 0 , con[2] ;
    for (auto v : ke[u]) if (v != p) {
        con[cnt ++] =  v ;
        visit(v,u) ;
    }
    if (cnt == 0) f[u][0] = abs(a[u] - 0) , f[u][1] = abs(a[u] - 1) ;
    else if (cnt == 1) forinc(i,0,n) f[u][i] = min(ooll,f[con[0]][i] + abs(a[u] - i)) ;
    else if (cnt == 2)
        forinc(i,0,n)
            forinc(j,0,i) minimize(f[u][i],f[con[0]][j] + f[con[1]][i-j] + abs(a[u]-i)) ;
}

void process () {
    forinc(i,0,n) forinc(j,0,n) f[i][j] = ooll ;
    visit(1,-1) ;
    long long res = ooll ;
    forinc(i,0,n) minimize(res,f[1][i]) ;
    //forinc(i,1,n) cout << f[1][i] << " " ; cout << endl ;
    cout << res << endl ;
}

int main () {
    freopen("TREE.inp" , "r" , stdin) ;
    freopen("TREE.out" , "w" , stdout) ;
    enter () ;
    process() ;
    return 0 ;
}
