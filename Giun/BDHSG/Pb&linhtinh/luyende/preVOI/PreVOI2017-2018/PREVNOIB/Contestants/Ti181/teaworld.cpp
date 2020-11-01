#include<bits/stdc++.h>

using namespace std;

const int maxm = 2010;
const int maxn = 17;
const double ms = 1e-13;

struct sphere{
    int x, y, z, r, e;
};

int m, n, k;
int xs, ys, zs;
sphere q[maxm], a[maxn];
vector<int> block[maxn];
bool del[maxm];

double dist(sphere a, sphere b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}

double getmindist(int i, int j){
    sphere s = {xs, ys, zs, 0, 0};
    double sa = dist(s, a[i]), sb = dist(s, q[j]), sc = dist(a[i], q[j]);
    double re = min(sb, sc);
    double area = sqrt((sa + sb + sc) * (sa + sb - sc)) * sqrt((sa - sb + sc) * (-sa + sb + sc)) / 4;
    if (sa * sa + sb * sb > sc * sc && sa * sa + sc * sc > sb * sb) re = min(re,  2 * area / sa);
    return re;
}

double getmaxdist(int i, int j){
    sphere s = {xs, ys, zs, 0, 0};
    double sb = dist(s, q[j]), sc = dist(a[i], q[j]);
    return max(sb, sc);
}

int main(){
    freopen("teaworld.inp", "r", stdin);
    freopen("teaworld.out", "w", stdout);

    scanf("%d %d %d", &m, &n, &k);
    for (int i = 1; i <= m; i++){
        int x, y, z, r;
        scanf("%d %d %d %d", &x, &y, &z, &r);
        q[i] = {x, y, z, r, 0};
    }
    for (int i = 1; i <= n; i++){
        int x, y, z, e;
        scanf("%d %d %d %d", &x, &y, &z, &e);
        a[i] = {x, y, z, 0, e};
    }
    scanf("%d %d %d", &xs, &ys, &zs);

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++)
            if (getmindist(i, j) <= (double) q[j].r + ms && !(getmaxdist(i, j) <= (double) q[j].r + ms))
                block[i].push_back(j);
    }

    int ans = 0;

    for (int i = 0; i < (1 << n); i++){
        int cnt = k, tg = i, val = 0;
        for (int j = 1; j <= m; j++) del[j] = false;
        for (int j = 1; j <= n; j++){
            if (tg % 2 == 1){
                for (int t = 0; t < block[j].size(); t++)
                    if (!del[block[j][t]]){
                        del[block[j][t]] = true;
                        cnt--;
                    }
                val += a[j].e;
            }
            tg /= 2;
        }
        if (cnt >= 0) ans = max(ans, val);
    }

    printf("%d", ans);

    return 0;
}
