#include <bits/stdc++.h>
#define ft(i,x,y) for(int i=x;i<=y;i++)
#define ftd(i,x,y) for(int i=x;i>=y;i--)
#define ftm(i,x,y) for(int i=x;i<y;i++)
#define ftdm(i,x,y) for(int i=x;i>y;i--)
#define fi first
#define se second
#define add push_back
#define ad push
using namespace std;
typedef struct pair <long long,int> ii;
void io()
{
    freopen("MINSUM.inp","r",stdin);
    freopen("MINSUM.out","w",stdout);
}
int t;
int x[1001];
long long a,b,c,A,res=1e18,resA=1,resB=1;
vector <long long> X;
void cut_with_(long long a)
{
	if(a%2==0)
	{
		int uc=0;
		while(a%2==0)
		{
			a/=2;
			uc++;
		}
		if(uc%2!=0) X.add(2);
	}
	int m=sqrt(a);
	for(int i=3;i<=m;i+=2)
	{
		int uc=0;
		while(a%i==0)
		{
			a/=i;
			uc++;
		}
		if(uc%2!=0) X.add(i);
	}
	if(a>1) X.add(a);
}
void bk(int i)
{
	if(i>=X.size())
	{
		long long B=c/A;
		if(A+B<res)
		{
			resA=A;
			resB=B;
			res=A+B;
		}
		return;
	}
	ft(j,0,1)
	{
		x[i]=j;
		if(j==1) A=A*X[i];
		bk(i+1);
		if(j==1) A=A/X[i];
	}
}
int main()
{
    #ifndef Mirai
        io();
    #endif //Mirai
    scanf("%d",&t);
    while(t--)
    {
    	X.clear();c=1;A=1;res=1e18;
    	scanf("%lld%lld",&a,&b);
    	long long ucln=__gcd(a,b);
    	a/=ucln;b/=ucln;
    	cut_with_(a);cut_with_(b);
    	if(X.size()==0)
    	{
    		cout<<1<<" "<<1<<"\n";
    		continue;
    	}
    	ftm(i,0,X.size()) c*=X[i];
    	sort(X.begin(),X.end());
    	bk(0);
    	cout<<resA<<" "<<resB<<"\n";
    	//ftm(i,0,X.size()) cout<<X[i].fi<<" "<<X[i].se<<"\n";
    	//cout<<"\n";
    }
    return 0;
}


