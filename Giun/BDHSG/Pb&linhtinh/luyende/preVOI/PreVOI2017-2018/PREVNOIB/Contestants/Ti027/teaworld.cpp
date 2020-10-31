#include <bits/stdc++.h>
#define maxn 2001

using namespace std;
int m, n, k, gsux, gsuy, gsuz;
struct yasuo{
    int x, y, z, r;
}qcau[maxn];

struct zed{
    int x, y, z, e;
}qtsua[maxn];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    freopen("teaworld.inp","r",stdin);
    freopen("teaworld.out","w",stdout);
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        qcau[i] = {a,b,c,d};
    }
    for (int i = 1; i <= n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        qtsua[i] = {a,b,c,d};
    }
    cin >> gsux >> gsuy >> gsuz;
    int dem = 0;
    for (int i = 1; i <= n; i++)
    {
        int thang = 0;
        int chuan = 0;
        for (int x = min(gsux, qtsua[i].x); x <= max(gsux, qtsua[i].x); x++)
        {
            int aa = (qtsua[i].y - gsuy) * (x - qtsua[i].x);
            int y = - aa / (gsux - qtsua[i].x) + qtsua[i].y;
            for (int j = 1; j <= m; j++)
            {
                if ((gsux - qcau[j].x) * (gsux - qcau[j].x) + (gsuy - qcau[j].y) * (gsuy - qcau[j].y) == qcau[j].r * qcau[j].r)
                    if (qtsua[i].x > qcau[i].x - qcau[i].r && qtsua[i].x < qcau[i].x + qcau[i].r) {dem += qtsua[i].e; chuan = 1;}
                if (chuan == 1) continue;
                int dcm = (x - qcau[j].x) * (x - qcau[j].x) + (y - qcau[j].y) * (y - qcau[j].y);
                if (dcm <= qcau[j].r * qcau[j].r) {thang++; break;}
            }
            if (thang == 1) break;
            if (chuan == 1) break;
        }
        if (thang == 0 && chuan == 0) dem += qtsua[i].e;
    }
    cout << dem;
}


/*12 5 4
0 10 0 1
1 5 0 2
1 4 0 2
0 0 0 2
10 0 0 1
3 -1 0 2
5 - 1 0 2
10 10 0 15
0 -10 0 1
10 -10 0 1
-10 -10 0 1
10 10 0 1
0 10 0 240
10 0 0 200
10 -2 0 52
-10 0 0 100
1 1 0 2
0 0 0*/
