/*********THACH THAO*********/

#include <bits/stdc++.h>
#define maxC 1000000007
#define maxn 107
#define Task "SEQUENCE"
#define pii pair <int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

int m, n, k, a[2][maxn], sae[maxn], save[maxn], vect1[maxn], vect2[maxn];
int d[2][maxn][maxn][maxn];

void in()
{
    cin >> m >> n >> k;
    for (int i = 1; i <= m; ++i) cin >> a[0][i];
    for (int i = 1; i <= n; ++i) cin >> a[1][i];
}

void calc(int id)
{
    int tt;
    if (id == 0) tt = m;
        else tt = n;
    for (int j = 1; j <= tt; ++j)
        for (int i = j; i <= tt; ++i)
        {
            int dem1 = 0, dem2 = 0, dem = 0;
            for (int t = 1; t <= j-1; ++t) vect1[++dem1] = d[id][i-1][j-1][t];
            vect1[++dem1] = a[id][i];
            if (!d[id][i-1][j][1])
            {
                for (int t = 1; t <= j; ++t) d[id][i][j][t] = vect1[t];
                continue;
            }
            for (int t = 1; t <= j; ++t) vect2[++dem2] = d[id][i-1][j][t];
            if (a[id][i] < vect2[dem2]) vect2[dem2] = a[id][i];
            for (int t = 1; t <= j; ++t)
                if (vect1[t] < vect2[t])
                {
                    for (int t = 1; t <= j; ++t) d[id][i][j][t] = vect1[t];
                    break;
                }
                else if (vect2[t] < vect1[t])
                {
                    for (int t = 1; t <= j; ++t) d[id][i][j][t] = vect2[t];
                    break;
                }
            if (!d[id][i][j][1]) for (int t = 1; t <= j; ++t) d[id][i][j][t] = vect1[t];
        }
}

void cal(int dm, int dn)
{
    int dem1 = 0, dem2 = 0;
    for (int i = 1; i <= dm; ++i) vect2[++dem2] = d[0][m][dm][i];
    for (int i = 1; i <= dn; ++i) vect1[++dem1] = d[1][n][dn][i];
    dem1 = 1; dem2 = 1;
    for (int i = 1; i <= k; ++i)
    {
        if (dem1 > dn)
        {
            sae[i] = vect2[dem2]; dem2++;
            continue;
        }
        if (dem2 > dm)
        {
            sae[i] = vect1[dem1]; dem1++;
            continue;
        }
        if ((vect1[dem1] < vect2[dem2]) || (vect1[dem1] == vect2[dem2] && vect1[dem1+1] < vect2[dem2+1])) sae[i] = vect1[dem1], dem1++;
            else sae[i] = vect2[dem2], dem2++;
    }
    for (int i = 1; i <= k; ++i)
        if (sae[i] < save[i] || !save[i])
        {
            for (int j = 1; j <= k; ++j) save[j] = sae[j];
            return;
        }
}

void solve()
{
    if (k == m+n)
    {
        int dm = 1, dn = 1;
        for (int i = 1; i <= k; ++i)
            if (a[0][dm] < a[1][dn] && dm <= m) save[i] = a[0][dm], dm++;
                else save[i] = a[1][dn], dn++;
        for (int i = 1; i <= k; ++i) cout << save[i] << " ";
    }
    else
    {
        calc(0);
        calc(1);
        if (m > n)
        {
            for (int dn = 0; dn <= n; ++dn)
            {
                int dm = k - dn;
                if (dm > m) continue;
                cal(dm, dn);
            }
        }
        else
        {
            for (int dm = 0; dm <= m; ++dm)
            {
                int dn = k - dm;
                if (dn > n) continue;
                cal(dm,dn);
            }
        }
        for (int i = 1; i <= k; ++i) cout << save[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(); cout.tie();
    freopen(Task".INP", "r", stdin);
    freopen(Task".OUT", "w", stdout);
	in();
    solve();
    return 0;
}
