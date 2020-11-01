#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<int> vi;
typedef vector<ii> vii;

const long long oo = 1e17 + 7;
const int maxN = 105;

int n, delta, a[maxN], b[maxN];
int f[105][105];
ii trace[105][105];

int main()
{
	freopen("LIONDANCE.inp", "r", stdin);
	freopen("LIONDANCE.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin >> n >> delta;
	for (int i = 1; i <= n; i++)	cin >> a[i];
	for (int i = 1; i <= n; i++)	cin >> b[i];
	for (int i = n; i >= 1; i--)
	for (int j = n; j >= 1; j--)
	{
		if (a[i] == b[j])
		{
			f[i][j] = 1;
			for (int p1 = i + 1; p1 <= n; p1++)
			for (int p2 = j + 1; p2 <= n; p2++)
				if (a[p1] == b[p2] && abs(a[i] - a[p1]) <= delta)
				{
					if (f[i][j] < f[p1][p2] + 1)
					{
						f[i][j] = f[p1][p2] + 1;
						trace[i][j] = ii(p1, p2);
					}
					else
					if (f[i][j] == f[p1][p2] + 1)
					{
						if (a[trace[i][j].fi] < a[p1])
							trace[i][j] = ii(p1, p2);
					}
				}
		}
	}
	ii Max = ii(0, 0);	ii id = ii(0, 0);
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		if (a[i] == b[j])
			if (Max < ii(f[i][j], a[i]))
			{
				Max = ii(f[i][j], a[i]);
				id = ii(i, j);
			}
	cout << Max.fi << "\n";
	while(1)
	{
		if (id == ii(0, 0))	break;
		cout << a[id.fi] << " ";
		id = trace[id.fi][id.se];
	}
	return 0;
}