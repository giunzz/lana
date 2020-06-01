#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define lpdk(a, b, c, d) for(ll a = b; c; d) 
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define vecite(a) vector<a>::iterator
#define fi first
#define se second
# define M_PI 3.14159265358979323846
using namespace std;
cll MOD = 1e9 + 7;
float es = 1e-9;
const string tenfile = "table";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

const double esp = 1e-9;
ll n,R,r;
int main()
{
    ios_base::sync_with_stdio(0);
    file;
	cin>>n>>R>>r;
	if(r > R)
	{
		cout<<"NO";
		return 0;
	}
	if(2*r > R)
	{
		if(n == 1)cout<<"YES";
		else cout<<"NO";
		return 0;
	}
	double alpha = asin((r*1.0)/(R-r));
	if(n*alpha - M_PI <= esp)
	{
		cout<<"YES";
	}
	else cout<<"NO";
}
