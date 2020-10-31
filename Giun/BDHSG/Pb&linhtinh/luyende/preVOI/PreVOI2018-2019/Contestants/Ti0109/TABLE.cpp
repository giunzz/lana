#include <bits/stdc++.h>
#define int long long
#define ii pair <int, int>
#define X first
#define Y second

using namespace std;

int m, n, k, u, v, p, q;
int a[1000][1000], trace[1000][1000];
queue <ii> qu;
int c1[] = {0, 1, 0};
int c2[] = {0, 0, 1};


int BFS(int x, int y){
	int maxx = 0;
	qu.push(ii(u, v));
	trace[u][v] = a[u][v]; 
	while (!qu.empty()){
        ii u = qu.front();
        qu.pop();
        for (int i = 1; i <= 2; ++i){
            int b = u.X + c1[i];
            int c = u.Y + c2[i];
            //cout << trace[b][c] << ' ' << trace[u.X][u.Y] << ' ' << a[b][c] << "-" <<endl;;
            if (trace[b][c] < trace[u.X][u.Y] + a[b][c] && b <= p && c <= q && (b != x || c != y)){
                trace[b][c] = trace[u.X][u.Y] + a[b][c];
                //cout << trace[u.X][u.Y] <<' '  <<trace[b][c]<< ' ' << b << ' ' << c << endl;
                if (b == p && c == q){
                	maxx = max(maxx, trace[b][c]);
                }
                qu.push(ii(b, c));
            }
        }
    }
    return maxx;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TABLE.INP", "r", stdin);
    freopen("TABLE.OUT", "w", stdout);
    	cin >> m >> n >> k;
    	for (int i = 1; i <= m; ++i){
    		for (int j = 1; j <= n; ++j){
    			cin >> a[i][j];
    		}
    	}
    	while (k--){
    		cin >> u >> v >> p >> q;
    		int minn = 1e16;
    		for (int x = u; x <= p; ++x){
    			for (int y = v; y <= q; ++y){
    				if ((x == u && y == v) || (x == p && y == q)){
    					continue;
    				}
    				for (int i = u; i <= p; ++i){
			    		for (int j = v; j <= q; ++j){
			    			trace[i][j] = -1e16;
			    		}
			    	}
    				//cout << BFS(x, y) << ' ' << x << ' ' << y << endl;
    				minn = min(minn, BFS(x, y));
    			}
    		}
    		cout << minn << "\n";

    	}
}
