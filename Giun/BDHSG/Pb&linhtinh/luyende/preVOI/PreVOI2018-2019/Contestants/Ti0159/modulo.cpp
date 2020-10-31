#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

int n, k, a, b, somod, mod, last, val[100], mod2 = 0, restmod;
int NhanNT(int a, int b)
{
    if(b == 0) return 0;
    int mid = NhanNT(a, b / 2);
    mid = (mid + mid) % somod;
    if(b & 1) mid = (mid + a) % somod;
    return mid;
}

int dich;
vector<pair<int, int>> vt1, vt2;

void BackTrack(int x, int mask, int val)
{
    if(x > last)
    {
        if(last == n) vt1.push_back({(restmod + somod - val) % somod, mask});
        else vt2.push_back({val, mask});
        return;
    }
    else
    {
        BackTrack(x + 1, mask, val);
        BackTrack(x + 1, mask ^ (1 << x), (val + ::val[x]) % somod);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("modulo.inp", "r", stdin);
    freopen("modulo.out", "w", stdout);
    cin >> a >> b >> n >> k;
    somod = 1;
    somod <<= n;
    int ans = min(a, b) % somod;
    for(int i = 2; i <= n; i++)
    {
        ans = (NhanNT(ans, 10) + min(a, b)) % somod;
    }
    int rest = max(a, b) - min(a, b);
    restmod = (k + somod - ans) % somod;
    val[1] = rest % somod;
    for(int i = 2; i <= n; i++)
    {
        val[i] = NhanNT(val[i - 1], 10);
    }
    int mid = (1 + n) / 2;
    last = mid;
    BackTrack(1, 0, 0);
    last = n;
    BackTrack(mid + 1, 0, 0);
    sort(vt1.begin(), vt1.end());
    sort(vt2.begin(), vt2.end());
    int cnt = 0;
    ans = -1;
    for(auto i: vt1)
    {
        while(cnt < vt2.size() && vt2[cnt].first < i.first) cnt++;
        if(cnt >= vt2.size()) break;
        else if(vt2[cnt].first == i.first)
        {
            ans = vt2[cnt].second ^ i.second;
            break;
        }
    }
    for(int i = n; i >= 1; i--)
    {
        if((ans >> i) & 1) cout << max(a, b);
        else cout << min(a, b);
    }
}
