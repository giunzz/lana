#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define LL long long 

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<int> vi;
typedef vector<ii> vii;

const LL oo = 1e17 + 7;
const int maxN = 305;

int n, m, k, u, v, p, q;
long long f1[105][105], a[105][105];
bool vis1[105][105], banned[105][105];
vii bagbanned;

long long solve1(int i, int j)
{
	if (i == p &&  j == q)	return a[p][q];
	if (vis1[i][j])	return f1[i][j];
	vis1[i][j] = true;
	long long cur = -oo;
	if (i + 1 <= p && !banned[i + 1][j])
		cur = max(cur, solve1(i + 1, j) + a[i][j]);
	if (j + 1 <= q && !banned[i][j + 1])
		cur = max(cur, solve1(i, j + 1) + a[i][j]);
	return f1[i][j] = cur;
}

void Try(int i, int j)
{
	if (i == p && j == q)	return;
	bagbanned.pb(ii(i, j));
	if (i + 1 <= p && solve1(i, j) == solve1(i + 1, j) + a[i][j])
		Try(i + 1, j);
	else
	if (j + 1 <= q && solve1(i, j) == solve1(i, j + 1) + a[i][j])
		Try(i, j + 1);
}

int main()
{
	freopen("TABLE.INP", "r", stdin);
	freopen("TABLE.OUT", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
		cin >> a[i][j];
	if (n <= 30 && m <= 30 && k <= 30)
	{
		for (int i = 1; i <= k; i++)
		{
			cin >> u >> v >> p >> q;
			long long ans = oo;
			for (int p1 = u; p1 <= p; p1++)
			for (int p2 = v; p2 <= q; p2++)
			{
				if (p1 == u && p2 == v)	continue;
				if (p1 == p && p2 == q)	continue;
				for (int t1 = u; t1 <= p; t1++)
				for (int t2 = v; t2 <= q; t2++)
					vis1[t1][t2] = false;
				banned[p1][p2] = true;
				ans = min(ans, solve1(u, v));
				banned[p1][p2] = false;
			}
			cout << ans << "\n";
		}
		return 0;
	}
	if (n <= 100 && m <= 100 && k <= 100)
	{
		for (int i = 1; i <= k; i++)
		{
			cin >> u >> v >> p >> q;
			for (int t1 = u; t1 <= p; t1++)
			for (int t2 = v; t2 <= q; t2++)
			{
				vis1[t1][t2] = false;
				banned[t1][t2] = false;
			}
			solve1(u, v);	bagbanned.clear();
			Try(u, v);	long long ans = oo;
			for (int p1 = 0; p1 < (int)bagbanned.size(); p1++)
			{
				int banX = bagbanned[p1].fi;
				int banY = bagbanned[p1].se;
				if (banX == u && banY == v)	continue;
				if (banX == p && banY == q)	continue;
				for (int t1 = u; t1 <= p; t1++)
				for (int t2 = v; t2 <= q; t2++)
					vis1[t1][t2] = false;
				banned[banX][banY] = true;
				ans = min(ans, solve1(u, v));
				banned[banX][banY] = false;
			}
			cout << ans << "\n";
		}
		return 0;
	}
	return 0;
}