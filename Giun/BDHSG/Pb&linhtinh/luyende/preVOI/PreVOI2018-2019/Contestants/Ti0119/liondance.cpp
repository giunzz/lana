#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> ii;

const int mod = 1e9 + 7;
//Ti0119
const int N = 4005;

int n, d, a[N], b[N], lis[N][N];

pair<ii, int> trace[N][N];

int lmao[105][105][205];
pair<ii, int> tr[105][105][205];

map<int, int> mymap, used;

vector<int> vec;

int main() {
    freopen("liondance.inp", "r", stdin);
    freopen("liondance.out", "w", stdout);
    scanf("%d%d", &n, &d);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        vec.pb(a[i]);
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        vec.pb(b[i]);
    }
    if(n > 100) {
        for(int i = n; i >= 1; i--) {
            for(int j = n; j >= 1; j--) {
                if(lis[i + 1][j] > lis[i][j]) {
                    lis[i][j] = lis[i + 1][j];
                    trace[i][j] = {{i + 1, j}, trace[i + 1][j].se};
                }
                else if(lis[i + 1][j] == lis[i][j]) {
                    if(trace[i][j].se < trace[i + 1][j].se)
                        trace[i][j] = {{i + 1, j}, trace[i + 1][j].se};
                }
                if(lis[i][j + 1] > lis[i][j]) {
                    lis[i][j] = lis[i][j + 1];
                    trace[i][j] = {{i, j + 1}, trace[i][j + 1].se};
                }
                else if(lis[i][j + 1] == lis[i][j]) {
                    if(trace[i][j].se < trace[i][j + 1].se)
                        trace[i][j] = {{i, j + 1}, trace[i][j + 1].se};
                }
                if(a[i] == b[j] && lis[i + 1][j + 1] + 1 > lis[i][j]) {
                    lis[i][j] = lis[i + 1][j + 1] + 1;
                    trace[i][j] = {{i + 1, j + 1}, a[i]};
                }
                else if(a[i] == b[j] && lis[i + 1][j + 1] + 1 >= lis[i][j]) {
                    if(trace[i][j].se < trace[i + 1][j + 1].se)
                        trace[i][j] = {{i + 1, j + 1}, a[i]};
                }
            }
        }
        printf("%d\n", lis[1][1]);
        int id1 = 1, id2 = 1;
        while(id1 != n || id2 != n) {
            pair<ii, int> frt = trace[id1][id2];
            if(frt.fi.fi - id1 + frt.fi.se - id2 > 1)
                printf("%d ", frt.se);
            id1 = frt.fi.fi;
            id2 = frt.fi.se;
        }
    }
    else {
        int cnt = 1;
        sort(vec.begin(), vec.end());
        mymap[vec[0]] = cnt;
        used[cnt] = vec[0];
        for(int i = 1; i < vec.size(); i++) {
            if(vec[i] == vec[i - 1]) continue;
            mymap[vec[i]] = ++cnt;
            used[cnt] = vec[i];
        }
        for(int i = n; i >= 1; i--) {
            for(int j = n; j >= 1; j--) {
                for(int k = cnt; k >= 0; k--) {
                    if(lmao[i + 1][j][k] > lmao[i][j][k]) {
                        lmao[i][j][k] = lmao[i + 1][j][k];
                        tr[i][j][k] = {{i + 1, j}, k};
                    }
                    if(lmao[i][j + 1][k] > lmao[i][j][k]) {
                        lmao[i][j][k] = lmao[i][j + 1][k];
                        tr[i][j][k] = {{i, j + 1}, k};
                    }
                    if(a[i] == b[j] && mymap[a[i]] == k) {
                        for(int l = 0; l <= cnt; l++) {
                            int khung = used[l];
                            if(abs(khung - a[i]) <= d) {
                                if(lmao[i + 1][j + 1][l] + 1 > lmao[i][j][k]) {
                                    lmao[i][j][k] = lmao[i + 1][j + 1][l] + 1;
                                    tr[i][j][k] = {{i + 1, j + 1}, l};
                                }
                                else if(lmao[i + 1][j + 1][l] + 1 == lmao[i][j][k]) {
                                    if(tr[i][j][k].se < l)
                                        tr[i][j][k] = {{i + 1, j + 1}, l};
                                }
                            }
                        }
                    }
                }
            }
        }
        int mx = 0, id3;
        for(int i = 0; i <= cnt; i++) {
            if(lmao[1][1][i] >= mx) {
                mx = lmao[1][1][i];
                id3 = i;
            }
        }
        printf("%d\n", mx);
        int id1 = 1, id2 = 1;
        while(id1 < n + 1 && id2 < n + 1) {
            pair<ii, int> frt = tr[id1][id2][id3];
            if(frt.fi.fi == 0) break;
            if(frt.fi.fi - id1 + frt.fi.se - id2 > 1)
                printf("%d ", used[id3]);
            id1 = frt.fi.fi;
            id2 = frt.fi.se;
            id3 = frt.se;
        }
    }
}

