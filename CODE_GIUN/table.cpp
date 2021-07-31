#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
# define M_PI 3.14159265358979323846
using namespace std;
const double esp = 1e-9;
ll n,R,r;
int main()
{
    giuncute;
    freopen("giun.inp" ,"r",stdin);
    freopen("giun.out", "w" ,stdout);
    cin >> n >> R >> r;
	if (r > R)
    {
		cout << "NO";
		return 0;
	}
	if (2*r > R)
    {
		if(n == 1) cout << "YES";
		else cout << "NO";
		return 0;
	}
	double alpha = asin((r*1.0)/(R-r));
    if (n*alpha - M_PI <= esp) cout << "YES";
	else cout << "NO";

}

