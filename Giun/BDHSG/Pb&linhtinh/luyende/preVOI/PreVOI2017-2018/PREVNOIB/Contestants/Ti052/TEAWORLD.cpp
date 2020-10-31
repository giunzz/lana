#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct pp
{
    int x, y, z, gt;
};
const int N = 2e3 + 7;
int n, m, tmp, res, i, j, t, k;
pp st[N], c[N], bd;
bool checky = true, checkz = true, check[N];
vector<int> luu[N];

void Enter()
{
    cin >> m >> n >> k;
    for(int i = 1; i <= m ; i ++)
    {
        cin >> c[i].x >> c[i].y >> c[i].z >> c[i].gt;
        if(c[i].y != 0) checky = false;
        if(c[i].z != 0) checkz = false;
    }
    for(int i = 1; i <= n; i ++)
    {
        cin >> st[i].x >> st[i].y >> st[i].z >> st[i].gt;
        if(st[i].y != 0) checky = false;
        if(st[i].z != 0) checkz = false;
    }
    cin >> bd.x >> bd.y >> bd.z;
}
void sub1()
{
    t = 1 << n;
    for(int i = 0 ; i < t; i ++)
    {
        int sl = 0, nx = bd.x, lx = bd.x, sum = 0;
        for(int j = 0; j < n; j ++)
            if((i >> j) & 1) nx = min(nx, st[i].x), lx = max(lx, st[i].x), sum += st[i].gt;
        for(int j = 1; j <= m; j ++)
        {
            if(c[j].x >= nx && c[j].x <= lx) sl ++;
            else
                if(c[j].x < nx) sl += (c[j].x + c[j].gt >= nx);
                else sl += (c[j].x - c[j].gt <= lx);
            if(sl > k) goto stp;
        }
        res = max(res, sum);
        stp: ;
    }
    cout << res << "\n";
}
void sub2()
{
    for(int i = 1; i <= n; i ++)
    {
        if(bd.x == st[i].x && bd.y == st[i].y)
        {
            for(int j = 1; j <= m; j ++)
                if((c[j].x - bd.x)*(c[j].x - bd.x) + (c[j].y - bd.y)*(c[j].y - bd.y) == c[j].gt * c[j].gt) luu[i].push_back(j);
        }
        else
            if(bd.x == st[i].x)
        {
            double t1 = min(bd.y, st[i].y), t2 = max(bd.y, st[i].y), t3 = t1 - 1, t4 = t1 - 1;
            for(int j = 1; j <= m; j ++)
            {
                int kc = abs(c[j].x - bd.x);
                if(kc <= c[j].gt)
                {
                    t3 = sqrt(c[j].gt * c[j].gt - kc * kc);
                    t4 = c[j].y + t3; t3 = c[j].y - t3;
                }
                if(t3 >= t1 && t3 <= t2) {luu[i].push_back(j); continue;}
                if(t4 >= t1 && t4 <= t2) {luu[i].push_back(j); continue;}
            }
        }
        else
            if(bd.y == st[i].y)
        {
            double t1 = min(bd.y, st[i].y), t2 = max(bd.y, st[i].y), t3 = t1 - 1, t4 = t1 - 1;
            for(int j = 1; j <= m; j ++)
            {
                int kc = abs(c[j].y - bd.y);
                if(kc <= c[j].gt)
                {
                    t3 = sqrt(c[j].gt * c[j].gt - kc * kc);
                    t4 = c[j].y + t3; t3 = c[j].y - t3;
                }
                if(t3 >= t1 && t3 <= t2) {luu[i].push_back(j); continue;}
                if(t4 >= t1 && t4 <= t2) {luu[i].push_back(j); continue;}
            }
        }
        else
        {
            int lux = bd.x - st[i].x, luy = st[i].y - bd.y, gc = __gcd(lux, luy);
            int a = luy / gc, b = lux / gc, sc = -(a*bd.x + b*bd.y), ab = abs(a) + abs(b);
            for(int j = 1; j <= m; j ++)
                if((a*c[j].x + b*c[j].y + sc) / ab <= c[j].gt)
                    luu[i].push_back(j);
        }
    }
    t = 1 << n;
    for(int i = 0 ; i < t; i ++)
    {
        int sl = 0, sum = 0;
        memset(check, false, sizeof(check));
        for(int j = 0; j < n; j ++)
            if((i >> j) & 1)
            {
                sum += st[j + 1].gt;
                for(int v = 0; v < luu[j + 1].size(); v ++)
                if(!check[luu[j + 1][v]]) sl ++, check[luu[j + 1][v]] = true;
                if(sl > k) goto stp;
            }
        if(sl <= k) res = max(res, sum);
        stp: ;
    }
    cout << res << "\n";
}

int main()
{
//#define file "r"
#define file "TEAWORLD"
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    Enter();
//    Init();
//    sub1();
    if(checky && checkz) sub1();
    else sub2();
//    Solve();
    return 0;
}
