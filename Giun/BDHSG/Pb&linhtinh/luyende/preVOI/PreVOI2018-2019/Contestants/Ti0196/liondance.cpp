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
#define TASK "liondance"
using   namespace   std;
const int maxn = 4005;
int N,delta,a[maxn],b[maxn];
int F[maxn],ans;
vector<ii> V[maxn];
///--------------------------
void    readf(){
    cin >> N >> delta;
    fo(i,1,N) cin >> a[i];
    fo(i,1,N) cin >> b[i];
}
///--------------------------
void    solve(){
    ans = 0;
    fd(i,N,1){
        int cur = 0;
        fd(j,N,1){
            int pre = cur;
            if (abs(a[i] - b[j]) <= delta)
                cur = max(cur,F[j]);
            if (a[i] == b[j]) {
                F[j] = max(F[j],pre + 1);
                ans = max(ans,F[j]);
                V[pre + 1].push_back(ii(i,j));
            }
        }
    }
    cout << ans << '\n';
    int n = 0, m = 0;
    fd(i,ans,1){
        int val = 0,tn = n,tm = m;
        fore(it,V[i]) if (n < (*it).fi && m < (*it).se && val < a[(*it).fi]){
            val = a[(*it).fi];
            tn = (*it).fi; tm = (*it).se;
        }
        n = tn;m = tm;
        cout << val << ' ';
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





