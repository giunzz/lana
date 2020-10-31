				///************** H.A.N Smile **************///
#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define MOD 1000000000000007
#define HAN "GIFTS"
#define ii pair<int , int>
#define lii pair <long long , int>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e6 + 5;
inline int ReadInt()
{
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar());
    int res = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        res = res * 10 + c - '0';
    return res;
}

void WriteInt(int x)
{
    if (x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}
int n , a[N], k;
long long f[N], g[N], t[N], d[N], ans = MOD;

void make_test()
{
	freopen(HAN".inp", "w", stdout);
	srand(time(0));
	int x = 10;
	int c = 3;
	cout <<x <<" " <<c <<endl;
	for (int i = 1 ; i <= x; ++i) cout <<rand() % 20 + 1 <<" ";
}

void sub1()
{
    long long minn = MOD;
    for (int i = k; i <= n; ++i)
    {
        long long res = 0;
        long long x = f[i] - f[i-k];
        int l = i - k + 1, r = i;

        for (int j = k ; j <= n; ++j)
        {
        if ((l <= j - k + 1 && j - k + 1 <= r) || (l <= j && j <= r)) continue;
        res = max(res , f[j] - f[j-k]);
        }
        minn = min(minn, res);
    }

    printf("%lld", minn);
}

void sub2()
{
    for (int i = n ; i > 0 ; --i) g[i] = g[i+1] + a[i];

    for (int i = k; i <= n; ++i) t[i] = max(f[i] - f[i-k], t[i-1]);

    for (int i = n - k + 1 ; i > 0 ; --i) d[i] = max(d[i+1] , g[i] - g[i+k]);

    for (int i = k ; i <= n; ++i)
        ans = min(ans , max(d[i+1], t[i-k]));
    printf("%lld", ans);
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//make_test();
	freopen(HAN".inp" , "r", stdin);
	freopen(HAN".out" , "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), f[i] = f[i-1] + a[i];

    if (n <= 5000) sub1();
    else sub2();
}
