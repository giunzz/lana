#include<bits/stdc++.h>
#define task "GIFTS"
#define ll long long
#define ff(i,a,b) for(int i=a; i<=b; ++i)
#define fd(i,a,b) for(int i=a; i>=b; --i)
#define rr(i,a,b) for(int i=a; i<b; ++i)
#define rd(i,a,b) for(int i=a; i>b; --i)
#define pb push_back
#define mp make_pair
using namespace std;

const int maxn=1E6+10;

int a[maxn], k, n;
ll L[maxn], R[maxn], s[maxn];

void INIT()
{
	ll sum=0; a[0]=0;
	ff(i, 1, k-1)sum+=1ll*a[i];
	ff(i, k, n)
	{
		sum+=1ll*a[i];
		sum-=1ll*a[i-k];
		s[i]=sum;
	}
	ff(i, 1, n)L[i] = max(L[i-1], s[i]);
	fd(i, n, 1)R[i] = max(R[i+1], s[i]);
	//ff(i, 1, n)cout<<s[i]<<" "; cout<<endl;
}

void READ()
{
	scanf("%d%d",&n,&k);
	ff(i, 1, n)scanf("%d",&a[i]);
}

void SOLVE()
{
	ll gg, res=(ll)1E18;
	ff(i, k, n)
	{
		// neu cam chon o day
		int l=max(1, i-2*k+2), r=min(n, i+k-1);
		gg=max(L[l-1], R[r+1]); //cout<<" chon tu "<<i-k+1<<" den "<<i<<" thi TAM ko dc chon tu "<<l<<" den "<<r<<endl;
		//cout<<" va gg="<<gg<<endl;
		res = min(res, gg);
	}
	cout<<res;
}

int main()
{
	freopen(task".inp","r",stdin);
	freopen(task".out","w",stdout);
	READ();
	INIT();
	SOLVE();
	return 0;
}
