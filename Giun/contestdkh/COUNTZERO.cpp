#include <bits/stdc++.h>

using namespace std;
unsigned long long n;

int main(){
    freopen("COUNTZERO.INP", "r", stdin);
    freopen("COUNTZERO.OUT", "w", stdout);
    cin >> n;
    unsigned long long int ans = 0, i = 5;
    while (n / i != 0){
        ans += (n / i);
        i *= 5;
    }
    cout << ans;
    return 0;
}