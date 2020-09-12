#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a, n, b = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> n;
    ll i = 0;
    while(LLONG_MAX/n >= i){
        b = max(b, a ^ (n * i++));
    }
    cout << b;
}