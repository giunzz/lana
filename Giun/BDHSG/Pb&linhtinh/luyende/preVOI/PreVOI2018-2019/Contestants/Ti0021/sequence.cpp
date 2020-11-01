using namespace std;
#include <bits/stdc++.h>

typedef long long ll;
typedef pair<int, int> cp;

#define forinc(i, a, b) for (int i = a; i <= b; i++)
#define fordec(i, a, b) for (int i = a; i >= b; i--)
#define fi first
#define se second
#define mp make_pair
#define LanHT "sequence"

const int maxn = 3123, base = 1e9 + 7;
int m, n, k, t[3][maxn], d = 1e9, c = 0;
cp a[3][maxn];

void Input(){
    cin >> m >> n >> k;
    forinc(i, 1, m) {
        cin >> a[1][i].fi; a[1][i].se = i;
            d = min(d, a[1][i].fi);
        c = max(c, a[1][i].fi);
    }
    forinc(i, 1, n) {
        cin >> a[2][i].fi; a[2][i].se = i;
                    d = min(d, a[2][i].fi);
        c = max(c, a[2][i].fi);
        }
    sort(a[1] + 1, a[1] + m + 1);
    sort(a[2] + 1, a[2] + n + 1);
}

vector<int> ans;
void Solve(){

    int x = 1, y = 1;
    int vt1 = 0, vt2 = 0;
    //priority_queue<cp, greater<cp>() > q;
    forinc(aa, d, c){
        while (a[1][x].se < vt1 || a[1][x].fi < aa) ++x;
        while (a[2][y].se < vt2 || a[2][y].fi < aa) ++y;
        if (a[1][x].fi == aa){
            while (a[1][x].fi == aa){
                int tg = m - a[1][x].se;
                int tg1 = n - vt2;
                if (tg + ans.size() + tg1 + 1>= k) {
                        ans.push_back(a[1][x].fi);
                }
                else break;
                vt1 = max(vt1, a[1][x].se);
                if (ans.size() == k) break;
                ++x;
            }
        }
        if (a[2][y].fi == aa){
            while (a[2][y].fi == aa){
                int tg = n - a[2][y].se;
                int tg1= m - vt1;
                if (tg + ans.size() + tg1 + 1>= k) {
                        ans.push_back(a[2][y].fi);
                }
                else break;
                vt2 = max(vt2, a[2][y].se);
                if (ans.size() == k) break;
                ++y;
            }
        }
        if (ans.size() == k) break;
    }
    for (int v : ans) cout << v << " ";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(LanHT".inp", "r", stdin);
    freopen(LanHT".out", "w", stdout);
    Input();
    Solve();
}
