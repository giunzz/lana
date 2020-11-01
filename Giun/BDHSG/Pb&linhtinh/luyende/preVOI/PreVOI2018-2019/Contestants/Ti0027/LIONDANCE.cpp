#include <bits/stdc++.h>
#define pii pair<int, int>
#define ft first
#define sd second
#define mp make_pair
#define pb push_back
using namespace std;
int n, x = 1, y = 1;
long long p, kc, a[4005], b[4005], c[8005], f[4000][4000], ma[4005][8005], mb[4005][8005];
void nhap()
{
    scanf("%d%lld", &n, &kc);
    for(int i = 1; i <= n; ++i) scanf("%lld", &a[i]), c[i] = a[i];
    for(int i = 1; i <= n; ++i) scanf("%lld", &b[i]), c[n+i] = b[i];
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("LIONDANCE.inp", "r", stdin);
    freopen("LIONDANCE.out", "w", stdout);
    nhap();
    for(int i = n; i; --i)
        for(int j = n; j; --j)
        {
            f[i][j] = max(f[i+1][j], f[i][j+1]);
            if(a[i] == b[j]) f[i][j] = max(f[i][j], f[i+1][j+1]+1);
        }
    sort(c+1, c+n*2+1);
    for(int i = n; i; --i)
    {
        int k = lower_bound(c+1, c+n*2+1, a[i]) - c;
        ma[i][k] = i;
        for(int j = i-1; j; --j)
            if(a[j] == a[i]) ma[j][k] = j;
            else ma[j][k] = ma[j+1][k];
    }
    for(int i = n; i; --i)
    {
        int k = lower_bound(c+1, c+n*2+1, b[i]) - c;
        mb[i][k] = i;
        for(int j = i-1; j; --j)
            if(b[j] == b[i]) mb[j][k] = j;
            else mb[j][k] = mb[j+1][k];
    }
    printf("%d\n", f[1][1]);
    for(int i = f[1][1]; i; --i)
    {
        int j = n*2;
        if(i != f[1][1]) j = upper_bound(c+1, c+n*2+1, p+kc) - c - 1;
        for(; j; --j)
            if(ma[x][j] && mb[y][j] && f[ma[x][j]][mb[y][j]] == i)
            {
                p = c[j];
                printf("%lld ", p);
                x = ma[x][j] + 1;
                y = mb[y][j] + 1;
                break;
            }
    }
}
