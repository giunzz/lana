#include <bits/stdc++.h>
#define ft first
#define sc second
using namespace std;

int Read_Int(){
    char c;
    for(c = getchar() ; (c < '0' || c > '9') && c != '-' ; c = getchar());
    int ans = c - '0';
    for(c = getchar() ; '0' <= c && c <= '9' ; c = getchar()) ans = ans * 10 + c - '0';
    return ans;
}

int64_t Read_Int64(){
    char c;
    for(c = getchar() ; (c < '0' || c > '9') && c != '-' ; c = getchar());
    int64_t ans = c - '0';
    for(c = getchar() ; '0' <= c && c <= '9' ; c = getchar()) ans = ans * 10 + c - '0';
    return ans;
}

void Write_Int(int64_t x){
    if(x > 9) Write_Int(x / 10);
    putchar(x % 10 + '0');
}

int A, B, n;
uint64_t K, mod;
void Input(){
    A = Read_Int(), B = Read_Int();
    n = Read_Int(), K = Read_Int64();
    mod = (1LL << n);
    return;
}

int64_t Mul(int64_t x,int64_t y){
    x %= mod, y %= mod;
    long double t = (long double) x * y / mod;
    int64_t q = int64_t(t),
        r = (x * y - q * mod) % mod;
    if(r < 0) r += mod;
    return r;
}

int64_t Pow(int64_t x, int n){
    if(n == 0) return 1;
    uint64_t b = Pow(x, n / 2);
    if(n & 1) return Mul(Mul(b, b), x);
    return Mul(b, b);
}

void SolveSub1(){
    for(int x = 0 ; x < (1 << n) ; ++ x){
        uint64_t t = 0;
        for(int i = 0 ; i < n ; ++ i) {
            if(x >> i & 1) t = (Mul(t, 10) + A) % mod;
            else t = (Mul(t, 10) + B) % mod;
        }
        if(t == K){
            for(int i = 0 ; i < n ; ++ i) putchar((x >> i & 1) ? (A + '0') : (B + '0'));
            return;
        }
    }
    putchar('-'), putchar('1');
    return;
}

typedef pair<uint64_t, int> II;
II p[(1 << 20) + 5], q[(1 << 20) + 5];
void SolveSub2(){
    int m1 = (n + 1) / 2, numP = 0, numQ = 0;
    for(int x = 0 ; x < (1 << m1) ; ++ x){
        uint64_t t = 0;
        for(int i = 0 ; i < m1 ; ++ i) {
            if(x >> i & 1) t = (Mul(t, 10) + A) % mod;
            else t = (Mul(t, 10) + B) % mod;
        }
        q[++numQ] = II(t, x);
    }
    for(int x = 0 ; x < (1 << (n - m1)) ; ++ x){
        uint64_t t = 0;
        for(int i = 0 ; i < (n - m1) ; ++ i) {
            if(x >> i & 1) t = (Mul(t, 10) + A) % mod;
            else t = (Mul(t, 10) + B) % mod;
        }
        p[++numP] = II(t, x);
    }
    sort(p + 1, p + numP + 1);
    for(int i = 1 ; i <= numQ ; ++ i){
        uint64_t t = Mul(Pow(10, n - m1), q[i].ft); int x = q[i].sc;
        int u = lower_bound(p + 1, p + numP + 1, II(K - t, 0)) - p;
        if(K >= t && 1 <= u && u <= numP && p[u].ft == K - t){
            int y = p[u].sc;
            for(int i = 0 ; i < m1 ; ++ i) putchar((x >> i & 1) ? (A + '0') : (B + '0'));
            for(int i = 0 ; i < n - m1 ; ++ i) putchar((y >> i & 1) ? (A + '0') : (B + '0'));
            return;
        }
        u = lower_bound(p + 1, p + numP + 1, II((K - t + mod) % mod, 0)) - p;
        if(1 <= u && u <= numP && p[u].ft == (K - t + mod) % mod){
            int y = p[u].sc;
            for(int i = 0 ; i < m1 ; ++ i) putchar((x >> i & 1) ? (A + '0') : (B + '0'));
            for(int i = 0 ; i < n - m1 ; ++ i) putchar((y >> i & 1) ? (A + '0') : (B + '0'));
            return;
        }
    }
    putchar('-'), putchar('1');
    return;
}

void SolveSubRandom(){
    srand(time(NULL));
    for(int w = 6500000 / n ; w > 0 ; -- w){
        int64_t x = 0;
        for(int i = 0 ; i < n ; ++ i){
            int t = rand() % 2;
            if(t) x |= (1 << i);
        }
        uint64_t t = 0;
        for(int i = 0 ; i < n ; ++ i) {
            if(x >> i & 1) t = (Mul(t, 10) + A) % mod;
            else t = (Mul(t, 10) + B) % mod;
        }
        if(t == K){
            for(int i = 0 ; i < n ; ++ i) putchar((x >> i & 1) ? (A + '0') : (B + '0'));
            return;
        }
    }
    putchar('-'), putchar('1');
    return;
}

#define TASK "MODULO"
int main(){
    #ifdef TASK
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    #else
    freopen("main.inp", "r", stdin);
    #endif // TASK
    Input();
    if(n <= 20) SolveSub1();
    else if(n <= 40) SolveSub2();
    else SolveSubRandom();
}

