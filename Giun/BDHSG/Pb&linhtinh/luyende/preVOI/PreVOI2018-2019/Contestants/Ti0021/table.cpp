using namespace std;
#include <bits/stdc++.h>

typedef long long ll;
typedef pair<int, int> cp;

#define forinc(i, a, b) for (int i = a; i <= b; i++)
#define fordec(i, a, b) for (int i = a; i >= b; i--)
#define fi first
#define se second
#define mp make_pair
#define LanHT "table"

const int maxn = 305, base = 1e9 + 7;
int m, n, k, a[maxn][maxn];
ll l[maxn][maxn], b[maxn][maxn];
cp tr[maxn][maxn];

void Input(){
    scanf("%d%d%d", &m, &n, &k);
    forinc(i, 1, m)
        forinc(j, 1, n) scanf("%d",&a[i][j]);
}
cp q[1000];
void Solve(){
    while (k--){
        int u,v,x,y;
        scanf("%d%d%d%d", &u, &v, &x, &y);
        memset(l, -0x3f, sizeof(l));
        l[u - 1][v] = l[u][v - 1] = 0;
        forinc(i, u, x)
            forinc(j, v, y){
                l[i][j] = max(l[i - 1][j], l[i][j - 1]) + a[i][j];
                if (l[i - 1][j] < l[i][j - 1]){
                    tr[i][j] = mp(i, j - 1);
                } else tr[i][j] = mp(i - 1, j);
            }
        tr[u][v] = mp(-1, -1);
        int sl = 0;
        ll res = l[x][y];
        int x2 = x, y2 = y;
        while (x2 != -1){
            q[++sl] = mp(x2, y2);
            int x1 = x2, y1 = y2;
            x2 = tr[x1][y1].fi;
            y2 = tr[x1][y1].se;
        }
        forinc(aa, 2, sl - 1){
            int u = q[aa].fi, v = q[aa].se;
            int tg = a[u][v];
            a[u][v] = -1e9;
            forinc(i, u, m) b[i][v - 1] = l[i][v - 1];
            forinc(i, v, n) b[u - 1][i] = l[u - 1][i];
            forinc(i, u, x)
                forinc(j, v, y){
                    ll tg = -1e14;
                    if (i - 1 >= u) tg = b[i - 1][j];
                    if (j - 1 >= v) tg = max(tg, b[i][j - 1]);
                    b[i][j] = max(b[i][j - 1], b[i - 1][j]) + a[i][j];
                }
            a[u][v] = tg;
            res = min(res, b[x][y]);
        }
        cout << res << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(LanHT".inp", "r", stdin);
    freopen(LanHT".out", "w", stdout);
    Input();
    Solve();
}
