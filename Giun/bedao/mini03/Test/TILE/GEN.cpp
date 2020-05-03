#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define fi first
#define se second

using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int n, m;

int main()
{
    for (int test = 1; test <= 20; ++test)
    {
        string inp = "";
        int tmp = test;
        while (tmp) inp.push_back((char)(tmp % 10 + '0')), tmp /= 10;
        reverse(inp.begin(), inp.end());
        string ou = inp + ".out";
        inp += ".inp";
        ofstream out(inp.c_str());

        int n, m;

        if (test <= 5)
        {
            n = rd() % 300 + 700, m = rd() % 300 + 700;
        }else
        {
            int proc = rd() % (int)5e5 + (int)5e5 + 1;
            if (test > 15) proc = rd() % (int)1e7 + (int)1e7 + 1;
            n = rd() % (proc / 2 - 10000) + 10001;
            m = proc / n;
            if (rd() % 2) swap(n,m);
        }
        int r1 = 0, r2 = 0;
        cerr << n << ' ' << m << '\n';
        out << n << ' ' << m << '\n';
        for (int i = 1; i <= n; ++i, out << '\n')
            for (int j = 1; j <= m; ++j)
            {
                bool v = rd() % 2;
                out << v;
                if ((i + j) % 2 == v) ++r1; else ++r2;
            }
        out.close();

        ofstream o2(ou.c_str());
        o2 << min(r1,r2);
        o2.close();
    }


    return 0;
}
