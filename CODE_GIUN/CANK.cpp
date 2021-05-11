#include <bits/stdc++.h>

using namespace std;

int n , k ,  total = 0 , s1 , s2;
vector <int> x(30);
vector <int> v(30);
bool check = false;

void write() {
	s1 = k , s2 = 0;
	for (int j = 1 ; j <= n; j++){ 
		if (x[j] == 1) s1 += v[j];
		else if (x[j] == 2) s2 += v[j];
	}
	if (s1 == s2) check = true;
}

int giuncute(int i) {
	for (int j = 1 ; j <= 3 ; j++){
		x[i] = j;
		if (i == n) write();
		else giuncute(i + 1);
	} 
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("cank.inp","r",stdin);
	freopen("cank.out","w",stdout);
	cin >> n >> k;
	for (int i = 1 ; i <= n ; i++){
		cin >> v[i];
		total += v[i];
	}
	giuncute(1);
	if (check == false) cout << "NO";
	else cout << "YES";
	return 0;
}