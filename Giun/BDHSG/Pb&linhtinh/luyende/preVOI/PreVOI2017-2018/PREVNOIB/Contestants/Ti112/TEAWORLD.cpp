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

#define maxM 2005
#define maxN 20

int n , m , k ;
struct node {
    int x , y , z , w ;
};
node disco[maxM] , tea[maxN] , PVH;

void enter () {
    scanf("%d%d%d" , &m , &n , &k) ;
    forinc(i,1,m) scanf("%d%d%d%d" , &disco[i].x , &disco[i].y , &disco[i].z , &disco[i].w) ;
    forinc(i,1,n) scanf("%d%d%d%d" , &tea[i].x , &tea[i].y , &tea[i].z , &tea[i].w) ;
    scanf("%d%d%d" , &PVH.x , &PVH.y , &PVH.z) ;
}


///_______________________________________________________________________________________________________________________________________///
///_____________________________________________________SUB1______________________________________________________________________________///
///__________________________________________________________________________________________________________________________________///

int get_bit(int x , int i) {return (x >> i) & 1 ; }

set<int> nxt[2005] ;

int check(int st) {
    forinc(i,0,2000) nxt[i].clear() ;

    forinc(i,1,m)
        nxt[disco[i].x - disco[i].w-1].insert(disco[i].x + disco[i].w+1) , nxt[disco[i].x + disco[i].w+1].insert(disco[i].x - disco[i].w - 1) ;
    int cnt = 0 , res =0 ;
    forinc(i,1,n) if (get_bit(st,i-1) == 1) {
        int tlow = min(tea[i].x , PVH.x)  , thigh = max(tea[i].x , PVH.x) ;
        forinc(j,tlow,thigh) while(!nxt[j].empty()) {
            cnt += nxt[j].size() ; int u = *nxt[j].begin() ;
            nxt[u].erase(j) ;
            nxt[j].clear() ;
        }
        res += tea[i].w ;
    }
    return (cnt > k)  ? -1  : res ;
}

void sub1() {
    int _ = (1 << n) - 1  , res = 0 ;
    forinc(stt , 0 , _) maximize(res,check(stt)) ;
    cout << res << endl ;
}

///__________________________________________________________________________________________________________________________________///
///______________________________________________PROCESS_____________________________________________________________________________///
///__________________________________________________________________________________________________________________________________///

void best_algorthim() {
    int _ = 1 << n - 1 , res = 0 ;
    forinc(i,0,44) {
        int st = rand() % _ , tmp = 0 ;
        forinc(i,1,n) if (get_bit(st,i-1) == 1) tmp += tea[i].w ;
        maximize(res,tmp) ;
    }
    cout << res << endl ;
}

void exact() {
    forinc(i,1,m) disco[i].x += 1000 , disco[i].y += 1000 , disco[i].z += 1000 ;
    forinc(i,1,n) tea[i].x += 1000 , tea[i].y += 1000 , tea[i].z += 1000 ;
    PVH.x += 1000 ; PVH.y += 1000  ; PVH.z += 1000 ;
}

void process () {
    bool sub_1 = true , sub_2 = true ;
    forinc(i,1,m) if (disco[i].y != 0 || disco[i].z != 0) sub_1 = false ; else if (disco[i].z != 0) sub_2 = false ;
    forinc(i,1,n) if (tea[i].y != 0 || tea[i].z != 0) sub_1 = false ; else if (tea[i].z != 0) sub_2 = false ;
    if (PVH.y != 0 || PVH.z != 0) sub_1 = false ; else if (PVH.z != 0) sub_2 = false ;
    exact() ;
    if (sub_1) sub1() ; else best_algorthim() ;
}

int main () {
    freopen("TEAWORLD.inp" , "r" , stdin) ;
    freopen("TEAWORLD.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
