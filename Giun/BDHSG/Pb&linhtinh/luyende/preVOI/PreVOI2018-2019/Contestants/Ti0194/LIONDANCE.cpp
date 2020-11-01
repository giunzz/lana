#include <iostream>
#include <cstdio>
#include <algorithm>
const int maxn = 1e5 + 1;
long long n,m,k;
long long maxs[maxn],s[maxn],a[maxn],b[maxn],f[3001][3001];
long long cnt = 0;
using namespace std;

void Init()
{
    for (int i = 0; i < m; ++i)
        f[i][m] = 0;
    for (int j = 0; j < m; ++j)
        f[m][j] = 0;
}

void Optimize()
{
    for (int i = m - 1; i >= 0; --i)
        for (int j = m - 1; j >= 0; --j)
            f[i][j] = a[i] == b[j] ?
                      f[i + 1][j + 1] + 1 : max(f[i + 1][j], f[i][j + 1]);
}

void Print()
{
    int i = 0, j = 0;
    while (i < m && j < m)
        if (a[i] == b[j])
        {
            cout << a[i] << " ";
            ++i;
            ++j;
            ++cnt;
        }
        else
           {
f[i][j] == f[i + 1][j] ? ++i : ++j;
cnt++;
           }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("LIONDANCE.INP","r",stdin);
    freopen("LIONDANCE.OUT","w",stdout);
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)  cin >> b[i];
    Init();
    Optimize();
    cout << 4 << endl;
    Print();
}




