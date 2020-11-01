#include <bits/stdc++.h>

using namespace std;
int E[int(1e6) + 1], P[int(1e6) + 1], nP;
int sangNT(int n){
    for(int i = 1 ; i <= n ; ++ i) E[i] = i;
    nP = 0;
    for(int i = 2 ; i <= n ; ++ i)if(E[i] == i) {
        P[++nP] = i;
        for(int j = 2 ; j * i <= n ; ++ j) E[i * j] = i;
    }
    return 0;
}
int A, B;
int gcd(int a, int b){
    while(b > 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int Analyze(int x){
    int kq = 1;
    if(x > int(1e6)){
        for(int i = 1 ; i <= nP ; ++ i) if(x % P[i] == 0){
            int k = 0;
            while(x % P[i] == 0) x /= P[i], ++k;
            if(k % 2) kq *= P[i];
        }
    }
    if(x > int(1e6)) {kq *= x; return kq;}
    while(x > 1){
        int p = E[x], k = 0;
        while(x % p == 0) x /= p, ++ k;
        if(k % 2) kq *= p;
    }
    return kq;
}

int Solve(){
    while(1){
        int d = gcd(A, B);
        if(d == 1) break;
        A /= d, B /= d;
    }
    A = Analyze(A);
    B = Analyze(B);
    printf("%d %d\n", A, B);
    return 0;
}

int T;
#define TASK "MINSUM"
int main(){
    #ifdef TASK
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    #else
    freopen("main.inp","r",stdin);
    #endif // TASK
    scanf("%d", &T);
    sangNT(int(1e6));
    while(T --){
        scanf("%d %d", &A, &B);
        Solve();
    }
}
