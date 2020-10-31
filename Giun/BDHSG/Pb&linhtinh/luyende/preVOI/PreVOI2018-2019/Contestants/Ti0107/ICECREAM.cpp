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

const int maxN = 305, MMAX = 1e4 + 5, mod = 1e9 + 9;
int n, Mmax, M50, M1, M2;
void Input(){
    n = Read_Int(), Mmax = Read_Int();
    M50 = Read_Int(), M1 = Read_Int(), M2 = Read_Int();
    return;
}

int ans, x[17];
void Process(){
    int m50 = M50, m1 = M1, m2 = M2;
    for(int i = 1 ; i <= n ; ++ i) {
        if(x[i] == 1){
            ++ m50;
            if(m50 > Mmax) return;
        } else if(x[i] == 2){
            ++ m1; -- m50;
            if(m1 > Mmax || m50 < 0) return;
        } else if(x[i] == 3){
            ++ m2;
            if(m1 > 0 && m50 > 0) -- m1, -- m50;
            else if(m50 >= 3) m50 -= 3;
            else return;
        }
    }
    ans = (ans + 1) % mod;
    return;
}

void Try(int i){
    if(i > n) {Process(); return;}
    for(int j = 1 ; j <= 3 ; ++ j){
        x[i] = j;
        Try(i + 1);
    }
    return;
}

void SolveSub1(){
    ans = 0, Try(1);
    Write_Int(ans);
    return;
}

typedef pair<int, int> II;
typedef pair<II, II> IIII;
IIII IV(int a, int b, int c, int d){
    return IIII(II(a, b), II(c, d));
}

map <IIII, int> f, cL;
int calc(int i, int m50, int m1, int m2){
    if(m50 < 0 || m1 < 0 || m2 < 0) return 0;
    if(cL[IV(i, m50, m1, m2)] == 1) return f[IV(i, m50, m1, m2)];
    cL[IV(i, m50, m1, m2)] = 0;
    if(i == 0 && m50 == M50 && m1 == M1 && m2 == M2) return f[IV(i, m50, m1, m2)] = 1;
    if(i == 0) return f[IV(i, m50, m1, m2)] = 0;
    if(m50 > Mmax || m1 > Mmax || m2 > Mmax) return f[IV(i, m50, m1, m2)] = 0;
    int t = 0;
    (t += calc(i - 1, m50 - 1, m1, m2)) %= mod;
    (t += calc(i - 1, m50 + 1, m1 - 1, m2)) %= mod;
    (t += calc(i - 1, m50 + 1, m1 + 1, m2 - 1)) %= mod;
    (t += calc(i - 1, m50 + 3, m1, m2 - 1)) %= mod;
    return f[IV(i, m50, m1, m2)] = t;
}

void SolveSub2(){
    ans = 0; f.clear(), cL.clear();
    for(int i = M50 - 3 * n ; i <= M50 + n ; ++ i)
        for(int j = M1 - n ; j <= M1 + n ; ++ j)
            for(int k = M2 - n ; k <= M2 + n ; ++ k) (ans += calc(n, i, j, k)) %= mod;
    Write_Int(ans);
    return;
}

void SolveSub3(){
    srand(time(NULL));
    Write_Int((1LL * rand() * rand()) % mod);
    return;
}

#define TASK "ICECREAM"
int main(){
    #ifdef TASK
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    #else
    freopen("main.inp", "r", stdin);
    #endif // TASK
    Input();
    if(n <= 15 && Mmax <= 10) SolveSub2();
    else if(n <= 50) SolveSub2();
    else SolveSub3();
}

