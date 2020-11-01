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
#define TASK "icecream"
using   namespace   std;
const int mod = 1e9 + 9;
int n,MMAX,M50,M1,M2;
int  F[205][105][55][55];
///--------------------------
int  f(int m50,int m1,int m2,int sb){
    int &rs = F[m50][m1][m2][sb];
    if (rs != -1) return rs;
    if (sb > n) return (rs = 1);
    int s50 = M50 + m50 - 150;
    int s1 = M1 + m1 - 50;
    int s2 = M2 + m2;
    rs = 0;
    if (s50 < MMAX) rs = (rs + f(m50 + 1,m1,m2,sb + 1)) % mod;
    if (s1 < MMAX && s50 > 0) rs = (rs + f(m50 - 1,m1 + 1,m2,sb + 1)) % mod;
    if (s2 < MMAX){
        if (s50 > 0 && s1 > 0) rs = (rs + f(m50 - 1,m1 - 1,m2 + 1,sb + 1)) % mod;
        else if (s50 > 2) rs = (rs + f(m50 - 3,m1,m2 + 1,sb + 1)) % mod;
    }
    return rs;
}
///--------------------------
void    solve(){
    cin >> n >> MMAX >> M50 >> M1 >> M2;
    memset(F,-1,sizeof(F));
    if (n <= 50) cout << f(150,50,0,1) << '\n';
}
///--------------------------
int     main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    #endif // ONLINE_JUDGE
    solve();
}





