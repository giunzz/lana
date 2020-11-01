#include<iostream>
using namespace std;
long long n,maxx,m50,m1,m2,dem=0,d,a[301],x[4],f,g,h,mol=1e9+9;
void att(int r)
{
    if(r==n+1)
    {
        d=0;
        m50=f;
        m1=g;
        m2=h;
        for(int i=1;i<=n;i++)
        {

            if(a[i]==50)
            {
                m50++;
                if(m50>maxx)
                {
                    d++;
                    break;
                }
            }
            else if(a[i]==1)
            {
                if(m50>=1&&m1+1<=maxx)
                {
                    m1++;
                    m50--;
                }
                else
                {
                    d++;
                    break;
                }
            }
            else if(a[i]==2)
            {
                if(m1>=1&&m50>=1&&m2+1<=maxx)
                {
                    m1--;
                    m50--;
                    m2++;
                }
                else if(m50>=3&&m2+1<=maxx)
                {
                    m50-=3;
                    m2++;
                }
                else
                {
                    d++;
                    break;
                }
            }
        }
        if(d==0) dem++;
        return;
    }
    for(int i=1;i<=3;i++)
    {
        a[r]=x[i];
        att(r+1);
    }


}
int main()
{
    freopen("ICECREAM.INP","r",stdin);
    freopen("ICECREAM.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>maxx>>m50>>m1>>m2;
    f=m50;
    g=m1;
    h=m2;
    x[1]=50;
    x[2]=1;
    x[3]=2;
    att(1);
    cout<<dem%mol;
}
