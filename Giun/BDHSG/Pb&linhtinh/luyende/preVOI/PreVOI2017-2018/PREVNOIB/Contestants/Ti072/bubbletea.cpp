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
#define NMAX 10003

int n,k,node,re;
int s[NMAX],cs1[NMAX],vui[NMAX],dem[NMAX];
int d[NMAX][NMAX];
vector<int> cost[NMAX],path[NMAX];

void enter()
{
    cin>>n>>k;
    F1(i,1,k)
        cin>>vui[i];
    int x,y,w;
    F1(i,1,n)
    {
        cin>>x>>y>>w;
        path[x].pb(y);
        cost[x].pb(w);
        path[y].pb(x);
        cost[y].pb(w);
    }
}

void dfs(int u)
{
    if (!path[u].empty())
    F1(i,0,path[u].size()-1)
    {
        int v=path[u][i];
        if (d[node][v]!=-1) continue;
        d[node][v]=d[node][u]+cost[u][i];
        dfs(v);
    }
}

void timduong()
{
    F1(i,1,n)
    {
        node=i;
        F1(j,1,n) d[node][j]=-1;
        d[node][node]=0;
        dfs(node);
    }
}

void tinh()
{
    int x=0;
    F1(i,1,k/2) cs1[i]=0;
    F1(i,1,k)
    {
        int hang=s[i];
        if (cs1[ hang ]==0)
            cs1[ hang ]=i;
        else
        {
            x=max(x,d[ vui[i] ][ vui[cs1[hang]] ] );
        }
    }
    re=min(re,x);
}

void duyet(int i)
{
    if (i>k)
    {
        tinh();
        return;
    }
    F1(j,1,k/2)
    if (dem[j]>0)
    {
        dem[j]--;
        s[i]=j;
        duyet(i+1);
        dem[j]++;
    }
}

void solve()
{
    F1(i,1,k/2) dem[i]=2;
    re=LONG_MAX;
    duyet(1);
    cout<<re;
}

main()
{
    ios::sync_with_stdio(0);
    freopen("bubbletea.inp","r",stdin);
    freopen("bubbletea.out","w",stdout);
    enter();
    timduong();
    solve();
}
