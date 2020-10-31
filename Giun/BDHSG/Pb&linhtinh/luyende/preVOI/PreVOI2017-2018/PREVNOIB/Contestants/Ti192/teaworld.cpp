#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define FORD(i,a,b) for (int i=a; i<b; i++)
int x[2025],y[2025],z[2025],e[2025];
int m,n,k,s[20],dx[2001],kq,xs,ys,zs;
vector<int>v[20];
void xuli()
{
    int S=0; int d=0;
    FOR(i,1,m) dx[i]=0;
    FOR(i,1,n)
        if (s[i]==1)
        {
            S+=e[i+m];
            FORD(j,0,v[i].size())
                dx[v[i][j]]=1;
        }
    FOR(i,1,m)
        if (dx[i]==1) d++;
    if (d<=k) kq=max(kq,S);
}
void Try(int i)
{
    s[i]=0;
    if (i<n) Try(i+1);
    else xuli();

    s[i]=1;
    if (i<n) Try(i+1);
    else xuli();
    s[i]=0;
}
int main()
{
    freopen("teaworld.inp","r",stdin);
    freopen("teaworld.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n >> k;
    int K=0;
    FOR(i,1,m)
    {
        cin >> x[i] >> y[i] >> z[i] >> e[i];
        if (y[i]!=0 || z[i]!=0) K=1;
    }
    FOR(i,1,n)
    {
        cin >> x[m+i] >> y[m+i] >> z[m+i] >> e[m+i];
        if (y[m+i]!=0 || z[m+i]!=0) K=1;
    }
    cin >> xs >> ys >> zs;
    if (K==0 && ys==0 && zs==0)
    {
        FOR(i,1,n)
        {
            if (x[i+m]==xs) continue;
            if (x[i+m]<xs)
            {
                FOR(j,1,m)
                {
                    if (x[j]-e[j]>xs) continue;
                    if (x[j]+e[j]<x[i+m]) continue;
                    if (x[j]-e[j]<=x[i+m] && x[j]+e[j]>=xs) continue;
                    v[i].push_back(j);
                }
            }
            if (x[i+m]>xs)
            {
                FOR(j,1,m)
                {
                    if (x[j]-e[j]>x[i+m]) continue;
                    if (x[j]+e[j]<xs) continue;
                    if (x[j]-e[j]<=xs && x[j]+e[j]>=x[i+m]) continue;
                    v[i].push_back(j);
                }
            }
        }
        Try(1);
        cout << kq;
        return 0;
    }
    FOR(i,1,n)
    {
        int x1=x[i+m];
        int y1=y[i+m];
        FOR(j,1,m)
        {
            FOR(p,1,1000)
            {
                if (p>xs+x1 || p>ys+y1) break;
                if ((xs+x1)%p==0 && (ys+y1)%p==0)
                {
                    int xx=(xs+x1)/p;
                    int yy=(ys+y1)/p;
                    if ((xx-x[j])*(xx-x[j])+(yy-y[j])*(yy-y[j])<=e[j]*e[j])
                    {
                        v[i].push_back(j);
                        break;
                    }
                }
            }
        }
    }
    Try(1);
    cout << kq;
}
