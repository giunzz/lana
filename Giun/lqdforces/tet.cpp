#include <bits/stdc++.h>
#define FOR(a, b, c) for(long long a = b; a <= c; a++)
#define FORD(a, b, c) for (long long a = b; a >= c; a--)

using namespace std;
const long long maxn = 1e5 + 7;
long long n, a[maxn], k, m, ans = 0, i;

void sol(){
    if (i + k - 1 < k){
        FORD(j, i + k - 1, 1){
            ans += a[j];
        }
        return;
    }
    long long check = 0;
    FOR(j, i, i + k - 1){
        check += a[j];
    }
    if (check > a[i + k - 1] && m > 0){
        ans += a[i + k - 1], --m;
    }
    else {
        ans += check;
    }
    //cerr << endl << ans << " " << i;
    FORD(j, i - 1, 1) ans += a[j];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
    cin >> n >> k >> m;
    FOR(i, 1, n){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    i = n - k + 1;
    while (a[i] >= 0 && i >= 1 && m > 0){
        ans += a[i + k - 1], i -= k, --m;
    }
    //cerr << i << " " << m;
    sol();
    cout << ans;
}