#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int m,n,k,a[303][303],u,v,p,q,res,x,y;
int f[303][303],kq=1e15;
void test()
{
    freopen("table.inp","w",stdout);
    srand(time(NULL));
    m=15,n=15,k=10;
    cout<<m<<" "<<n<<" "<<k<<'\n';
    For(i,1,m)
    {
        For(j,1,n)
            cout<<rand()%(m*n)+1<<" ";
        cout<<'\n';
    }
    while(k--)
    {
        x=rand()%(m/2)+1,y=rand()%(n/2)+1;
        p=x+rand()%(m-x+1),q=y+rand()%(n-y+1);
        cout<<x<<" "<<y<<" "<<p<<" "<<q<<'\n';
    }
}
void reset()
{
    For(i,1,m)
    For(j,1,n)
        f[i][j]=0;
}
void trace(int x,int y)
{
    int i=p,j=q;
    res=x=y=0;
    while(i>=u+x&&j>=v+y)
    {
        if(f[i][j]==f[i-1][j]+a[i][j])
        {
            if(!(i==u&&j==v)&&!(i==p&&j==q))
            {
                if(res<a[i][j])
                {
                    res=a[i][j];
                    x=i,y=j;
                }
            }
            i--;
        }
        if(f[i][j]==f[i][j-1]+a[i][j])
        {
            if(!(i==u&&j==v)&&!(i==p&&j==q))
            {
                if(res<a[i][j])
                {
                    res=a[i][j];
                    x=i,y=j;
                }
            }
            j--;
        }
    }
}
void check(int x,int y)
{
    reset();
    int tg=a[x][y];
    a[x][y]=0;
    For(i,u,p)
        For(j,v,q)
            f[i][j]=max(f[i][j],max(f[i-1][j],f[i][j-1]))+a[i][j];
    kq=min(kq,f[p][q]);
    a[x][y]=tg;
}
void trau()
{
    reset();
    For(i,u,p)
        For(j,v,q)
            f[i][j]=max(f[i][j],max(f[i-1][j],f[i][j-1]))+a[i][j];
    kq=f[p][q];
    For(i,u,p)
    For(j,v,q)
    {
       if(!(i==u&&j==v)&&!(i==p&&j==q))
        check(i,j);
    }
    cout<<kq<<'\n';
}
int main()
{
    //test();
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);
    cin>>m>>n>>k;
    For(i,1,m)
    For(j,1,n)
        cin>>a[i][j];
    while(k--)
    {
        cin>>u>>v>>p>>q;
        //xl();
        trau();
    }
}
