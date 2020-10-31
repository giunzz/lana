#include <bits/stdc++.h>
#define maxn 5000

using namespace std;
struct bg {int gt,cs;} c[maxn],tg;
long long n,dt,r[maxn],l[maxn],d[maxn],tv[maxn],maxx,q;
bool kt[maxn];
void nhap()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("LIONDANCE.inp","r",stdin);
    freopen("LIONDANCE.out","w",stdout);
    cin>>n>>dt;
    maxx=0;
    for (int i=1;i<=n;i++) {cin>>l[i];kt[i]=true;d[i]=0;tv[0]=0;}
    for (int i=1;i<=n;i++) cin>>r[i];
    c[0].gt=0;
}
void xuly()
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            if (r[i]==l[j]&&kt[j]) {c[i].gt=l[j];c[i].cs=j;kt[j]=false;break;}
            c[i].cs=0;
        }
    for (int i=2;i<=n;i++)
        for (int j=1;j<=i;j++)
    {
        if (c[j].cs<c[i].cs&&abs(c[i].gt-c[j].gt)<=dt)
        {
            if (d[i]<d[j]+1) {d[i]=d[j]+1;tv[i]=j;}
            if (d[i]==d[j]+1)
            {
            if (c[tv[i]].gt<c[j].gt) {tv[i]=j;}
            }
        }
    }
    for (int i=1;i<=n;i++)
    {
        if (d[i]>maxx) {maxx=d[i];q=i;}
    }
    cout<<maxx<<' '<<q<<endl;
    vector <int> w;
    while (q!=0)
    {
        w.push_back(c[q].gt);
        q=tv[q];
    }
    while (!w.empty())
    {
        cout<<w.back()<<' ';
        w.pop_back();
    }
}
int main()
{
    nhap();
    xuly();
    return 0;
}
