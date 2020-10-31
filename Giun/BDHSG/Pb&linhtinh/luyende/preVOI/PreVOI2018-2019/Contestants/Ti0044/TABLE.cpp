#include <bits/stdc++.h>

#define fn "test"
#define fn1 "TABLE"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 3 * (int)(1e2) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;

void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (ifstream(fn".inp"))
    {
        freopen(fn".inp", "r", stdin);
        if (!aNs) freopen(fn".out", "w", stdout);
		else freopen (fn".ans", "w", stdout);
    }else if (ifstream(fn1".inp"))
    {
        freopen(fn1".inp", "r", stdin);
        freopen(fn1".out", "w", stdout);
    }
}

template <typename T>
void read(T& x)
{
    x = 0; T f = 1;
    char ch = getchar();
    while (!isdigit(ch)) f = ch == '-' ? - f : f, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    x *= f;
}

template <typename T>
void write (T a)
{
    if (a < 0)
    {
        putchar ('-');
        write (-a);
        return;
    }
    if (a < 10)
    {
        putchar ('0' + a);
        return;
    }
    write (a / 10);
    putchar ((char)('0' + (a % 10)));
}

int d[mm][mm], a[mm][mm];
bool ok[mm][mm];
int m, n, k;
int hx[2] = {0, 1};
int hy[2] = {1, 0};
pair<int, int> tr[mm][mm];
bool pl[mm][mm];

bool kt (int x, int y)
{
    return (x >= 1 && x <= m && y >= 1 && y <= n && !ok[x][y]);
}

void enter()
{
    read (m); read (n); read (k);
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    read (a[i][j]);
    for (int i = 0; i < k; ++ i)
    {
        int u, v, p, q;
        read (u); read (v); read (p); read (q);
        queue<pair<int, int> > qu;
        qu.emplace(u, v);
        d[u][v] = a[u][v];
        memset (pl, 0, sizeof (pl));
        pl[u][v] = 1;
        while (qu.size())
        {
            int x = qu.front().first, y = qu.front().second;
            if (x == p && y == q) break;
            qu.pop();
            for (int h = 0; h < 2; ++ h)
            {
                int X = x + hx[h], Y = y + hy[h];
                if (!kt (X, Y)) continue;
                if (!pl[X][Y] || d[x][y] + a[X][Y] > d[X][Y])
                {
                    d[X][Y] = d[x][y] + a[X][Y];
                    tr[X][Y] = {x, y};
                }
                if (!pl[X][Y])
                qu.emplace(X, Y);
                pl[X][Y] = 1;
            }
        }
        int sol = INT_MAX;
        for (auto x = tr[p][q]; x != make_pair(u, v); x = tr[x.first][x.second])
        {
            ok[x.first][x.second] = 1;
            queue<pair<int, int> > qu;
            qu.emplace(u, v);
            d[u][v] = a[u][v];
            memset (pl, 0, sizeof (pl));
            pl[u][v] = 1;
            while (qu.size())
            {
                int x = qu.front().first, y = qu.front().second;
                if (x == p && y == q) break;
                qu.pop();
                for (int h = 0; h < 2; ++ h)
                {
                    int X = x + hx[h], Y = y + hy[h];
                    if (!kt (X, Y)) continue;
                    if (!pl[X][Y])
                    d[X][Y] = d[x][y] + a[X][Y];
                    else
                    d[X][Y] = max (d[x][y] + a[X][Y], d[X][Y]);
                    if (!pl[X][Y])
                    qu.emplace(X, Y);
                    pl[X][Y] = 1;
                }
            }
            sol = min (sol, d[p][q]);
            ok[x.first][x.second] = 0;
        }
        cout << sol << "\n";
    }
}

void solve()
{

}

void print_result()
{

}

int main()
{
    docfile();
    //cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}