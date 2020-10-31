#include <bits/stdc++.h>

using namespace std;
const int N = 2e3 + 12;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
struct node {
    int x,y;
};

int get( int x, int y, int u, int v ) {
    return abs(x - u) + abs(y - v);
}

int n,m,x,y,d,c, vis[N][N];
node q[N*N + 100], u, v;

void sub_1() {
    int res = 0, tmp = 0;
    for(int i = 1; i <= m; ++ i)
        cin >> q[i].x >> q[i].y;
    cin >> x >> y;

    for(int i = x - n; i <= x + n; ++ i) {
        for(int j = y - n; j <= y + n; ++ j) {
            if( get(x,y,i,j) % 2 == n % 2 ) {
                tmp = 2e9;
                for(int k = 1; k <= m; ++ k) {
                    tmp = min( tmp, get(q[k].x, q[k].y,i,j) );
                }
                res = max( res, tmp );
            }
        }
    }
    cout << res;
}

void sub_2() {

    for(int i = 1; i <= m; ++ i) {
        cin >> x >> y;
        x += 1e3; y += 1e3;
        q[++ c] = { x,y };
        vis[x][y] = 1;
    }
    cin >> x >> y;
    x += 1e3; y += 1e3;
    d = 1;
    while( d <= c ) {
        u = q[d]; ++ d;
        for(int i = 0; i < 4; ++ i) {
            v = { u.x + dx[i], u.y + dy[i] };
            if( v.x >= x - n && v.y >= y - n && v.x <= x + n && v.y <= y + n && !vis[v.x][v.y] ) {
                vis[v.x][v.y] = vis[u.x][u.y] + 1;
                q[++ c] = v;
            }
        }
    }
    int res = 0;
    for(int i = x - n; i <= x + n; ++ i) {
        for(int j = y - n; j <= y + n; ++ j) {
            if( get(x,y,i,j) % 2 == n % 2 ) {
                res = max( res, vis[i][j] - 1 );
            }
        }
    }
    cout << res;

}

int main() {
    freopen("ROBOTS.inp","r",stdin);
    freopen("ROBOTS.out","w",stdout);

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    if( n <= 300 && m <= 300 ) sub_1();
    else sub_2();
    return 0;
}
