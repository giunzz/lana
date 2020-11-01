#include <bits/stdc++.h>
#define fi cin
#define fo cout
#define Pii pair<long long,long long>
using namespace std;
typedef long long llint;
void LOAD();
void PROCESS();
const int oo = (int)1e9+7;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("MINSUM.INP", "r", stdin);
        freopen("MINSUM.OUT", "w", stdout);
    #endif // ONLINE_JUDGE
    int T;
    fi >> T;
    for (int i = 1; i <= T; ++i) LOAD();
}

llint A, B;
void LOAD(){
     fi >> A >> B;
     PROCESS();
}

map<Pii, bool> M;
llint res = (llint)1e15+7;
int cnt, lim;
void DQ(llint u,llint v){
    if (M[{u, v}] != 0) return;
    llint sum = u + v;
    if ((u + v) < res){
        res = u + v;
        A = u;
        B = v;
    }
    cnt++;
    if (cnt > lim) return;
    M[{u, v}] = 1;
    for (int i = 2; i * i <= max(u, v); ++i){
         if (u % i == 0 && v % i == 0) DQ(u / i, v / i);
         if (u % i == 0) DQ(u / i, v * i);
         if (v % i == 0) DQ(u * i, v / i);
    }
    return;
}

void Subtwo(){
     llint k = __gcd(A, B);
     if (A / k > (int)1e6) lim = 50;
     DQ(A / k, B / k);
     fo << A <<" "<<B<<'\n';
}
void PROCESS(){
     res = oo;
     M.clear();
     lim = (int)1e4;
     if (A > 100 && B > 100) Subtwo();
     else{
        DQ(A, B);
        fo << A <<" "<< B <<'\n';
     }
}
