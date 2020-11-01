#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<int> vi;
typedef vector<ii> vii;

const long long oo = 1e17 + 7;
const int maxN = 2005;

int n, m, k, cntj, a[maxN], b[maxN], dqA[maxN], dqB[maxN];
int f[105][105][105];
pii trace[105][105][105];
vi ans[200], finalans;

void joinnn(int X, int Y)
{
	cntj++;	int i = 1, j = 1;
	while(i <= X && j <= Y)
		if (dqA[i] <= dqB[j])	
		{
			ans[cntj].pb(dqA[i]);
			i++;
		}
		else
		{
			ans[cntj].pb(dqB[i]);
			j++;
		}
	while(i <= X)	
	{
		ans[cntj].pb(dqA[i]);
		i++;
	}
	while(j <= Y)
	{
		ans[cntj].pb(dqB[j]);
		j++;
	}
}

bool cmp(vi A, vi B)
{
	for (int i = 0; i < (int)A.size(); i++)
	{
		if (A[i] < B[i])	return true;
		if (A[i] > B[i])	return false;
	}
	return true;
}

int main()
{
	freopen("SEQUENCE.INP", "r", stdin);
	freopen("SEQUENCE.OUT", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)	cin >> a[i];
	for (int i = 1; i <= m; i++)	cin >> b[i];
	a[0] = 10000000;	b[0] = 100000000;
	for (int t = 1; t <= k; t++)
	{
		int needA = t;	int needB = k - t;
		if (needA > n || needB > m)	continue;
		int cntA = needA, cntB = needB;
		int lA = 1, rA = n - needA + 1;
		for (int i = 1; i <= needA; i++)
		{
			int chosen = 0;
			for (int p = lA; p <= rA; p++)
				if (a[p] < a[chosen])	chosen = p;
			dqA[i] = a[chosen];	
			lA = chosen + 1;		rA++;
		}
		int lB = 1, rB = m - needB + 1;
		for (int i = 1; i <= needB; i++)
		{
			int chosen = 0;
			for (int p = lB; p <= rB; p++)
				if (b[p] < b[chosen])	chosen = p;
			dqB[i] = b[chosen];	
			lB = chosen + 1;		rB++;
		}
		joinnn(needA, needB);
	}
	for (int i = 0; i < ans[1].size(); i++)
		finalans.pb(ans[1][i]);
	for (int i = 2; i <= cntj; i++)
	{
		if (cmp(ans[i], finalans))
		{
			finalans.clear();
			for (int j = 0; j < ans[i].size(); j++)
				finalans.pb(ans[i][j]);
		}
	}
	for (int i = 0; i < finalans.size(); i++)
		cout << finalans[i] << " ";
	return 0;
}