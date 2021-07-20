#include <bits/stdc++.h>
#define ll unsigned long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
using namespace std;

ll read(){
	ll tmp;
	cin >> tmp;
	return tmp;
}

cll mxdig = 63;
ll l, r, k, ans;
bool ok = 0;

bool val(ll x, ll pos){return (x >> pos) & 1;}

void sol(ll pos, bool check1, bool check2, bool dig, ll cnt){
	if(!pos){
		ok = 1;
		return;
	}
	ll npos = pos - 1, ncheck1 = check1, ncheck2 = check2;
	lp(i, 0, 1){
		if(check1){
			if(val(l, npos) < i) ncheck1 = 0;
			else if(val(l, pos) == i) ncheck1 = 1;
			else continue;
		}
		if(check2){
			if(val(r, npos) > i) ncheck2 = 0;
			else if(val(l, npos) == i) ncheck2 = 1;
			else continue;
		}
		if((!i && k - cnt < pos) || (i && k - cnt <= pos && k - cnt >= 1)){
			ans += (i << npos), sol(npos, ncheck1, ncheck2, i, cnt + i);
			if(ok) return;
			ans -= (i << npos);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	EACHCASE{
		ok = ans = 0;
		cin >> l >> r >> k;
		sol(mxdig, 1, 1, 0, 0);
		if(ok) cout << ans << '\n';
		else cout << "-1\n";
	}
}