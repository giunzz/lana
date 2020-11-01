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

void Write_Int(int64_t x){
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) Write_Int(x / 10);
    putchar(x % 10 + '0');
}

const int maxN = 305;
const int64_t inf = 1e18;
int m, n, k, a[maxN][maxN], u[maxN], v[maxN], p[maxN], q[maxN];
void Input(){
    m = Read_Int(), n = Read_Int(), k = Read_Int();
    for(int i = 1 ; i <= m ; ++ i)
        for(int j = 1 ; j <= n ; ++ j) a[i][j] = Read_Int();
    for(int i = 1 ; i <= k ; ++ i) u[i] = Read_Int(), v[i] = Read_Int(), p[i] = Read_Int(), q[i] = Read_Int();
    return;
}

int64_t f[maxN][maxN];
typedef pair<int, int> II;
int64_t Try(int x, int y, int u, int v, int fx, int fy){
    for(int i = x - 1 ; i <= u + 1 ; ++ i) for(int j = y - 1 ; j <= v + 1 ; ++ j) f[i][j] = -inf;
    for(int i = x ; i <= u ; ++ i) for(int j = y ; j <= v ; ++ j) f[i][j] = 0;

    if(II(fx, fy) == II(x, y)) return inf;
    if(II(fx, fy) == II(u, v)) return inf;

    for(int i = x ; i <= u ; ++ i)
        for(int j = y ; j <= v ; ++ j) if(II(i, j) != II(fx, fy)) {
            f[i][j] = (II(i, j) == II(x, y)) ? a[x][y] : 0;
            if(II(i - 1, j) != II(fx, fy)) f[i][j] = max(f[i][j], f[i - 1][j] + a[i][j]);
            if(II(i, j - 1) != II(fx, fy)) f[i][j] = max(f[i][j], f[i][j - 1] + a[i][j]);
    } else f[i][j] = - inf;

    return f[u][v];
}

void SolveSub1(){
    for(int l = 1 ; l <= k ; ++ l){
        int64_t ans = inf;
        for(int i = u[l] ; i <= p[l] ; ++ i)
            for(int j = v[l] ; j <= q[l] ; ++ j) ans = min(ans, Try(u[l], v[l], p[l], q[l], i, j));
        Write_Int(ans), putchar('\n');
    }
    return;
}

void SolveSub2(){
    SolveSub1();
    return;
}

void SolveSub3(){
    SolveSub1();
    return;
}

#define TASK "TABLE"
int main(){
    #ifdef TASK
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    #else
    freopen("main.inp", "r", stdin);
    #endif // TASK
    Input();
    if(m <= 30 && n <= 30 && k <= 30) SolveSub1();
    else if(m <= 80 && n <= 80 && k <= 80) SolveSub2();
    else SolveSub3();
}

