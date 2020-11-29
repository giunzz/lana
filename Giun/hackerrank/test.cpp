#include <bits/stdc++.h>
using namespace std;

long long a, b, c;

int main(){
	cin >> a >> b >> c;
	long long ab = a * b, ac = a * c, bc = c * b;
	if(ab >= bc && bc >= ac) cout << a << " " << b;
	else if(bc >= ab && ab >= ac) cout << b << " " << c;
	else cout << a << " " << c;
	return 0;
}