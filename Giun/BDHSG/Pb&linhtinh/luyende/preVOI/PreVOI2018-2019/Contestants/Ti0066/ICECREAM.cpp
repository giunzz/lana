#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define LL long long 

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<int> vi;
typedef vector<ii> vii;

const LL oo = 1e17 + 7;
const int maxN = 305;
const long long MOD = 1e9 + 9;

int N, MMAX, M50, M1, M2;
long long f[52][152][52][52];

long long solve(int in, int fiftyxen, int oneUSD, int twoUSD)
{
	if (in == N + 1)	return 1;
	if (f[in][fiftyxen][oneUSD][twoUSD] != -1)
		return f[in][fiftyxen][oneUSD][twoUSD];
	long long cur = 0;
	// Tra = 50 xen;
	if (fiftyxen + 1 <= MMAX)
		cur = (cur + solve(in + 1, min(fiftyxen + 1, 150), oneUSD, twoUSD)) % MOD;
	// Tra = 1 USD;
	if (fiftyxen >= 1 && oneUSD + 1 <= MMAX)
		cur = (cur + solve(in + 1, fiftyxen - 1, min(oneUSD + 1, 50), twoUSD)) % MOD;
	// Tra = 2 USD;
	if (oneUSD >= 1 && fiftyxen >= 1 && twoUSD + 1 <= MMAX)
		cur = (cur + solve(in + 1, fiftyxen - 1, oneUSD - 1, min(twoUSD + 1, 50))) % MOD;
	else
	if (fiftyxen >= 3 && twoUSD + 1 <= MMAX)
		cur = (cur + solve(in + 1, fiftyxen - 3, oneUSD, min(twoUSD + 1, 50))) % MOD;
	return f[in][fiftyxen][oneUSD][twoUSD] = cur;
}

int main()
{
	freopen("ICECREAM.INP", "r", stdin);
	freopen("ICECREAM.OUT", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin >> N >> MMAX;
	cin >> M50 >> M1 >> M2;
	if (N <= 50)
	{
		M50 = min(M50, 150);
		M1 = min(M1, 50);
		M2 = min(M2, 50);
		memset(f, -1, sizeof f);
		cout << solve(1, M50, M1, M2);
	}
	return 0;
}