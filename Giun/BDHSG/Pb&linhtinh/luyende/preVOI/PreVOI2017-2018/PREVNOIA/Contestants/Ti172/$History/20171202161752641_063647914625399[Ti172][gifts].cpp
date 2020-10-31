#include <iostream>
#include <cstdio>

using namespace std;

int n, i, b[1000001], f[1000001], j, kq(0), m, a;
bool flag[1000001];

inline void fastRead_int(int &a)
{
    register char c=0;
    while (c<33) c=getchar(); a=0;
    while (c>33)
    {
        a= a*10+c-'0';
        c=getchar();
    }
}

void Init()
{
    //cin >> m;
    fastRead_int(m);
    fill (flag + 1, flag + 1000001, true);
    for (i = 1; i <= 1000001; i++) f[i] = i;
    for (i = 1; i <= m; i++) //cin >> b[i];
        fastRead_int(b[i]);
}

void Solve()
{
    //cin >> n;
    fastRead_int(n);
    for (i = 1; i <= n; i++)
    {
        fastRead_int(a); j = 0;
        while (j < a && f[a] <= 1e6)
        {
            if (flag[f[a]])
            {
                flag[f[a]] = false; j++;
            }
            f[a] += a;
        }
        //cout << f[a[i]] << " ";
    }

    for (i = 1; i <= m; i++) if (flag[b[i]] == false) kq++;
    cout << kq;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    freopen("gifts.inp", "r", stdin);
    //freopen("gifts.out", "w", stdout);

	Init();
	Solve();
}
//Date 25 Month 2 Year 2017


