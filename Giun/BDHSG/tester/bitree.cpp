// /*
//   Croatian Open Competition in Informatics 2006/2007
//   Contest 4 - Task JOGURT
//   Programming language C++
// */

// #include <cstdio>

// #define maxt (1<<15)

// int t, sol[maxt], depth[maxt]; // sol pamti stablo u preorderu, depth pamti dubinu nekog cvora

// void next( int d ) {
//    for( int i = t; i > 0; i-- ) { // kopiranje stabla dvaput
//       sol[t+i] = sol[i] = sol[i-1]*2;
//       depth[t+i] = depth[i] = depth[i-1]+1;
//    }
//    for( int i = 1; i <= t+t; i++ ) // dodavanje jedinice nekim elementima
//       if( (depth[i]==d)^(i<=t) ) sol[i]++;

//    sol[0] = 1; // dodavanje korijena
//    depth[0] = 0;
//    t = t+t+1; // stablo je sad dvaput vece
// }

// int main(void) {
//     freopen("bitree.inp", "r", stdin);
//     freopen("bitree.out", "w", stdout);
//    depth[0] = 0; // inicijalizacija, stablo ima samo jedan element
//    sol[0] = t = 1;

//    int n;
//    scanf( "%d", &n );

//    for( int i = 1; i < n; i++ ) next( i ); // udvostruci stablo n puta

//    for( int i = 0; i < t; i++ ) printf( "%d ", sol[i] ); // ispisi rjesenje

//    return 0;
// }


#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "bitree"
using namespace std;

template <typename T> inline void Read(T &x){
    x = 0; char c;
    while(!isdigit(c = getchar()));
    do
    {
        x = x * 10 + c - '0';
    } while (isdigit(c = getchar()));
}

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = (1LL << 15) + 7;
ll n, node, ans[maxn];
bool d[maxn] = {0};

#define left first
#define right second

void dfs(ll fl, ll u, vec(ll) &num){
    if(num.size() == 1){
        ans[u] = num.back();
        num.clear();
        return;
    }
    ll s = 0;
    vec(ll) a[2];
    lp(i, 0, num.size() - 1){
        a[i & 1].push_back(num[i]);
        s += ((i & 1) ? -1 : 1) * num[i];
    }
    s -= (1LL << fl);
    ans[u] = s;
    a[0].erase(remove(a[0].begin(), a[0].end(), s), a[0].end());
    num.clear();
    dfs(fl + 1, u << 1, a[0]);
    dfs(fl + 1, (u << 1) | 1, a[1]);
}

void printdfs(ll num){
    if(num > node) return;
    cout << ans[num] << ' ';
    printdfs(num << 1);
    printdfs((num << 1) | 1);
}

// #define ONLINE_JUDGE PMQ
int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    node = (1LL << n) - 1;
    vec(ll) a;
    lp(i, 1, node) a.push_back(i);
    dfs(0, 1, a);  
    printdfs(1);
}