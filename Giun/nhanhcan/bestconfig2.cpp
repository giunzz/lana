#include <bits/stdc++.h>

using namespace std;
const int maxn = 23, maxc = 100 * (20 + (20 - 3) * 20);
int c[maxn][maxn], n, cost = 0, best = maxc + 1, wa[maxn], bwa[maxn];
bool d[maxn];

void inp(){
    int q, p, k, m;
    cin >> n >> m;
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= m; i++){
        cin >> q >> p >> k;
        c[q][p] = k, c[p][q] = k;
    }
    wa[0] = 1;
}

void updwa(){
    for (int i = 0; i <= n; i++) bwa[i] = wa[i];
}

void sol(int i){
    int j = 2;
    while (j <= n && i != n){
        if (d[j] == 0 && c[wa[i - 1]][j] != 0){
            cost += c[wa[i - 1]][j], d[j] = 1, wa[i] = j;
            //cerr << i << " " << j << " ";
            //if (i == n - 1) cerr << cost << " " << best;
            //cerr << endl;
            //cerr << ".";
            if (cost < best) sol(i + 1);
            d[j] = 0, cost = cost - c[wa[i - 1]][j];
        }
        ++j;
    }
    //for (int p = 1; p < n; p++) cerr << wa[p] << " ";
    if (c[wa[n - 1]][1] != 0 && cost + c[wa[n - 1]][1] < best && i == n){
        //cerr << i << " " << j << "    " << best << endl;
        best = c[wa[n - 1]][1] + cost, wa[n] = 1;
        updwa();
    }
}

void in(){
    for (int i = 0; i < n; i++) cout << bwa[i] << " -> "; 
    cout << 1 << endl << best;
}

int main(){
    freopen("bestconfig.INP", "r", stdin);
    freopen("bestconfig2.OUT", "w", stdout);
    inp();
    sol(1);
    in();
    return 0;
}