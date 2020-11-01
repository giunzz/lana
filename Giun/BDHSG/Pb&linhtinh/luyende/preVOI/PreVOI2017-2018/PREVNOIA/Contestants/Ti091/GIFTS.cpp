#include<bits/stdc++.h>
#define mn 100005
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORE(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
long long n,k,a[mn],s[mn],kq,d,c,g;
struct dt
{
    int x,cs;
};
dt b[mn];
bool cmp(dt i,dt j)
{
    return i.x<j.x;
}
int kt(int g)
{
    FOR(i,g,n)
    if((b[i].x>b[g].x)&&(abs(b[i].cs-b[g].cs)>=k)) return 0;
    return 1;
}
void nhap()
{
    cin>>n>>k;
    FOR(i,1,n)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    n=n-k+1;
    FOR(i,1,n)
    {
        b[i].x=s[i+k-1]-s[i-1];
        b[i].cs=i;
    }
    sort(b+1,b+n+1,cmp);
    d=1,c=n;
    while(d<=c)
    {
       g=(d+c)/2;
        if(kt(g))
        {
            kq=b[g].x;
            c=g-1;
        }
        else d=g+1;
    }
    cout<<kq;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("GIFTS.inp","r",stdin);
    freopen("GIFTS.out","w",stdout);
    nhap();
    return 0;
}
