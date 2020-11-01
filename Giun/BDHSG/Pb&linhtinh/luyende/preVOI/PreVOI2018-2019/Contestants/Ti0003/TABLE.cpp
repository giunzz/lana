#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
const int N = 515;
const ll oo = 1e12 + 15;

int n, m, tmp, num, T;
ll res, ss;
int a[N][N], a1[N][N];
ll f[N][N], g[N][N], tn[N];

void sol()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            f[i][j] = g[i][j] = a1[i][j] = 0;
    int x, y, u, v;
    cin >> x >> y >> u >> v;
    int n1 = 0, m1 = 0;
    for (int i = x; i <= u; i++)
    {
        n1++, m1 = 0;
        for (int j = y; j <= v; j++)
            m1++, a1[n1][m1] = a[i][j];
    }

    /*cout <<"ss\n";
    //cout << n1 <<" "<< m1 <<"\n";
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= m1; j++) cout << a1[i][j] <<" "; cout <<"\n";
    }*/
    for (int i = 1; i <= n1; i++)
        for (int j = 1; j <= m1; j++)
            f[i][j] = max(f[i - 1][j], f[i][j - 1]) + 1LL*a1[i][j];
    for (int i = n1; i; i--)
        for (int j = m1; j; j--)
        {
            g[i][j] = max(g[i + 1][j], g[i][j + 1]) + 1LL*a1[i][j];
            //cout << i <<" "<< j <<" "<< g[i][j] <<"\n";
        }
    res = oo;
    for (int k = 3; k < (n1 + m1); k++)
    {
        //cout <<"ss "<< k <<"\n";
        num = 0;
        for (int i = 1; i <= min(n1, k - 1); i++)
        {
            int j = k - i;
            tn[++num] = f[i][j] + g[i][j] - a1[i][j];
        }
        sort(tn + 1, tn + 1 + num);
        res = min(res, tn[num - 1]);
    }
    cout << res <<"\n";

}

int main()
{
    #define file "TABLE"
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m >> T;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    while (T--) sol();

    return 0;
}
