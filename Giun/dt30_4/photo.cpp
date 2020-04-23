#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
long long w[maxn], h[maxn], tw = 0, mh1 = 0, mh2 = 0, n, dm = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("photo.inp", "r", stdin);
    freopen("photo.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> w[i] >> h[i];
        tw += w[i];
        if (h[i] > mh1) mh1 = h[i], dm = 0;
        else if (h[i] == mh1) ++dm;
        else if (h[i] > mh2) mh2 = h[i];
    }
    for (int i = 1; i <= n; i++){
        if (dm != 0){
            cout << (tw - w[i])*(mh1) << " ";
        }
        else if (h[i] == mh1) cout << (tw - w[i])*(mh2) << " ";
        else cout << (tw - w[i])*(mh1) << " ";
    }
}   