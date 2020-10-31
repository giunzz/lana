#include <bits/stdc++.h>

#define fn "test"
#define fn1 "MINSUM"

using namespace std;

const int mn = 1 * int(1e5) + 10;
const int mod = 1 * int(1e5) + 10;
const int mm = 1 * int(1e5) + 10;

int tt, ntest = 1;
int v1[mn], v2[mn];
int x, y;

void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (ifstream(fn".inp"))
    {
        freopen(fn".inp", "r", stdin);
        freopen(fn".out", "w", stdout);
    }else if (ifstream(fn1".inp"))
    {
        freopen(fn1".inp", "r", stdin);
        freopen(fn1".out", "w", stdout);
    }
}

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) f = ch == '-' ? - f : f, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}

void write(int a)
{
    int i = 0;
    char S[20];
    if (a == 0) {putchar('0'); return;}
    while(a > 0)
    {
        S[i++] = a % 10 + '0';
        a /= 10;
    }
    --i;
    while(i >= 0) putchar(S[i--]);
}

void enter()
{
	cin >> x >> y;
}

void d (long long& x, long long& y)
{
	long long t = __gcd (x, y);
	x /= t;
	y /= t;
}

void solve()
{
	int v1c = 0, v2c = 0;
    for (int i = 1; i <= trunc(sqrt(x)); ++ i)
	if (x % i == 0)
    {
    	v1[v1c ++] = i;
        v1[v1c ++] = x / i;
    }
    for (int i = 1; i <= trunc(sqrt(y)); ++ i)
	if (y % i == 0)
	{
		v2[v2c ++] = i;
		v2[v2c ++] = y / i;
	}
	long long sol = x + y, solx = x, soly = y;
    for (int I = 0; I < v1c; ++ I)
	for (int J = 0; J < v2c; ++ J)
    {
    	int i = v1[I], j = v2[J];
    	long long X = x / i * j;
    	long long Y = y / j * i;
    	d (X, Y);
    	if (X + Y < sol)
		{
			sol = X + Y;
			solx = X;
            soly = Y;
		}
    }
    cout << solx << " " << soly << "\n";
}

void print_result()
{

}

int main()
{
    docfile();
    cin >> ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
