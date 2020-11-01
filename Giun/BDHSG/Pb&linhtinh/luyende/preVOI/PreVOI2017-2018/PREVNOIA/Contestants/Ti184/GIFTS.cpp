#include<bits/stdc++.h>
const long long N = 1e6 + 5;
const long long inf = 1e18;
using namespace std;

ifstream fi ("GIFTS.inp");
ofstream fo ("GIFTS.out");

vector <long long> mv;
long long a[N], sum, f[N], g[N], ans = inf;
int n, k;

int main(){
    fi >> n >> k;
    for (int i = 1; i <= n; i++) fi >> a[i];
    for (int i = 1; i <= n; i++) {
        if (i > k) sum -= a[i-k]; sum += a[i];
        if (i >= k) mv.push_back(sum);
    }
    for (int i = 1; i <= (int)mv.size(); i++) f[i] = max(f[i-1], mv[i-1]);
    for (int i = (int)mv.size(); i >= 1; i--) g[i] = max(g[i+1], mv[i-1]);
    for (int i = 1; i+k-1 <= n; i++){
        long long x = ((i-k > 0) ? f[i-k] : 0), y = ((i+2*k-1 <= n) ? g[i+k] : 0);
        ans = min(ans, max(x, y));
    }
    fo << ans;
}
/*
10 2
1 2 4 5 2 4 2 2 1 6
*/
