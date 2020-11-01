#include <bits/stdc++.h>

using namespace std;

const int md = 3005;

int n, m, k, ra, rb;
long long a[md], b[md], ans[md], res[md], va[md], vb[md];;

int main() {
    srand(time(NULL));
    freopen("sequence.inp", "r", stdin);
    freopen("sequence.out", "w", stdout);
    clock_t times = clock();
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int j = 1; j <= m; j++)
        cin >> b[j];
    int zz = min(k + 1, n + 1);
    for(int i = 1; i <= k; i++)
        ans[i] = 1e15;
    while ((1.0 * clock() - times) / (CLOCKS_PER_SEC) < 0.6) {
        int nn = rand() % 1000000 % zz;
        int mm = k - nn;
        if (mm > m) continue;
        int ra = 0;
        long long preMin = 0;
        for(; nn > 0;) {
            long long Min = 1e15;
            for(int j = 1; j <= n; j++)
                if (a[j] > preMin)
                    Min = min(Min, a[j]);
            for(int j = n; j >= 1; j--) {
                if (nn == 0)
                    break;
                if (a[j] == Min)
                    va[++ra] = j, nn--;
            }
            preMin = Min;
        }
        sort(va + 1, va + 1 + ra);
        for(int i = 1; i <= ra; i++)
            va[i] = a[va[i]];
        int rb = 0;
        preMin = 0;
        for(; mm > 0;) {
            long long Min = 1e15;
            for(int j = 1; j <= m; j++)
                if (b[j] > preMin)
                    Min = min(Min, b[j]);
            for(int j = m; j >= 1; j--) {
                if (mm == 0)
                    break;
                if (b[j] == Min)
                    vb[++rb] = j, mm--;
            }
            preMin = Min;
        }
        sort(vb + 1, vb + 1 + rb);
        for(int i = 1; i <= rb; i++)
            vb[i] = b[vb[i]];
        /*if (ra == 5) {
            for(int j = 1; j <= rb; j++)
                cout << vb[j] << " ";
            return 0; 
        }*/
        int k1 = 1, k2 = 1;
        int r = 0;
        while (r < k) {
            if (k1 > ra) {
                for(int i = k2; i <= rb; i++)
                    res[++r] = vb[i];
            } else if (k2 > rb) {
                for(int i = k1; i <= ra; i++)
                    res[++r] = va[i];
            } else if (va[k1] < vb[k2])
                res[++r] = va[k1++];
            else if (vb[k2] < va[k1])
                res[++r] = vb[k2++];
            else {
                //ok = false;
                int pa = 0, pb = 0;
                for(pa = k1; pa <= ra; pa++)
                    if (va[pa] != va[k1])
                        break;
                for(pb = k2; pb <= rb; pb++)
                    if (vb[pb] != vb[k2])
                        break;
                if (va[pa] < va[k1] && pa <= ra)  {
                    for(int i = k1; i <= pa; i++)
                        res[++r] = va[k1++];
                } else if (vb[pb] < vb[k2] && pb <= rb) {
                    for(int i = k2; i <= pb; i++)
                        res[++r] = vb[k2++];
                } else {
                    res[++r] = va[k1++];
                    res[++r] = vb[k2++];
                }
            }
        }
        bool ok = true;
        for(int i = 1; i <= r; i++)
            if (res[i] > ans[i]) {
                ok = false;
                break;
            }
        if (ok) {
            for(int i = 1; i <= r; i++)
                ans[i] = res[i];
        }
    }   
    for(int i = 1; i <= k; i++)
        cout << ans[i] << " ";
    return 0;
}