#include <bits/stdc++.h>
#define pii pair<int, int>
#define ft first
#define sd second
#define mp make_pair
#define pb push_back
using namespace std;
int m, n, k, kt = 1, f[20], s = 0;
struct st
{
    int x, y, z, d;
} qc[2005], ch[20], gs;
void nhap()
{
    scanf("%d%d%d", &m, &n, &k);
    for(int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d%d", &qc[i].x, &qc[i].y, &qc[i].z, &qc[i].d);
        if(qc[i].y || qc[i].z) kt = 0;
    }
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d%d%d%d", &ch[i].x, &ch[i].y, &ch[i].z, &ch[i].d);
        if(ch[i].y || ch[i].z) kt = 0;
    }
    scanf("%d%d%d", &gs.x, &gs.y, &gs.z);
    if(gs.y || gs.z) kt = 0;
}
bool cmp(st a, st b)
{
    return (a.x < b.x);
}
main()
{
    freopen("TEAWORLD.inp", "r", stdin);
    freopen("TEAWORLD.out", "w", stdout);
    nhap();
    if(kt)
    {
        ch[n+1] = gs;
        sort(qc+1, qc+m+1, cmp);
        qc[m+1] = {1e9, 0, 0, 0};
        sort(ch+1, ch+n+2, cmp);
        int vt2, p = 1, q, vt1 = 1;
        for(int i = 1; i <= n+1; ++i)
        {
            f[i] = f[i-1] + ch[i].d;
            if(gs.x == ch[i].x) vt2 = i;
        }
        while(ch[vt1].x < qc[1].x-qc[1].d) vt1++;
        for(int i = vt1; i <= vt2; ++i)
        {
            while(p <= m && qc[p].x+qc[p].d < ch[i].x) p++;
            q = min(m+1, p+k);
            if(!k && gs.x >= qc[p].x-qc[p].d) q = qc[p].x + qc[p].d + 1;
            else q = qc[q].x - qc[q].d;
            if(gs.x < q)
            {
                int j = vt2;
                while(j <= n && ch[j+1].x < q) j++;
                s = max(s, f[j]-f[i-1]);
            }
        }
    }
    printf("%d", s);
}
