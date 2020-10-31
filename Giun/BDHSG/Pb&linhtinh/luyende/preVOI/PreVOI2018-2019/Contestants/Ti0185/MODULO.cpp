#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int A, B, n, k;
ll MOD;
string x ,y;
void slove(int i, ll S, string a){
    if ( i > n){
        if (S % MOD == k){
            cout << a;
            exit(0);
        }
        return;
    }
    slove(i + 1, (S * 10 + ll(A)) % MOD, a + x);
    slove(i + 1, (S * 10 + ll(B)) % MOD, a + y);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("MODULO.INP", "r", stdin);
    freopen("MODULO.OUT", "w", stdout);
    cin >> A >> B >> n >> k;
    x = char(A) + '0';
    y = char(B) + '0';
    MOD = 2 << (n - 1);
    string a = "";
    slove(1, 0 ,a);
    cout << -1;
}
