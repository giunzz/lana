#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a, n, b = LLONG_MAX;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> n;
    ll i = 0;
    // while(1e18/n >= i){
    //     b = min(b, a ^ (n * i++));
    //     cerr << 1;
    // }
    ll tmp = 1e18/n * n;
    // cerr << (a ^ 0);
    cout << (a ^ tmp);
    b = a ^ tmp;
    cerr << endl << tmp;
}