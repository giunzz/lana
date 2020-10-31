#include <bits/stdc++.h>
#define fi cin
#define fo cout
#define pb push_back
using namespace std;
void LOAD();
void PROCESS();
void SINH();
const int N = (int)5e3+5, oo = (int)1e9+7;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("TREE.INP", "r", stdin);
        freopen("TREE.OUT", "w", stdout);
    #endif // ONLINE_JUDGE
    LOAD();
    //SINH();
}

void SINH(){
     queue <int> Q;
     fo << 300 <<'\n';
     for (int i = 1; i <= 300; ++i) fo << 5000 <<" ";
     fo<<'\n';
     for (int i = 1; i <= 300; ++i){
          if (i * 2 <= 300) fo << i <<" "<<i*2 <<'\n';
          if (i * 2 + 1 <= 300) fo  << i <<" "<<i*2+1 <<'\n';
     }
}
int n, A[N];
vector <int> G[N];
void LOAD(){
     fi >> n;
     for (int i = 1; i <= n; ++i) fi >> A[i];
     int u, v;
     for (int i = 1; i <  n; ++i){
          fi >> u >> v;
          G[u].pb(v);
          G[v].pb(u);
     }
     PROCESS();
}

vector <int> P[N];
bool Mark[N];
void DFS(int u){
     Mark[u] = 1;
     for (int i = 0; i < G[u].size(); ++i)
          if (Mark[ G[u][i] ] == 0){
              P[u].pb(G[u][i]);
              DFS(G[u][i]);
          }
}

int res = oo, F[N][4100];
int  Dp(int u,int k){
     if (F[u][k] != -1) return F[u][k];
     if (P[u].size() == 0 && k > 1) return F[u][k] = oo;
     else
        if (P[u].size() == 0) return F[u][k] = abs(A[u] - k);
     int sum = oo;
     if (P[u].size() == 2){
         for (int i = 0; i <= k; ++i)
              sum = min(sum, Dp(P[u][0], i) + Dp(P[u][1], k - i));
     }
     if (P[u].size() == 1)
         sum = Dp(P[u][0], k);
     sum += abs(A[u] - k);
     return F[u][k] = sum;
}

void Go(int  u,int val){
     res += abs(A[u] - val);
     for (int i = 0; i < P[u].size(); ++i)
          if (P[u].size() == 2) Go(P[u][i], val / 2);
          else Go(P[u][i], val);
}
void EnSub(){
     res = 0;
     int k = log2(n);
     k = (1 << k);
     Go(1, k);
     fo << res;
     exit(0);
}
void PROCESS(){
     DFS(1);
     int lim = (1 << (int)log2(n));
     for (int i = 1; i <= n; ++i)
          for (int j = 0; j <= lim; ++j) F[i][j] = -1;
     if (n > 1000) EnSub();

     for (int i = 1; i <= lim; ++i)
          res = min(res, Dp(1, i));

     fo << res;
}
