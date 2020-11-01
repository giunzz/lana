#include <bits/stdc++.h>

using namespace std;

int Read_Int(){
    char c;
    for(c = getchar() ; (c < '0' || c > '9') && c != '-' ; c = getchar());
    int ans = 0; int sgn = 1;
    if(c == '-') sgn = -1;
    else ans = c - '0';
    for(c = getchar() ; '0' <= c && c <= '9' ; c = getchar()) ans = ans * 10 + c - '0';
    return ans * sgn;
}

void Write_Int(int x){
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) Write_Int(x / 10);
    putchar(x % 10 + '0');
}

const int maxN = 3005;
int n, delta, L[maxN], R[maxN];
void Input(){
    n = Read_Int(), delta = Read_Int();
    for(int i = 0 ; i < n ; ++ i) L[i] = Read_Int();
    for(int i = 0 ; i < n ; ++ i) R[i] = Read_Int();
    return;
}

int cmp(int x, int y){
    int k = __builtin_popcount(x); vector <int> X, Y;
    for(int i = 0 ; i < n ; ++ i) if(x >> i & 1) X.push_back(L[i]);
    for(int i = 0 ; i < n ; ++ i) if(y >> i & 1) Y.push_back(L[i]);
    for(int i = 0 ; i < k ; ++ i){
        if(X[i] == Y[i]) continue;
        else if(X[i] > Y[i]) return x;
        else if(X[i] < Y[i]) return y;
    }
    return x;
}

void SolveSub1(){
    int ans = -1, X;
    for(int x = 0 ; x < (1 << n) ; ++ x){
        int P = -1, k = __builtin_popcount(x); int j = 0;
        for(int i = 0 ; i < n ; ++ i) if(x >> i & 1) {
            while(L[i] != R[j] && j < n) ++ j;
            if(j == n) goto L; ++ j;
            if(P == -1) P = L[i];
            else if(abs(P - L[i]) > k) goto L;
        }
        if(k > ans) ans = k, X = x;
        else if(k == ans) X = cmp(X, x);

        L:;
    }
    Write_Int(ans), putchar('\n');
    for(int i = 0 ; i < n ; ++ i) if(X >> i & 1) Write_Int(L[i]), putchar(' ');
    return;
}

int f[maxN][maxN];
int calc(int i, int j){
    if(f[i][j] != -1) return f[i][j];
    if(L[i] != R[j]) return f[i][j] = 0;
    f[i][j] = 1;
    for(int x = 0 ; x < i ; ++ x)
        for(int y = 0 ; y < j ; ++ y) if(L[x] == R[y] && abs(L[x] - L[i]) <= delta) f[i][j] = max(f[i][j], f[x][y] + 1);
    return f[i][j];
}

vector <int> CMP(vector <int> x, vector <int> y){
    int k1 = x.size(), k2 = y.size();
    if(k1 > k2) return x;
    if(k2 > k1) return y;
    for(int i = 0 ; i < k1 ; ++ i){
        if(x[i] == x[i]) continue;
        else if(x[i] > y[i]) return x;
        else if(x[i] < y[i]) return y;
    }
    return x;
}

vector <int> X, x1;
void Trace(int i, int j, int k){
    if(k == 0){
        X = CMP(x1, X);
        return;
    }
    for(int x = 0 ; x < i ; ++ x)
        for(int y = 0 ; y < j ; ++ y) if(L[x] == R[y] && abs(L[x] - L[i]) <= delta && f[i][j] == f[x][y] + 1){
            x1.push_back(L[x]);
            Trace(x, y, k - 1);
            x1.pop_back();
        }
    return;
}

void SolveSub2(){
    memset(f, -1, sizeof(f));
    int ans = 0;
    for(int i = 0 ; i < n ; ++ i)
        for(int j = 0 ; j < n ; ++ j) if(L[i] == R[j]) ans = max(ans, calc(i, j));
    Write_Int(ans), putchar('\n');

    for(int i = 0 ; i < n ; ++ i)
        for(int j = 0 ; j < n ; ++ j) if(L[i] == R[j] && ans == calc(i, j)) {
            x1.clear(); x1.push_back(L[i]);
            Trace(i, j, ans - 1);
        }
    reverse(X.begin(), X.end());
    for(int v : X) Write_Int(v), putchar(' ');
    return;
}

void TraceW(int u, int v, int k){
    if(u == 0 || v == 0) return;
    if(L[u - 1] == R[v - 1] && f[u][v] == f[u - 1][v - 1] + 1) {
        x1.push_back(L[u - 1]), TraceW(u - 1, v - 1, k - 1);
        //for(int v : x1) Write_Int(v), putchar(' '); putchar('\n');
        X = CMP(x1, X);
        x1.pop_back();
    } else {
        if(f[u - 1][v] == f[u][v]) TraceW(u - 1, v, k);
        if(f[u][v - 1] == f[u][v]) TraceW(u, v - 1, k);
    }
    return;
}

void SolveSub3(){
    for(int i = 1 ; i <= n ; ++ i)
        for(int j = 1 ; j <= n ; ++ j){
            if(L[i - 1] == R[j - 1]) f[i][j] = f[i - 1][j - 1] + 1;
            else f[i][j] = max(f[i][j - 1], f[i - 1][j]);
    }
    Write_Int(f[n][n]), putchar('\n');
    x1.clear(); TraceW(n, n, f[n][n]);
    reverse(X.begin(), X.end());
    for(int v : X) Write_Int(v), putchar(' ');
    return;
}

#define TASK "LIONDANCE"
int main(){
    #ifdef TASK
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    #else
    freopen("main.inp", "r", stdin);
    #endif // TASK
    Input();
    if(n <= 20) SolveSub1();
    else if(n <= 100) SolveSub2();
    else SolveSub3();
}
