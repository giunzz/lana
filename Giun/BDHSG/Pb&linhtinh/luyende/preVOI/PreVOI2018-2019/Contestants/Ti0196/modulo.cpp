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
#define bit(S,i) (((S)>>(i - 1))&1)
#define PI	acos(-1)
#define fi  first
#define se  second
#define LL  long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define TASK "modulo"
using   namespace   std;
map <LL,LL> M;
LL a,b,n,k,mod;
///--------------------------
LL  mul(LL X,LL Y){
    X%=mod;Y%=mod;
    LL  q = (long double) X*Y/mod;
    return (((X*Y-q*mod)%mod+mod)%mod);
}
///--------------------------
void    sub12(){
    M.clear();
    int x = n/2, y = n - x;
    fo(mask,0,(1<<y) - 1){
        LL rs = 0;
        fo(i,1,y) if (bit(mask,i)) rs = (mul(rs,10) + a) % mod;
        else rs = (mul(rs,10) + b) % mod;
        M[rs] = mask;
    }
    LL tmp = 1;
    fo(i,1,y) tmp = mul(tmp,10);
    fo(mask,0,(1<<x) - 1){
        LL rs = 0;
        fo(i,1,x) if (bit(mask,i)) rs = (mul(rs,10) + a) % mod;
        else rs = (mul(rs,10) + b) % mod;
        rs = mul(rs,tmp);
        rs = ((k - rs) % mod + mod) % mod;
        if (M.find(rs) == M.end()) continue;
        int mask2 = M[rs];
        fo(i,1,x) if (bit(mask,i)) cout <<a;
        else cout <<b;
        fo(i,1,y) if (bit(mask2,i)) cout << a;
        else cout <<b;
        exit(0);
    }
    cout << -1 << '\n';
}
///--------------------------
void    solve(){
    cin >> a >> b >> n >> k;
    mod = 1;
    fo(i,1,n) mod *= 2;
    if (n <= 40) sub12();
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





