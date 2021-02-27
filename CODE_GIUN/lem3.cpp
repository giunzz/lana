// Goi f[u][mask ] : chi phi nho nhat khi da di tham cac thanh pho duoc bieu dien boi mask va dang dung
// tai u o hien tai
// BTCS : f[u][1<<u] = 0 ( 2^n <=> 1<< n)
// Gia su  dag fung o f[u][mask]
// Gia su trc khi to u thi dung o v ( v != u)  f[u][mask] = min{f[v][mask^1<<u] + cost[v][u]}
// ans : min f[u][(1<<n)-1]

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)
#pragma GCC optimize("Ofast")

int n , c[20][20] , f[20][1<<20];
const int inf = 200000;

bool check (int &pos , int &mask)
{
    if ((mask&(1<<pos)) == (1<<pos)) return true;
    return false;
}
void dp_bitmask ()
{
    for (int u = 0 ; u < n ; u++)
        for (int mask = 0 ; mask < (1 << n) ; mask++) f[u][mask] = inf;
    for (int u = 0 ; u < n ; u++) f[u][1 << u ] = 0;
    for (int mask = 1 ; mask < (1 << n) ; mask++)
        for (int u = 0 ; u < n ; u++)
            if (check(u,mask) == true)
                for (int v = 0 ; v < n ; v ++)
                    if (v != u && check(v,mask) == true)
                        f[u][mask] = min(f[u][mask], f[v][mask^(1<<u)]+c[v][u]);
    int ans = inf;
    for (int u = 0 ; u < n ; u++) ans = min(ans,f[u][(1<<n)-1]);
    cout << ans;
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n;
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < n ; j++) cin >> c[i][j];
    }
    dp_bitmask();
}