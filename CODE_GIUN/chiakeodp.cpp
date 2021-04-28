#include <bits/stdc++.h> 
using namespace std;
 
int main()
{
	int n,t=0,f[10001],d[10001];
	cin>>n;
	int a[n+1];
	for (int i=1;i<=n;i++)
	   {
	   	cin>>a[i];
	   	t=t+a[i];
	   }
	t=t/2;
//QHD
	for (int i=1;i<=t;i++)
	{
		f[i]=INT_MAX;
	   for (int j=1;j<=n;j++)
	      if (i>=a[j] && j>f[i-a[j]]) 
	      {
	      	f[i]=j;
	      	break;
		  }
	}
//Truyvet
	while (f[t] > n) t--;
	while (t > 0)
	{
		d[f[t]]=1;
		t=t-a[f[t]];
	}
	for (int i=1;i<=n;i++)
	   if (d[i]==1) cout<<a[i]<<" ";
	   cout<<endl;
	for (int i=1;i<=n;i++)
		if (d[i]!=1) cout<<a[i]<<" ";
		cout<<endl;
}