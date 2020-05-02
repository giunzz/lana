#include <bits/stdc++.h>

using namespace std;
const int maxs = 1e5;
long long int sum[maxs + 5];
int num, n, k, q, p;

void tinh(){
    for (int i = 2; i <= n; i++){
        cin >> num;
        sum[i] = sum[i - 1] + num;
    }
}

int main(){
    freopen("sum.INP", "r", stdin);
    freopen("sum.OUT", "w", stdout);
    cin >> n >> k;
    cin >> sum[1];
    tinh();
    for (int i = 0; i != k; i++){
        cin >> p >> q;
        cout << sum[q] - sum[p - 1] << endl;
    }
    return 0;
}
