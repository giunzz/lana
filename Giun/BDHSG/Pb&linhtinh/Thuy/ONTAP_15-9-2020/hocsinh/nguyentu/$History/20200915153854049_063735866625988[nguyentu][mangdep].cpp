#include <bits/stdc++.h>
using namespace std;
long long x , a[1000000];
int main(){
	freopen("mangdep.inp","r",stdin);
	freopen("mangdep.out","w",stdout);
	long long n;	cin >> n;
	if (n % 6 != 0) cout << n;
	else {
		for (long long i = 1 ;i <= n ; i++){
			cin >> a[i];
		}
		x = a[1]; a[1] = 0;
		long long dem = 1 , s = 0;
		for (long long k = 1 ; k <= (n/6) ; k++){
			for (long long i = 2 ; i <= n ; i++){
				if ((x == 0) && (a[i] == 4) && (dem <= 6)) {
					dem ++;
					a[i] = 0;
					x = 4;
				}
				if ((x == 4) && (a[i] == 8)){
					dem ++;
					a[i] = 0;
					x = 8;
				}
				else if ((x == 8) && (a[i] == 15)){
					dem ++;
					a[i] = 0;
					x = 15;
				}
				else if ((x == 15) && (a[i] == 16)){
					dem ++;
					a[i] = 0;
					x = 16;
				}
				else if ((x == 16) && (a[i] == 23)){
					dem ++;
					a[i] = 0;
					x = 23;
				}
				else if ((x == 23) && (a[i] == 42)){
					dem ++;
					a[i] = 0; 
					x = 0;
				}
			}
			if (dem < 6) {
				s += 6;
			}
			dem = 0;

		}

		cout << s;
	}

	return 0;
}