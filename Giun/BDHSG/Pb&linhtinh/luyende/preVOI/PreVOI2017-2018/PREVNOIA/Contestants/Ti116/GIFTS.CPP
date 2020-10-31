#include<bits/stdc++.h>
using namespace std;
ifstream fii("GIFTS.INP");
ofstream fo("GIFTS.OUT");
#define fi first
#define se second
typedef pair<long long,int>pii;
int n,k,c,b,ans,x[1000001];
long long a[1000001];
vector<pii>v;
int main()
{
    fii>>n>>k;
    a[0]=0;
    for(int i=1;i<=n;++i)
    {
        fii>>x[i];
        a[i]=a[i-1]+x[i];
        if(i>k)a[i]-=x[i-k];
        if(i>=k)v.push_back({a[i],i});
    }
    sort(v.begin(),v.end());
    ans=v[v.size()-1].fi+1;
    b=v[v.size()-1].se;
    c=b;
    int i;
    for(int i=0;i<v.size();++i)cout<<v[i].fi<<' '<<v[i].se<<"\n";
    for(i=v.size()-1;i>=0;--i)
    {
        b=max(b,v[i].se);
        c=min(c,v[i].se);
        if(b-c>=k)break;
        if(i>0&&v[i].fi==v[i-1].fi)continue;
        ans=v[i-1].fi;
    }
    fo<<ans;
}
