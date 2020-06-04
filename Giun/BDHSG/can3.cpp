#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define lpdk(a, b, c, d) for(ll a = b; c; d) 
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define vecite(a) vector<a>::iterator
#define fi first
#define se second
using namespace std;
cll MOD = 1e9 + 7;
const string tenfile = "f";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

// ll a[40] = {0}, f[40][40] = {{0}}, m, sr, sl, alp, s = 0, d[37] = {0};
// vec(ll) ansr, anrl;

// int main(){
//     opt;
//     file;
//     a[0] = 1;
//     lp(i, 1, 37) a[i] = a[i - 1] * 3;
//     cin >> m;
//     lp(i, 0, 37 && (s + a[i] <= m)) alp = i, s += a[i];
//     s = m;
//     while(1){
//         // chuyen m sang so he co so 3
//         // bruce A sang he co so 3: 0 & 1 M + A = B voi A B chi co 0 va 1 A & B = 0
//         // duyet vi tri i o so m o he co so 3: 0 thi ko tang o B, 1 thi tang o B tai vi tri i, 2 thi tang A tai i va tang B o i + 1, neu i + 1 B va i o m deu = 1 tang i+ 1 tai A tang i + 2 tai B bo i + 1
//         lpd(i, alp, 0){
//             s += a[i];
//             d[i] = 1;
//             lpd(i, alp + 2, 0){
                
//             }
//         }
//     }
// }

ll m;
vec(ll) m3, a, b;

void doicoso(ll a){
    while(a != 0){
        m3.push_back(a % 3);
        m /= 3;
    }
}

ii main(){
    opt;
    file;
    cin >> m;
    doicoso(m);
    a.resize(m3.size());
    b.resize(m3.size());
    reverse(m3.begin(), m3.end());
    lp(i, 0, m3.size() - 1){
        
    }
}