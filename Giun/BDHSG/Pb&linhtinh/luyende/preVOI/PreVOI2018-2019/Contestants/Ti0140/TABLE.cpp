#include <bits/stdc++.h>

using namespace std;

int d[10005],m,n,k,a[305][305],f[305][305],u,v,p,q;

void input()
{
    cin>>m>>n>>k;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    }
}

void solve()
{
    for(int Mask=1;Mask<=k;Mask++)
    {
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                f[i][j]=0;
            }
        }
        cin>>u>>v>>p>>q;
        int min1=0;
        int x=0;
        int y=0;
        int e=0;
        for(int i=u;i<=p;i++)
        {
            for(int j=v;j<=q;j++)
            {
                if(((i!=u)||(j!=v))&&((i!=p)||(j!=q)))
                {
                    if(a[i][j]>min1)
                    {
                        x=i;
                        y=j;
                        min1=a[i][j];
                    }
                }
            }
        }
        e=a[x][y];
        a[x][y]=0;
        for(int i=u;i<=p;i++)
        {
            for(int j=v;j<=q;j++)
            {
                f[i][j]=max(f[i-1][j],f[i][j-1])+a[i][j];
            }
        }
        cout<<f[p][q]<<"\n";
//        int i=p;
//        int j=q;
//        int k=0;
        //d[k]=a[i][j];
//        int tong=f[i][j];
//        while(tong!=0)
//        {
//            int x=tong-a[i][j];
//            if(x==f[i][j-1])
//            {
//                k++;
//                d[k]=a[i][j];
//                tong-=a[i][j];
//                j--;
//            }
//            else
//            {
//                k++;
//                d[k]=a[i][j];
//                tong-=a[i][j];
//                i--;
//            }
//        }
        a[x][y]=e;
    }
}
int main()
{
    freopen("TABLE.INP","r",stdin);
    freopen("TABLE.OUT","w",stdout);
    input();
    solve();
    return 0;
}
