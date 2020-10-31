#include <bits/stdc++.h>
#define pb push_back
#define ii pair<int,int>
#define li pair<long long,int>
#define x first
#define y second

using namespace std;

const int N=1e6+2;
const int MOD=1e9+7;
const long long oo=1e18;
const int bm=1;
int n,k,dem;
int d[N];
long long MIN=oo;
long long s[N],f[N],g[N];

void sinh()
{
    freopen(".inp","w",stdout);
    srand(time(0));
}

int main()
{
    ios_base::sync_with_stdio(0);
    //sinh();
    freopen("GIFTS.inp","r",stdin);
    freopen("GIFTS.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>s[i],s[i]+=s[i-1];
    for(int i=1;i<=n;i++)
        if ( i >= k ) f[i]=max(f[i-1],s[i]-s[i-k]);
        else f[i]=max(f[i-1],s[i]);
    for(int i=n;i>0;i--)
        if ( n < i+k-1 ) g[i]=max(g[i+1],s[n]-s[i-1]);
        else g[i]=max(g[i+1],s[i+k-1]-s[i-1]);
    for(int i=k;i<=n;i++)
        MIN=min(MIN,max(f[i-k],g[i+1]));
    cout<<MIN;
}
