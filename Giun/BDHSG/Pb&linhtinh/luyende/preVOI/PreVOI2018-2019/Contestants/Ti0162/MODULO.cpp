#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
typedef pair<int, int> ii;

int a, b, n, K, mod;

int read_int () {
    int ret = 0; char inp; bool neg = 0;
    do { inp = getchar(); } while (inp != '-' && !isdigit(inp) );
    if (inp == '-') neg = 1;
    else ret = inp - '0';
    while (isdigit(inp = getchar() ) ) { ret = 10 * ret + inp - '0'; }
    return neg ? -ret : ret;
}

namespace Small {
    bool ok;
    int lim[2], pow10;
    set<int> num[2];
    vector<int> ans[2];

    void bt (bool _, int pos, int cur) {
        if (pos == lim[_]) {
            num[_].insert(cur);
            return ;
        }
        bt(_, pos + 1, (10 * cur + a) % mod );
        bt(_, pos + 1, (10 * cur + b) % mod );
    }

    void findNum (bool _, int pos, int cur, int need) {
        if (pos == lim[_]) {
            if (cur == need) ok = 1;
            return ;
        }
        ans[_][pos] = a;
        findNum(_, pos + 1, (10 * cur + a) % mod, need);
        if (ok) return ;
        ans[_][pos] = b;
        findNum(_, pos + 1, (10 * cur + b) % mod, need);
    }

    void Main () {
        lim[0] = (n + 1) / 2; lim[1] = n - lim[0];
        pow10 = 1;
        for (int i = 0; i < lim[1]; ++i) pow10 = (10LL * pow10) % mod;

        bt(0, 0, 0); bt(1, 0, 0);

        for (int _ : num[0]) {
            int nxt = ( ( (K - _ * pow10) % mod) + mod) % mod;
            if (num[1].count(nxt) ) {
                ans[0].assign(lim[0], 0); ans[1].assign(lim[1], 0);
                ok = 0; findNum(0, 0, 0, _);
                ok = 0; findNum(1, 0, 0, nxt);
                for (int i : ans[0]) cout << i;
                for (int i : ans[1]) cout << i;
                return ;
            }
        }

        cout << -1;
    }
}

namespace Large {
    void Main () {
        cout << -1;
    }
}

int32_t main () {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("MODULO.INP", "r", stdin);
    freopen("MODULO.OUT", "w", stdout);

    a = read_int(); b = read_int(); n = read_int(); K = read_int(); mod = (1LL << n);

    if (n <= 40) Small::Main();
    else Large::Main();

    return 0;
}
// Ti0162
