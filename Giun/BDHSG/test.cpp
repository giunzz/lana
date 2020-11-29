#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
	freopen(Fname".inp", "r", stdin);
	freopen(Fname".out", "w", stdout);
}

using point = pp(ll, ll);

#define x first
#define y second

int area(point a, point b, point c){
	point ab = {b.x - a.x, b.y - a.y}, bc = {c.x - b.x, c.y - b.y};
	return ab.x * bc.y - ab.y * bc.x;
}

int ccw(point a, point b, point c){
	ll tmp = area(a, b, c);
	if(tmp < 0) return -1;
	else if(tmp > 0) return 1;
	else return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	OF();
	point a = {2, 5}, b = {5, 7}, c = {4, 10};
	cerr << ccw(a, b, c) << '\n' << abs(area(a, b, c)) / 2.0;
}