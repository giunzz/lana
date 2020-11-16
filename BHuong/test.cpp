#include <bits/stdc++.h>

using namespace std;

long n;
string f[5000][5000];

string plusTwoString(string a, string b)
{
	string st;
	if(a.size() < b.size())
	{
		swap(a, b);
	}
	while(b.size() != a.size())
	{
		b = "0" + b;
	}
	long remainder = 0;
	for(long i = a.size() - 1; i >= 0; i--)
	{
		remainder += long(a[i] - '0') + long(b[i] - '0');
		st = char(remainder % 10 + long('0')) + st;
		remainder /= 10;
	}
	return (remainder == 0 ? st : char(remainder % 10 + long('0')) + st);
}

void dp()
{
	for(long i = 1; i <= n; i++)
	{
		f[i][1] = "1";
	}
	for(long i = 1; i <= n; i++)
	{
		for(long j = 2; j <= i; j++)
		{
			f[i][j] = plusTwoString(f[i - j][j], f[i - j][j - 1]);
		}
	}
	string sum = f[n][2];
	for(long i = 3; i <= n; i++)
	{
		sum = plusTwoString(sum, f[n][i]);
	}
	cout << sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	dp();
	return 0;
}