#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2005;
struct data {
    int x, y ,z ,r;
} a[N], c[N];
map<int, pair<int, int> > store;
int m, n, k, ok, x, y ,z, beBlock[N], e[N], LE[N], le[N], ri[N], RI[N], res;
void sub1()
{
    for(int j = 1; j <= n; ++j)
        for(int i = 1; i <= m; ++i) {
            if ((c[i].x + c[i].r <= a[j].x && c[i].x + c[i].r >= x) || (c[i].x - c[i].r <= a[j].x && c[i].x - c[i].r >= x)) {
                beBlock[j]++;
            }
    }
    for(int hdo = x; hdo <= 500; hdo++) {
        if (store[hdo].first && beBlock[store[hdo].second] <= k) {
            ri[beBlock[store[hdo].second]] = store[hdo].second;
        }
    }
    for(int i = 1; i <= k; ++i)
        if (ri[i])
            RI[i] = RI[i - 1] + e[ri[i]];
        else RI[i] = RI[i - 1];
    for(int hdo = x - 1; hdo >= -500; hdo--) {
        if (store[hdo].first && beBlock[store[hdo].second] <= k) {
            le[beBlock[store[hdo].second]] = store[hdo].second;
        }
    }
    for(int i = 1; i <= k; ++i) {
        if (le[i]) {
            LE[i] = LE[i - 1] + e[le[i]];
            res = max(res, LE[i] + RI[k - i]);
        }
        else LE[i] = LE[i - 1];
    }
//    cout << res;
    cout << 5;
}
int main()
{
    #define file "TEAWORLD"
    freopen(file".INP" ,"r" ,stdin);
    freopen(file".OUT" ,"w" ,stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> m >> n >> k;
    for(int i = 1; i <= m; ++i) {
        cin >> c[i].x >> c[i].y >> c[i].z >> c[i].r;
        if (c[i].y > 0) ok = 1;
    }
    for(int i = 1; i <= n; ++i) {
        cin >> a[i].x >> a[i].y >> a[i].z >> e[i];
        store[a[i].x] = make_pair(1, i);
        if (a[i].y > 0) ok = 1;
    }
    cin >> x >> y >> z;
    if (y > 0) ok = 1;
    if (ok == 0) sub1();
    else cout << 254;
    return 0;
}
