#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 9;

int z[4], a[4], x[20], cnt, n, m;
//bool vis[(1 << 20)];
bool vis[20];

void backTrack(int i) {
    if (i > n) {
        z[0] = a[0]; z[1] = a[1]; z[2] = a[2];
        bool ok = true;
        /*for(int j = 1; j <= n; j++)
            cout << x[j] <<" ";
        cout << endl;
        cout << z[0] <<" " << z[1] <<" " << z[2] << endl;*/
        for(int j = 1; j <= n; j++) {
            if (x[j] == 0) {
                z[0]++;
            } else if (x[j] == 1) {
                if (z[0] == 0) {
                    ok = false;
                    break;
                }
                z[1]++; z[0]--;
            } else {
                if (z[1] > 0 && z[0] > 0) {
                    z[1]--; z[0]--; z[2]++;
                    //x[j] = 1;
                } else if (z[0] > 2) {
                    z[0] -= 3;
                    z[2]++;
                } else {
                    ok = false;
                    break;
                }
            }
            if (z[0] > m || z[1] > m || z[2] > m) {
                    ok = false;
                    break;
                }
        //    cout << z[0] <<" " << z[1] <<" " << z[2] <<"*\n";
        }
        //cout  << ok << endl;
        if (!ok) return ;
        //int res = 0;
        //cout << "*\n";
        cnt++;
    } else {
        for(int j = 0; j <= 2; j++) {
                x[i] = j;
                //vis[i] = true;
                backTrack(i + 1);
                //vis[j] = false;
                //x[i] = 0;
                //vis[i] = false;
            }
    }
}

int main() {
    freopen("icecream.inp", "r", stdin);
    freopen("icecream.out", "w", stdout);
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i <= 2; i++) 
        cin >> a[i];
    backTrack(1);
    cout << cnt;
}