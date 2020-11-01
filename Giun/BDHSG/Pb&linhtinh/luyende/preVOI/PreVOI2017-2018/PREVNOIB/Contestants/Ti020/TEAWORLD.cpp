#include <iostream>
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define filename "TEAWORLD."
using namespace std;
typedef pair<int,int> ii;
int n,m,k;
int xx,y,z,sz;
vector<ii> TS;
vector<ii> A;
vector<int> QC;
int dd[1005];
struct iii
{
    int f,s,t;
};
void io()
{
    freopen(filename"INP","r",stdin);
    freopen(filename"OUT","w",stdout);
}
int getbit(int x,int k)
{
    return (x>>(k-1))&1;
}
main()
{
    io();
    scanf("%d%d%d",&m,&n,&k);
   // cin>>m>>n>>k;

    for(int i=0;i<=1000;i++) dd[i]=-1;
    FOR(i,1,m)
    {
        int a,b,c,d;
         scanf("%d%d%d%d",&a,&b,&c,&d);
       // cin>>a>>b>>c>>d;
        a+=500;
        dd[a]=0;
    }
    FOR(i,1,n)
    {
        int a,b,c,d;
         scanf("%d%d%d%d",&a,&b,&c,&d);
      //  cin>>a>>b>>c>>d;
         a+=500;
        dd[a]=d;
        TS.push_back(ii(a,d));
    }
    sort(TS.begin(),TS.end());
    cin>>xx>>y>>z;
    xx+=500;
    int sz=(1<<n)-1;
    int res=0;
    for(int x=1;x<=sz;x++)
    {
        FOR(i,0,TS.size()-1) dd[TS[i].first]=TS[i].second;
        int ans=0;
        int kk=0;
        int maxx=0,minn=1e5;
       FOR(i,1,n)
        {
            if(getbit(x,i)==0) dd[TS[n-i].first]=-1;
            else if(getbit(x,i)>0) {
                    maxx=max(maxx,TS[n-i].first);
            minn=min(minn,TS[n-i].first);
            }
        }
        for(int i=xx;i<=maxx;i++)
        {
            if(dd[i]>=1) ans+=dd[i];
            else if(dd[i]==0) kk++;
            else continue;
        }
        for(int i=xx;i>=minn;i--)
        {
            if(dd[i]>=1) ans+=dd[i];
            else if(dd[i]==0) kk++;
            else continue;
        }

       if(kk<=k) res=max(res,ans);
    }
    cout<<res<<endl;
}
