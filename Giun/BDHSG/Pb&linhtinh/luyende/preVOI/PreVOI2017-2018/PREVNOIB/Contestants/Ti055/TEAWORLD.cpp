#include<bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;
int n, m, k, GSx, GSy, GSz, GS;
long long res;
vector<int> need[100];
ii point[100], p[5000];
bool kt[5000];

int main()
{
    freopen("TEAWORLD.INP", "r", stdin);
    freopen("TEAWORLD.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n >> k;
    int d = 0;
    for (int i = 1; i <= m; i++)
    {
        int x, y, z, r;
        cin >> x >> y >> z >> r;
        x += 1000;
        p[i] = ii(x, r);
    }
    for (int i = 1; i <= n; i++)
    {
        int x, y, z, e;
        cin >> x >> y >> z >> e;
        x += 1000;
        point[i] = ii(x, e);
    }
    cin >> GSx >> GSy >> GSz;
    GS = GSx + 1000;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int l = p[j].f - p[j].s;
            int r = p[j].f + p[j].s;
            //if (i == 2) cout << point[i].f << " " << l << " "<< r << endl;
            if (point[i].f <= GS)
            {
                if (r < point[i].f || l > GS)   continue;
                if (l < point[i].f && r > GS)   continue;
                need[i].push_back(j);
            }
            if (point[i].f > GS)
            {
                if (r < GS || l > point[i].f)   continue;
                if (l < GS && r > point[i].f)   continue;
           //     if (i == 2) cout << j << " ";
                need[i].push_back(j);
            }
        }
    }
    for (int i = 0; i < (1 << n); i++)
    {
        long long sum = 0;
        for (int j = 1; j <= m; j++)    kt[j] = false;
        for (int j = 1; j <= n; j++)
        {
            int t = (1 << (j - 1));
            if ((i & t) != 0)
            {
                sum += point[j].s;
                for (int k = 0; k < need[j].size(); k++)
                    kt[need[j][k]] = true;
            }
        }
        int d = 0;
        for (int j = 1; j <= m; j++)    if (kt[j] == true)  d++;
        if (d <= k) res = max(res, sum);
    }
    cout << res;
    return 0;
}
