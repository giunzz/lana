#include<bits/stdc++.h>

using namespace std;

#define int unsigned long long

int n, k, a, b;
int f[10];

int qpow(int a,int exp,int mod) {
	int ans = 1;
	while (exp) {
		if(exp & 1) ans = ans * a;
		a = a * a;  exp >>= 1;
	}
	return  ans % mod;
}
int inv(int a,int p)    {
	if (a == 1 || p == 1)   return 1;
	int x = p * inv(p % a,a) - 1;
	    x = (x / a) % p;
	    x = (p - x) % p;
	return  x;
}

signed main()   {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("MODULO.INP","r",stdin);
	freopen("MODULO.OUT","w",stdout);
	
	cin >> a >> b >> n >> k;
	
	if (a == b) return 0;
	
	int x = a, y = b;
	
	while((a & 1) == (b & 1))   {
		if(a & 1)   k += inv(9,(1ll << n));
		if(k & 1)   return 0 * puts("-1");
		k /= 2;
		a /= 2;
		b /= 2;
	}
	string s = "";
	for(int i = 0 ; i < n ; ++i)    {
		int z = (k & 1);
		if (z == (a & 1))   s += (char)(x + '0');
		else                s += (char)(y + '0');
		k = (k - a) / 2;
		k *= inv(5,(1ll << n));
	}
	reverse(s.begin(),s.end());
	cout << s << endl;
}
