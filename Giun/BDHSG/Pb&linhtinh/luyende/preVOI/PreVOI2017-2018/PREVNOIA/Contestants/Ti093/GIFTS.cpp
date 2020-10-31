#include <bits/stdc++.h>
using namespace std;
int Read_Int(){
    char c;
    for(c = getchar(); c < '0' || c > '9'; c = getchar());
    int ans = c - '0';
    for(c = getchar(); c >= '0' && c <= '9'; c = getchar())
        ans = ans * 10 + c - '0';
    return ans;
}
void Write_Int64(int64_t x){
    if(x > 9) Write_Int64(x / 10);
    putchar(x % 10 + '0');
}
const int maxN = int(1e6) + 5;
const int64_t INF = 10000000000000LL;
int n, k, a[maxN];
int Input(){
    n = Read_Int(), k = Read_Int();
    for(int i = 1 ; i <= n ; ++ i) a[i] = Read_Int();
    return 0;
}
int64_t S[maxN], Max_L[maxN], Max_R[maxN];
int Solve(){
    S[0] = 0;
    for(int i = 1 ; i <= n ; ++ i) S[i] = S[i - 1] + a[i];
    for(int i = 1 ; i <= n ; ++ i) Max_L[i] = max(Max_L[i - 1], S[i] - S[max(0 , i - k)]);
    for(int i = n ; i >= 1 ; -- i) Max_R[i] = max(Max_R[i + 1], S[min(n , i + k - 1)] - S[i - 1]);
    int64_t x = INF;
    for(int i = 1 ; i <= n ; ++ i) x = min(x, max(Max_L[i - 1], Max_R[min(n + 1, i + k)]));
    Write_Int64(x);
    return 0;
}
#define TASK "GIFTS"
int main(){
    #ifdef TASK
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    #else
    freopen("main.inp","r",stdin);
    #endif // TASK
    Input();
    Solve();
}
