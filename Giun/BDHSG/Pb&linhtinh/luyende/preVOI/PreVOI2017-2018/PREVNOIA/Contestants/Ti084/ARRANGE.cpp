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
    freopen("ARRANGE.inp","r",stdin);
    freopen("ARRANGE.out","w",stdout);
}
int n;
long long a[100001],res=0;
int main()
{
    #ifndef Mirai
        io();
    #endif //Mirai
    scanf("%d",&n);
    ft(i,1,n)
    	scanf("%lld",&a[i]);	
    while(true)
    {
    	long long _max=-1,_min=1e18;
    	ft(i,1,n)
    	{
    		_max=max(_max,a[i]);
    		_min=min(_min,a[i]);
    	}
    	//ft(i,1,n) cout<<a[i]<<" ";
    	//cout<<"\n";
    	if(_max-_min<=1) break;
    	ft(i,1,n)
    	{
    		//cout<<i<<"\n";
    		//ft(i,1,n) cout<<a[i]<<" ";
    		//cout<<"\n";
    		if(i==1)
    		{
    			if(a[i+1]<a[i])
    			{
    				long long text=(a[i]-a[i+1])/2;
    				a[i+1]+=text;
    				a[i]-=text;
    				res+=text;
    			}
    			continue;
    		}
    		if(i==n)
    		{
    			if(a[i-1]<a[i])
    			{
    				long long text=(a[i]-a[i-1])/2;
    				a[i-1]+=text;
    				a[i]-=text;
    				res+=text;
    			}
    			continue;
    		}
    		if(a[i-1]>a[i+1] and a[i]>=a[i-1])
    		{
    			long long text=(a[i-1]-a[i+1]);
    			if(a[i]-text>=a[i-1])
    			{
    				a[i]-=text;
    				a[i+1]+=text;
    				text=(a[i]-a[i-1])/2;
    				a[i-1]+=text;
    				a[i+1]+=text;
    				res+=text;
    				continue;
    			}
    			if(a[i]-text<a[i-1])
    			{
    				text=(a[i]-a[i-1]);
    				a[i+1]+=text;
    				a[i]-=text;
    				res+=text;
    				continue;
    			}
    		}
    		if(a[i-1]<a[i+1] and a[i]>=a[i+1])
    		{
    			long long text=a[i+1]-a[i-1];
    			if(a[i]-text>=a[i+1])
    			{
    				a[i]-=text;
    				a[i-1]+=text;
    				text=(a[i]-a[i+1])/2;
    				a[i-1]+=text;
    				a[i+1]+=text;
    				res+=text;
    				continue;
    			}
    			if(a[i]-text<a[i+1])
    			{
    				text=(a[i]-a[i+1]);
    				a[i-1]+=text;
    				a[i]-=text;
    				res+=text;
    				continue;
    			}
    		}
    		if(a[i-1]==a[i+1])
    		{
    			long long text=(a[i]-a[i-1])/2;
    			a[i]-=text;
    			a[i-1]+=text;
    			a[i+1]+=text;
    			res+=text;
    		}
    	}
    }
    cout<<res;
    return 0;
}


