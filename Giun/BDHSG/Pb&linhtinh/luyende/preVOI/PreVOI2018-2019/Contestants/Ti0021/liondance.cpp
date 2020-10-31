using namespace std;
#include <bits/stdc++.h>

typedef long long ll;
typedef pair<int, int> cp;

#define forinc(i, a, b) for (int i = a; i <= b; i++)
#define fordec(i, a, b) for (int i = a; i >= b; i--)
#define fi first
#define se second
#define mp make_pair
#define LanHT "liondance"

const int maxn = 4006, base = 1e9 + 7;
int n, w;
int l[maxn], r[maxn], f[maxn][maxn];
cp tr[maxn][maxn];
int luu[maxn];

void Input(){
    cin >> n >> w;
    forinc(i, 1, n) cin >> l[i];
    forinc(i, 1, n) cin >> r[i];
}

void Solve(){
    forinc(i, 1, n + 1)
        forinc(j, 1, n + 1) if (l[i] == r[j])
            fordec(u, i - 1, 0)
                fordec(v, j - 1, 0) if (l[u] == r[v] && (abs(l[u] - l[i]) <= w || (i == n + 1 && j == n + 1) || (!u && !v))){
                    if (f[i][j] < f[u][v] + 1) {
                            f[i][j] = f[u][v] + 1;
                            tr[i][j] = mp(u, v);
                    } else if (f[i][j] == f[u][v] + 1 && l[tr[i][j].fi] < l[u]){
                            tr[i][j] = mp(u, v);
                    }
                }
    cout << f[n + 1][n + 1] - 1 << '\n';
    int u = n + 1, v = n + 1, sl = 0;
    while (u != 0){
        luu[++sl] = l[u];
        int x = u, y = v;
        u = tr[x][y].fi;
        v = tr[x][y].se;
    }
    fordec(i, sl, 2) cout << luu[i] << " ";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(LanHT".inp", "r", stdin);
    freopen(LanHT".out", "w", stdout);
    Input();
    Solve();
    //if (n <= 100) Solve(); else Tham();
}
