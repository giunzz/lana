#include <bits/stdc++.h>
#define fi cin
#define fo cout
using namespace std;
typedef long long llint;
void LOAD();
void PROCESS();
const int N = (int)1e5+5;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("ARRANGE.INP", "r", stdin);
        freopen("ARRANGE.OUT", "w", stdout);
    #endif // ONLINE_JUDGE
    LOAD();
}

llint A[N], n;
void LOAD(){
     fi >> n;
     for (int i = 1; i <= n; ++i) fi >> A[i];
     PROCESS();
}

llint k;
llint res = 0;
void Subone(){
     llint sum = 0;
     for (int i = 1; i <= n; ++i) sum += A[i];
     k = sum / n;
     if (sum % n == 0){
         for (int i = 1; i <= n; ++i) res += abs(A[i] - k);
         fo << res;
         exit(0);
     }
}
void PROCESS(){
     Subone();

     for (int i = 1; i <= n; ++i)
         res += min(abs(A[i] - k), abs(A[i] - k - 1));
     fo << res;
}
