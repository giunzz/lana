#include <bits/stdc++.h>

using namespace std;
const int maxr = 1e4 + 5, maxc = 1e5 + 5;
int n, m, r[maxr], sp[105], a[maxr], f[maxr];
string cs;

void enter(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> r[i];
    cin.ignore();
    getline(cin, cs);
    cs = "0" + cs + "0";
    cs = cs + string(100, '1');
}

void spe(){
    memset(sp, 0, sizeof(sp));
    int bdi, j;
    for (int i = 1; i <= n; i++){
        if (sp[r[i]] == 0){
            bdi = 1, j = r[i];
            while (j <= m){
                while (cs[j] == '1') {
                    --j;
                }
                j += r[i];
                ++bdi;
            }
            sp[r[i]] = bdi;
            a[i] = bdi;
        }
        else a[i] = sp[r[i]];
    }
}

int sol(){
    if (n == 1) return a[1];
    else if (n == 2) return a[2];
    else{
        f[1] = a[1], f[2] = a[2];
        for (int i = 3; i <= n; i++){
            f[i] = min(f[i - 2] + a[1] + a[i] + 2*a[2], f[i - 1] + a[1] + a[i]);
        }
        return f[n];
    }
}

void alltest(){
    enter();
    spe();
    sort(a + 1, a + n + 1);
    cout << sol() << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CROSS12.INP", "r", stdin);
    freopen("CROSS12.OUT", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) alltest();
    return 0;
}
