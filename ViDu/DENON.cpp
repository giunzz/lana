#include <iostream>
#include <map>
using namespace std;
long long l[100009],r[100009];
int main()
{
	long long n,m,k;
	cin>>n>>m>>k;
	long long d=n*m;
	map<long long, bool> checkd,checkc;
	for (int i=1;i<=k;i++)
	{
		cin>>l[i]>>r[i];
		checkd[l[i]]=false;
		checkc[r[i]]=false;
	}
	long long demd=0,demc=0;
    for (int i=1;i<=k;i++)
     {
      	if (!checkd[l[i]])
        {
      		d-=m-demc;
      		demd++;
      	}
      	if (!checkc[r[i]])
        {
      		d-=n-demd;
      		demc++;
      	}
        checkd[l[i]]=true;
		checkc[r[i]]=true;
    }
    cout<<d;
	return 0;
}