#include <bits/stdc++.h>
#define int long long

using namespace std;
const int MAX = 1e6+7;
int a[MAX];
int A,B;
int k,n,N;
int res,ans;
int printyet = 1;

int power(int a)
{
	ans = 1;
	for(int i=1;i<=a;i++)
	{
		ans *= 2;
	}
	return ans;
}

void show()
{
	for(int i=1;i<=n;i++)
	{
		cout<<a[i];
	}
//	cout<<endl;
}

void cre()
{
	int mod = power(N);
	res = 0;
	for(int i=1;i<=n;i++)
	{
		res = (res + a[i]) % mod;
		if(i != n)
		{
			res = (res*10) % mod;
		}
	}
}

void back(int i)
{
	if(i == n + 1)
	{
		cre();
		if(res % power(N) == k)
		{
			if(printyet == 1)
			{
				show();
				printyet = 0;
			}
		}
	}
	
	else
	{
		a[i] = A;
		back(i+1);
		a[i] = B;
		back(i+1);
	}
}

signed main()
{
	freopen("MODULO.INP","r",stdin);
	freopen("MODULO.OUT","w",stdout);
//	cout<<power(20)<<" ";
	cin>>A>>B;
	cin>>N>>k;

	for(n=1;n<=N;n++)
	{
		back(1);
	}
	
	if(printyet == 1) cout<<-1;
}
