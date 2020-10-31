#include <bits/stdc++.h>

#define fn "test"
#define fn1 "GIFTS"

using namespace std;

const int mn = 1 * int(1e5) + 10;
const int mod = 1 * int(1e5) + 10;
const int mm = 1 * int(1e5) + 10;

int tt, ntest = 1;
vector<long long> s;

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

inline long long S (int a, int b)
{
    return s[b] - (a == 0 ? 0 : s[a - 1]);
}

void enter()
{
	int n, k;
    n = read(); k = read();
    if (k == 1)
	{
		vector<int> a(n);
		for (int& i : a) i = read();
		sort (a.begin(), a.begin() + n);
		cout << a[n - 2];
		return;
	}
    s.resize (n);
    priority_queue <pair<long long , int> > qu1, qu2;
    for (int i = 0; i < n; ++ i)
	{
		int x = read();
		s[i] = (i == 0 ? 0 : s[i - 1]) + x;
	}

	for (int i = k; i <= n - k; ++ i)
	qu2.push ({S (i, i + k - 1), i});
	long long sol = LLONG_MAX;
	long long res = 0, c = 0;
    for (int i = 0; i <= n - k; ++ i)
	{
		if (i && i + k + k - 2 <= n - 1) qu1.push ({S (i - 1, i - 1) + S (i + k, i + k + k - 2) - res, i - 1});
        while (qu2.size() && qu2.top().second < i + k) qu2.pop();
        while (qu1.size() && (qu1.top().second <= i - k || (k - (i - qu1.top().second)) + i + k - 1 >= n)) qu1.pop();
        if (i - k >= 0) c = max (c, S (i - k, i - 1));
        long long a = (qu1.size() ? qu1.top().first + res : 0);
		long long b = (qu2.size() ? qu2.top().first : 0);
		sol = min (sol, max (a, max (b, c)));
        res += - S (i + k, i + k) + S (i, i);
        //cout << i << " " << a << " " << b << " " << c << "\n";
	}
	cout << sol;
}

void solve()
{

}

void print_result()
{

}

int main()
{
    docfile();
    //cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
