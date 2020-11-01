#include    <bits/stdc++.h>
#define stat akjcjalsjcjalscj
#define hash ajkscjlsjclajsc
#define next ackjalscjaowjico
#define prev ajcsoua0wucckjsl
#define y1 alkscj9u20cjeijc
#define left lajcljascjljl
#define right aucouasocjolkjl
#define y0 u9cqu3jioajc
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define fd(i,a,b) for(int i=(a);i>=(b);--i)
#define rep(i,a,b)  for(int i=(a);i<(b);++i)
#define fore(i,a)  for(__typeof((a).begin()) i=(a).begin();i!=(a).end();++i)
#define __unique(V) (V).resize(unique((V).begin(),(V).end())-(V).begin())
#define cntbit(X)   __builtin_popcount((X))
#define bit(S,i) (((S)>>(i))&1)
#define PI	acos(-1)
#define fi  first
#define se  second
#define LL  long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define TASK "table"
using   namespace   std;
const int maxn = 305;
const LL oo = 1e12;
int n,m,k,a[maxn][maxn],U,V,P,Q;
LL  F[maxn][maxn][2];
///--------------------------
void    readf(){
    cin >> m >> n >> k;
    fo(i,1,m) fo(j,1,n) cin >> a[i][j];
}
///--------------------------
void    DP_EZ(){
    fo(i,U,P) fo(j,V,Q){
        if (i == U && j == V){
            F[i][j][1] = -oo;
            F[i][j][0] = a[i][j];
            continue;
        }
        if (i == U || j == V){
            F[i][j][1] = -oo;
            if (i > U) F[i][j][0] = F[i - 1][j][0] + a[i][j];
            if (j > V) F[i][j][0] = F[i][j - 1][0] + a[i][j];
            continue;
        }
        F[i][j][0] = max(F[i][j - 1][0],F[i - 1][j][0]) + a[i][j];
        F[i][j][1] = min(F[i-1][j][0],F[i][j-1][0]) + a[i][j];
        if (i == U + 1 && j == V + 1) continue;
        F[i][j][1] = min(F[i][j][1],max(F[i-1][j][1],F[i][j-1][1]) + a[i][j]);
    }
    cout << ((F[P][Q][1] == -oo) ? 0 : F[P][Q][1]) << '\n';
}
///--------------------------
void    solve(){
    fo(i,1,k){
        cin >> U >> V >> P >> Q;
        DP_EZ();
    }
}
///--------------------------
int     main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    #endif // ONLINE_JUDGE
    readf();
    solve();
}





