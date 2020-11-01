#include <bits/stdc++.h>
#define int long long
#define ii pair <int, int>
#define X first
#define Y second

using namespace std;

int n, m;
int a[1000000], b[1000000];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("LIONDANCE.INP", "r", stdin);
    freopen("LIONDANCE.OUT", "w", stdout);
    	cin >> n >> m;
    	for (int i = 1; i <= n; ++i){
    		cin >> a[i];
    	}
		for (int i = 1; i <= n; ++i){
    		cin >> b[i];
    	}
    	int d = 0;
    	for (int i = 1; i <= n; ++i){
    		if (a[i] != b[i]){
    			++d;
    		}
    	}
    	cout << d<< endl;
    	for (int i = 1; i <= n; ++i){
    		if (a[i] != b[i]){
    			cout << i << ' ';
    		}
    	}
}
