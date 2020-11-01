//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <stdio.h>
#include <map>
#include <set>
#include <vector>
#include <string.h>
#include <cmath>
#include <climits>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
const int N = 5015;
const int oo = 1e9 + 15;

int n, m, tmp, x, y, res;
int w[N], sum[N], f[N][N];
vector <int> a[N];

void dfs(int u, int p)
{
	//cout << u << endl;
	sum[u] = 0;
	if (u != 1 && a[u].size() == 1)
	{
		sum[u] = 1, f[u][1] = abs(w[u] - 1), f[u][0] = abs(w[u] - 0);
		return;
	}
    for (int i = 0; i < a[u].size(); i++)
	{
		int v = a[u][i];
		if (v == p) continue;
		dfs(v, u); sum[u] += sum[v];
	}
	int x = 0, y = 0;
	for (int i = 0; i < a[u].size(); i++)
	{
		int v = a[u][i];
		if (v == p) continue;
		if (x == 0) x = v;
		else y = v;
	}
	if (y == 0)
    {
		for (int i = 0; i <= sum[u]; i++)
		{
			if (f[x][i] != oo)
				f[u][i] = abs(w[u] - i) + f[x][i];
			else break;
		}
    }
	else
	{
		for (int i = 0; i <= sum[u]; i++)
    		for (int j = 0; j <= i; j++)
			{
				if (f[x][j] == oo || f[y][i - j] == oo) continue;
				f[u][i] = min(f[u][i], abs(w[u] - i) + f[x][j] + f[y][i - j]);
				//cout << u <<" "<< i <<" "<< j <<" "<< abs(w[u] - i) + f[x][j] + f[y][i - j]<< endl;
			}
	}
	//cout <<"asdf "<< u << " "<< x <<" "<< y <<" "<< sum[u] << endl;
	//for (int i = 0; i <= sum[u]; i++) cout << i <<" "<< f[u][i] << endl;
}

int main()
{
    #define file "TREE"
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
	ios_base::sync_with_stdio(false);cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		//w[i] = 5000;
		cin >> w[i];
	}
    for (int i = 1; i < n; i++)
	{
        cin >> x >> y;
        //cout << x <<" "<<y << endl;
        a[x].push_back(y);
        a[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= n; j++) f[i][j] = oo;
	dfs(1, 1);
	res = oo;
	for (int i = 0; i <= sum[1]; i++) res = min(res, f[1][i]);
	cout << res;

    return 0;
}
