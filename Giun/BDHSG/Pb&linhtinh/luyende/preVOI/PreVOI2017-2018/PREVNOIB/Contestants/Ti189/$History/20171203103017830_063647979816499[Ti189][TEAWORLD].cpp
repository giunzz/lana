#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a); i <= (b); i ++)
#define FORd(i, a, b) for(int i = (a); i >= (b); i --)
#define FORv(i, a, b) for(int i = (a); i < (b); i ++)
#define II pair<int, int>
#define x first
#define y second
#define pb push_back
#define mp make_pair
using namespace std;
ll m, n, k, res, dd[2005];
struct data{
    ll x, y, z, r, e;
} cau[2005], ch[20], gs;
int main()
{
    freopen("TEAWORLD.inp", "r", stdin);
    freopen("TEAWORLD.out", "w", stdout);
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n >> k;
    for(int i = 1; i <= m; i ++) cin >> cau[i].x >> cau[i].y >> cau[i].z >> cau[i].r;
    for(int i = 0; i <= n - 1; i ++){
        cin >> ch[i].x >> ch[i].y >> ch[i].z >> ch[i].e;
        res += ch[i].e;
    }
    cin >> gs.x >> gs.y >> gs.z;
    cout << res;
    return 0;
}
