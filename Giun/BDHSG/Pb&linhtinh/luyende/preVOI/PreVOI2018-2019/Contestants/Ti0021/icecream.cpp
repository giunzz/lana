using namespace std;
#include <bits/stdc++.h>

typedef long long ll;
typedef pair<int, int> cp;

#define forinc(i, a, b) for (int i = a; i <= b; i++)
#define fordec(i, a, b) for (int i = a; i >= b; i--)
#define fi first
#define se second
#define LanHT "icecream"

const int base = 1e9 + 9;
int n, mmax, m50, m1, m2, res;

void backtrack(int i, int u, int v, int z){
    forinc(j, 1, 3){
        int m50 = u, m1 = v, m2 = z;
        if (j == 2) {
                if(m50 > 0) m50--;
                else continue;
        }
        if (j == 3){
            bool ok = false;
            if (m1 > 0 && m50 > 0) {m50--; m1--; ok = true;}
            if (!ok) if (m50 > 2) {ok = true; m50 -= 3;}
            if (!ok) continue;
        }
        if (j == 1) ++m50; else if (j == 2) ++m1; else ++m2;
        int tg = max(m50, max(m1, m2));
        if (tg > mmax) continue;
        if (i == n) res++; else backtrack(i + 1, m50, m1, m2);
    }
}

void Input(){
    cin >> n >> mmax;
    cin >> m50 >> m1 >> m2;
}

void Sub1(){
    backtrack(1, m50, m1, m2);
    cout << res;
}

ll f[55][155][55][55];

ll tinh(int i, int u, int v, int z){
    if (i == n + 1) return 1;
    if (f[i][u][v][z] != -1) return f[i][u][v][z];
    ll res = 0;
    forinc(j, 1, 3){
        int m50 = u, m1 = v, m2 = z;
        if (j == 2) {
                if(m50 > 0) m50--; else continue;
        }
        if (j == 3){
            bool ok = false;
            if (m1 > 0 && m50 > 0) {m50--; m1--; ok = true;}
            if (!ok) if (m50 > 2) {ok = true; m50 -= 3;}
            if (!ok) continue;
        }
        if (j == 1) ++m50; else if (j == 2) ++m1; else ++m2;
        int tg = max(m50, max(m1, m2));
        if (tg > mmax) continue;
        res = (res + tinh(i + 1, m50, m1, m2)) % base;
    }
    f[i][u][v][z] = res;
    return res;
}

void Sub2(){
    memset(f, -1, sizeof(f));
    ll res = tinh(1, m50, m1, m2);
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(LanHT".inp", "r", stdin);
    freopen(LanHT".out", "w", stdout);
    Input();
    if (n <= 15) Sub1(); else
    Sub2();
}
