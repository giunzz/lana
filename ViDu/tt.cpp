/*#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n , m , t[(int) 1e6], sum = 0, ma = INT_MIN, ans = 0;

int main()
{
    // m người n bàn
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m ;
    for (ll i = 1 ; i <= n ; i++) cin >> t[i], ma = max(ma,t[i]);
    ll l = 1 , r = ma*m ;
    while (l <= r)
    {
        ll mid = (l+r) / 2;
        sum = 0;
        for (int i = 1 ; i <= n ; i++)
        {
            sum += mid / t[i];
        }
        if(sum >= m) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans;    
}*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,b,k,ans= 0,a;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k >> a >>b ;
	freopen("giun.inp","r",stdin);
	freopen("giun.out","w",stdout);
	
	while(n != 1)
	{
		cerr << 1 << endl;
		if(n % k == 0) 
		{
			if (b < ((n - n/k)*a)) ans += b;
			else ans += (n - n/k)*a, n = n/k;
		}
		else ans += n - n / k * k * a,n = n / k * k;
        n--;
	}
	cout << ans;
}

