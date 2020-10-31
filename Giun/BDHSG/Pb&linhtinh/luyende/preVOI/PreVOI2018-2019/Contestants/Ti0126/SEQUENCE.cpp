#include <bits/stdc++.h>

#define text "SEQUENCE"

using namespace std;

const int maxn = 1e6+7;

long long m, n, k, a[maxn], b[maxn], s[maxn], s2[maxn], r, c[maxn];
stack <int> st;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    freopen(text".inp", "r", stdin);
    freopen(text".out", "w", stdout);

    cin >> m >> n >> k;

    for (int i = 1; i <= m; ++i) cin >> a[i], s[i] = s[i-1]+a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i], s2[i] = s2[i-1]+b[i];

    for (int i = 1; i <= m; ++i)
    {
        st.push(i);
        for (int j = i; j <= m; ++j)
        {
            if (s[j]-s[i-1] == s2[i])
            {
                if (j != i && i != 1) st.top() = -1;
            }
        }
        if (r > k-n) st.top() = -1;
        if (st.top() != -1)
        {
            if (a[st.top()] > a[st.top()+1] && st.top()+1 <= m) swap(a[st.top()], a[st.top()+1]);
            c[++r] = a[st.top()];
        }

        if (r == k-n)
            for (int j = 1; j <= n; ++j) c[++r] = b[j];
    }

    for (int i = 1; i <= k; ++i) cout << c[i] << " ";

    return 0;
}
