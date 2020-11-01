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

const int maxN = int(1e5 + 5);
int n, a[maxN];
int Input(){
    n = Read_Int();
    for(int i = 1 ; i <= n ; ++ i) a[i] = Read_Int();
    return 0;
}

int64_t Sum;
int Solve_Fake(){
    int k = Sum / n;
    int64_t ds = 0;
    for(int i = 1 ; i <= n ; ++ i){
        if(a[i] < k){
            for(int j = i + 1 ; j <= n ; ++ j){
                if(a[j] + a[i] == k) a[i] += a[j], ds += a[j] * (j - i), a[j] = 0;
                else if(a[j] + a[i] < k) a[i] += a[j], ds += a[j] * (j - i), a[j] = 0;
                else if(a[j] + a[i] > k) ds += (k - a[i]) * (j - i), a[j] -= k - a[i], a[i] = k;
                if(a[i] == k) break;
            }
        }
        else if(a[i] > k){
            ds += a[i] - k;
            a[i + 1] += a[i] - k;
        }
    }
    Write_Int64(ds);
    return 0;
}

int Solve_Brute(){
    //int kI = Sum % n, kII = n - Sum % n;
    int k = Sum / n;
    int64_t ds = 0;
    for(int i = 1 ; i <= n ; ++ i){
        if(a[i] < k){
            for(int j = i + 1 ; j <= n ; ++ j){
                if(a[j] + a[i] == k) a[i] += a[j], ds += a[j] * (j - i), a[j] = 0;
                else if(a[j] + a[i] < k) a[i] += a[j], ds += a[j] * (j - i), a[j] = 0;
                else if(a[j] + a[i] > k) ds += (k - a[i]) * (j - i), a[j] -= k - a[i], a[i] = k;
                if(a[i] == k) break;
            }
        }
        else if(a[i] > k + 1){
            ds += a[i] - k - 1;
            a[i + 1] += a[i] - k - 1;
        }
    }
    Write_Int64(ds);
    return 0;
}

int Solve(){
    Solve_Brute();
    return 0;
}

int Call(){
    Sum = 0;
    for(int i = 1 ; i <= n ; ++ i) Sum += a[i];
    if(Sum % n == 0) Solve_Fake();
    else if(n <= 2000) Solve_Brute();
    else Solve();
    return 0;
}
#define TASK "ARRANGE"
int main(){
    #ifdef TASK
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    #else
    freopen("main.inp","r",stdin);
    #endif // TASK
    Input();
    Call();
}
