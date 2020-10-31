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
const int N = 1000015;
const ll oo = (long long) 1e18 + 15;

int n, m, tmp, k;
ll ss, res, a[N], an;
ll mad[N], mac[N], sum[N];

template <typename T> inline void read(T &n) {
    n = 0; char ch;
    for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar()); n = ch - 48;
    for (ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar()) n = (n << 1) + (n << 3) + ch - 48;
}
template <typename T> inline void writee(T n) { if (n > 9) writee(n / 10); putchar(n % 10 + 48); }
template <typename T> inline void write(T n) { writee(n); putchar(' '); }
template <typename T> inline void writeln(T x) { write(x); putchar('\n'); }


int main()
{
    #define file "GIFTS"
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    read(n); read(k);
    m = 0; a[0] = 0; mad[0] = 0;
 	for (int i = 1; i <= n; i++)
	{
		read(a[i]);
		//a[i] = 1000000;
		ss += a[i];
		if (i >= k)
		{
			m++, sum[m] = ss, ss -= a[i - k + 1];
			mad[m] = max(sum[m], mad[m - 1]);
		}
	}
    mac[m + 1] = 0;
	for (int i = m; i >= 1; i--) mac[i] = max(mac[i + 1], sum[i]);

	//writeln(m);
	//for (int i = 1; i <= m; i++) write(sum[i]); putchar('\n');
	//for (int i = 1; i <= m; i++) write(i), write(mad[i]), writeln(mac[i]);
    //for (int i = 1; i <= k; i++) res = max(res, mac[i + k]);
	//for (int i = m; i >= (m - k + 1); i--) res = max(res, mad[i - k]);
	res = oo;
	for (int i = 1; i <= m; i++)
	{
		ss = an = 0;
		if (i - k > 0) ss = mad[i - k];
		if (i + k <= m) an = mac[i + k];
		//cout << i << " "<< ss <<" "<< an << endl;
		res = min(res, max(ss, an));
	}
	write(res);

    return 0;
}
