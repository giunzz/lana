#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define se second
using namespace std;
int m,n,dem,cnt,ans[6006],tg[6006],k;
pair<int,int> a[3003],b[3003],d1[6006],d2[6006];
bool ok=0;
void test()
{
    freopen("sequence.inp","w",stdout);
    m=10,n=10,k=10;
    cout<<m<<" "<<n<<" "<<k<<'\n';
    For(i,1,m) cout<<rand()%m+1<<" ";
    cout<<'\n';
    For(i,1,n) cout<<rand()%n+1<<" ";
    cout<<'\n';
}
bool cmp(pair<int,int>a,pair<int,int>b)
{
    if(a.fi==b.fi) return a.se>b.se;
    return a.fi<b.fi;
}
void special()
{
    if(m>=k)
    {
        For(i,1,k) d1[i]={a[i].se,a[i].fi};
        sort(d1+1,d1+k+1);
        For(i,1,k) ans[i]=d1[i].se;
        ok=1;
    }
    if(n>=k)
    {
        For(i,1,k) d1[i]={b[i].se,b[i].fi};
        sort(d1+1,d1+k+1);
        if(ok)
        {
            For(i,1,k)
            if(ans[i]>d1[i].se)
            {
                For(j,1,k) ans[j]=d1[j].se;
                break;
            }
            else if(d1[i].se>ans[i]) break;
        }
        else
        {
            For(i,1,k) ans[i]=d1[i].se;
            ok=1;
        }
    }
}
void check()
{
//    For(j,1,k) cout<<ans[j]<<" ";
//    cout<<'\n';
//    For(j,1,k) cout<<tg[j]<<" ";
//    cout<<"\n\n";
    if(ok)
    {
        For(j,1,k)
        if(ans[j]>tg[j])
        {
            For(p,1,k) ans[p]=tg[p];
            return;
        }
        else if(tg[j]>ans[j]) return;
    }
    For(j,1,k) ans[j]=tg[j];
    ok=1;
}
void trau()
{
    sort(a+1,a+m+1,cmp);
    sort(b+1,b+n+1,cmp);
    special();
    For(t,1,k-1)
    {
        int x=t;
        int y=k-t;
        if(x>m) break;
        if(y>n) continue;
        For(i,1,x) d1[i]={a[i].se,a[i].fi};
        For(i,1,y) d2[i]={b[i].se,b[i].fi};
        sort(d1+1,d1+x+1);
        sort(d2+1,d2+y+1);
        For(i,0,y)
        {
            dem=0;cnt=0;
            For(j,1,i)
                tg[j]=d2[++dem].se;
            For(j,i+1,i+x)
                tg[j]=d1[++cnt].se;
            For(j,i+x+1,k)
                tg[j]=d2[++dem].se;
            check();
        }

    }
    For(i,1,k) cout<<ans[i]<<" ";
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    //test();
    freopen("sequence.inp","r",stdin);
    freopen("sequence.out","w",stdout);
    cin>>m>>n>>k;
    For(i,1,m) cin>>a[i].fi,a[i].se=i;
    For(i,1,n) cin>>b[i].fi,b[i].se=i;
    trau();
}
