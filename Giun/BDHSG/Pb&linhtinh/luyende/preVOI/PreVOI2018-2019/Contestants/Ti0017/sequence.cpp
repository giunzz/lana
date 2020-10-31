#include <bits/stdc++.h>
#define crys "sequence"

using namespace std;

int m, n, sl, a[10001], b[10001], xd[3001][3001], dd[3001][3001], kq[10001], lv[10001], c[3001], d[3001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(crys".inp", "r", stdin);
    freopen(crys".out", "w", stdout);
    cin >> m >> n >> sl;
    for (int i=1; i<=m; ++i) cin >> a[i];
    for (int i=1; i<=n; ++i) cin >> b[i];
    if (sl==0) return(0);
    for (int i=1; i<=m; ++i)
    {
        for (int j=1; j<=m; ++j) xd[i][j] = xd[i-1][j];
        int vt = 0, so = 1e9;
        int k = m;
        while (true)
        {
            for (int j=k; j>=1; --j) if (xd[i][j]==1) {k = j-1; break;}
            else
            {
                if (so >= a[j]) {so = a[j]; vt = j;}
            }
            if (vt) break;
        }
        xd[i][vt]=1;
    }
    for (int i=1; i<=n; ++i)
    {
        for (int j=1; j<=n; ++j) dd[i][j]=dd[i-1][j];
        int vt = 0, so = 1e9;
        int k = n;
        while (true)
        {
            for (int j=k; j>=1; --j) if (dd[i][j]==1) {k = j-1; break;}
            else
            {
                if (so >= b[j]) {so = b[j]; vt = j;}
            }
            if (vt) break;
        }
        dd[i][vt]=1;
    }
    for (int i=1; i<=sl; ++i) kq[i]=1e9;
    for (int u=0; u<=m; ++u)
    {
        int v = sl - u;
        if (v>n) continue;
        int i = 0, j = 0, dem = 0;
        for (int k = 1; k<=m; ++k) if (xd[u][k]) c[++i]=a[k];
        for (int k = 1; k<=n; ++k) if (dd[v][k]) d[++j]=b[k];
        i = 1, j = 1;
        while (i <= u || j <= v)
        {
            int so1 = 1e9, so2 = 1e9;
            if (i <= u) so1 = c[i];
            if (j <= v) so2 = d[j];
            if (so1<=so2) {lv[++dem] = so1; ++i;}
                else {lv[++dem] = so2; ++j;}
        }
        for (int k=1; k<=sl; ++k) if (lv[k]<kq[k])
        {
            for (int o=1; o<=sl; ++o) kq[o]=lv[o];
            break;
        } else if (lv[k]>kq[k]) break;
    }
    for (int i=1; i<=sl; ++i) cout << kq[i] << " ";
    return(0);
}

