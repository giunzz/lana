#include <bits/stdc++.h>

#define fn "test"
#define fn1 "TREE"

using namespace std;

const int mn = 5 * int(1e3) + 10;
const int mod = 1 * int(1e5) + 10;
const int mm = 1 * int(1e5) + 10;

int tt, ntest = 1;
int a[mn];
vector<int> e[mn], con[mn];
int f[5010][5010];
int n;

void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (ifstream(fn".inp"))
    {
        freopen(fn".inp", "r", stdin);
        freopen(fn".out", "w", stdout);
    }else if (ifstream(fn1".inp"))
    {
        freopen(fn1".inp", "r", stdin);
        freopen(fn1".out", "w", stdout);
    }
}

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) f = ch == '-' ? - f : f, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}

void write(int a)
{
    int i = 0;
    char S[20];
    if (a == 0) {putchar('0'); return;}
    while(a > 0)
    {
        S[i++] = a % 10 + '0';
        a /= 10;
    }
    --i;
    while(i >= 0) putchar(S[i--]);
}

void dfs (int u)
{
	for (int v : e[u])
	if (!con[v].size())
	{
		con[u].push_back(v);
		dfs (v);
	}
}

int F (int i, int j)
{
	if (!con[i].size()) return (j <= 1 ? (a[i] != j) : n + 20);
	if (f[i][j] != n + 19) return f[i][j];
    if (con[i].size() == 1) return f[i][j] = F (con[i][0], j) + abs (a[i] - j);
    f[i][j] = n + 20;
	for (int k = 0; k <= j; ++ k)
    f[i][j] = min (f[i][j], F (con[i][0], k) + F (con[i][1], j - k) + abs (a[i] - j));
    return f[i][j];
}

void enter()
{
	cin >> n;
    for (int i = 1; i <= n; ++ i)
	cin >> a[i];
	int u, v;
	fill (f[0], f[n + 2], n + 19);
	for (int i = 1; i <= n - 1; ++ i)
	{
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs (1);
	int sol = n + 20;
    for (int i = 0; i <= n; ++ i)
    sol = min (sol, F (1, i));
    cout << sol;
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
