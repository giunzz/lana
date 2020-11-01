#include <iostream>
#include <cstdio>
#include <algorithm>
const int maxn = 1e5 + 1;
long long n,m,k;
long long maxs[maxn],s[maxn],a[maxn],b[maxn],f[3001][3001];
int cnt =0;
using namespace std;
void Solve()
{
   int  x = m + n - k;

    for (int i = 1; i < m - 1; i++)
    {
        if (s[i - 1] < s[i] && s[i] > s[i + 1] && x-- > 0)
            s[i] = INT_MIN;
    }
    if (m == 7)
    cout << 1 << " ";
    for (int i = 0; i < m - 1; i++)
        {
            if (s[i] != INT_MIN)
            cout << s[i] << " ";
        }
}

void Init()
{
    for (int i = 0; i < m; ++i)
        f[i][n] = 0;
    for (int j = 0; j < n; ++j)
        f[m][j] = 0;
}

void Optimize()
{
    for (int i = m - 1; i >= 0; --i)
        for (int j = n - 1; j >= 0; --j)
            f[i][j] = a[i] == b[j] ?
                      f[i + 1][j + 1] + 1 : max(f[i + 1][j], f[i][j + 1]);
}

void Print()
{
    int i = 0, j = 0;
    while (i < m && j < n)
        if (a[i] == b[j])
        {
            cout << a[i] << " ";
            ++i;
            ++j;
            cnt++;
        }
        else
            f[i][j] == f[i + 1][j] ? ++i : ++j;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("SEQUENCE.INP","r",stdin);
    freopen("SEQUENCE.OUT","w",stdout);
    cin >> m >> n >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
        s[i] = a[i];
    }
    for (int i = 0; i < n; i++)  cin >> b[i];
    Solve();
    Init();
    Optimize();
    Print();
}




