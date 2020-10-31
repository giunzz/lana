#include<bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(a,b) for(auto &a:b)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
using namespace std;
const int N=110;
int n,del,a[N],b[N],f[N][N][N],kq;
struct oo {int i,j,k;};
vector<int> trc[N][N][N];
vector<int> e;
map<int,int> ht;
bool ss(vector<int> u,vector<int> v)
{
    if(u.size()!=v.size()) return u.size()>v.size();
    if(u.empty()) return 0;
    forinc(i,0,u.size()-1) if(a[u[i]]!=a[v[i]]) return a[u[i]]>a[v[i]];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("LIONDANCE.inp","r",stdin);
    freopen("LIONDANCE.out","w",stdout);
    cin>>n>>del;
    forinc(i,1,n) cin>>a[i];
    forinc(i,1,n) cin>>b[i];
    f[0][0][0]=1;
    forinc(i,0,n) forinc(j,0,n) forinc(t,0,n) if(f[i][j][t])
    {
        vector<int> pre=trc[i][j][t];
        if(a[i]==b[j]&&a[i]==a[t]&&pre.size()<f[i][j][t]-1) pre.pb(t);
        if(f[i+1][j][t]<f[i][j][t]) f[i+1][j][t]=f[i][j][t],trc[i+1][j][t]=pre;
        else if(f[i+1][j][t]==f[i][j][t]&&ss(pre,trc[i+1][j][t])) trc[i+1][j][t]=pre;
        if(f[i][j+1][t]<f[i][j][t]) f[i][j+1][t]=f[i][j][t],trc[i][j+1][t]=pre;
        else if(f[i][j+1][t]==f[i][j][t]&&ss(pre,trc[i][j+1][t])) trc[i][j+1][t]=pre;
        if(a[i+1]==b[j+1]&&(!t||abs(a[i+1]-a[t])<=del))
        {
            if(f[i+1][j+1][i+1]<f[i][j][t]+1) f[i+1][j+1][i+1]=f[i][j][t]+1,trc[i+1][j+1][i+1]=pre;
            else if(f[i+1][j+1][i+1]==f[i][j][t]+1&&ss(pre,trc[i+1][j+1][i+1])) trc[i+1][j+1][i+1]=pre;
        }
        kq=max(kq,f[i][j][t]);
    }
    cout<<kq-1<<"\n";
    vector<int> ans;
    forinc(i,0,n) forinc(j,0,n) forinc(t,0,n) if(f[i][j][t]==kq&&a[i]==b[j]&&a[i]==a[t])
    {
        vector<int> tg=trc[i][j][t];
        tg.pb(i);
        if(ss(tg,ans)) ans=tg;
    }
    forv(x,ans) if(x!=0) cout<<a[x]<<" ";
}
