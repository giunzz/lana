#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "f"
using namespace std;

ll read(){
	ll tmp;
	cin >> tmp;
	return tmp;
}

void OF(){
	freopen(Fname".inp", "r", stdin);
	freopen(Fname".out", "w", stdout);
}

void sol(){
	ll n, ans = 0;
	cin >> n;
	lp(i, 1, n) ans ^= (read() + 1);
	// if(ans){
	// 	if((n & 1) && n != 1) cout << "L\n";
	// 	else cout << "W\n";
	// }
	// else{
	// 	if(n & 1) cout << "W\n";
	// 	else cout << "L\n";
	// } 
	if(ans) cout << "W\n";
	else cout << "L\n";
}

// #define ONLINE_JUDGE
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	OF();
	#endif
	EACHCASE sol();
}