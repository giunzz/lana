#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
int n, hi[maxn];

void sol(){
    int i = 1, j, pi = n, ma = 0, be = 0;
    while (i < pi){
        if (hi[i] < ma || ma == 0){
            j = n;
            while (j > i + be){
                ma = max(hi[j], ma);
                if(hi[i] < hi[j]) {
                    be = j - i;
                    break;
                }
                --j;
            }
            pi = n - be;
        }
        ++i;
    }
    if (be == 0) cout << -1;
    else cout << be;
}

void inp(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> hi[i];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TREES.INP", "r", stdin);
    freopen("TREES.OUT", "w", stdout);
    inp();
    if (n == 1) cout << -1;
    else sol();
    return 0;
}
