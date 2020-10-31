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
ll sqr(ll a)
{
    return a * a;
}
bool cat(data cau, data ch)
{
    int l = cau.x - cau.r, r = cau.x + cau.r;
    if(l > max(ch.x, gs.x)) return 0;
    if(r < min(ch.x, gs.x)) return 0;
    if(l <= ch.x && ch.x <= r && l <= gs.x && gs.x <= r) return 0;
    return 1;
}
int main()
{
    freopen("TEAWORLD.inp", "r", stdin);
    freopen("TEAWORLD.out", "w", stdout);
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n >> k;
    for(int i = 1; i <= m; i ++) cin >> cau[i].x >> cau[i].y >> cau[i].z >> cau[i].r;
    for(int i = 0; i <= n - 1; i ++) cin >> ch[i].x >> ch[i].y >> ch[i].z >> ch[i].e;
    cin >> gs.x >> gs.y >> gs.z;
    int maxst = (1 << n) - 1;
    for(int st = 0; st <= maxst; st ++){
        ll temp = 0;
        for(int i = 0; i <= n - 1; i ++){
            if((st >> i) & 1){
                for(int j = 1; j <= m; j ++){
                    if(cat(cau[j], ch[i])) dd[j] = 1;
                }
                temp += ch[i].e;
            }
        }
        int cnt = 0;
        for(int i = 1; i <= m ; i ++){
            cnt += dd[i];
            dd[i] = 0;
        }
        if(cnt <= k) res = max(res, temp);
    }
    cout << res;
    return 0;
}
