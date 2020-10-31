#include <bits/stdc++.h>
#define int long long

#define fn "test"
#define fn1 "ROBOTS"

using namespace std;

const int mn = 1 * (int)(1e4) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int x[mn], y[mn];

struct Z
{
    int v, Y1, Y2, id;
    Z (){}
    Z (int _v, int _Y1, int _Y2, int _id)
    {
        v = _v; Y1 = _Y1; Y2 = _Y2; id = _id;
    }
    bool operator < (const Z& b)
    {
        return v < b.v;
    }
};


void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
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

pair<int, int> ch (int x, int y)
{
    return make_pair (x + y, y - x);
}

template<class T>
class IT
{
    T MAX (T a, T b)
    {
        return (a & b);
    }
    void Assign (T& a, T b)
    {
        a += b;
    }
    public:
        vector<T> it, la;
        vector<bool> vl;
        int n;
        bool Lazy;
        IT (int N = mn, bool LazY = 0)
        {
            n = N;
            it.resize(4 * n + 10);
            la.resize(4 * n + 10);
            vl.resize (4 * n + 10);
            Lazy = LazY;
            clear();
        }   

        void resize (int N)
        {
            n = N;
            it.resize (4 * n + 10);
            la.resize (4 * n + 10);
            vl.resize (4 * n + 10);
        }

        void lazy (int id, T w)
        {
            Assign (it[id], w);
            if (it[id]) vl[id] = 1;
            else vl[id] = 0;
            if (!Lazy) return;
            Assign (la[id], w);
        }

        void layd (int id)
        {
            if (!Lazy) return;
            int i = id << 1;
            lazy (i, la[id]);
            lazy (i ^ 1, la[id]);
            la[id] = 0;
        }

        void clear (int id = 1, int l = 1, int r = - 1)
        {
            if (r == - 1) r = n;
            it[id] = vl[id] = 0;
            if (l == r) return;
            int i = id << 1, m = (l + r) >> 1;
            clear (i, l, m);
            clear (i ^ 1, m + 1, r);
        }

        void ud (int a, int b, T w, int id = 1, int l = 1, int r = - 1)
        {
            if (r == - 1) r = n;
            if (l > b || r < a) return;
            if (l >= a && r <= b)
            {
                lazy (id, w);
                return;
            }
            int m = (l + r) >> 1, i = id << 1;
            layd (id);
            ud (a, b, w, i, l, m);
            ud (a, b, w, i ^ 1, m + 1, r);
            vl[id] = MAX (vl[i], vl[i ^ 1]);
        }

        T qu (int a, int b, int id = 1, int l = 1, int r = - 1)
        {
            if (r == - 1) r = n;
            if (l > b || r < a) return 1;
            if (l >= a && r <= b)
            return vl[id];
            int i = id << 1, m = (l + r) >> 1;
            layd (id);
            return MAX (qu (a, b, i, l, m), qu (a, b, i ^ 1, m + 1, r));
        }
};

void enter()
{
    int u, n;
    cin >> u >> n;
    for (int i = 0; i <= u; ++ i)
    {
        cin >> x[i] >> y[i];
    }
    int inf = 0, sup = 2 * (int)(1e9), Sol;
    // inf = sup = 5;
    while (inf <= sup)
    {
        // sol.clear();
        int mid = (inf + sup) >> 1;
        vector<int> vy;
        vector<Z> v;
        for (int i = 0; i <= u; ++ i)
        {
            pair<int, int> p1, p2, p3, p4;
            int d = (i < u ? mid : n);
            p1 = ch (x[i] - d, y[i]);
            p2 = ch (x[i], y[i] + d);
            p3 = ch (x[i], y[i] - d);
            p4 = ch (x[i] + d, y[i]);
            if (i == u)
            {
                v.push_back(Z (p1.first, p4.second, p2.second, 0));
                v.push_back(Z (p2.first + 1, p4.second, p2.second, 0));
            }
            else
            {
                v.push_back(Z (p1.first, p4.second, p2.second, 1));
                v.push_back(Z (p2.first + 1, p4.second, p2.second, - 1));
            }
            vy.push_back(p4.second);
            vy.push_back(p2.second);
        }
        IT<int> sol (2*u + 10, 1);
        sort (vy.begin(), vy.end());
        vy.resize(unique (vy.begin(), vy.end()) - vy.begin());
        sort (v.begin(), v.end());
        bool res = 1;
        bool ok = 0;
        int Y1, Y2;
        for (int i = 0; i < v.size(); ++ i)
        {
            v[i].Y1 = lower_bound (vy.begin(), vy.end(), v[i].Y1) - vy.begin() + 1;
            v[i].Y2 = lower_bound (vy.begin(), vy.end(), v[i].Y2) - vy.begin() + 1;
            if (!v[i].id)
            {
                ok ^= 1;
                Y1 = v[i].Y1;
                Y2 = v[i].Y2;
            }
            else
            sol.ud (v[i].Y1, v[i].Y2, v[i].id);
            if (ok && (i == v.size() - 1 || v[i].v != v[i + 1].v))
            if (!sol.qu (Y1, Y2))
            res = 0;
        }
        if (res)
        {
            Sol = mid;
            sup = mid - 1;
        }
        else inf = mid + 1;
    }
    cout << Sol;
}

void solve()
{

}

void print_result()
{

}

main()
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