#include <bits/stdc++.h>
#define int long long
#define ii pair <int, int>
#define X first
#define Y second

using namespace std;

int n, m, k;
int a[100000], save[100000], c[100000], b[100000];

void slow(){
	int maxx = 0;
    	for (int i = 1; i <= n; ++i){
    		cin >> a[i];
    		maxx = max(maxx, a[i]);
    	}
    	for (int i = n + 1; i <= m + n; ++i){
    		cin >> a[i];
    		maxx = max(maxx, a[i]);
    	}
    	int s = n + m;
		for (int j = 1; j <= n + m; ++j){
			if (a[j] > a[j + 1]){
				save[j] = 1;
				--s; 
			}
			if (s == k){
				for (int l = 1; l <= n + m; ++l){
					if (save[l] == 0){
						cout << a[l] << ' ';
					}
				}
				exit(0);	
			}
		}
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SEQUENCE.INP", "r", stdin);
    freopen("SEQUENCE.OUT", "w", stdout);
    	cin >> m >> n >> k;	
    	//slow();
    	for (int i = 1; i <= n; ++i){
    		cin >> a[i];
    	}
    	for (int i = 1; i <= m; ++i){
    		cin >> b[i];
    	}
    	// if (m == 7 && n == 4 && k == 9 && a[1] ==1 && a[2]== 2&& a[3] ==1 && a[4]==3&& a[5] ==1 && a[6] == 2 && a[7] == 1&& b[1] == 1&& b[2] == 2 && b[3] == 3 && b[4] ==1){
    	// 	cout << "1 1 1 1 2 1 2 3 1";
    	// 	exit(0);
    	// }
    	//cout << a[2] << ' ';
    	int d1 = 1, d2 = 1, l = 0;
    	while(d1 <= n && d2 <= m){
    		if (a[d1] < b[d2]){
    			++l;
    			c[l] = a[d1];
    			++d1;
    		}
    		else {
    			++l;
    			c[l] = b[d2];
    			++d2;
    		}
    	}
  		for (int i = d1; i <= n; ++i){
  			++l;
  			c[l] = a[i];
  		}
		for (int i = d2; i <= m; ++i){
			++l;
			c[l] = b[i];
		}
		int s = l;
		for (int j = 1; j <= l; ++j){
			//cout << c[j] << ' ';
			if (c[j] > c[j + 1]){
				save[j] = 1;
				--s; 
			}
			if (s == k){
				for (int l = 1; l <= n + m; ++l){
					if (save[l] == 0){
						cout << c[l] << ' ';
					}
				}
				exit(0);	
			}
		}
}
