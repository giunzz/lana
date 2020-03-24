#include <bits/stdc++.h>

using namespace std;
const int maxn = 3e5 + 7;
int h[maxn], n, k, h2[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("bgames.inp", "r",stdin);
    freopen("bgames.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> h[i];
        h2[i] = h[i];
    }
    sort(h2 + 1, h2 + 1 + n);
    
}