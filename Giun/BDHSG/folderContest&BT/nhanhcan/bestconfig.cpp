#include <bits/stdc++.h>

using namespace std;
const int maxn = 23, maxc = 100 * (20 + (20 - 3) * 20);
int c[maxn][maxn], cost, bewa[maxn], bec = maxc + 1;
vector<int> wa;
bool d[maxn];

void inp(){
    int q, p, k, m;
    cin >> n >> m;
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= m; i++){
        cin >> q >> p >> k;
        c[q][p] = k, c[p][q] = k;
    }
    wa.push_back(1);
}

void sol(int i){
    for (int j = 2; j <= n; j++){
        if (d[j] == 0 && c[i][j] != 0){

        }
    }
}

int main(){
    freopen("bestconfig.INP", "r", stdin);
    freopen("bestconfig.OUT", "w", stdout);
    inp();
    sol(1);
    return 0;
}