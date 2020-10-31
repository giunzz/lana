#include <bits/stdc++.h>
#define Task "SEQUENCE"
#define pii pair<int,int>
#define pb push_back
#define reset(x) memset(x,0,sizeof(x))
#define F first
#define S second
#define ll long long

using namespace std;
const int maxn = 3e3+7;
int n, m, k, a[maxn], b[maxn], p[maxn], q[maxn];
pii A[maxn];
int h;
vector <int> c;

struct data { int x,y; } d[maxn];
bool cmp(data p, data q) { return p.y > q.y; }

bool cmpp(int a, int b)
{
    vector <int> v1, v2, f1,f2; int pos = -1;
    while (a) v1.pb(a%10), a/=10;
    while (b) v2.pb(b%10), b/=10;
    for (int i = v1.size() - 1;  i >= 0; --i) f1.pb(v1[i]);
    for (int i = v2.size() - 1;  i >= 0; --i) f2.pb(v2[i]);
    for (int i = 0; i < max(f1.size(),f2.size()); ++i)
        if (f1[i] != f2[i])
        {
            pos = -1;
            if (f1[i]>f2[i]) return 1;
            else return 0;
        }
    if (pos == -1) if (f1.size()>f2.size()) return 1; else return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(Task".inp","r",stdin);
	freopen(Task".out","w",stdout);
	cin >> m >> n >> k; h = k - n;
	for (int i = 1; i <= m; ++i) cin >> a[i], A[i].F = a[i], A[i].S = i;
	for (int i = 1; i <= n; ++i) cin >> b[i];
    sort(A+1,A+m+1);
    for (int i = 1; i <= h; ++i) d[i].x = A[i].F, d[i].y = A[i].S;
    sort(d+1,d+h+1,cmp);
    for (int i = 1; i <= h; ++i) p[i] = d[i].x;

    int i = 1, j = 1;
    while (i <= h || j <= n)
    {
        if (i == h)
        {
            c.pb(p[i]);
            for (int ii = j; ii <= n; ++ii) c.pb(b[ii]);
            break;
        }
        else if (j == n)
        {
            c.pb(b[j]);
            for (int ii = i; ii <= h; ++ii) c.pb(p[ii]);
            break;
        }
        else
        {
            if (cmpp(p[i],b[j]) == 0) c.pb(p[i]), ++i;
            else c.pb(b[j]), ++j;
        }
    }
    for (int t:c) cout << t <<" ";
	return 0;
}
