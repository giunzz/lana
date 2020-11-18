#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 307;
ll n, m, a[maxn][maxn] = {{0}}, row[maxn][maxn] = {{0}}, col[maxn][maxn] = {{0}};

void dfs(pp(ll, ll) p){

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n >> m;
    char c;
    lp(i, 1, n) lp(j, 1, m){
        cin >> c;
        if(c == '.') a[i][j] = 1;
        if(!a[i][j]) row[i][j] = col[i][j] = 0;
        else row[i][j] = row[i][j - 1] + 1, col[i][j] = col[i - 1][j] + 1;
    }
    lp(i, 1, n){
        if(a[i][1]){dfs(make_pair(i, 1));}
    }
}