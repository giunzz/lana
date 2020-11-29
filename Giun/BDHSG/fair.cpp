#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
// #define Fname "fair"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 1e3 + 7;
ll m, n, a[maxn][maxn], num[maxn][maxn] = {{0}}, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, cnt = 0;
bool d[maxn][maxn] = {{0}};
map<pp(ll, ll), bool> e;
stack<pp(ll, ll)> st;

void prcNum(ll rx, ll ry, ll r){
    queue<pp(ll, ll)> q;
    q.push({rx, ry});
    while(q.size()){
        ll x = q.front().first, y = q.front().second;
        q.pop();
        if(num[x][y]) continue;
        num[x][y] = r;
        lp(i, 0, 3){
            ll nx = x + dx[i], ny = y + dy[i];
            if(num[nx][ny] || d[nx][ny]) continue;
            if(a[x][y] != a[nx][ny]){
                if(num[nx][ny] && !e[{num[nx][ny], r}]){
                    e[{num[nx][ny], r}] = e[{r, num[nx][ny]}] = 1;
                    
                } 
                st.push({nx, ny});
            }
            else
                q.push({nx, ny}); 
        }
    }   
}

void createGraph(){
    st.push({1, 1});
    while(st.size()){
        ll x = st.top().first, y = st.top().second;
        st.pop();
        if(num[x][y]) continue; 
        prcNum(x, y, ++cnt);
    }
    lp(i, 1, m){
        lp(j, 1, n) cerr << num[i][j] <<' ';
        cerr << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> m >> n;
    lp(i, 0, n + 1) d[0][i] = d[m + 1][i] = 1;
    lp(i, 0, m + 1) d[i][0] = d[i][n + 1] = 1;
    lp(i, 1, m) lp(j, 1, n) cin >> a[i][j];
    createGraph();
}