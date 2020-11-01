#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define int long long
#define endl '\n'
#define pi acos(-1)
#define pque priority_queue
#define N 1000000
#define lmax LONG_LONG_MAX
#define cin fi
#define cout fo
ifstream fi("minsum.inp");
ofstream fo("minsum.out");
typedef pair < int, int > ii;
typedef vector < int > vi;
typedef vector < vi > vii;
int mod = 1000000007;
int test, a, b, n, sq, num, x, y, f[1000];
void bt(int u, int val)
{
	if(u > n)
	{
		if(val + num / val < x + y)
			x = val, y = num / val;
		return ;
	}
	if(val > sq)
		return;
	for(int i = u + 1; i <= n; i ++)
	{
		if(val * f[i] + num / (val * f[i]) < x + y)
			x = val * f[i], y = num / (val * f[i]);
		if(val * f[i] * f[i + 1] <= sq)
			bt(i, val * f[i]);
		if(val * f[i] > sq)
			return;
	}	
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin >> test;
	while(test --)
	{
		cin >> a >> b;
		n = 0;
		if(a > b)
			swap(a, b);
		sq = sqrt(b);
		num = a * b;
		x = 1e9;
		y = 1e9;
		num = 1;
		for(int i = 2; i <= sq; i ++)
		{
			while(a % (i * i) == 0)
				a = a / (i * i);
			while(b % (i * i) == 0)
				b = b / (i * i);
			if(a % i == 0 && b % i == 0)
				a = a / i, b = b / i;
			if(a % i == 0)
				n ++, f[n] = i, a = a / i, num *= i;
			if(b % i == 0)
				n ++, f[n] = i, b = b / i, num *= i;
		}
		if(a != b)
		{
			if(a > 1)
				n ++, f[n] = a, num *= a;
			if(b > 1)
				n ++, f[n] = b, num *= b;
		}
		sq = sqrt(num);
		f[n + 1] = f[n];
		if(n == 0)
			n ++, f[n] = 1;
		bt(0, 1);
		cout << x << ' ' << y << endl;
	}
}

