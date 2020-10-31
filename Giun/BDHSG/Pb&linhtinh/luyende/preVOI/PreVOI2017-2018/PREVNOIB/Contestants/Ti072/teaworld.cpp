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
#define db double
#define F1(i,i1,i2) for(int i=i1;i<=i2;i++)
#define F2(i,i1,i2) for(int i=i1;i>=i2;i--)
#define pb push_back
#define pp pair<int,int>
#define mp make_pair
#define xx first
#define yy second
#define NMAX 17
#define MMAX 2003
const db eps = 1e-10;
struct myst{int x,y,z,re;}ch[NMAX],qc[MMAX];
int m,n,re,k,mut,tvote;
int dem[MMAX];
myst goc;
vector<int> path[NMAX];

void enter()
{
    cin>>m>>n>>k;
    F1(i,1,m)
        cin>>qc[i].x>>qc[i].y>>qc[i].z>>qc[i].re;
    F1(i,1,n)
        cin>>ch[i].x>>ch[i].y>>ch[i].z>>ch[i].re;
    cin>>goc.x>>goc.y>>goc.z;
}

db dis(myst u,myst v)
{
    int x=u.x-v.x;
    int y=u.y-v.y;
    int z=u.z-v.z;
    return (db)sqrt((x*x)+(y*y)+(z*z));
}

db duongcao(db x1,db x2,db x3)
{
    db hcos=(db) x1*x1 + x3*x3 - x2*x2;
    hcos= hcos/(db)(2*x1*x3);
    db h1=x1*hcos;
    x1*=x1;
    h1*=h1;
    x1+=eps;
    db h= sqrt( x1 - h1 );
    return h;
}

//bool catnhau(int u,int v)
//{
//    db x2=dis(ch[u],qc[v]);
//    if (x2<=qc[v].re+eps) return 1;
//
//    db x1=dis(qc[v],goc);
//    db x3=dis(ch[u],goc);
//    db h=duongcao(x1,x2,x3);
//    if (h>qc[v].re+eps) return 0;
//
//    db h1=sqrt( x1*x1 - h*h );
//    db h2=sqrt( x2*x2 - h*h );
//    if (h1+h2>x3+eps) return 0;
//    return 1;
//}

bool catnhau(int u,int v)
{
    db x1=dis(qc[v],goc);
    db x2=dis(ch[u],qc[v]);
    if (x1<=qc[v].re+eps && x2<=qc[v].re+eps) return 0;
    //
    if (x1<=qc[v].re+eps && x2>qc[v].re+eps)return 1;
    if (x1>qc[v].re+eps && x2<=qc[v].re+eps)return 1;
    db x3=dis(ch[u],goc);
    db h=duongcao(x1,x2,x3);
    if (h>qc[v].re+eps) return 0;
    //
    db h1=sqrt( x1*x1 - h*h );
    db h2=sqrt( x2*x2 - h*h );
    if (h1+h2>x3+eps) return 0;
    return 1;
}

void predele()
{
    F1(i,1,n)
        F1(j,1,m)
            if (catnhau(i,j))
                path[i].pb(j);
}

void them(int u)
{
    mut+=ch[u].re;
    if (!path[u].empty())
    F1(i,0,path[u].size()-1)
    {
        int v=path[u][i];
        if (dem[v]==0) tvote++;
        dem[v]++;
    }
}

void loai(int u)
{
    mut-=ch[u].re;
    if (!path[u].empty())
    F1(i,0,path[u].size()-1)
    {
        int v=path[u][i];
        dem[v]--;
        if (dem[v]==0) tvote--;
    }
}

void duyet(int i)
{
    if (tvote>k) return;
    if (i>n)
    {
        re=max(re,mut);
        return;
    }
    F1(j,0,1)
    {
        if (j==1) them(i);
        duyet(i+1);
        if (j==1) loai(i);
    }
}

void solve()
{
    duyet(1);
    cout<<re;
}

main()
{
    ios::sync_with_stdio(0);
    freopen("teaworld.inp","r",stdin);
    freopen("teaworld.out","w",stdout);
    enter();
    predele();
    solve();
}
