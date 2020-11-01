#include <bits/stdc++.h>
#define fi cin
#define fo cout
using namespace std;
typedef long long llint;
void LOAD();
void PROCESS();
const int N = (int)1e6+5;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("GIFTS.INP", "r", stdin);
        freopen("GIFTS.OUT", "w", stdout);
    #endif // ONLINE_JUDGE
    LOAD();
}

int n, k;
llint A[N];
void LOAD(){
     fi >> n >> k;
     for (int i = 1; i <= n; ++i){
          fi >> A[i];
          A[i] += A[i-1];
     }
     PROCESS();
}

int m;
llint res = (llint)1e15+7;
llint L[N], R[N];
void Prepare(){
     for (int i = k; i <= n; ++i)
          L[i] = max(L[i-1], A[i] - A[ i - k ]);
     for (int i = n; i >= k; --i)
          R[i] = max(R[i+1], A[i] - A[ i - k ]);
}

void PROCESS(){
     Prepare();
     for (int i = k ; i <= n; ++i){
          llint x = A[i] - A[i - k];
          if (x >= L[i - k] && x >= R[ i + k ]) res = min(res, x);
     }
     fo << res;
}
