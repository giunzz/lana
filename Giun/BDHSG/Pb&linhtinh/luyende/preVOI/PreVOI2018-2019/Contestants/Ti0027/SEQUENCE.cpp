#include <bits/stdc++.h>
#define pii pair<int, int>
#define ft first
#define sd second
#define mp make_pair
#define pb push_back
using namespace std;
int m[2], k, a[2][3005], f[2][3005][3005], p[2][3005], kq[6005];
void nhap()
{
    scanf("%d%d%d", &m[0], &m[1], &k);
    for(int h = 0; h < 2; ++h)
        for(int i = 1; i <= m[h]; ++i) scanf("%d", &a[h][i]);
}
void xl(int x, int y)
{
    int z = 1;
    p[x][0] = 0;
    while(y)
    {
        p[x][++p[x][0]] = a[x][f[x][z][y]];
        z = f[x][z][y] + 1, y--;
    }
    p[x][p[x][0]+1] = 1e9;
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("SEQUENCE.inp", "r", stdin);
    freopen("SEQUENCE.out", "w", stdout);
    nhap();
    for(int h = 0; h < 2; ++h)
        for(int j = 1; j <= min(k, m[h]); ++j)
        {
            f[h][m[h]-j+1][j] = m[h] - j + 1;
            for(int i = m[h]-j; i; --i)
                if(a[h][i] <= a[h][f[h][i+1][j]]) f[h][i][j] = i;
                else f[h][i][j] = f[h][i+1][j];
        }
    memset(kq, 60, sizeof(kq));
    for(int h = max(0, k-min(m[0], m[1])); h <= min(k, m[0]); ++h)
    {
        xl(0, h), xl(1, k-h);
        int x = 1, y = 1, q;
        for(int i = 1; i <= k; ++i)
        {
            if(p[0][x] == p[1][y])
            {
                if(p[0][x+1] < p[1][y+1]) q = p[0][x++];
                else q = p[1][y++];
            }
            else if(p[0][x] < p[1][y]) q = p[0][x++];
            else q = p[1][y++];
            if(q <= kq[i]) kq[i] = q;
            else break;
        }
    }
    for(int i = 1; i <= k; ++i) printf("%d ", kq[i]);
}
