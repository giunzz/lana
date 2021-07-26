#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
using namespace std;
const ll maxn = 3e3 + 3;
ll n, ans = 0;
string s ;

inline bool check (string x)
{
	ll a = 0 , b = 0 , c = 0;
	for (int i = 0 ; i < x.size() ; i++)
	{
		if (x[i] >= 'a' && x[i] <= 'z') a++;
		if (x[i] >= 'A' && x[i] <= 'Z') b++;
		if (x[i] >= '0' && x[i] <= '9') c++;
	}
	if (a > 0 && b > 0 && c > 0) return true;
	return false;
}
int main()
{
    giuncute;
    freopen("MATKHAU.INP","r",stdin);
    freopen("MATKHAU.OUT","w",stdout);
    cin >> s ;
	for (int i = 0 ; i < s.size()-1 ; i++)
	{
		string tmp = "";
		tmp += s[i];
		for (int j = i + 1 ; j < s.size() ; j++)
		{
			tmp += s[j];
			if (check (tmp) == true) ans++;
		}
	}
	cout << ans;
}
