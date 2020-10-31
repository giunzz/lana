#include<bits/stdc++.h>
using namespace std;

struct COOR {
    int X, Y, Z, val;
    COOR() {}; COOR(int X, int Y, int Z, int val) : X(X), Y(Y), Z(Z), val(val) {};
};

typedef long long LL;

const int N = 2004;
int m, n, k;
COOR cir[N], a[N], st;

struct LINE {
    int A, B, C;
    LINE() {}; LINE(int A, int B, int C) : A(A), B(B), C(C) {};
};

LINE create(COOR a, COOR b) {
    LINE denta;
    denta.A = a.Y - b.Y;
    denta.B = b.X - a.X;
    denta.C = -(denta.A*a.X + denta.B * a.Y);

        //cerr << a.X << " " << a.Y << " " << b.X << " " << b.Y << '\n';
    //denta.C = a.X * b.Y - a.Y - b.X;

        //cerr << a.X << " " << a.Y << " " << b.X << " " << b.Y << '\n';
        //swap(denta.A, denta.B);

    //if (denta.A == 0 && denta.C == 0) denta.B = 1;
    //if (denta.B == 0 && denta.C == 0) denta.A = 1;

    return denta;
}

bool Inside(COOR point, COOR cirl) {
    LL dis = 1LL * (cirl.X - point.X) * (cirl.X - point.X) + (cirl.Y - point.Y) * (cirl.Y - point.Y);
    if (dis <= 1LL * cirl.val * cirl.val) return true;
    return false;
}

bool check(int id, LINE denta) {
    LL dis = 1LL * abs(denta.A * cir[id].X + denta.B * cir[id].Y + denta.C);
    dis = dis * dis;

        if (dis == 0) {
            if (!Inside(st, cir[id]) || !Inside(st, cir[id]))
            return false;
        }

        //cerr << denta.A << " " << denta.B << " " << denta.C << '\n';

    if (dis <= 1LL * ( (denta.A * denta.A) + (denta.B * denta.B) ) * cir[id].val) return true;
    return false;
}

int cc[N]; bool kt[N];
bool BIT(int n, int k) { return n & (1<<k); }

void sol() {
    int res = 0;

    for (int id = 1; id <= m; ++id) {
        for (int i = 1; i <= n; ++i) {
            if (!check(id, create(a[i], st))) {
                //cerr << i << '\n';
                cc[id] += (1<<(i-1));
            }
            else {
                if (Inside(a[i], cir[id]) && Inside(st, cir[id])) cc[id] += (1<<(i-1));
            }
        }
    }

    for (int mask = 0; mask < (1<<n); ++mask) {
        for (int i = 0; i < n; ++i) kt[i] = BIT(mask, i);

        int dem = 0;
        for (int id = 1; id <= m; ++id) {
            for (int i = 0; i < n; ++i) if (!BIT(cc[id], i) && kt[i]) {
                //if (mask == 22) cerr << id << " " << i+1 << '\n';
                dem++;
                break;
            }
        }


        if (dem > k) continue;
        int tmp = 0;
        for (int i = 0; i < n; ++i) if (kt[i]) tmp += a[i+1].val;
        res = max(res, tmp);
    }

    //cerr << Inside(a[5], cir[11]);
    //cerr << cc[11] - (1<<n) + 1;
    //cerr <<  a[1].X << " " << a[1].Y;
    //cerr << check(11, create(st, a[5]));

    cout << res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("TEAWORLD.inp", "r", stdin);
    freopen("TEAWORLD.out", "w", stdout);

    cin >> m >> n >> k;
    for (int i = 1; i <= m; ++i) cin >> cir[i].X >> cir[i].Y >> cir[i].Z >> cir[i].val;

    for (int i = 1; i <= n; ++i) cin >> a[i].X >> a[i].Y >> a[i].Z >> a[i].val;

    cin >> st.X >> st.Y >> st.Z;

    sol();

    return 0;
}
