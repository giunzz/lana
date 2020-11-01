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
const ll oo = (long long) 1e17 + 15;

int n, k;
ll ss, sum, m, tmp, ma, mi, d, res;
ll a[N], b[N];
struct data
{
	ll x, y;
	data(ll x = 0, ll y = 0) : x(x), y(y) {};
};
data f[2015][2015][3];
data minn(data x, data y, ll k)
{
    if ((abs(x.x) + abs(x.y)) > (abs(y.x) + abs(y.y))) return y;
    if ((abs(x.x) + abs(x.y)) == (abs(y.x) + abs(y.y)))
	{
        if (abs(x.y + k) > abs(y.y + k)) return y;
        return x;
	}
    return x;
}

void sub1()
{
    m = sum / n;
    res = 0;
    int k = 1;
    ss = 0;
    while (k <= n)
    {
        tmp = a[k] - m;
        ss += tmp;
        res += abs(ss);
        k++;
    }
    cout << res <<"\n";
}

void sub2()
{
	mi = ma = sum / n;
	if (sum % n != 0) ma++;
    int d = sum % n;
    for (int i = 1; i <= n; i++)
		for (int j = 0; j <= d; j++) f[i][j][1] = data(oo, oo), f[i][j][0] = data(oo, oo);
	f[1][1][1] = data(0, a[1] - ma);
	f[1][0][0] = data(0, a[1] - mi);
	for (int i = 2; i <= n; i++)
		for (int j = 0; j <= min(d, i); j++)
		{
			data ss = minn(f[i - 1][j][1], f[i - 1][j][0], a[i] - mi);
            f[i][j][0] = data(abs(ss.y) + ss.x, a[i] - mi + ss.y);
			ss = minn(f[i - 1][j - 1][1], f[i - 1][j - 1][0], a[i] - ma);
			if (j != 0)
				f[i][j][1] = data(abs(ss.y) + ss.x, a[i] - ma + ss.y);
		}
	cout << min(f[n][d][1].x, f[n][d][0].x) <<"\n";
}


ll cal(ll a[])
{
	ll ss, tmp, res, d;
	int k;
    d = sum % n;
    ss = res = 0;
    k = 1;
    while (k <= n)
    {
        tmp = a[k] - mi;
        if (tmp > 0 && d != 0)
        {
            if (ss + tmp > 0) tmp--, d--;
        }
        if (tmp < 0 && d != 0)
        {
            if (ss + tmp > 0) tmp--, d--;
        }
        if (d >= (n - k + 1)) d--, tmp--;
        ss += tmp;
        res += abs(ss);
        k++;
    }
    return res;
}

int main()
{
	#define file "ARRANGE"
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], sum +=  a[i];
    if (sum % n == 0)
    {
        sub1();
        return 0;
    }
    ma = mi = sum / n;
    if (sum % n != 0) ma++;
    d = sum % n;
    if (n <= 2000)
	{
		sub2();
		return 0;
	}
    for (int i = 1; i <= n; i++) b[i] = a[n - i + 1];
    cout << min(cal(a), cal(b));

    return 0;
}