#include <bits/stdc++.h>
#define maxn 2005
#define maxC 1000000007
#define Reset(d, a) memset(d, a, sizeof(d))
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i >= b; --i)
#define Length(a) int(a.length())
#define Size(a) int(a.size())
#define F first
#define S second
#define Task "TEAWORLD"

using namespace std;

int m, n, k, x[maxn], y[maxn], z[maxn], xx[maxn], yy[maxn], zz[maxn], r[maxn], e[maxn];
int dem1 = 0, dem2 = 0, a[maxn] = {1}, answer = 0;
bool dd[maxn];

void Setup()
{
    cin >> m >> n >> k;
    FOR(i, 1, m) cin >> x[i] >> y[i] >> z[i] >> r[i], dem1 += (y[i] == 0 && z[i] == 0), dem2 += (z[i] == 0);
    FOR(i, 1, n) cin >> xx[i] >> yy[i] >> zz[i] >> e[i], dem1 += (yy[i] == 0 && zz[i] == 0), dem2 += (zz[i] == 0);
    cin >> xx[0] >> yy[0] >> zz[0];
    dem1 += (yy[0] == 0 && zz[0] == 0);
    dem2 += (zz[0] == 0);
}

//x[j] - r[j] <= xx[0] && xx[0] <= x[j] + r[j]

void Process_1(int id)
{
    if (id > n)
    {
        int dem = 0, result = 0;
        FOR(i, 0, n)
            if (a[i])
                FOR(j, 1, m)
                {
                    if (!dd[j] && x[j] - r[j] <= xx[i] && xx[i] <= x[j] + r[j])
                    {
                        dd[j] = true;
                        dem++;
                    }
                    if(dem <= k) answer += e[i];
                        else return;
                }
        answer = max(answer, result);
        return;
    }
    FOR(i, 0, 1)
    {
        a[id] = i;
        Process_1(id + 1);
    }
}

bool Check(int i, int j)
{
    int aa = yy[0] - yy[i];
    int bb = xx[i] - xx[0];
    int cc = -xx[0] * (yy[0] - yy[i]) + yy[0] * (xx[0] - xx[i]);
    return (abs(aa * x[j] + bb * y[j] + cc) / (aa * aa + bb * bb) <= r[j]);
}

void Process_2(int id)
{
    if (id > n)
    {
        int dem = 0, result = 0;
        FOR(i, 0, n)
            if (a[i])
                FOR(j, 1, m)
                {
                    if (!dd[j] && Check(i, j))
                    {
                        dd[j] = true;
                        dem++;
                    }
                    if(dem <= k) answer += e[i];
                        else return;
                }
        answer = max(answer, result);
        return;
    }
    FOR(i, 0, 1)
    {
        a[id] = i;
        Process_2(id + 1);
    }
}

void Process_3()
{
    FOR(i, 1, n) answer += e[i];
}

void Operate()
{
    if (dem1 == m + n + 1) Process_1(1);
        else if (dem2 == m + n + 1) Process_2(1);
            else Process_3();
    cout << answer;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);

    Setup();
    Operate();
}
