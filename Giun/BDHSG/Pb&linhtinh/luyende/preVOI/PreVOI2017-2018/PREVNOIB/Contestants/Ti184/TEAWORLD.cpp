#include<bits/stdc++.h>
const int N = 65536 + 5;
const int inf = 1e9;
const double EPS = 1e-9;
using namespace std;

ifstream fi ("TEAWORLD.inp");
ofstream fo ("TEAWORLD.out");

struct bit{
    int a[64];
} f[N];

struct circle{
    double x, y, z, r;
} ci[2005], ts[20], cur;

void init(bit& a){
    for (int i = 0; i < 64; i++) a.a[i] = 0;
}

bit OR(bit x, bit y){
    bit ans;
    for (int i = 0; i < 64; i++) ans.a[i] = (x.a[i] | y.a[i]);
    return ans;
}

void on(bit& x, int num){
    int pos = num / 31; num %= 31;
    x.a[pos] |= (1 << num);
}

int Count(bit x){
    int ans = 0;
    for (int i = 0; i < 64; i++) {
        ans += __builtin_popcountll(x.a[i]);
    }
    return ans;
}

int n, m, k, ans, g[N];

circle cal(circle a, circle b, double x, double y){
    circle ans;
    ans.x = (a.x * x + b.x * y) / (x + y);
    ans.y = (a.y * x + b.y * y) / (x + y);
    ans.z = (a.z * x + b.z * y) / (x + y);
    return ans;
}

double distance (circle a, circle b){
    return sqrtl((a.x - b.x)*(a.x - b.x)+(a.y - b.y)*(a.y - b.y)+(a.z - b.z)*(a.z - b.z));
}

bool check(circle ts, circle ci){
    double l = 0, r = 1000;
    if (distance(ci, ts) <= ci.r + EPS && distance(ci, cur) <= ci.r + EPS) return false;
    for (int i = 0; i < 100; i++){
        double mid1 = (l*2 + r)/3, mid2 = (l + r*2)/3;
        if (distance(ci, cal(ts, cur, mid1, 1000 - mid1)) > distance(ci, cal(ts, cur, mid2, 1000 - mid2))) l = mid1;
        else r = mid2;
    }
    if (distance(ci, cal(ts, cur, l, 1000-l)) <= ci.r + EPS) {
        return true;
    }
    else return false;
}

int main(){
    fi >> n >> m >> k;
    for (int i = 0; i < n; i++) fi >> ci[i].x >> ci[i].y >> ci[i].z >> ci[i].r;
    for (int i = 0; i < m; i++) fi >> ts[i].x >> ts[i].y >> ts[i].z >> ts[i].r;
    fi >> cur.x >> cur.y >> cur.z;
    for (int i = 0; i < (1 << m); i++) init(f[i]);
    for (int i = 0; i < m; i++){
        int pos = (1 << i); g[pos] = ts[i].r;
        for (int j = 0; j < n; j++){
            if (check(ts[i], ci[j])) {
                on(f[pos], j);
            }
        }
    }
    for (int i = 1; i < (1 << m); i++){
        if ((i&(i-1)) == 0) continue;
        f[i] = OR(f[i-(i&(-i))], f[(i&(-i))]);
        g[i] = g[i-(i&(-i))] + g[(i&(-i))];
    }
    for (int i = 0; i < (1 << m); i++){
        if (Count(f[i]) <= k) ans = max(ans, g[i]);
    }
    fo << ans;
}
/*
1 2 0
0 0 0 1
-1 0 0 5
2 0 0 100
1 0 0
*/
