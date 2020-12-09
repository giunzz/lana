#include <bits/stdc++.h>
#define ll long long
#define ii int
#define cll const ll
#define cii const ii
#define lp(a, b, c) for(ii a = b; a <= c; ++a)
#define lpd(a, b, c) for(ii a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

// f[len][sum][ok] la so luong so co final cham toi sum

cll MOD = 1e9 + 7, MAXS = 1027;
class ASCIISum{
    private:
    ll n, L;
    ll dp[20][MAXS + 7] = {{0}}, freq[MAXS + 7] = {{0}};
    vec(ii) digs;
    public:
    ii total(ll _n);
};

ll f(ll num){
    ll tmp = 0;
    while(num) tmp += (num % 10) + '0', num /= 10;
    return tmp;
}

// asciisum topcoder, find a car codeforces, familiar digit

ii ASCIISum::total(ll _n){
    this -> n = _n;
    while(n) digs.push_back(n % 10), n /= 10;
    this -> L = digs.size();
    // for(int l = 1; l < L; l++){
    //     for(int d = 1; d < 10; d++){
    //         int v = '0' + d; // The contribution of the most significant digit.
    //         for(int s = 0; s + v < MAXS; s++){
    //             freq[s + v] += dp[l - 1][s]; // The remaining l - 1 digits have ascii sum s
    //         }
    //     }
    // }
    // return sol();
    int s = 0;
    for(int i = L - 1; i >= 0; i--){
        // All digits at positions > i are the same in n and N, and the sum of ascii values at these positions is s
        for(int d = (i==L-1); d < digs[i]; d++){ // If i == L - 1, we can't have the first digit as 0
            int v = '0' + d; // the i-th digit in n
            for(int x = 0; x + v + s < MAXS; x++){
                // x = ascii sum in the remaining i digits.
                // Total sum = x + v + s
                freq[x + v + s] += dp[i][x];
            }
        }
        s += '0' + digs[i];
    }
    freq[s]++; // add the contribution of n = N
    ll res = 0;
    lp(i, 1, MAXS - 1) (res += freq[i] * f(i)) %= MOD;
    return res;
}

// 48 * len + sumdigit = sum

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    ASCIISum tmp;
    cerr << tmp.total(3);
}