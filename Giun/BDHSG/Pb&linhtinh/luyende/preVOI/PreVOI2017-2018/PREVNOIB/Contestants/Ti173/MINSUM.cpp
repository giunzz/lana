#include<bits/stdc++.h>
#define ioi             exit(0)
using namespace std;

typedef pair<int, int> ii;

int T, a, b;

queue<ii> Q;
int vis[3000][3000]; int Time;

void brute() {
    ++Time; vis[a][b] = vis[b][a] = Time; //cerr << Time << '\n';
    Q.push(ii(a, b)); Q.push(ii(b, a));

    int res = a+b; ii save = ii(a, b);

    while (Q.size()) {
        int u = Q.front().first, v = Q.front().second; Q.pop();

            //if (Time == 2) cout << u << " " << v << '\n';
            //cerr << u << " " << v << '\n';

        for (int i = 1; i <= sqrt(u); ++i) {
            if (u % i != 0) continue;

            int x = u / i, y = v * i;
            if (vis[x][y] != Time) {
                vis[x][y] = Time; vis[y][x] = Time;
                Q.push(ii(x, y)); Q.push(ii(y, x));
                if (res > x + y) { res = x + y; save = ii(x, y); }
            }

            int div = u / i;

            x = u / div, y = v * div;
            if (vis[x][y] != Time) {
                vis[x][y] = Time; vis[y][x] = Time;
                Q.push(ii(x, y)); Q.push(ii(y, x));
                if (res > x + y) { res = x + y; save = ii(x, y); }
            }

            if (v % i == 0) {
                x = u / i; y = v / i;
                if (vis[x][y] != Time) {
                    vis[x][y] = Time; vis[y][x] = Time;
                    Q.push(ii(x, y)); Q.push(ii(y, x));
                    if (res > x + y) { res = x + y; save = ii(x, y); }
                }
            }

            if (v % div == 0) {
                x = u / div, y = v / div;
                if (vis[x][y] != Time) {
                    vis[x][y] = Time; vis[y][x] = Time;
                    Q.push(ii(x, y)); Q.push(ii(y, x));
                    if (res > x + y) { res = x + y; save = ii(x, y); }
                }
            }
        }
    }

    cout << save.first << " " << save.second << '\n';
}


int main() {
    freopen("MINSUM.inp", "r", stdin);
    freopen("MINSUM.out", "w", stdout);

    cin >> T;
    while (T--) {
        cin >> a >> b;
        brute();
    }

    return 0;
}
