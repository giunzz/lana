#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define FOR(a, b, c) for(int a = b; a <= c; ++a)
#define pb push_back
#define ll long long
typedef pair<int, int> lii;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;
const int N = 3005;
const int oo = 1e9;

int n, m, k;
ll ha[2][N], hb[2][N], pwb[2][N];
int a[N], b[N], nexa[N], nexb[N];

bool cmp(vector<int> x, vector<int> y)  {
    for(int i = 0; i < k; ++i) if(x[i] != y[i]) {
       return x[i] > y[i];
    }
    return false;
}
lii gethash(int base, int l, int r) {
    lii res;
    res.fi = (ha[0][r] - 1ll * ha[0][l - 1] * pwb[0][r - l + 1] + 1ll * mod1 * mod1) % mod1;
    res.se = (ha[1][r] - 1ll * ha[1][l - 1] * pwb[1][r - l + 1] + 1ll * mod2 * mod2) % mod2;
    if(base == 1) {
        res.fi = (hb[0][r] - 1ll * hb[0][l - 1] * pwb[0][r - l + 1] + 1ll * mod1 * mod1) % mod1;
        res.se = (hb[1][r] - 1ll * hb[1][l - 1] * pwb[1][r - l + 1] + 1ll * mod2 * mod2) % mod2;
    }
    return res;
}
bool check(int a1, int a2, int b1, int b2)  {
    return gethash(0, a1, a2) == gethash(1, b1, b2);
}
signed main()
{
    freopen("SEQUENCE.inp", "r", stdin);
    freopen("SEQUENCE.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for(int j = 1; j <= m; ++j) scanf("%d", &b[j]);
    pwb[0][0] = pwb[1][0] = 1; FOR(i, 1, N - 1) {
        pwb[0][i] = pwb[0][i - 1] * 3000 % mod1;
        pwb[1][i] = pwb[1][i - 1] * 3000 % mod2;
    }
    memset(nexa, -1, sizeof nexa); memset(nexb, -1, sizeof nexb);
    stack<int> st;
    for(int i = n; i >= 1; --i) {
        while(!st.empty() && a[ st.top() ] >= a[i]) st.pop();
        if(!st.empty()) nexa[i] = st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i = m; i >= 1; --i) {
        while(!st.empty() && b[ st.top() ] >= b[i]) st.pop();
        if(st.size() > 0) nexb[i] = st.top();
        st.push(i);
    }
    vector<int> ans, res;
    ans.assign(k, oo);
    for(int i = 0; i <= k; ++i) {
        vector<int> na, nb;
        int cnta = i, cntb = k - i;
        if(cnta > n || cntb > m) continue;
        int ptr = 1;
        while(ptr <= n && cnta > 0) {
            int cur = ptr;
            while(nexa[cur] != -1 && n - nexa[cur] + 1 >= cnta) cur = nexa[cur];
            na.pb(a[cur]); ptr = cur + 1; cnta --;
        }
        ptr = 1;
        while(ptr <= m && cntb > 0) {
            int cur = ptr;
            while(nexb[cur] != -1 && m - nexb[cur] + 1 >= cntb) cur = nexb[cur];
            nb.pb(b[cur]); ptr = cur + 1; cntb --;
        }
        //for(int v: na) cout << v << ' '; cout << '\n';
        //for(int v: nb) cout << v << ' '; cout << '\n';

        for(int j = 1; j <= i; ++j) {
            ha[0][j] = (ha[0][j - 1] * 3000 + na[j - 1]) % mod1;
            ha[1][j] = (ha[1][j - 1] * 3000 + na[j - 1]) % mod2;
        }
        for(int j = 1; j <= (k - i); ++j) {
            hb[0][j] = (hb[0][j - 1] * 3000 + nb[j - 1]) % mod1;
            hb[1][j] = (hb[1][j - 1] * 3000 + nb[j - 1]) % mod2;
        }

        int pa = 0, pb = 0;
        while(pa < na.size() && pb < nb.size()) {
            if(na[pa] < nb[pb]) res.pb(na[pa]), pa ++;
            else if(na[pa] > nb[pb]) res.pb(nb[pb]), pb ++;
            else {
                int l = 0, r = min(na.size() - pa - 1, nb.size() - pb - 1);
                while(r > l)    {
                    int mid = (l + r + 1) / 2;
                    if(check(pa + 1, pa + mid + 1, pb + 1, pb + mid + 1)) l = mid;
                    else r = mid - 1;
                }
                bool ok = true;
                if(l == min(na.size() - pa - 1, nb.size() - pb - 1)) ok = true;
                else ok = (na[pa + l + 1] < nb[pb + l + 1]);
                //cout << ok << ' ' << l << '\n';
                if(ok) res.pb(na[pa]), pa ++;
                else res.pb(nb[pb]), pb ++;
            }
        }
        while(pa < na.size()) res.pb(na[pa]), pa ++;
        while(pb < nb.size()) res.pb(nb[pb]), pb ++;
        if(cmp(ans, res)) {
            for(int j = 0; j < k; ++j) ans[j] = res[j];
        }
        res.clear();
    }
    for(int i = 0; i < k; ++i) printf("%d ", ans[i]);
}
