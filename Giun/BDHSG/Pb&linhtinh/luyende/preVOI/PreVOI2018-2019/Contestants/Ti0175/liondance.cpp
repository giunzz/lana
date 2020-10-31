#include <bits/stdc++.h>

using namespace std;

const int md = 25;

int temp[md], ans[md], x[md], l[md], r[md];
int len, n, delta;

void backTrack(int i) {
    if (i > n) {
        int rr = 0;
        for(int j = 1; j <= n; j++) 
            if (x[j] == 1) 
               temp[++rr] = l[j];
        for(int j = 2; j <= rr; j++)
            if (abs(temp[j] - temp[j - 1]) > delta)
                return ;
        int k = 1;
        for(int j = 1; j <= n; j++)
            if (temp[k] == r[j])
                k++;
        if (k <= rr) return ;
        if (len < rr) {
            len = rr;
            for(int j = 1; j <= len; j++)
                ans[j] = temp[j];
        } else if (len == rr) {
            bool ok = true;
            for(int j = 1; j <= len; j++)
                if (ans[j] > temp[j]) {
                    ok = false;
                    break;
                } else if (ans[j] < temp[j]) 
                    break;
            if (ok)
                for(int j = 1; j <= len; j++)
                    ans[j] = temp[j];
        }
    } else {
        for(int j = 0; j <= 1; j++) {
            x[i] = j;
            backTrack(i + 1);
        }
    }
}

int main() {
    freopen("liondance.inp", "r", stdin);
    freopen("liondance.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n  >> delta;
    for(int i = 1; i <= n; i++)
        cin >> l[i];
    for(int i = 1; i <= n; i++)
        cin >> r[i];
    backTrack(1);
    cout << len << '\n';
    for(int i = 1; i <= len; i++)
        cout << ans[i] << " ";
    return 0;
}