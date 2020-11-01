#include <bits/stdc++.h>

using namespace std;

const int N = 1e4;
int n,m,k,mem[20], vt[N];
long double xx,yy,zz;
bool kt[N];

struct data {
    long double  x,y,z,val,r;
}a[N],b[N];

void load() {
    freopen("teaworld.inp","r",stdin);
    freopen("teaworld.out","w",stdout);
}


void sub_1() {

    int ans = 0;

    for (int i = 1 ; i <= m ; ++ i)
        if (abs(xx - a[i].x) <= a[i].r)
                   vt[0] = i;
    a[0].x = xx;


    for (int i = 1 ; i <= n ; ++ i)
        for (int j = 1 ; j <= m ; ++ j)
            if (abs(a[j].x - b[i].x) <= a[j].r)
                vt[i] = j;

    for (int i = 0 ; i < (1 << n) ; ++ i) {

        int cnt = 0, l = 0, r  = 0, res = 0;
        for (int j = 1 ; j <= m ; ++ j)
            kt[j] = 0;

        for (int j = 0 ; j < n ; ++ j)
            if (i & (1 << j)) {

                if (b[j + 1].x > b[r].x)
                    r = j + 1;
                if (b[j+1].x < b[l].x)
                    l = j + 1;
                res += b[j+1].val;

            }

        if (k == 0 && vt[l] == vt[r]) {ans = max(ans,res);continue;};

        for (int j = 1 ; j <= m ; ++ j) {
            if (a[j].x >= b[l].x - a[j].r && a[j].x <= b[r].x + a[j].r)
                kt[j] = 1;


        }

        int sl = 0;
        for (int j = 1 ; j <= m ; ++ j)
            if (kt[j]) ++ sl;

        if (sl > k)
            continue;


        ans = max(ans,res);
    }

    cout << ans << endl;
    return ;
}


void process() {

    bool ok = 0, ok1 = 0;

    cin >> m >> n >> k;

    for (int i = 1 ; i <= m ; ++ i) {
        cin >> a[i].x >> a[i].y >> a[i].z >> a[i].r;

        if (a[i].y != 0 || a[i].z != 0) ok = 1;
        if (a[i].z != 0)
            ok1 = 1;

    }

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> b[i].x >> b[i].y >> b[i].z >> b[i].val;

        if (b[i].y != 0 || b[i].z != 0) ok =1;
        if (b[i].z != 0) ok1 =1;
    }

    cin >> xx >> yy >> zz;
    if (yy != 0 || zz != 0)
        ok = 1;
    if (zz != 0)
        ok1 = 1;


        sub_1();

}

int main() {
    load();
    process();
    return 0;
}
