#include <bits/stdc++.h>
using namespace std;
long long t, a, b, c, r;

void sol(){
    long long tgian = abs(a - b), le = c - r, ri = c + r;
    if (le < a) le = a;
    if (ri > b) ri = b;
    if (le <= b && ri >= a) tgian = tgian - abs(ri - le);
    cout << tgian << "\n"; 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> a >> b >> c >> r;
        if (a > b) swap(a, b);
        sol();
    }
    return 0;
}