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

int a , b ;

void enter () {
    scanf("%d%d" , &a , &b) ;
}

vector<pii> p[2] ;

void factor(int id , int na) {
    for (int i = 2 ; i <= (int) sqrt(na) ; i ++ ) if (na % i == 0) {
        int cnt = 0 ;
        while (na % i == 0) cnt ++ , na /= i ;
        p[id].push_back({i,cnt}) ;
    }
    if (na > 1) p[id].push_back({na,1}) ;
}

void prepare () {
    forinc(i,0,1) p[i].clear() ;
    factor(0,a) ; factor(1,b) ;
    forinc(i,0,1) sort(p[i].begin() , p[i].end()) ;
}

vector<pii> q ;

int get_bit(int x , int i) {return (x >> i) & 1 ; }

void solve() {
    vector<int> g ;
    for (auto tmp : q) if (tmp.se > 0) g.push_back(tmp.fi) ;
    int k = g.size()  , s = (1 << k) - 1 ;
    long long res = ooit , ans_1 = 0 , ans_2 = 0 ;
    forinc(stt,0,s) {
        long long tmp_1 = 1 , tmp_2 = 1 ;
        forinc(i,0,k-1) if (get_bit(stt,i) == 1) tmp_1 *= (long long) g[i] ; else tmp_2 *= (long long) g[i] ;
        if (minimize(res,tmp_1 + tmp_2)) ans_1 = tmp_1  , ans_2 = tmp_2 ;
    }
    cout << ans_1 << " " << ans_2 << endl ;
}

void process () {
    prepare () ; q.clear() ;
    int j = 0 ;
    forinc(i,0,p[0].size()-1) {
        while (j < p[1].size() && p[1][j].fi < p[0][i].fi) q.push_back({p[1][j].fi,p[1][j++].se % 2}) ;
        if (j < p[1].size() && p[1][j].fi == p[0][i].fi) q.push_back({p[0][i].fi , (p[0][i].se + p[1][j++].se) % 2}) ;
        else q.push_back({p[0][i].fi , p[0][i].se % 2}) ;
    }
    while(j < p[1].size()) q.push_back({p[1][j].fi , p[1][j++].se % 2}) ;
    solve() ;
}

int main () {
    freopen("MINSUM.inp" , "r" , stdin) ;
    freopen("MINSUM.out" , "w" , stdout) ;
    int t = 0 ; scanf("%d" , &t) ;
    forinc(i,1,t) enter () , process ()  ;
    return 0 ;
}
