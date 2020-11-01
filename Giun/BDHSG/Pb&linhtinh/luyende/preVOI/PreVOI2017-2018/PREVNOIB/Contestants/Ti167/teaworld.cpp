#include<bits/stdc++.h>
#define ll long long
using namespace std;
int m,n,k;
const int nmax=1e3+10;
const int base=500;
struct data{int x,y;} a[nmax];
int d[nmax];
int X;
int cl[nmax];


bool cmp(data a1,data a2)
{
    if (X>=a1.x && X<=a1.y) return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("teaworld.inp","r",stdin);
    freopen("teaworld.out","w",stdout);
    cin>>m>>n>>k;
    for (int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v>>v>>v;
        a[i].x=u-v;
        a[i].y=u+v;
    }
    for (int i=1;i<=n+1;i++)
    {
        int u,v;
        cin>>u>>v>>v;
        if (i<=n)
        {
            cin>>v;
            d[u+base]=v;
        }
        else
        {
            X=u;
        }
    }
    sort(a+1,a+m+1,cmp);
    int v1=0;
    for (int i=1;i<=m;i++)
    {
        if (a[i].x<=X && a[i].y>=X) v1++;
        else break;
    }
    if (v1>k)
    {
        for (int i=1;i<=k;i++)
        {
            int id;
            ll gt=0;
            for (int j=1;j<=v1;j++) if (cl[j]==0)
            {
                ll dem=0;
                int l=INT_MIN,r=INT_MAX;
                for (int t=1;t<=v1;t++) if (cl[j]==0 && t!=j)
                {
                    l=max(l,a[t].x);
                    r=min(r,a[t].y);
                }
                if (l==INT_MIN) l=-500;
                if (r==INT_MAX) r=500;
                for (int t=l;t<=r;t++) dem+=d[t+base];
                if (dem>gt)
                {
                    gt=dem;
                    id=j;
                }
            }
            cl[id]=1;
        }
        ll res=0;
        int l=INT_MIN, r=INT_MAX;
        for (int i=1;i<=v1;i++)  if (cl[i]==0)
        {
            l=max(l,a[i].x);
            r=min(r,a[i].y);
        }
        if (l==INT_MIN) l=-500;
        if (r==INT_MAX) r=500;
        for (int i=l;i<=r;i++) res+=d[i+base];
        cout<<res;
    }
    else if (v1==k)
    {
        int l=INT_MIN,r=INT_MAX;
        for (int i=v1+1;i<=m;i++)
        {
            if (a[i].y<X) l=max(l,a[i].y);
            else if (a[i].x>X) r=min(r,a[i].x);
        }
        if (l==INT_MIN) l=-500;
        if (r==INT_MAX) r=500;
        ll res=0;
        for (int i=l;i<=r;i++) res+=d[i+base];
        cout<<res;
    }
    else if (v1<k)
    {
        for (int i=v1+1;i<=k;i++)
        {
            int id;
            ll gt=0;
            for (int j=v1+1;j<=m;j++) if (cl[j]==0)
            {
                ll dem=0;
                int l=INT_MIN,r=INT_MAX;
                for (int t=v1+1;t<=m;t++) if (cl[j]==0 && t!=j)
                {
                    if (a[i].y<X) l=max(l,a[i].y);
                    else if (a[i].x>X) r=min(r,a[i].x);
                }
                if (l==INT_MIN) l=-500;
                if (r==INT_MAX) r=500;
                for (int t=l;t<=r;t++) dem+=d[t+base];
                if (dem>gt)
                {
                    gt=dem;
                    id=j;
                }
            }
            cl[id]=1;
        }
        int l=INT_MIN,r=INT_MAX;
        for (int i=v1+1;i<=m;i++) if (cl[i]==0)
        {
            if (a[i].y<X) l=max(l,a[i].y);
            else if (a[i].x>X) r=min(r,a[i].x);
        }
        if (l==INT_MIN) l=-500;
        if (r==INT_MAX) r=500;
        ll res=0;
        for (int i=l;i<=r;i++) res+=d[i+base];
        cout<<res;
    }
    return 0;
}

