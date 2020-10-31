#include<bits/stdc++.h>
using namespace std;
const int maxn=310;
const long long oo=1e14;
//int dr[]={1,0};
//int dc[]={0,1};
int a[maxn][maxn];
int n,m,k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("TABLE.inp","r",stdin);
    freopen("TABLE.out","w",stdout);
    cin>>m>>n>>k;
    for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
    if( m<=30 && n<=30 && k<=30 )
    {
        for(int id=1;id<=k;id++)
        {
            int f[32][32];
            int u,v,p,q;
            cin>>u>>v>>p>>q;
            int kq=1e9;
            for(int i=u;i<=p;i++) for(int j=v;j<=q;j++)
            {
                if( i==u && j==v ) continue;
                if( i==p && j==q ) continue;
                int remem=a[i][j];
                a[i][j]=0;
                memset(f,0,sizeof f);
                for(int x=u;x<=p;x++) for(int y=v;y<=q;y++) if(a[x][y]!=0) f[x][y]=max(f[x-1][y],f[x][y-1])+a[x][y];
                a[i][j]=remem;
                kq=min(kq,f[p][q]);
            }
            cout<<kq<<"\n";
        }
        return 0;
    }
        long long f[310][310];
        for(int id=1;id<=k;id++)
        {
            int u,v,p,q;
            cin>>u>>v>>p>>q;
            memset(f,0,sizeof f);
            for(int x=u;x<=p;x++) for(int y=v;y<=q;y++) f[x][y]=max(f[x-1][y],f[x][y-1])+  (long long) a[x][y];
            vector<int > kq;
            int coun=0;
            long long sum=f[p][q];
            int x=p,y=q;
            //cout<<sum<<"\n";
            while(sum!=a[u][v])
            {
                if(f[x-1][y]+ (long long) a[x][y]==sum)
                {
                    sum=sum- (long long) a[x][y];
                    x=x-1;
                    kq.push_back(x);kq.push_back(y);
                    //cout<<x<<" "<<y<<" "<<sum<<"\n";
                    //continue;
                }else
                {
                    sum=sum- (long long) a[x][y];
                    y=y-1;
                    kq.push_back(x);kq.push_back(y);
                    //cout<<x<<" "<<y<<" "<<sum<<"\n";
                    //continue;
                }
            }
            long long res=1e14;
            for(int ii=0;ii<kq.size()-2;ii=ii+2)
            {
                int i=kq[ii],j=kq[ii+1];
                //cout<<i<<" "<<j<<"\n";
                int remem=a[i][j];
                a[i][j]=0;
                memset(f,0,sizeof f);
                for(int x=u;x<=p;x++) for(int y=v;y<=q;y++) if(a[x][y]!=0) f[x][y]=max(f[x-1][y],f[x][y-1])+ (long long) a[x][y];
                a[i][j]=remem;
                res=min(res,f[p][q]);
            }
            cout<<res<<"\n";
        }
        return 0;
}
