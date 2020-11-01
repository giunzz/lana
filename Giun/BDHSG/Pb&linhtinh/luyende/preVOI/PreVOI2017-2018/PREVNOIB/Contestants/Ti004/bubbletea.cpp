#include <bits/stdc++.h>
#define mp make_pair
#define ll long long
using namespace std;
int n,k,a,b,dem,hot[11],ht[50001],d[50001],cap[11];
ll c,cm,cn,nguong,kq,nhan[11][50001];
vector<pair<int,ll> > ke[50001];
set<pair<ll,int> > S;
bool dx[11],tang_cap;
void nhap()
{
    freopen("bubbletea.inp","r",stdin);
    freopen("bubbletea.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        cin>>a;
        hot[i]=a;
        ht[a]=1;
    }
    cn=LLONG_MAX;
    for(int i=1;i<n;i++)
    {
        cin>>a>>b>>c;
        ke[a].push_back(mp(b,c));
        ke[b].push_back(mp(a,c));
    }
}
void dijkstra(int s,int p)
{
    S.clear();
    for(int i=1;i<=n;i++)
    {
        nhan[p][i]=LLONG_MAX;
        d[i]=0;
    }
    nhan[p][s]=0;
    S.insert(mp(nhan[p][s],s));
    while(S.size()>0)
    {
        pair<ll,int> q=*S.begin();
        S.erase(q);
        int v=q.second;
        for(int i=0;i<ke[v].size();i++)
        {
            int u=ke[v][i].first;
            ll w=ke[v][i].second;
            if(ht[u]==1)
            {
                if(d[v]==0)
                {
                    if(nhan[p][u]>nhan[p][v]+w)
                    {
                        d[u]=1;
                        S.erase(mp(nhan[p][u],u));
                        nhan[p][u]=nhan[p][v]+w;
                        S.insert(mp(nhan[p][u],u));
                    }
                }
            }
            else
            {
                if(nhan[p][u]>nhan[p][v]+w)
                {
                    S.erase(mp(nhan[p][u],u));
                    nhan[p][u]=nhan[p][v]+w;
                    S.insert(mp(nhan[p][u],u));
                }
            }
        }
    }
}
void timcap(int x)
{
    for(int i=1;i<=k;i++)
    {
        if(i==x)
            continue;
        if(nhan[x][hot[i]]!=LLONG_MAX&&nhan[x][hot[i]]<=nguong)
        {
            if(dx[i]==false)
            {
                dx[i]=true;
                if(cap[i]==0)
                {
                    cap[i]=x;
                    ht[x]=i;
                    tang_cap=true;
                    return;
                }
                else
                {
                    timcap(cap[i]);
                    if(tang_cap)
                    {
                        cap[i]=x;
                        ht[x]=i;
                        return;
                    }
                }
            }
        }
    }
}
void xu_li()
{
    for(int i=1;i<=k;i++)
    {
        dijkstra(hot[i],i);
    }
    kq=LLONG_MAX;
    cm=6;
    cn=0;
    while(cn<=cm)
    {
        nguong=(cn+cm)/2;
        memset(cap,0,sizeof(cap));
        dem=0;
        for(int i=1;i<=k;i++)
        {
            tang_cap=false;
            memset(dx,false,sizeof(dx));
            timcap(i);
            if(tang_cap)
                dem++;
        }
        if(dem==k)
        {
            if(nguong<kq)
                kq=nguong;
            cm=nguong-1;
        }
        else
            cn=nguong+1;
    }
    cout<<kq;
}
int main()
{
    nhap();
    xu_li();
}
