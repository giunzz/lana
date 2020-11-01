#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL)
#define FRE freopen("modulo.inp","r",stdin),freopen("modulo.out","w",stdout)
using namespace std;
typedef long long ll;
ll a[3],b,n,k,ans[70],res=0,t,chot[3][70];
int counter=0;

ll gt(ll i)
{
	return i==0? 1 : (ll)2*gt(i-1);
}

void dfs(int i)
{
	if (i==n+1) {if (res%t==k) {for (int j=1;j<=n;j++) cout<<ans[j];
	counter=1;}
	return ;
	}
	for (int j=0;j<=1;j++)
	{
		ans[i]=a[j];
		ll previous=res;
		res=(res*10+ans[i])%t;
		dfs(i+1);
		if (counter==1) return;
		res=previous%t;
	}
}

int main()
{
	IOS;
	FRE;
	cin>>a[0]>>a[1]>>n>>k;
	t=gt(n);
	dfs(1);
	if (counter==0) cout<<"-1";
	return 0;
}
/*
int main()
{
	IOS;
	cin>>a[0]>>a[1]>>n>>k;
	t=gt(n);
	ll tong=1; 
	for (int i=0;i<=1;i++) chot[i][1]=a[i];
	for (int i=2;i<=n;i++)
	{
		tong=tong * 10 %t;
		for (int j=0;j<=1;j++)
		{
			chot[j][i]=(a[j]*tong)%t;
		}
	}
}
*/
