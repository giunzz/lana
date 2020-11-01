#include <bits/stdc++.h>
#define FILE "MODULO"
#define long long long

using namespace std;
const int maxn=+5;

int A, B, n, cnt; unsigned long k, M, p[65];

int backtrack(int c, long R)
{
    if (cnt == 3e7) return 0; cnt++;
    if (c == n){ if (R == k) return 1; return 0; } c++;
    if (backtrack(c, (R +p[c]*A) %M)){ cout << A; return 1; }
    if (backtrack(c, (R +p[c]*B) %M)){ cout << B; return 1; }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin >> A >> B >> n >> k; M = (1LL<<n);
    p[1] = 1; for (int i = 2; i <= n; ++i) p[i] = p[i-1]*10 %M;
    if (!backtrack(0, 0)) cout << -1;
    return 0;
}
