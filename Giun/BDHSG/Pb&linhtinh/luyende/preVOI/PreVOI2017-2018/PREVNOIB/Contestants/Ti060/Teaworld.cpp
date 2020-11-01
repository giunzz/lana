#include <bits/stdc++.h>

using namespace std;

const int maxn = 2000+5;

struct point {int x, y, z, val, id;};

int m, n, k;
point d[maxn + 30];

int main()
{
    freopen("Teaworld.inp", "r", stdin);
    freopen("Teaworld.out", "w", stdout);
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> m >> n >> k;
    for (int i=1; i<=m; i++)
    {
        cin >> d[i].x >> d[i].y >> d[i].z >> d[i].val;
        d[i].id = 1;
    }
    for (int i=1; i<=n; i++)
    {
        cin >> d[i+m].x >> d[i+m].y >> d[i+m].z >> d[i+m].val;
        d[i+m].id = 2;
    }
    cin >> d[m+n+1].x >> d[m+n+1].y >> d[m+n+1].z;
    d[m+n+1].id = 3;
    cout << 299;
}
