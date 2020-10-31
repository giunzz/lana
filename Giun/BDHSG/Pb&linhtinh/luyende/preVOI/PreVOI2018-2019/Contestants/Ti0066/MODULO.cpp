#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<int> vi;
typedef vector<ii> vii;

const long long oo = 1e17 + 7;
const int maxN = 44;

long long A, B, N, K, mid, MOD = 1, a[maxN];
map<long long, bool> mp;

void check()
{
	long long remain = 0;
	for (int i = 1; i <= N; i++)
		remain = (remain * 10 + a[i]) % MOD;
	if (remain == K)	
	{
		for (int i = 1; i <= N; i++)	cout << a[i];
		exit(0);
	}
}

void solvesub1(int in)
{
	if (in == N + 1)	
	{
		check();
		return;
	}
	a[in] = A;	solvesub1(in + 1);
	a[in] = B;	solvesub1(in + 1);
}

void inkq(int in, long long remain, long long cremain)
{
	if (in == N + 1)	
	{
		if (remain == cremain)
		{
			for (int i = mid + 1; i <= N; i++)	cout << a[i];
			exit(0);
		}
		return;
	}
	a[in] = A;	inkq(in + 1, (remain * 10 + A) % MOD, cremain);
	a[in] = B;	inkq(in + 1, (remain * 10 + B) % MOD, cremain);
}


void solvesub2(int in, long long remain, int ketthuc)
{
	if (in == ketthuc + 1)	
	{
		if (ketthuc == mid)
		{
			for (int j = 1; j <= N - mid; j++)
				remain = (remain * 10) % MOD;
			if (mp[K - remain])
			{
				for (int i = 1; i <= mid; i++)	cout << a[i];
				inkq(mid + 1, 0, K - remain);
				exit(0);
			}
			if (mp[K + MOD - remain])
			{
				for (int i = 1; i <= mid; i++)	cout << a[i];
				inkq(mid + 1, 0, K + MOD - remain);
				exit(0);
			}
		}
		else
		{
			mp[remain] = true;
		}
		return;
	}
	a[in] = A;	solvesub2(in + 1, (remain * 10 + A) % MOD, ketthuc);
	a[in] = B;	solvesub2(in + 1, (remain * 10 + B) % MOD, ketthuc);
}

int main()
{
	freopen("MODULO.INP", "r", stdin);
	freopen("MODULO.OUT", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin >> A >> B >> N >> K;
	for (int i = 1; i <= N; i++)	MOD = MOD * 2;
	if (N <= 20)
	{
		solvesub1(1);
		cout << -1;
		return 0;
	}
	if (N <= 40)
	{
		mid = N / 2;	if (K == 0)	K = MOD;
		solvesub2(mid + 1, 0, N);
		solvesub2(1, 0, mid);
		cout << -1;
		return 0;
	}
	return 0;
}