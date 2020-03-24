#include <bits/stdc++.h>
using namespace std;
//const string task = "input";
const int N = 1e4 + 10;
const int inf = 1e9 + 7;
//#define FileOpen freopen ((task + ".inp").c_str(), "r", stdin);	freopen (("output" + ".out").c_str(), "w", stdout);
#define fi first
#define se second
#define dd pair < double, double >
#define segment pair < dd, dd >
int n;
vector < dd > point;
segment a;
double sqr(double x) {
    return (x * x);
}
double DistanceOf2Points(dd a, dd b) {
    return (sqrt(sqr(a.fi - b.fi) + sqr(a.se - b.se)));
}
segment FindLongestSegment() {
    double res = -inf * 1.0;
    segment ans;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            double tmp = DistanceOf2Points(point[i], point[j]);
            if (tmp > res) {
                res = tmp;
                ans = segment(point[i], point[j]);
            }
        }
    }
    return (ans);
}
main() {
    freopen("input.inp", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> point[i].fi >> point[i].se;
    }
    a = FindLongestSegment();
}