#include <bits/stdc++.h>

using namespace std;
const string filename = "LDS";

int n;
int a[1000001], pos[1000001];
int f[1000001];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen( (filename + ".inp").c_str(), "r", stdin);
	freopen( (filename + ".out").c_str(), "w", stdout);

	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		pos[a[i]] = i;
	}
	int res = 0;
	for (int i=1;i<=n;i++)
		f[i] = 1;
	for (int i=1;i<=n;i++)
	{
		res = max(res, f[a[i]]);
		for (int j=a[i];j<=n;j+=a[i])
			if (pos[j] > i)
				f[j] = max(f[j], f[a[i]] + 1);		
	}
	cout << res;
}