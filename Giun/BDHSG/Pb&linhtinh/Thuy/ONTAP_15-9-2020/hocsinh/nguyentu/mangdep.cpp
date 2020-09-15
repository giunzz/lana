#include <bits/stdc++.h>
using namespace std;
long long x , a[1000000];
int main(){
	freopen("mangdep.inp","r",stdin);
	freopen("mangdep.out","w",stdout);
	long long n ; cin >> n;
	for (int i = 1 ; i<= n ; i++)
		cin >> a[i];
	long long c1 = 0 , c2 = 0 , c3 = 0 , c4 = 0 , c5 = 0 , c6 = 0;
	for (int i = 1 ; i <= n ; i++){
		if (a[i] == 4) c1 ++;
		if ((a[i] == 8) && (c2 + 1 <= c1)) c2 ++;
		if ((a[i] == 15) && (c3 + 1 <= c2)) c3 ++;
		if ((a[i] == 16) && (c4 + 1 <= c3)) c4 ++;
		if ((a[i] == 23) && (c5 + 1 <= c4)) c5 ++;
		if ((a[i] == 42) && (c6 + 1 <= c5)) c6 ++;
	}

	cout << n - (c6*6);
	return 0;
}