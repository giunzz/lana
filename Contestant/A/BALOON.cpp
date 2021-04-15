// Xin loi minh nop nham code 92 diem vao acc ban Hoang ;-; Minh khong co tinh ;-;

#include <bits/stdc++.h>

using namespace std;

int col[201];
int g[5][201][201][201];

int t;
string s;

int dp2(int c,int d,int l,int r)
{
	if (l == r)
	{
		if (d == 1)
			return -1e9;
		return d*d;
	}	
	if (g[c][d][l][r] != -1)
		return g[c][d][l][r];
	if (col[s[l]] == c)
	{
		if (l == r-1)
			return (d+1)*(d+1);
		return g[c][d][l][r] = dp2(c,d+1,l+1,r);
	}
	else
	{
		int cur = -1e9;
		for (int k=l+2;k<=r;k++)
			cur	= max(cur,dp2(col[s[l]],1,l+1,k) + 
			dp2(c,d,k,r));
		return g[c][d][l][r] = cur;					
	}           	
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("baloon.inp", "r", stdin);
	freopen("baloon.out", "w", stdout);
	col['B'] = 1;
	col['G'] = 2;
	col['R'] = 3;
	col['Y'] = 4;
	cin >> t;
	while(t--)
	{
		cin >> s;
		for (int i=0;i<=s.size();i++)
			for (int j=0;j<=s.size();j++)
				for (int k=0;k<=s.size();k++)
					for (int c=0;c<=4;c++)
						g[c][i][j][k] = -1;
		cout << max(0,dp2(col[s[0]],1,1,s.size())) << '\n';
	}
}