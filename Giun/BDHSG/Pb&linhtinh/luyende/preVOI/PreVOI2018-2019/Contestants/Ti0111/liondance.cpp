#include<bits/stdc++.h>
#define For(i, a, b)  for(int i = a; i <= b; ++i)
#define Ford(i, a, b) for(int i = a; i >= b; --i)
#define FileName      "liondance"
#define ll            long long
#define ld            long double
#define ull           unsigned long long
#define pb            push_back
#define X             first
#define Y             second
#define Karma

using namespace std;

template <typename T> inline void Cin(T &x)
{
    char c;
    T sign = 1;
    x = 0;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') sign = -1;
    for (; c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    x *= sign;
}

typedef pair<int, int> pii;
typedef pair<ll, int> plli;
const int N = 4007;

int n, m, res, x, y, k, fir, nVal, a[N], b[N], nxta[N][N], nxtb[N][N], trace[N][N], f[N][N];
vector<int> v, ans;

void Enter()
{
     Cin(n), Cin(k);
     For(i, 1, n) Cin(a[i]), v.pb(a[i]);
     For(i, 1, n) Cin(b[i]), v.pb(b[i]);
     sort(v.begin(), v.end());
     v.erase(unique(v.begin(), v.end()), v.end());
     nVal = v.size();
}

void Solve()
{
     For(i, 1, n + 1)
     {
         a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
         b[i] = lower_bound(v.begin(), v.end(), b[i]) - v.begin() + 1;
         For(j, 1, nVal)
         {
             if(a[i - 1] == j) nxta[i][j] = i - 1;
             else nxta[i][j] = nxta[i - 1][j];
             if(b[i - 1] == j) nxtb[i][j] = i - 1;
             else nxtb[i][j] = nxtb[i - 1][j];
         }
     }
     res = 0;
     For(i, 1, n)
     {
         For(j, 1, n)
         {
             if(a[i] == b[j])
             {
                 Ford(k, nVal, 1)
                 {
                     if(f[nxta[i][k]][nxtb[j][k]] + 1 > f[i][j] && abs(v[a[i] - 1] - v[j - 1]) <= k)
                     {
                        f[i][j] = f[nxta[i][k]][nxtb[j][k]] + 1;
                        trace[i][j] = k;
                     }
                 }
             }
             res = max(res, f[i][j]);
         }
     }
     cout << res << '\n';
     For(i, 1, n)
     {
         For(j, 1, n)
         {
             if(f[i][j] == res)
             {
                vector<int> t;
                t.pb(a[i]);
                int x = i, y = j;
                while(x > 0 && y > 0)
                {
                    if(t.size() < res) t.pb(trace[x][y]);
                    int k = trace[x][y];
                    x = nxta[x][k], y = nxtb[y][k];
                }
                reverse(t.begin(), t.end());
                if(ans.empty()) ans = t;
                else For(i, 0, res - 1) if(t[i] > ans[i]) {ans = t; break;}
             }
         }
     }
     for(int v: ans) cout << v << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#ifdef Karma
    freopen(FileName".inp", "r", stdin);
    freopen(FileName".out", "w", stdout);
#endif // Karma

    Enter();
    Solve();

    return 0;
}
