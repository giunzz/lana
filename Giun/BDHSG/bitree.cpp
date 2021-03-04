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