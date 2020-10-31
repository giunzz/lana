#include <bits/stdc++.h>

#define fn "test"
#define fn1 "LIONDANCE"

using namespace std;

const int mn = 4 * (int)(1e3) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;

void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (ifstream(fn".inp"))
    {
        freopen(fn".inp", "r", stdin);
        if (!aNs) freopen(fn".out", "w", stdout);
		else freopen (fn".ans", "w", stdout);
    }else if (ifstream(fn1".inp"))
    {
        freopen(fn1".inp", "r", stdin);
        freopen(fn1".out", "w", stdout);
    }
}

template <typename T>
void read(T& x)
{
    x = 0; T f = 1;
    char ch = getchar();
    while (!isdigit(ch)) f = ch == '-' ? - f : f, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    x *= f;
}

template <typename T>
void write (T a)
{
    if (a < 0)
    {
        putchar ('-');
        write (-a);
        return;
    }
    if (a < 10)
    {
        putchar ('0' + a);
        return;
    }
    write (a / 10);
    putchar ((char)('0' + (a % 10)));
}

int n, d;

template<class T>
class IT
{
    T MAX (T a, T b)
    {
        return max (a, b);
    }
    void Assign (T& a, T b)
    {
        a = max (a, b);
    }
    public:
        vector<T> it, la;
        bool Lazy;
        IT ()
        {
            it.resize(4 * n + 10);
            la.resize(4 * n + 10);
            // cerr << n << "\n";
            Lazy = 0;
        }
        // IT (int N = mn, bool LazY = 0)
        // {
        //     n = N;
        //     it.resize(4 * n + 10);
        //     la.resize(4 * n + 10);
        //     Lazy = LazY;
        //     clear();
        // }   

        void resize (int N)
        {
            n = N;
            it.resize (4 * n + 10);
            la.resize (4 * n + 10);
        }

        void clear (int id = 1, int l = 1, int r = - 1)
        {
            if (r == - 1) r = n;
            it[id] = 0;
            if (l == r) return;
            int i = id << 1, m = (l + r) >> 1;
            clear (i, l, m);
            clear (i ^ 1, m + 1, r);
            it[id] = MAX (it[i], it[i ^ 1]);
        }

        void ud (int a, T w, int id = 1, int l = 1, int r = - 1)
        {
            if (r == - 1) r = n;
            if (l > a || r < a) return;
            if (l == r)
            {
                it[id] = max (it[id], w);
                return;
            }
            int m = (l + r) >> 1, i = id << 1;
            ud (a, w, i, l, m);
            ud (a, w, i ^ 1, m + 1, r);
            it[id] = MAX (it[i], it[i ^ 1]);
        }

        T qu (int a, int b, int id = 1, int l = 1, int r = - 1)
        {
            if (r == - 1) r = n;
            if (l > b || r < a) return 0;
            if (l >= a && r <= b)
            return it[id];
            int i = id << 1, m = (l + r) >> 1;
            return MAX (qu (a, b, i, l, m), qu (a, b, i ^ 1, m + 1, r));
        }
};

vector<IT<int> > bi;

void ub (int x, int l, int v)
{
    for (; x <= n; x += x & - x)
    bi[x].ud (l, v);
}

int db (int x, int l, int r)
{
    int R = 0;
    for (; x >= 1; x -= x & - x)
    R = max (R, bi[x].qu (l, r));
    return R;
}

int a[mn], b[mn], x[mn], l[mn], r[mn];
int f[mn];
vector<int> V[mn];

void enter()
{
    cin >> n >> d;
    vector<int> v;
    bi.resize(n + 2);
    for (int i = 1; i <= n; ++ i)
    cin >> a[i];
    for (int i = 1; i <= n; ++ i)
    {
        cin >> b[i];
        v.emplace_back(b[i]);
    }
    sort (v.begin(), v.end());
    v.resize(unique (v.begin(), v.end()) - v.begin());
    for (int j = 1; j <= n; ++ j)
    {
        x[j] = lower_bound(v.begin(), v.end(), b[j]) - v.begin() + 1;
        l[j] = lower_bound(v.begin(), v.end(), b[j] - d) - v.begin() + 1;
        r[j] = upper_bound(v.begin(), v.end(), b[j] + d) - v.begin();
    }
    int sol = 0;
    for (int i = 1; i <= n; ++ i)
    {
        for (int j = 1; j <= n; ++ j)
        if (a[i] == b[j])
        {
            f[j] = db (j - 1, l[j], r[j]) + 1;
            sol = max (sol, f[j]);
        }
        for (int j = 1; j <= n; ++ j)
        if (a[i] == b[j])
        {
            ub (j, x[j], f[j]);
            V[f[j]].emplace_back(b[j]);
        }
    }
    cout << sol << "\n";
    for (int i = sol; i >= 1; -- i)
    {
        if (i != sol)
        {

            for (int j = V[i].size() - 1; j >= 0; -- j)
            {
                auto it1 = upper_bound(V[i + 1].begin(), V[i + 1].end(), V[i][j] + d);
                auto it2 = lower_bound(V[i + 1].begin(), V[i + 1].end(), V[i][j] - d);
                if (it1 == it2) 
                {
                    V[i][j] = V[i].back();
                    V[i].pop_back();
                }
            }
        }
        sort (V[i].begin(), V[i].end());
        V[i].resize(unique(V[i].begin(), V[i].end()) - V[i].begin());
    }
    cout << V[1].back() << " ";
    int x = V[1].back();
    for (int i = 2; i <= sol; ++ i)
    {
        int l = upper_bound(V[i].begin(), V[i].end(), x + d) - V[i].begin() - 1;
        x = V[i][l];
        cout << V[i][l] << " ";
    }
}

void solve()
{

}

void print_result()
{

}

int main()
{
    docfile();
    //cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}