#include <bits/stdc++.h>
#define FILE "LIONDANCE"
#define long long long
#define pii pair < int, int >
#define u tmp[{i, j}]
#define v t[{i, j}]

using namespace std;
const int maxn=4e3+5;
typedef map < pii, int >::iterator pi;
typedef map < pii, pii >::iterator pp;

int n, k, a[maxn], b[maxn]; pii ans;
vector < int > p, q[maxn];
map < pii, int > d, tmp; map < pii, pii > t;

int id(int x)
{
    int loc = lower_bound(p.begin(), p.end(), x) -p.begin();
    if (p[loc] != x) return -1; return loc;
}

void Cout(pii ans)
{
    if (t[ans] != make_pair(0,0)) Cout(t[ans]);
    cout << a[ans.first] << " ";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i], p.push_back(a[i]);
    sort(p.begin(), p.end()); p.resize(unique(p.begin(), p.end()) -p.begin());

    for (int i = 1, l; i <= n; ++i)
    {
        cin >> b[i];
        if ((l = id(b[i])) > -1) q[l].push_back(i);
    }

    d[{0, 0}] = 0;
    for (int i = 1; i <= n; ++i)
    {
        tmp.clear(); int x = id(a[i]);
        for (pi s = d.begin(); s != d.end(); ++s)
        {
            int L = (*s).first.first, R = (*s).first.second, W = (*s).second;
            if (abs(a[L] -a[i]) > k) continue;

            int j = upper_bound(q[x].begin(), q[x].end(), R) -q[x].begin();
            if (j == q[x].size()) continue; j = q[x][j];

            if (tmp.find({i, j}) == tmp.end() || u < W+1) u = W+1, v = {L, R};
            else if (u == W+1 && a[v.first] < a[L]) v = {L, R};
        }

        for (pi f = tmp.begin(); f != tmp.end(); ++f)
        {
            int L = (*f).first.first, R = (*f).first.second, W = (*f).second;
            d[{L, R}] = W; if (W > d[ans]) ans = {L, R};
        }
    }

    cout << d[ans] << "\n"; Cout(ans);
    return 0;
}
