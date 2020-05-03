#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define fi first
#define se second

using namespace std;

int n, m;
char a[1000007];

int pos(int i, int j)
{
    return (i - 1)*m + j;
}

int main()
{
    freopen("TILE.INP","r",stdin);
    freopen("TILE.OUT","w",stdout);
    io;
    cin >> n >> m;
    int r1 = 0, r2 = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) cin >> a[pos(i,j)];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (((i + j) & 1) == (a[pos(i,j)] - '0')) ++r1; else ++r2;

    cout << min(r1,r2);
    return 0;
}

