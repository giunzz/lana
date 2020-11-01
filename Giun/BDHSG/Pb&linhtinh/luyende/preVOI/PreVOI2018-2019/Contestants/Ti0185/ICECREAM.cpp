#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
int MMAX, M50, M1, M2, n, res = 0;
void slove(int i, int m50, int m1, int m2){
    if (i > n){
        res++;
        res = res%MOD;
        return;
    }
    if (m50 < MMAX){
        slove(i + 1, m50 + 1, m1, m2);
    }
    if  (m1 < MMAX){
        if ( m50 > 0)
            slove(i + 1, m50 - 1, m1 + 1, m2);
        else return;
    }
    if ( m2 < MMAX){
        if (m1 > 0 && m50 > 0)
            slove(i + 1 , m50 - 1, m1 - 1, m2 + 1);
        else if (m50 >= 3)
            slove(i + 1 , m50 - 3, m1, m2 + 1);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("ICECREAM.INP", "r", stdin);
    freopen("ICECREAM.OUT", "w", stdout);
    cin >> n >> MMAX >> M50 >> M1 >> M2;
    slove(1, M50, M1, M2);
    cout << res%MOD;
}
