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
const int N = 100015;
const ll oo = (long long) 1e18 + 15;

int n, ss, m, tmp, A, B, T;
ll sum, res, x, y, rx, ry;
int a[N], d[N];

int get(int x, int i)
{
    return (x >> i) & 1;
}

void sol()
{
	m = 50000;
	for (int i = 1; i <= m; i++) d[i] = 0;
	for (int i = 1; i <= 20; i++) a[i] = 0;
	cin >> A >> B;
	ss = __gcd(A, B); A /= ss, B /= ss;
	ss = 2;
    while (A >= ss || B >= ss)
	{
		while (A % ss == 0) d[ss]++, A /= ss;
		while (B % ss == 0) d[ss]++, B /= ss;
		ss++;
	}
	n = 0;
    if (A != B)
	{
        if (A == 1 || B == 1) n = 1, a[n] = A * B;
        else n = 2, a[1] = A, a[2] = B;
	}
	for (int i = 1; i <= m; i++)
		if (d[i] % 2 == 1) n++, a[n] = i;
	//cout << n << endl;
	//for (int i = 1; i <= n; i++) cout << a[i] <<" "; cout << endl;
	res = oo, rx = ry = 1;
	for (int i = 0; i < (1 << n); i++)
	{
		x = y = 1;
		for (int j = 0; j < n; j++)
		{
            if (get(i, j)) x *= 1LL * a[j + 1];
            else y *= 1LL * a[j + 1];
		}
        if (res > (x + y))
			res = x + y, rx = x, ry = y;
	}
	cout << rx <<" "<< ry <<"\n";
}

int main()
{
    #define file "MINSUM"
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
    ios_base::sync_with_stdio(false);cin.tie(NULL);

	cin >> T;
	while (T--) sol();

    return 0;
}
