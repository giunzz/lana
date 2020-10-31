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
void io()
{
    freopen("GIFTS.inp","r",stdin);
    freopen("GIFTS.out","w",stdout);
}
int n,k;
long long a[1000002],s[1000002];
long long max_n_[1000002],max_1_[1000002];
long long res=1e18;
int main()
{
    #ifndef Mirai
        io();
    #endif //Mirai
    scanf("%d%d",&n,&k);
    ft(i,1,n) scanf("%lld",&a[i]);
    ft(i,1,n) s[i]=s[i-1]+a[i];
    ft(i,1,n)
    	if(i>=k) max_1_[i]=max(max_1_[i-1],s[i]-s[i-k]);
    ftd(i,n,1)
    {
    	if(i+k-1<=n)
    		max_n_[i]=max(max_n_[i+1],s[i+k-1]-s[i-1]);
    }
    //ft(i,1,n) cout<<max_1_[i]<<" "<<max_n_[i]<<"\n";
    ft(i,1,n)
    {
    	if(i+k-1>n) continue;
    	if(s[i+k-1]-s[i-1]>=max_1_[i-1] and s[i+k-1]-s[i-1]>=max_n_[i+k])
    	{
    		//cout<<i+k-1<<" "<<i<<"\n";
    		res=min(res,s[i+k-1]-s[i-1]);
    		//cout<<res<<" "<<i<<" "<<i+k-1<<"\n";
    	}
    }
    cout<<res;
    return 0;
}

/*
20 5
1 2 3 7 4 5 6 7 9 10 11 12 14 15 16 17 18 19 52 21
*/
/*
10 2
1 2 4 5 2 4 2 2 1 6
*/
