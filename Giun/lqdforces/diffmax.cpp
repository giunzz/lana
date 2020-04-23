#include <bits/stdc++.h>
#define imin INT_MIN
#define imax INT_MAX
#define prians cout << ans

using namespace std;
const int maxn = 1e5 + 7;
int n, a[maxn], ma = imin, mi = imax, num, vmi, vma, ans = 0; 

int main(){
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        ma = max(ma, a[i]);
        mi = min(mi, a[i]);
    }
    int i = 1;
    while (a[i] != ma){++i;}
    vmi = i, i = n;
    while (a[i] != mi){--i;}
    vma = i, ans = abs(vma - vmi);
    i = 1;
    while (a[i] != mi){++i;}
    vmi = i, i = n;
    while (a[i] != ma){--i;}
    vma = i, ans = max(ans, abs(vma - vmi));
    prians;
}