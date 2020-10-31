#include<bits/stdc++.h>

using namespace std;
long long a,b,n,k;
long long mangsinh[100],luu[100];
void tao(long long i,long long du)
{
	if(i==n+1) 
	{
		if(du==k)for(int i=1;i<=n;i++) luu[i]=mangsinh[i];
	}
	else
	{
		mangsinh[i]=a;
		tao(i+1,(du*10+a)%(long long)(pow(2,n)));
		mangsinh[i]=b;
		tao(i+1,(du*10+b)%(long long)(pow(2,n)));
	}
}
main()
{
	freopen("MODULO.inp","r",stdin);
	freopen("MODULO.out","w",stdout);
	cin>>a>>b>>n>>k;
	if(n<=20)
	{
		tao(1,0);
		if(luu[1]!=0) for(int i=1;i<=n;i++) cout<<luu[i];
		else cout<<-1;
	}
	else cout<<-1;
}
