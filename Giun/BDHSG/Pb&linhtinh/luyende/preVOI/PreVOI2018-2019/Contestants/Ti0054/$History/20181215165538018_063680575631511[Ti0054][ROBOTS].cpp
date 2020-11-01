#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int maxn=1e4+2;
int n,m,U,V;
pair<int,int> a[maxn];
int mx;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1},dd[2002][2002];
typedef pair<int,int> ii;
queue<ii> q;
map<ii,int> dd2;
inline void read(int &x)
{
    char c;
    bool kt=0;
    for(c=getchar();!isdigit(c);c=getchar())
        if(c=='-') kt=1;
    x=c-'0';
    for(c=getchar();isdigit(c);c=getchar())
        x=x*10+c-'0';
    if(kt) x=-x;
}
void BFS1(int u,int v)
{
    dd[u][v]=1;
    q.push({u,v});
    while(!q.empty())
    {
        u=q.front().F; v=q.front().S; q.pop();
        if(dd[u][v]==m+2) break;
        int mn=INT_MAX;
        for(int i=1;i<=n;++i) mn=min(mn,abs(u-a[i].F)+abs(v-a[i].S));
        mx=max(mx,mn);
        for(int i=0;i<=3;++i)
        {
            int uu=u+dx[i],vv=v+dy[i];
            if(uu<0 || uu>2e3 || vv<0 || vv>2e3) continue;
            if(!dd[uu][vv])
            {
                dd[uu][vv]=dd[u][v]+1;
                q.push({uu,vv});
            }
        }
    }
}
void BFS2(int u,int v)
{
    dd2[{u,v}]=1;
    q.push({u,v});
    while(!q.empty())
    {
        u=q.front().F; v=q.front().S; q.pop();
        if(dd2[{u,v}]==m+2) break;
        int mn=INT_MAX;
        for(int i=1;i<=n;++i) mn=min(mn,abs(u-a[i].F)+abs(v-a[i].S));
        mx=max(mx,mn);
        cout<<u<<' '<<v<<'\n';
        for(int i=0;i<=3;++i)
        {
            int uu=u+dx[i],vv=v+dy[i];
            if(!dd2[{uu,vv}])
            {
                dd2[{uu,vv}]=dd2[{u,v}]+1;
                q.push({uu,vv});
            }
        }
    }
}
main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    freopen("ROBOTS.INP","r",stdin);
    freopen("ROBOTS.OUT","w",stdout);
    read(n); read(m);
    bool kt=1;
    for(int i=1;i<=n;++i)
    {
        read(a[i].F); read(a[i].S);
        if(abs(a[i].F)>1e3 || abs(a[i].S)>1e3) kt=0;
    }
    read(U); read(V);
    if(kt)
    {
        for(int i=1;i<=n;++i) {a[i].F+=1e3; a[i].S+=1e3;}
        U+=1e3; V+=1e3;
        BFS1(U,V);
        cout<<mx;
        return 0;
    }
    //if(n<=300 && m<=300)
    {
        BFS2(U,V);
        cout<<mx;
        return 0;
    }
}
