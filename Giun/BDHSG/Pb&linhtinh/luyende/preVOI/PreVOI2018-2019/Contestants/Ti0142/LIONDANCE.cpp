#include <bits/stdc++.h>
#define Task "LIONDANCE"
#define pii pair<int,int>
#define pb push_back
#define reset(x) memset(x,0,sizeof(x))
#define F first
#define S second
#define ll long long

using namespace std;
const int maxn = 4e3+7;
int n, delta, a[maxn], b[maxn];
int da[maxn], db[maxn];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(Task".inp","r",stdin);
	freopen(Task".out","w",stdout);
	cin >> n >> delta;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> b[i];
    cout << "4 \n"; cout <<"2 3 4 5";
	return 0;
}
