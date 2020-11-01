#include <bits/stdc++.h>
#define FILE "SEQUENCE"
#define long long long

using namespace std;
const int maxn=3e3+5;

int m, n, k, a[maxn], b[maxn];
int s[2*maxn], t[2*maxn], d[2][maxn][maxn];
int cur = 1, pre = 0, p[2][2*maxn];

void Spec()
{
    for (int i = 1; i <= m; ++i) s[i] = t[i+n] = a[i];
    for (int i = 1; i <= n; ++i) t[i] = s[i+m] = b[i];

    for (int i = 1; i <= k; ++i)
        if (s[i] < t[i]){ for (int j = 1; j <= k; ++j) cout << s[j] << " "; return; }
        else if (s[i] > t[i]){ for (int j = 1; j <= k; ++j) cout << t[j] << " "; return; }

    for (int j = 1; j <= k; ++j) cout << s[j] << " ";
}

bool checka(int i, int l)
{
    for (int j = 0; j < l; ++j)
        if (a[i+j] < a[s[l]+j]) return 1;
        else if (a[i+j] > a[s[l]+j]) return 0;
    return 0;
}

bool checkb(int i, int j, int l)
{
    for (int z = 0; z < l; ++z)
        if (b[i+z] < b[j+z]) return 0;
        else if (b[i+z] > b[j+z]) return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin >> m >> n >> k;
    for (int i = 1; i <= m; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];

    if (k == m+n){ Spec(); return 0; }

    for (int j = 1; j <= m; ++j) s[j] = 1;
    for (int i = 2; i <= m; ++i)
        for (int l = 1; l <= m-i+1; ++l) if (checka(i, l)) s[l] = i;

    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j) d[0][i][j-i+1] = d[1][j][j-i+1] = i;

    for (int i = n-1; i >= 1; --i)
        for (int l = 1; l <= n-i+1; ++l) if (checkb(i, d[0][i+1][l], l)) d[0][i][l] = d[0][i+1][l];

    for (int i = 1; i <= min(k, m); ++i) t[i] = a[i];
    for (int i = 1; i <= min(k-m, n); ++i) t[m+i] = b[i];

    for (int i = 0; i <= m; ++i)
    {
        for (int j = s[i]; j <= s[i]+i-1; ++j) p[cur][j] = p[pre][j+i] = a[j];
        for (int j = d[0][1][k-i]; j <= d[0][1][k-i]+k-i+1; ++j) p[cur][j+i] = p[pre][j] = b[j];

        for (int j = 1; j <= k; ++j) if (p[pre][j] > p[cur][j]){ swap(cur, pre); break; }

        for (int j = 1; j <= k; ++j)if (t[j] > p[cur][j]){ for (int z = 1; z <= k; ++z) t[z] = p[cur][z]; break; }
    }

    for (int i = 1; i <= k; ++i) cout << t[i] << " ";
    return 0;
}
