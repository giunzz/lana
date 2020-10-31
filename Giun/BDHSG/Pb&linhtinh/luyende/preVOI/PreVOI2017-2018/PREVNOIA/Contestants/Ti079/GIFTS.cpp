#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e6 + 6;
const ll oo = 1e13;
ll n, k, a[N], sum[N], f[N], g[N], ans, l, r;
bool check(ll mid)
{
    for(int i = 1; i <= n; ++i)
        if (max(f[i - 1] ,g[i + k]) <= mid) return true;
    return false;
}
inline ll ReadInt()
{
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar());
    ll res = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        res = res * 10 + c - '0';
    return res;
}

void WriteInt(ll x)
{
    if (x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}
int main()
{
    #define file "GIFTS"
    freopen(file".INP" ,"r" ,stdin);
    freopen(file".OUT" ,"w" ,stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    n = ReadInt(); k = ReadInt();
    for(int i = 1; i <= n; ++i) {
        a[i] = ReadInt();
        sum[i] = sum[i - 1] + a[i];
    }
    f[k] = sum[k];
    for(int i = k + 1; i <= n; ++i) {
        f[i] = max(f[i - 1], sum[i] - sum[i - k]);
    }
    g[n - k + 1] = sum[n] - sum[n - k];
    for(int i = n - k; i >= 1; --i) {
        g[i] = max(g[i + 1], sum[i + k - 1] - sum[i - 1]);
    }
    l = 1; r = sum[n];
    ans = oo + 10;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (check(mid)) ans = min(ans, mid), r = mid - 1;
        else l = mid + 1;
    }
    WriteInt(ans);
    return 0;
}
