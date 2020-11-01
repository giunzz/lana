#include<bits/stdc++.h>
using namespace std;
long long a[302][302];
long long b[302][302];
int x,y,u,v;
long long f[302][302];
long long _min(long long a,long long b)
{
    if(a>b)
        return b;
    return a;
}
long long _max(long long a,long long b)
{
    if(a>b)
        return a;
    else return b;
}
main()
{
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
            b[i][j]=a[i][j];
        }
    }
    while(k--)
    {
        scanf("%d%d%d%d",&x,&y,&u,&v);
        memset(f,0,sizeof(f));
        pair<int,int> tr[302][302];
        long long minn=1e9;
        for(int i=x;i<=u;i++)
        {
            for(int j=y;j<=v;j++)
            {
                if(f[i-1][j]>f[i][j-1])
                {
                    f[i][j]=f[i-1][j]+a[i][j];
                    tr[i][j]={i-1,j};
                }
                else
                {
                    f[i][j]=f[i][j-1]+a[i][j];
                    tr[i][j]={i,j-1};
                }
            }
        }
            int xx,yy;
            xx=tr[u][v].first;
            yy=tr[u][v].second;
            int r;
            while(!(xx==x&&yy==y))
            {

//                cout<<xx<<"  "<<yy<<endl;
                b[xx][yy]=-1e9;
                for(int i=xx;i<=u;i++)
                {
                    for(int j=yy;j<=v;j++)
                    {
                        if(i==1)
                        f[i][j]=f[i][j-1]+b[i][j];
                        else if(j==1)
                        f[i][j]=f[i-1][j]+b[i][j];
                        else
                        f[i][j]=_max(f[i-1][j],f[i][j-1])+b[i][j];
                    }
                }
//                for(int i=x;i<=u;i++)
//                {
//                    for(int j=y;j<=v;j++)
//                        cout<<f[i][j]<<" ";
//                    cout<<endl;
//                }
//                cout<<"f[u][v]: "<<f[u][v]<<endl;
                minn=_min(f[u][v],minn);
                b[xx][yy]=a[xx][yy];

                r=xx;
                xx=tr[xx][yy].first;
                yy=tr[r][yy].second;
//                cout<<endl<<tr[xx][yy].first<<"   "<<tr[xx][yy].second<<"    "<<endl<<endl;

            }
            printf("%lld\n",minn);
        }

    }
/*
3 4 2
5 2 4 2
3 2 6 8
7 8 9 3
1 1 3 4
*/
/*
4 6 1
0 0 9 9 9 9
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
1 1 4 6
*/
