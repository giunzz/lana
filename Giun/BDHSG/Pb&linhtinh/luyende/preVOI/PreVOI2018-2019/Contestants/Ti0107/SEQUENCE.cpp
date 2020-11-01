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

const int maxN = 3005, maxV = 3005;
int m, n, k, a[maxN], b[maxN];
void Input(){
    m = Read_Int(), n = Read_Int(), k = Read_Int();
    for(int i = 1 ; i <= m ; ++ i) a[i] = Read_Int();
    for(int i = 1 ; i <= n ; ++ i) b[i] = Read_Int();
    return;
}

vector <int> CMP(vector <int> x, vector <int> y){
    int k1 = x.size(), k2 = y.size();
    for(int i = 0 ; i < k1 ; ++ i){
        if(x[i] == x[i]) continue;
        else if(x[i] < y[i]) return x;
        else if(x[i] > y[i]) return y;
    }
    return x;
}

void Solve(){
    vector <int> X;
    X.resize(k, maxV);
    for(int l = 0 ; l <= k ; ++ l){
        if(k - l > n || l > m) continue;
        int m1 = l, m2 = k - l;
        vector <int> x1;
        for(int x = 0 ; x < (1 << m) ; ++ x) if(__builtin_popcount(x) == m1){
            for(int y = 0 ; y < (1 << n) ; ++ y) if(__builtin_popcount(y) == m2){
                for(int i = 1 ; i <= m ; ++ i) if(x >> (i - 1) & 1) x1.push_back(a[i]);
                for(int i = 1 ; i <= n ; ++ i) if(y >> (i - 1) & 1) x1.push_back(b[i]);
                X = CMP(x1, X);
                x1.clear();
            }
        }
    }
    for(int v : X) Write_Int(v), putchar(' ');
    return;
}

#define TASK "SEQUENCE"
int main(){
    #ifdef TASK
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    #else
    freopen("main.inp", "r", stdin);
    #endif // TASK
    Input();
    Solve();
}

