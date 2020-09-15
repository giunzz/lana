#include <bits/stdc++.h>
using namespace std;
long tam,n,dem[7]={0};
int main()
{
	freopen("mangdep.inp","r",stdin);
	freopen("mangdep.out","w",stdout);
	cin>>n;
	for (long i=1; i<=n; i++)
	{
		cin>>tam;
		if (tam==4) dem[1]+=1;
		if (tam==8) 
			if (dem[2]+1<=dem[1]) dem[2]+=1;
		if (tam==15) 
			if (dem[3]+1<=dem[2]) dem[3]+=1;
		if (tam==16) 
			if (dem[4]+1<=dem[3]) dem[4]+=1;
		if (tam==23)
			if (dem[5]+1<=dem[4]) dem[5]+=1;
		if (tam==42)
			if (dem[6]+1<=dem[5]) dem[6]+=1;
	}

	cout<<n-dem[6]*6;
	return 0;
}