#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 111;
struct Enemy {
    int x, y, t;
    void read() {
        cin >> x >> y >> t;
    }
    bool Attack(const Enemy& a) {
        if (t == 1) {
            return abs((a.x - x) * (a.y - y)) == 2;
        }
        if (t == 2) {
            return (a.x - a.y == x - y) || (a.x + a.y == x + y); 
        }
        if (t == 3) {
            return (a.x == x) || (a.y == y);
        }
        if (t == 4) {
            return (a.x - a.y == x - y) || (a.x + a.y == x + y) || (a.x == x) || (a.y == y);
        }
    }
}enemy[N * N];
int n, k, def[N * N], atk[N * N];
int main() {
    freopen("GOCHESS.inp","r",stdin);
    freopen("GOCHESS.out","w",stdout);
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        enemy[i].read();
    }
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) if (i != j) {
            if (enemy[i].Attack(enemy[j])) {
                ++atk[i], ++def[j];
            }
        }
    }
    for (int i = 0; i < k; ++i) cout << atk[i] <<  ' ' << def[i] << '\n';
}