#include<bits/stdc++.h>
const int N = 4005;
const int inf = 1e9;
using namespace std;

typedef pair <int, int> ii;
vector <ii> mv[N];
int n, dif, a[N], b[N];
int dp[N][N], ans, Max[N];

int read(){
    int res = 0; char c = getchar();
    while (c == ' ' || c == '\n') c = getchar();
    while ('0' <= c && c <= '9') res = (res << 1) + (res << 3) + c - '0', c = getchar();
    return res;
}

bool up(int&a, int b){
    if (a >= b) return false;
    a = b;
    return true;
}

int cal(int num){
    if (num != ans){
        vector <ii> New;
        for (auto x : mv[num]){
            for (auto y : mv[num+1]){
                if (abs(a[x.first] - a[y.first]) <= dif && x.first < y.first && x.second < y.second) {
                    New.push_back(x);
                    break;
                }
            }
        }
        New.swap(mv[num]);
    }
    int Max = -1, Min = inf;
    vector <ii> New;
    for (auto x : mv[num]) up(Max, a[x.first]);
    for (auto x : mv[num]) {
        if (Max == a[x.first] && x.second < Min) {
            Min = x.second;
            New.push_back(x);
        }
    }
    mv[num].swap(New);
    return Max;
}

int main(){
    freopen("LIONDANCE.inp", "r", stdin);
    freopen("LIONDANCE.out", "w", stdout);
    n = read(); dif = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) b[i] = read();
    reverse(a+1, a+1+n);
    reverse(b+1, b+1+n);
    for (int i = 1; i <= n; i++){
        int cur = 0;
        for (int j = 1; j <= n; j++){
            if (a[i] == b[j]) dp[i][j] = cur + 1;
            if (abs(a[i] - b[j]) <= dif) cur = max(cur, Max[j]);
            ans = max(ans, dp[i][j]);
            mv[dp[i][j]].push_back(ii(i, j));
        }
        for (int j = 1; j <= n; j++) Max[j] = max(Max[j], dp[i][j]);
    }
    printf("%d\n", ans);
    for (int i = ans; i > 0; i--) printf("%d ", cal(i));
}
