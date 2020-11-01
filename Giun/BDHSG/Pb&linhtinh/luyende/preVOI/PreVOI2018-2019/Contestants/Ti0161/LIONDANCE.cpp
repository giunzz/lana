/*********THACH THAO*********/

#include <bits/stdc++.h>
#define maxC 1000000007
#define maxn 4007
#define Task "LIONDANCE"
#define pii pair <int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

int read()
{
    int x;
    char c;
    while(!isdigit(c = getchar()));
    x = c - 48;
    while(isdigit(c = getchar())) x = x * 10 + c - 48;
    return x;
}

int n, k, l[maxn], r[maxn], ans = 0, save[maxn], luu[maxn], d[maxn];

void in()
{
    n = read(); k = read();
    for (int i = 1; i <= n; ++i) l[i] = read();
    for (int i = 1; i <= n; ++i) r[i] = read();
}

void Check()
{
    int dem = 0, po = 1;
    for (int i = 1; i <= n; ++i)
        if (d[i])
        {
            dem++;
            luu[dem] = l[i];
        }
    if (!dem) return;
    for (int i = 2; i <= dem; ++i)
        if (abs(luu[i]-luu[i-1]) > k) return;
    for (int i = 1; i <= n; ++i)
        if (r[i] == luu[po]) po++;
    if (po <= dem) return;
    if (ans < dem)
    {
        ans = dem;
        for (int i = 1; i <= dem; ++i) save[i] = luu[i];
    }
    if (ans == dem)
    {
        for (int i = 1; i <= dem; ++i)
        {
            if (save[i] < luu[i])
            {
                for (int i = 1; i <= dem; ++i) save[i] = luu[i];
                return;
            }
            else if (save[i] > luu[i]) return;
        }
    }
}

void Backtrack(int id)
{
    if (id > n)
    {
        Check();
        return;
    }
    for (int i = 0; i <= 1; ++i)
    {
        d[id] = i;
        Backtrack(id+1);
    }
}

void solve()
{
    Backtrack(1);
    cout << ans << "\n";
    for (int i = 1; i <= ans; ++i) cout << save[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(); cout.tie();
    freopen(Task".INP", "r", stdin);
    freopen(Task".OUT", "w", stdout);
	in();
    solve();
    return 0;
}
