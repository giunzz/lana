#include<bits/stdc++.h>
#define For(i, a, b)  for(int i = a; i <= b; ++i)
#define Ford(i, a, b) for(int i = a; i >= b; --i)
#define FileName      "sequence"
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
const int N = 3007;

int n, m, k, nVal;
vector<int> v;
struct TSolveOne
{
    int f[N][N], trace[N][N], n, need, a[N], nxt[N][N];
    vector<int> res;
    void Pre()
    {
         Ford(i, n, 0)
         {
             a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
             For(j, 1, nVal)
             {
                 if(a[i + 1] == j) nxt[i][j] = i + 1;
                 else nxt[i][j] = nxt[i + 1][j];
             }
         }
    }
    void Reset()
    {
        memset(&f, -1, sizeof f);
    }
    void Trace(int x, int k)
    {
         if(k > need) return;
         res.pb(v[a[x] - 1]);
         Trace(nxt[x][trace[x][k]], k + 1);
    }
    int DP(int x, int y)
    {
        if(f[x][y] != -1) return f[x][y];
        if(y == need) return x <= n && x > 0;
        f[x][y] = 0;
        For(i, 1, nVal)
            if(nxt[x][i] >= 1 && nxt[x][i] <= n && DP(nxt[x][i], y + 1))
            {
                trace[x][y] = i;
                return f[x][y] = 1;
            }
        return f[x][y];
    }
    void Calc(int k)
    {
        need = k;
        res.clear();
        For(i, 1, n)
        if(DP(i, 1)) {Trace(i, 1); break;}
    }
} A, B;
vector<int> ans;

void Enter()
{
     Cin(A.n), Cin(B.n), Cin(k);
     For(i, 1, A.n) Cin(A.a[i]), v.pb(A.a[i]);
     For(i, 1, B.n) Cin(B.a[i]), v.pb(B.a[i]);
     sort(v.begin(), v.end());
     v.erase(unique(v.begin(), v.end()), v.end());
     nVal = v.size();
}

void Update()
{
    vector<int> t1, t2, t;
    int i, j;
    if(A.res.empty()) t = B.res;
    else if(B.res.empty()) t = A.res;
    else
    {
        int j = 0, i = 0;
        while(i < A.res.size() || j < B.res.size())
        {
            while((B.res[j] < A.res[i] || (i == A.res.size())) && j < B.res.size()) t1.pb(B.res[j]), ++j;
            while((A.res[i] <= B.res[j] || (j == B.res.size())) && i < A.res.size()) t1.pb(A.res[i]), ++i;
        }
        i = 0, j = 0;
        while(i < A.res.size() || j < B.res.size())
        {
             while((A.res[i] < B.res[j] || (j == B.res.size())) && i < A.res.size()) t2.pb(A.res[i]), ++i;
             while((B.res[j] <= A.res[i] || (i == A.res.size())) && j < B.res.size()) t2.pb(B.res[j]), ++j;
        }
        if(t1.size() == k) t = t1;
        if(t2.size() == k) t = t2;
        if(t1.size() == t2.size() && t1.size() == k)
        {
            For(i, 0, k - 1)
            {
                if(t1[i] < t2[i]) {t = t1; break;}
                if(t1[i] > t2[i]) {t = t2; break;}
                if(i == k - 1) t = t1;
            }
        }
    }
    if(t.size() < k) return;
    if(ans.empty()) ans = t;
    else
    {
        For(i, 0, k - 1) if(ans[i] < t[i]) return;
        ans = t;
    }
}

void Solve()
{
     For(i, 1, min(A.n, k))
     {
         if(k - i > B.n) continue;
         B.Pre(); B.Reset();
         A.Pre(); A.Reset();
         A.Calc(i); B.Calc(k - i);
         Update();
     }
     for(int x: ans) cout << x << ' ';
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
