#include <bits/stdc++.h>
#define FILE "TEAWORLD"
#define pii pair <int,int>

using namespace std;
const int maxm=2e3+5, mn=5e2+5;

struct Data{ int x, y, z, r; } s, B[maxm], T[20];
struct Data_2{ int val, c; bool fg[maxm]; } f[1<<17];
int m, n, k, ans; bool s1;

void Build(int &a, int &b, int &c, int t)
{ a = s.y-T[t].y; b = T[t].x-s.x; c = -a*s.x - b*s.y; }

bool check_1_1(int u, int t)
{
    int c1 = B[u].x-T[t].x, c2 = B[u].y-T[t].y;
    return sqrt(c1*c1+c2*c2) > B[u].r;
}

bool check_1_2(int u)
{
    int c1 = B[u].x-s.x, c2 = B[u].y-s.y;
    return sqrt(c1*c1+c2*c2) > B[u].r;
}

bool check_2(int a, int b, int c, int u)
{
  return abs(a*B[u].x+b*B[u].y+c)/(sqrt(a*a+b*b)) > B[u].r;
}

void Hand_1()
{
    for (int i=0; i<(1<<n); i++)
    {
        if (f[i].c > k) continue;
        for (int t=0; t<n; t++)
        if (!((i>>t) &1))
        {
            int v = i + (1<<t);
            if (f[v].val > f[i].val+T[i].r) continue;
            f[v].val = f[i].val + T[i].r; f[v].c = f[i].c;
            int a, b, c; Build(a,b,c,t);
            for (int u=1; u<=m; u++) f[v].fg[u] = f[i].fg[u];
            for (int u=1; u<=m; u++)
                if (!f[i].fg[u])
                {
                    if (!check_1_1(u,t) && !check_2(a,b,c,u)) continue;
                    if (!check_1_1(u,t)) f[v].fg[u] = 1, f[v].c++;
                    else if (!check_1_2(u)) f[v].fg[u] = 1, f[v].c++;
                    else if (!check_2(a,b,c,u)) f[v].fg[u] = 1, f[v].c++;
                    if (f[v].c > k) break;
                }
        }
    }
    for (int i=0; i<(1<<n); i++) if (f[i].c <= k) ans = max(ans,f[i].val);
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin >> m >> n >> k;
    for (int i=1; i<=m; i++)
    {
        cin >> B[i].x >> B[i].y >> B[i].z >> B[i].r;
        if (B[i].z) s1 = 1;
    }
    for (int i=0; i<n; i++)
    {
        cin >> T[i].x >> T[i].y >> T[i].z >> T[i].r;
        if (T[i].z) s1 = 1;
    } cin >> s.x >> s.y >> s.z;
    Hand_1();
    return 0;
}
