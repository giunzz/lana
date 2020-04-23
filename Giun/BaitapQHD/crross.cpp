#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000000];
int b[1000000];
char bridge[100005];
int time ( int r, int m, string bridge)
{
	int i=0;
	int res=1;
	while(r+i<=m )
	{
		res++;
		i=i+r;
		while (bridge[i]=='1') i--;

	}
	return res;
}
int main()
{
	freopen("CROSS12.INP","r",stdin);
	freopen("CROSS12.OUT","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)

	 cin>>b[i];
	string bridge;
	 cin>>bridge;
	 bridge='0'+bridge+'0';
	 //cout<<bridge<<endl;
	 for(int i=1; i<=n; i++)
	   {
	   	a[i]=time(b[i],m,bridge);

       }
      sort(a+1,a+n+1); //sort time cua moi nguoi

      long long  f1,f2,f3;
      if(n==1) cout<<a[1];
      else if (n==2) cout<<a[2];
        else
        {
        	f1=a[1];
        	f2=a[2];
        	for(int i=3; i<=n; i++)
        	{
			f3=min(f1+a[1]+2*a[2]+a[i],f2+a[1]+a[i]);
			cerr << f1 << " " << f2 << " " << f3 << endl;
        	f1=f2;
        	f2=f3;
            }
		}


	// for(int i=1; i<=n; i++)
	 cout<<f2;

}
