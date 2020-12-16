#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
const ll maxn = 1e5;
using namespace std;
ll n , a[maxn] , vt[maxn]={0} , f[maxn]={0};
vector<ll> b;

void trace_back(ll i)
{
	if(i != 0)
	{
		trace_back(vt[i]);
		b.push_back(a[i]);
	}
}
void dp()
{
	ll maxx = f[1], pos = 1;
	f[1] = 1;
	vt[1] = 0;
	for(ll i = 2; i <= n; i++)
	{
		f[i] = 1;
		vt[i] = 0;
		for(ll j = i - 1; j >= 1; j--)
		{
			if(a[i] % a[j] == 0) 
			{
				if(f[i] < f[j] + 1)
				{
					f[i] = f[j] + 1;
					vt[i] = j;
				}
			}
		}
		if(maxx < f[i]) 
		{
			maxx = f[i];
			pos = i;
		}
	}
	//cout << f[n] << endl;
	trace_back(pos);
    cout << b.size() << endl;
    for (int i = 0 ; i < b.size() ; i++) cout << b[i] << " ";
}

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i] ;
    sort(a+1,a+1+n);
    dp();
	return 0;
}