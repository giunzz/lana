				///************** H.A.N Smile **************///
#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define MOD 1000000007
#define HAN "TEAWORLD"
#define ii pair<int , int>
#define lii pair <long long , int>
#define ll long long
#define pb push_back
using namespace std;
const int N = 2e3 + 5;

void make_test()
{
	freopen(HAN".inp", "w", stdout);
	srand(time(0));
}

int n , m , k , dem, ans, anss;
struct point{int x , y , z , r;} a[N], s , b[N];
bool dd[N], d[N];
vector <int> c[N], ss;

bool get_bit(int x , int i)
{
    return (x >> i) & 1;
}
main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//make_test();
	freopen(HAN".inp" , "r", stdin);
	freopen(HAN".out" , "w", stdout);
    scanf("%d%d%d", &m , &n , &k);
    for (int i = 1; i <= m; ++i) scanf("%d%d%d%d", &a[i].x, &a[i].y, &a[i].z , &a[i].r);
    for (int i = 1; i <= n; ++i) scanf("%d%d%d%d", &b[i].x, &b[i].y, &b[i].z , &b[i].r);
    scanf("%d%d%d", &s.x, &s.y, &s.z);

    for (int i = 1; i <= m; ++i)
    {
        int l = a[i].x - a[i].r;
        int r = a[i].x + a[i].r;
        for (int j = 1; j <= n; ++j)
        if (( s.x < l && r < b[j].x) || (b[j].x < l && r < s.x) || ( l <= s.x && s.x <=r && (b[j].x < l || b[j].x > r)) || ( l <= b[j].x && b[j].x <=r && (s.x < l || s.x > r)))
            c[j].pb(i);
    }

    for (int x = 0 ; x < (1 << n) ; ++x)
    {
        int cou = 0;
        int res = 0;
        memset(dd , 0 , sizeof(dd));

        for (int i = 1; i <= n; ++i) if (!d[i] && get_bit(x , i-1))
        {
            res += b[i].r;
            for (int j = 0 ; j < c[i].size(); ++j)
            {
                int v = c[i][j];
                if (!dd[v]) cou++, dd[v] = 1;
            }
        }

        if (cou <= k) ans = max(ans, res);
    }
    printf("%d", ans);
}
