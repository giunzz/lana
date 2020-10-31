#include<bits/stdc++.h>
#define nmax 303
#define U first
#define V second

using namespace std;

typedef pair<int, int> pii;
int m, n, k;
int a[nmax][nmax], res1 = 0;
int hX[2] = {1, 0};
int hY[2] = {0, 1};
pii s, t, cdv;
bool avail[nmax][nmax];
void slove(pii U, int S){
    if (U.U == t.U &&  U.V == t.V){
        S = S - a[t.U][t.V];
        res1 = max(res1, S);
        return;
    }
    for (int i = 0 ; i < 2 ; i++){
        if ( U.U + hX[i] == cdv.U && U.V + hY[i] == cdv.V)
            continue;
        if (U.U + hX[i] <=  t.U && U.V + hY[i] <= t.V)
            slove(pii(U.U + hX[i], U.V + hY[i]), S + a[U.U + hX[i]][ U.V + hY[i]]);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("TABLE.INP", "r", stdin);
    freopen("TABLE.OUT", "w", stdout);
    cin >> m >> n >> k;
    for(int i = 1 ; i <= m ; i++)
        for (int j = 1 ; j <= n ; j++)
            cin >> a[i][j];
    for (int i = 1 ; i <=  k ;i++){
        int res = 1e9;
        cin >> s.U >> s.V >> t.U >> t.V;
        for (int x = s.U ; x <= t.U ;x++)
            for (int j = s.V + 1;  j <= t.V  ; j++){
                if (x == t.U && j == t.V) continue;
                cdv = pii(x, j);
                res1 = 0;
                slove(s, 0);
                res = min(res, res1);
            }
        cout << res << "\n";
    }
}
