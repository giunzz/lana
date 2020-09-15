#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int n,k,b[300001];
bool ok[300001];
struct cap
{
    long long x,y;
}a[30001];
bool cmd(const cap &u,const cap &v)
{
    return u.x<v.x;
}
void xuli()
{
    int vt=0;
    long long t=0;
    for(int i=1;i<=k;i++)
    {
        long long maxx=-1;
        for(int j=1;j<=n;j++)
            if(!ok[j])
            {
                if(a[j].x<=b[i])
                {
                    if(maxx<a[j].y)
                    {
                        maxx=a[j].y;
                        vt=j;
                    }
                }
                else break;
            }
        ok[vt]=true;
        t+=maxx;
    }
    cout<<t;
}
int main()
{
    freopen("vanchuyen.inp","r",stdin);
    freopen("vanchuyen.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i].x>>a[i].y;
    for(int i=1;i<=k;i++)
        cin>>b[i];
    sort(a+1,a+1+n,cmd);
    sort(b+1,b+1+k);
    xuli();
    return 0;
}
