// He always smiles :)
#include <bits/stdc++.h>
#define maxn 4005
#define mod 1000000007
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>
#define f first
#define s second
#define pb push_back
#define task "LIONDANCE"
#define ll long long
#define reset(x) memset(x, 0, sizeof(x))

using namespace std;
int n;
ll delta, l[maxn], r[maxn], p[maxn][maxn];
piii kq[maxn];
//void update(int x, int i)
//{
//    for ( ; x <= n ; x += x&(-x) ) t[x] = max(t[x], i);
//}
//int get(int x)
//{
//    int ma = 0;
//    for (int i = x - delta ; i <= x + delta ; i += i&(-1)) ma = max(ma, t[i]);
//    return ma;
//}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%lld", &n, &delta);
    for (int i = 1 ; i <= n ; i ++ ) scanf("%lld", &l[i]);
    for (int i = 1 ; i <= n ; i ++ ) scanf("%lld", &r[i]);
    for (int i = 1 ; i <= n ; i ++ ) kq[i].f = 0, kq[i].s.f = kq[i].s.s = 10*maxn;
    for (int i = 1 ; i <= n ; i ++ )
        for (int j = 1 ; j <= n ; j ++ )
    {
        if(l[i] == r[j])
        {
            int x;
            for (x = p[i-1][j-1] ; x ; x -- ) if(abs(kq[x].f-l[i]) <= delta && kq[x].s.f != i&& kq[x].s.s != j ) break;
            p[i][j] = x + 1;
            if(kq[p[i][j]].f < l[i] && i < kq[p[i][j]+1].s.f && j < kq[p[i][j]+1].s.s  ) kq[p[i][j]] = {l[i], {i, j}};
            p[i][j] = max(p[i][j], p[i-1][j-1]);
        }
        else p[i][j] = max(p[i-1][j], p[i][j-1]);
    }
    printf("%d\n", p[n][n]);
    for (int i = 1 ; i <= p[n][n] ; i ++) printf("%d ", kq[i].f);
    return 0;
}
