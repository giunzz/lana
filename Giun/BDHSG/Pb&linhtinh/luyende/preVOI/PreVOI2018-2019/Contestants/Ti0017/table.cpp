#include <bits/stdc++.h>
#define crys "table"

using namespace std;

int m, n, k, a[1001][1001], l[1001][1001], tx[1001][1001], ty[1001][1001], xd[1001][1001];

void dij(int xpi, int xpj, int kti, int ktj)
{
    for (int i=1; i<=m; ++i)
        for (int j=1; j<=n; ++j)
        {
            l[i][j]=0;
            tx[i][j]=0; ty[i][j]=0;
        }
    int so = kti - xpi + ktj - xpj;
    l[xpi][xpj] = a[xpi][xpj];
    for (int buoc = 0; buoc <= so-1; ++buoc)
    {
        for (int i=xpi; i<=kti; ++i)
        {
            if (i - xpi > buoc) break;
            int j = xpj + (buoc - (i-xpi));
            if (xd[i][j]) continue;
            int u = i+1, v = j;
            if (!xd[u][v] && l[u][v] < l[i][j] + a[u][v]) {l[u][v] = l[i][j]+a[u][v]; tx[u][v] = i; ty[u][v]=j;}
            u = i; v = j+1;
            if (!xd[u][v] && l[u][v] < l[i][j] + a[u][v]) {l[u][v] = l[i][j]+a[u][v]; tx[u][v] = i; ty[u][v]=j;}
        }
    }
}

void dij1(int xpi, int xpj, int kti, int ktj)
{
    for (int i=1; i<=m; ++i)
        for (int j=1; j<=n; ++j)
        {
            l[i][j]=0;
        }
    int so = kti - xpi + ktj - xpj;
    l[xpi][xpj] = a[xpi][xpj];
    for (int buoc = 0; buoc <= so-1; ++buoc)
    {
        for (int i=xpi; i<=kti; ++i)
        {
            if (i - xpi > buoc) break;
            int j = xpj + (buoc - (i-xpi));
            if (xd[i][j]) continue;
            int u = i+1, v = j;
            if (!xd[u][v] && l[u][v] < l[i][j] + a[u][v]) {l[u][v] = l[i][j]+a[u][v];}
            u = i; v = j+1;
            if (!xd[u][v] && l[u][v] < l[i][j] + a[u][v]) {l[u][v] = l[i][j]+a[u][v];}
        }
    }
}

void xuli()
{
    for (int i=1; i<=k; ++i)
    {
        int u, v, p, q;
        cin >> u >> v >> p >> q;
        dij(u,v,p,q);
        int pp = tx[p][q], qq = ty[p][q];
        int kq = 1e9;
        while (pp!=u && qq!=v)
        {
            xd[pp][qq]=1;
            dij1(u,v,p,q);
            kq = min(kq,l[p][q]);
            xd[pp][qq]=0;
            int p1 = tx[pp][qq], q1 = ty[pp][qq];
            pp = p1; qq = q1;
        }
        cout << kq << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(crys".inp", "r", stdin);
    freopen(crys".out", "w", stdout);
    cin >> m >> n >> k;
    for (int i=1; i<=m; ++i)
        for (int j=1; j<=n; ++j) cin >> a[i][j];
    xuli();
    return(0);
}
