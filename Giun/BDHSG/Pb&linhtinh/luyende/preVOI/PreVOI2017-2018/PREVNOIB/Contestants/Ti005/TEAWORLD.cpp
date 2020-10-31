#include <bits/stdc++.h>
#define fi cin
#define fo cout
#define Pii pair<int,int>
#define x first
#define y second
using namespace std;
void LOAD();
void PROCESS();
struct Data{
       int x, y, z, r;
};
const int N = 2e3+5;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("TEAWORLD.INP", "r", stdin);
        freopen("TEAWORLD.OUT", "w", stdout);
    #endif // ONLINE_JUDGE
    LOAD();
}

int n, m, k;
Data B[N], T[N];
void LOAD(){
     fi >> m >> n >> k;
     for (int i = 1; i <= m; ++i)
          fi >> B[i].x >> B[i].y >> B[i].z >> B[i].r;
     for (int i = 1; i <= n; ++i)
          fi >> T[i].x >> T[i].y >> T[i].z >> T[i].r;
     fi >> T[n+1].x >> T[n+1].y >> T[n+1].z;
     PROCESS();
}

int cnt, res;
bool Mark[N];
double Dis(int u, int v){
       int x = (T[u].x - T[v].x) * (T[u].x - T[v].x);
       int y = (T[u].y - T[v].y) * (T[u].y - T[v].y);
       int z = (T[u].z - T[v].z) * (T[u].z - T[v].z);
       return sqrt(x + y + z);
}
double DisB(int u,int v){
       int x = (T[u].x - B[v].x) * (T[u].x - B[v].x);
       int y = (T[u].y - B[v].y) * (T[u].y - B[v].y);
       int z = (T[u].z - B[v].z) * (T[u].z - B[v].z);
       return sqrt(x + y + z);
}
int Cross(int u, int v, int p){
    Pii AB = make_pair(B[v].x - T[u].x, B[v].y - T[u].y);
    Pii AC = make_pair(B[v].x - T[p].x, B[v].y - T[p].y);
    return AB.x * AC.y - AB.y * AC.x;
}

int Dot(Data A, Data B, Data C){
    Pii BA = make_pair(B.x - A.x, B.y - A.y);
    Pii BC = make_pair(B.x - C.x, B.y - C.y);
    return BA.x * BC.x + BA.y * BC.y;
}
double Kc(int u,int i,int k){
       int S = abs(Cross(u, i, n+1));
       double d= Dis(u, k);
       int Cor = Dot(B[i],T[u], T[k]);
       if (Cor < 0) return DisB(u, i);
       Cor = Dot(B[i], T[k], T[u]);
       if (Cor < 0) return DisB(k, i);
       return (double)S / d;
}
int check;
void Update(int u){
     for (int i = 1; i <= m; ++i){

          double d = Kc(u, i, n+1);

          if (d <= B[i].r && (DisB(u, i) > B[i].r || DisB(n+1, i) > B[i].r)){
              if (Mark[i] == 0) cnt++;
              Mark[i] = 1;
          }
     }
}

bool GetBit(int k,int pos){
     return (k >> pos ) & 1;
}
void PROCESS(){
     for (int i = 1; i <= (1 << n); ++i){
          check = i;
          for (int j = 1; j <= m; ++j) Mark[j] = 0;
          cnt = 0;
          int sum = 0;
          for (int j = 0; j < n; ++j)
               if (GetBit(i, j)){
                   Update(j+1);
                   sum += T[j+1].r;
               }

          if (cnt <= k) res = max(res, sum);
     }
     fo << res;
}
