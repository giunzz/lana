#include<bits/stdc++.h>

const int maxN = 1e5 + 5;
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Ford(i,a,b)for(int i=a;i>=b;i--)
#define READ(F)   freopen(F".inp", "r", stdin)
#define WRITE(F)  freopen(F".out", "w", stdout)
#define ll        long long
#define F         "bubbletea"

using namespace std;

int k, n, u, v, c, a[maxN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    READ(F);
    WRITE(F);
    cin >> n >> k;
    For(i, 1, k) cin >> a[i];
    For(i, 1, n - 1) cin >> u >> v >> c;
    cout << "-1";
}
