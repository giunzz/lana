#include <bits/stdc++.h>
using namespace std;
int n,mmax,m50,m1,m2,mod=1e9+9;
int x[17],dem,t1,t2,t3;
void update()
{
    int t1=m50,t2=m1,t3=m2;
    for(int i=1;i<=n;++i)
    {
        if(x[i]==0)
        {
            if(t1<mmax) ++t1;
            else return;
        }
        if(x[i]==1)
        {
            if(t1>0 && t2<mmax) {++t2; --t1;}
            else return;
        }
        if(x[i]==2)
        {
            if(t1>0 && t2>0 && t3<mmax) {++t3; --t1; --t2;}
            else
                if(t1>=3 && t3<mmax) {++t3; t1-=3;}
                else return;
        }
    }
    ++dem;
}
void xaydung(int i)
{
    for(int j=0;j<=2;++j)
    {
        x[i]=j;
        if(i==n) update();
        else xaydung(i+1);
    }
}
void sub1()
{
    xaydung(1);
    cout<<dem;
}
struct data{int x,y,z,d;};
queue<data> q;
void BFS(int t1,int t2,int t3)
{
    q.push({t1,t2,t3,1});
    while(!q.empty())
    {
        t1=q.front().x; t2=q.front().y; t3=q.front().z; int d=q.front().d; q.pop();
        if(d==n) break;
        if(t1<mmax) q.push({t1+1,t2,t3,d+1});
        if(t1>0 && t2<mmax) q.push({t1-1,t2+1,t3,d+1});
        if(t1>0 && t2>0 && t3<mmax) q.push({t1-1,t2-1,t3+1,d+1});
        else if(t1>=3 && t3<mmax) q.push({t1-3,t2,t3+1,d+1});
    }
    dem=(dem+q.size()+1)%mod;
}
main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    freopen("ICECREAM.INP","r",stdin);
    freopen("ICECREAM.OUT","w",stdout);
    cin>>n>>mmax>>m50>>m1>>m2;
    if(n<=15) {sub1(); return 0;}
    if(m50<mmax) BFS(m50+1,m1,m2);
    if(m50>0 && m1<mmax) BFS(m50-1,m1+1,m2);
    if(m50>0 && m1>0 && m2<mmax) BFS(m50-1,m1-1,m2+1);
    else if(m50>=3 && m2<mmax) BFS(m50-3,m1,m2+1);
    cout<<dem;
}
