#include <bits/stdc++.h>
#define FILE "ICECREAM"
#define long long long
#define mp(a,b,c) make_pair(a, make_pair(b,c))

using namespace std;
const int maxn=3e2+5, M=1e9+9;

struct data{ int a, b, c; bool operator <(const data x) const{ return mp(a, b, c) < mp(x.a, x.b, x.c); } };
typedef map < data, int >::iterator it;

int n, m, A, B, C, ans, cur = 1, pre = 0;
map < data, int > S[2];

void Mod(int &a, int b){ a += b; if (a >= M) a -= M; }
void Add(int a, int b, int c, int w){ Mod(S[cur][{a, b, c}], w); }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin >> n >> m >> A >> B >> C; S[cur][{A, B, C}] = 1;

    for (int i = 1; i < n; ++i)
    {
        swap(cur, pre); S[cur].clear();
        for(it s = S[pre].begin(); s != S[pre].end(); ++s)
        {
            int a = (*s).first.a, b = (*s).first.b, c = (*s).first.c, v = (*s).second;
            if (a < m) Add(a+1, b, c, v);
            if (a >= 1 && b < m) Add(a-1, b+1, c, v);
            if (a >= 1 && b >= 1 && c < m) Add(a-1, b-1, c+1, v);
            if (a >= 3 && b == 0 && c < m) Add(a-3, b, c+1, v);
        }
    }

    for (it s = S[cur].begin(); s != S[cur].end(); ++s)
    {
        int a = (*s).first.a, b = (*s).first.b, c = (*s).first.c, v = (*s).second;
        if (a < m) Mod(ans, v);
        if (a >= 1 && b < m) Mod(ans, v);
        if (a >= 1 && b >= 1 && c < m) Mod(ans, v);
        if (a >= 3 && b == 0 && c < m) Mod(ans, v);
    }

    cout << ans;
    return 0;
}
