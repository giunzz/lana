#include<bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(a,b) for(auto &a:b)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define reset(f,x) memset(f,x.sizeof(f))
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
using namespace std;
const int N=3010;
int n,m,k,a[N],b[N],dd1[N],dd2[N],l1,l2,ok,dd[N][N];
vector<pii> sv;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("SEQUENCE.inp","r",stdin);
    freopen("SEQUENCE.out","w",stdout);
    cin>>m>>n>>k;
    forinc(i,1,m) cin>>a[i];
    forinc(i,1,n) cin>>b[i];
    forinc(t,1,k)
    {
        pii tg1={2e9,0};
        pii tg2={2e9,0};
        fordec(i,m,1) if(!dd1[i]&&a[i]<=tg1.fi&&i>l1&&m-i+n-l2>=k-t) tg1={a[i],i};
        fordec(i,n,1) if(!dd2[i]&&b[i]<=tg2.fi&&i>l2&&m-l1+n-i>=k-t) tg2={b[i],i};
        cout<<min(tg1.fi,tg2.fi)<<" ";
        if(tg1.fi<tg2.fi||(tg1.fi==tg2.fi&&tg1.se-l1<tg2.se-l2)) dd1[tg1.se]=1,l1=tg1.se;
        else dd2[tg2.se]=1,l2=tg2.se;
        if(m-l1+n-l2==k-t) {ok=1;break;}
    }
    sv.pb({l1,l2});
    dd[l1-1][l2-1]=1;
    if(ok) forinc(Q,1,m-l1+n-l2)
    {
        int mi=1e9;
        forv(x,sv)
        {
            if(x.fi<m) mi=min(mi,a[x.fi+1]);
            if(x.se<n) mi=min(mi,b[x.se+1]);
        }
        cout<<mi<<" ";
        vector<pii> nv;
        forv(x,sv)
        {
            if(x.fi<m&&a[x.fi+1]==mi&&!dd[x.fi+1][x.se])
            {
                nv.pb({x.fi+1,x.se});
                dd[x.fi+1][x.se]=1;
            }
            if(x.se<n&&b[x.se+1]==mi&&!dd[x.fi][x.se+1])
            {
                nv.pb({x.fi,x.se+1});
                dd[x.fi][x.se+1]=1;
            }
        }
        sv=nv;
    }
}
