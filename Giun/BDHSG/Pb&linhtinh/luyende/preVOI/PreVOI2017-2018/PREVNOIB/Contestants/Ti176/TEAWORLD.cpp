#include <bits/stdc++.h>
#define ii pair<int,int>
using namespace std;
int n,m,k;
const int Nmax=1e5+7;
int r1[Nmax],r2[2007][2007],ts1[Nmax],ts2[2007][2007];
bool app1[Nmax];
int xs,ys,zs;
int bfs1()
{
    int x,y,ans=0;
    for (int w=0;w<=k;w++)
    {
        x=w;
        y=k-w;
        int res=0;
        for (int i=xs;i>=0;i--)
        {
            if (x>=0)
            {
                if (app1[i]==false) res+=ts1[i];
                if (app1[i]==true)
                {
                    res+=ts1[i];
                    x--;
                }
            }
        }
        for (int i=xs+1;i<=1000;i++)
        {
            if (y>=0)
            {
                if (app1[i]==false) res+=ts1[i];
                if (app1[i]==true)
                {
                    res+=ts1[i];
                    y--;
                }
            }
        }
        ans=max(ans,res);
    }
    return ans;
}
int main()
{
    freopen("TEAWORLD.inp","r",stdin);
    freopen("TEAWORLD.out","w",stdout);
    cin>>m>>n>>k;
    bool kt1=true,kt2=true;
    for (int i=1;i<=m;i++)
    {
        int x,y,z,r;
        cin>>x>>y>>z>>r;
        if (z!=0) kt2=false;
        if (y!=0&&z!=0) kt1=false;
        r1[x+500]=r;
        app1[x+500]=true;
        r2[x+500][y+500]=r;
    }
    if (kt1==true)
    {
        for (int i=1;i<=n;i++)
        {
            int x,y,z,e;
            cin>>x>>y>>z>>e;
            ts1[x+500]=e;
        }
        cin>>xs>>ys>>zs;
        xs+=500;
        ys+=500;
        zs+=500;
        cout<<bfs1();
    }
    else
    if (kt2==true)
    {
        for (int i=1;i<=n;i++)
        {
            int x,y,z,e;
            cin>>x>>y>>z>>e;
            ts2[x+500][y+500]=e;
        }
        cin>>xs>>ys>>zs;
        xs+=500;
        ys+=500;
        zs+=500;
    }
    return 0;
}
