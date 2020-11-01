#include <bits/stdc++.h>
#define Task "MODULO"
#define pii pair<int,int>
#define pb push_back
#define reset(x) memset(x,0,sizeof(x))
#define F first
#define S second
#define ll long long

using namespace std;
const int maxn = 27;
int a[3], n, x[maxn];
long long k , n2, res;

void Calc()
{
    long long s = 0;
    for (int i = 1; i <= n; ++i) s = s * 10 + x[i];
    if ( (s % n2 )== k) { res = s; return; }
}

void Try(int i)
{
    for (int j = 0; j <= 1; ++j)
    {
        x[i] = a[j];
        if (i == n) Calc(); else Try(i+1);
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(Task".inp","r",stdin);
	freopen(Task".out","w",stdout);
	if (n > 20) { cout << -1; return 0; }
	cin >> a[0] >> a[1] >> n >> k;
    n2 = 1 << n;
    Try(1);
    if (res == 0) res = -1;
    cout << res;
	return 0;
}
