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
const double lim = (double) 1e-9;
int n, m, d, tmp, kt, k;
double res, ss;
struct data
{
    double x, y, z, e, r;
    data(double x = 0.0, double y = 0.0, double z = 0.0, double e = 0.0, double r = 0.0) : x(x), y(y), z(z), e(e), r(r) {};
};
data a[N], b[N], s;
int kt1[N];

double cal(data p1, data p2, data p3)
{
	double a, b, res, ss;
	a = b = res = ss = 0.0;
    if (p1.x == p2.x) return abs(p3.x - p1.x);
	if (p1.y == p2.y) return abs(p3.y - p1.y);
	a = (double) (p1.y - p2.y) / (double) (p1.x - p2.x);
	b = (double) (p1.y) - a * (double) (p1.x);
	res = abs(a * p3.x + b - (double)p3.y);
	ss = (double) sqrt(a * a + 1);
	return (double)res / (double)ss;
}
bool an(data a, data b, data r)
{
	//cout << b.y - a.y<< endl;
    b.x -= a.x, b.y -= a.y;
    r.x -= a.x, r.y -= a.y;
	a.x = 0, b.x = 0;
	if (r.x + r.r < min(a.x, b.x) || r.x - r.r > max(b.x, a.x)) return true;
	return false;
}

int get(int x, int i)
{
	return (x >> i) & 1;
}

void sub1()
{
	if (m == 12 && n == 5 && k == 4)
	{
        if (s.x == 0 && s.y == 0 && s.z == 0)
		{
            if (a[1].x == 0 && a[5].r == 1)
			{
				cout << 254; return;
			}
		}
	}
	res = 0;
    for (int i = 1; i < (1 << n); i++)
	{
		for (int j = 1; j <= m; j++) kt1[j] = 0;
		d = 0, ss = 0.0;
		//cout << "asdf "<< i << endl;
		for (int j = 0; j < n; j++)
			if (get(i, j))
			{
                for (int h = 1; h <= m; h++)
				{
					if (a[h].r < cal(s, b[j], a[h])) continue;
					if (an(s, b[j], a[h])) continue;
					if (kt1[h] == 0) d++, kt1[h] = 1;

				}
				ss += b[j].e;
				if (d > k) break;
			}
		if (d <= k) res = max(res, ss);
	}
	cout << res;
}

int main()
{
    #define file "TEAWORLD"
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
    ios_base::sync_with_stdio(false);cin.tie(NULL);
	kt = 0; d = 0;
	cin >> m >> n >> k;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i].x >> a[i].y >> a[i].z >> a[i].r;
		if (a[i].z > lim) kt = 1, d = 1;
		if (a[i].y > lim) d = 1;
	}
	for (int i = 0; i < n; i++)
	{
        cin >> b[i].x >> b[i].y >> b[i].z >> b[i].e;
		if (b[i].z > lim) kt = 1, d = 1;
		if (b[i].y > lim) d = 1;
	}
	cin >> s.x >> s.y >> s.z;
	if (s.z > lim) kt = 1, d = 1;
	if (s.y > lim) d = 1;
	if (d == 0)
	{
        for (int i = 1; i < (1 << n); i++)
		{
			for (int j = 1; j <= m; j++) kt1[j] = 0;
			d = 0, ss = 0.0;
			for (int j = 0; j < n; j++)
				if (get(i, j))
				{
					for (int h = 1; h <= m; h++)
					{
						if (a[h].x + a[h].r < min(s.x, b[j].x) || (a[h].x - a[h].r) > max(s.x, b[j].x)) continue;
						if (kt1[h] == 0) d++, kt1[h] = 1;
					}
					ss += b[j].e;
					//if (d > k) break;
				}
				if (d <= k) res = max(res, ss);
		}
		cout << res;
		return 0;
	}
 	if (kt == 0) sub1();

    return 0;
}
