#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int n,m,k,t,res,cnt;
int a[3002],b[3002],d[3002],c[3002],ans[7002],tmp[7002];
void Update()
{
    if (res == 0)
    {
        for (int i = 1; i <= cnt; i++)
            ans[i] = tmp[i];
        res = cnt;
        return;
    }
    bool ok = 0;
    for (int i = 1; i <= res; i++)
        if (ans[i] > tmp[i]) {ok = 1; break;}
    if (ok) for (int i = 1; i <= res; i++) ans[i] = tmp[i];
    return;
}
void Tron(int m, int n)
{
    int i = 1, j = 1; cnt = 0;
    c[m+1] = 2e9; d[n+1] = 2e9;
    while (cnt <= m+n)
    {
        if (c[i] < d[j] || (c[i] == d[j] && c[i+1] <= d[j+1]))
        {
            tmp[++cnt] = c[i];
            i++;
        }
        else if (c[i] > d[j] || (c[i] == d[j] && c[i+1] > d[j+1]))
        {
            tmp[++cnt] = d[j];
            j++;
        }
        if (cnt == m+n) break;
    }
    Update();
}
int main()
{
    freopen("SEQUENCE.inp","r",stdin);
    freopen("SEQUENCE.out","w",stdout);
    scanf("%d%d%d",&m,&n,&k);
    for (int i = 1; i <= m; i++) scanf("%d",&a[i]);
    for (int i = 1; i <= n; i++) scanf("%d",&b[i]);
    for (int x = 0; x <= min(m+n-k,m); x++)
    {
        t = x;
        int j = 0,l = 0;
        for (int i = 1; i <= m; i++)
        {
            while (t > 0 && j > 0 && c[j] > a[i])
            {
                j--; t--;
            }
            c[++j] = a[i];
        }
        while (t > 0) {j--; t--;}
        t = m+n-k - x;
        for (int i = 1; i <= n; i++)
        {
            while (t > 0 && l > 0 && d[l] > b[i])
            {
                l--; t--;
            }
            d[++l] = b[i];
        }
        while (t > 0) {t--; l--;}
        Tron(j,l);
    }
    for (int i = 1; i <= res; i++) cout<<ans[i]<<' ';
}
