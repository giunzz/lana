#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <queue>
#include <string>
#include <set>
#include <deque>

using namespace std;
#define int long long
#define uint unsigned long long
#define F1(i,i1,i2) for(int i=i1;i<=i2;i++)
#define F2(i,i1,i2) for(int i=i1;i>=i2;i--)
#define pb push_back
#define pp pair<int,int>
#define mp make_pair
#define xx first
#define yy second
#define NMAX 5003

int n,a[NMAX],s,node,fl,re,x,du;
pp Q[NMAX];
int F[NMAX],sum;
int da[NMAX],ddem,kq;

int readint()
{
    char c;
    do c=getchar();
    while (c<'0'||c>'9');
    int re=0;
    while (c>='0'&&c<='9')
    {
        re=re*10+c-'0';
        c=getchar();
    }
    return re;
}

void enter()
{
    n=readint();
    F1(i,1,n)
    {
        a[i]=readint();
        s+=a[i];
    }
    fl=s/n;
}

void xep(int u,int v)
{
    node++;
    Q[node].xx=u;
    Q[node].yy=v;
    if (du) sum+=v;
    else sum-=v;
}

void chuyenden(int u,int v)
{
    while (node>0 && v>0)
    {
        int x=min(v,Q[node].yy);
        v-=x;
        Q[node].yy-=x;
        re+=x*abs(Q[node].xx-u);
        if (Q[node].yy==0) node--;
    }
    if (v>0)
    {
        du=0;
        xep(u,v);
    }
}

void chuyendi(int u,int v)
{
    while (node>0 && v>0)
    {
        int x=min(v,Q[node].yy);
        v-=x;
        Q[node].yy-=x;
        re+=x*abs(Q[node].xx-u);
        if (Q[node].yy==0) node--;
    }
    if (v>0)
    {
        du=1;
        xep(u,v);
    }
}

void solve()
{
    F1(i,1,n)
    {
        if (a[i]<fl)
        {
            if (du) chuyenden(i,fl-a[i]);
            else xep(i,fl-a[i]);
        }
        if (a[i]>fl)
        {
            if (du) xep(i,a[i]-fl);
            else chuyendi(i,a[i]-fl);
        }
    }
    cout<<re;
}

void tinh()
{
    re=0;
    node=0;
    F1(i,1,n)
    {
        if (a[i]<da[i])
        {
            if (du) chuyenden(i,da[i]-a[i]);
            else xep(i,da[i]-a[i]);
        }
        if (a[i]>da[i])
        {
            if (du) xep(i,a[i]-da[i]);
            else chuyendi(i,a[i]-da[i]);
        }
    }
    kq=min(kq,re);
}

void duyet(int i)
{
    if (i>n)
    {
        if (ddem==(s-n*fl)) tinh();
        return;
    }
    F1(j,fl,fl+1)
    {
        if (j==fl+1) ddem++;
        da[i]=j;
        duyet(i+1);
        da[i]=0;
        if (j==fl+1) ddem--;

    }
}

void solve2()
{
    kq=LONG_MAX;
    duyet(1);
    cout<<kq;
}

main()
{
    ios::sync_with_stdio(0);
    freopen("arrange.inp","r",stdin);
    freopen("arrange.out","w",stdout);
    enter();
    if (s%n==0) solve();
    else solve2();
}
