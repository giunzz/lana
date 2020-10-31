#include<bits/stdc++.h>
const int N = 3005;
const int inf = 1e9;
using namespace std;

typedef pair <int, int> ii;
typedef vector <ii> vi;
map <int, int> mp;
vector <ii> best;
int n, m, k, a[N], b[N];
int cnt, f[2 * N], ans[2 * N];
ii Min[2][N][N];

void dobest(vi& best){
    vector <ii> ans;
    sort(best.begin(), best.end());
    int Min = inf;
    for (auto x : best){
        if (x.second < Min){
            Min = x.second;
            ans.push_back(x);
        }
    }
    best.swap(ans);
}

int read(){
    int res = 0; char c = getchar();
    while (c == ' ' || c == '\n') c = getchar();
    while ('0' <= c && c <= '9') res = (res << 1) + (res << 3) + c - '0', c = getchar();
    return res;
}

int main(){
    freopen("SEQUENCE.inp", "r", stdin);
    freopen("SEQUENCE.out", "w", stdout);
    n = read(); m = read(); k = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        mp[a[i]] = 1;
    }
    for (int i = 1; i <= m; i++){
        b[i] = read();
        mp[b[i]] = 1;
    }
    for (auto& x : mp) x.second = ++cnt, f[cnt] = x.first;
    for (int i = 1; i <= n; i++) a[i] = mp[a[i]];
    for (int i = 1; i <= m; i++) b[i] = mp[b[i]];
    for (int i = 0; i < 2; i++) for (int j = 0; j < N; j++) for (int k = 0; k < N; k++) Min[i][j][k] = ii(inf, inf);
    for (int i = 1; i <= n; i++){
        Min[0][i][i] = ii(a[i], i);
        for (int j = i+1; j <= n; j++){
            Min[0][i][j] = min(Min[0][i][j-1], ii(a[j], j));
        }
    }
    for (int i = 1; i <= m; i++){
        Min[1][i][i] = ii(b[i], i);
        for (int j = i+1; j <= n; j++){
            Min[1][i][j] = min(Min[1][i][j-1], ii(b[j], j));
        }
    }
    best.push_back(ii(0, 0));
    for (int i = 1; i <= k; i++){
        vector <ii> nbest;
        ans[i] = 2 * N;
        for (auto x : best){
            int last1 = min(n - x.first, k-i-m+x.second), last2 = min(m - x.second, k-i-n+x.first);
            ans[i] = min(ans[i], min(Min[0][x.first+1][n-last1].first, Min[1][x.second+1][m-last2].first));
        }
        for (auto x : best){
            int last1 = min(n - x.first, k-i-m+x.second), last2 = min(m - x.second, k-i-n+x.first);
            if (ans[i] == Min[0][x.first+1][n-last1].first){
                nbest.push_back(ii(Min[0][x.first+1][n-last1].second, x.second));
            }
            if (ans[i] == Min[1][x.second+1][m-last2].first){
                nbest.push_back(ii(x.first, Min[1][x.second+1][m-last2].second));
            }
        }
        dobest(nbest);
        best.swap(nbest);
        printf("%d ", ans[i]);
    }
}
