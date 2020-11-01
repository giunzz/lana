#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = (a), _b = (b) ; i <= _b ; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b) ; i >= _b ; --i)
#define For(i, a, b) for(int i = (a), _b = (b) ; i < _b ; ++i)
#define Ford(i, a, b) for(int i = (a), _b = (b) ; i > _b ; --i)
#define ll long long
#define ii pair <int,int>
#define mp make_pair
#define pb push_back
#define X first
#define Y second

using namespace std;

const int N = 1e5+5;

int n;
int a[N];
ii b[N];
ll sum = 0, res = 0;

int main()
{
	freopen("ARRANGE.INP", "r", stdin); freopen("ARRANGE.OUT", "w", stdout);
	scanf("%d", &n);
	FOR(i, 1, n) scanf("%d", &a[i]), sum += a[i];
	sum /= n;
	int top = 0;
	FOR(i, 1, n) if(a[i] != sum) b[++top] = mp(a[i], i);
	///FOR(i, 1, top) cout << b[i] << " "; cout << endl;
	sort(b+1, b+top+1);
	FORD(i, top, 2) if(b[i].X > b[i-1].X) {
		b[i-1].X += (b[i].X - sum) * abs(b[i].Y - b[i-1].Y);
		res += (b[i].X - sum) * abs(b[i].Y - b[i-1].Y);
	}
	cout << res << endl;
    return 0;
}
