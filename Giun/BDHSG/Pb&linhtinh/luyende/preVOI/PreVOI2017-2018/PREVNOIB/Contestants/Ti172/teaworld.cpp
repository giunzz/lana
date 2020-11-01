#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 1e6 + 5;
const int mod  = 1e9 + 7;
const int oo   = 1e9 + 1;

int n, T, xS, yS, zS, res(0), m, k;
vector <int> v;

struct Cau
{
    int x, y, z, r;
};
Cau t[2001];

struct Tea
{
    int x, y, z, e;
};
Tea s[16];

void Init()
{
    cin >> m >> n >> k;
    for (int i = 1; i <= m; ++i) cin >> t[i].x >> t[i].y >> t[i].z >> t[i].r;
    for (int i = 1; i <= n; ++i) cin >> s[i].x >> s[i].y >> s[i].z >> s[i].e;
    cin >> xS >> yS >> zS;
}

void Solve()
{
    for (int i = 1; i < (1 << n); ++i)
    {
        v.clear();
        for (int j = 1; j <= m; ++j) v.push_back(j);
        int cnt = 0, sum = 0;
        for (int j = 1; j <= n; ++j)
            if ((i >> (j - 1) & 1) == 1)
            {
                //cout << j << endl;
                sum += s[j].e;
                for (int l = (int)v.size() - 1; l >= 0; --l)
                    if (min (xS, s[j].x) <= t[v[l]].x - t[v[l]].r && t[v[l]].x + t[v[l]].r <= max (xS, s[j].x))
                    {
                        cnt++;
                        v[l] = v.back(); v.pop_back();
                    }
            }
        //cout << i << " " << cnt << " " << sum << endl;
        if (cnt <= k) res = max (res, sum);
    }
    cout << res;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    freopen ("teaworld.inp", "r", stdin);
    freopen ("teaworld.out", "w", stdout);

    Init();
    Solve();
}
// Date 2 Month 12 Year 2017

