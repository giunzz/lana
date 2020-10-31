#include<bits/stdc++.h>
using namespace std;

#define FOR(i,x,n) for(int i=x;i<=n;i++)
#define REP(i,x) for(int i=0;i<x;i++)
#define ii pair < int , int >
#define iii pair < int , ii >
#define iv pair < ii , ii >
#define fi first
#define se second
#define fr front()
#define t top()
#define pb push_back
#define pp pop_back
#define lli long long int
#define li long int
#define ld long double
#define vi vector<int>
#define vii vector<ii>
#define viii vector<iii>
#define viv vector<iv>
#define qi queue<int>
#define qii queue<ii>
#define qiii queue<iii>
#define qiv queue<iv>
#define sii stack<ii>
#define oo 999999999
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define eps 1e-9

//PLEASE DON'T HACK IT 😞

const int N=2005;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1},n,k,x,y,c[N][N],f[N][N],Max;
queue<ii> q;

void BFS()
{
    while(!q.empty())
    {
        int i = q.fr.fi;
        int j = q.fr.se;
        q.pop();
        REP(s,4)
        {
            int u=i+dx[s];
            int v=j+dy[s];
            if(u<=2000 && u>=0 && v>=0 && v<=2000 )
            {
                if(c[u][v]>1e7)
                {
                    c[u][v]=c[i][j]+1;
                    q.push(ii(u,v));
                }
            }
        }
    }
}

void BFSS()
{
    f[x][y]=0;
    while(!q.empty())
    {
        int i = q.fr.fi;
        int j = q.fr.se;
        q.pop();
        if(f[i][j]>k)
        {
            cout<<Max;
            exit(0);
        }
        if(Max<c[i][j])
            Max=c[i][j];
        REP(s,4)
        {
            int u=i+dx[s];
            int v=j+dy[s];
            if(u<=2000 && u>=0 && v>=0 && v<=2000 )
            {
                if(f[u][v]>1e7)
                {
                    f[u][v]=f[i][j]+1;
                    q.push(ii(u,v));
                }
            }
        }
    }
}

int main()
{
    freopen("ROBOTS.inp","r",stdin);
    freopen("ROBOTS.out","w",stdout);
    fast
    cin>>n>>k;
    memset(c,0x1f,sizeof(c));
    memset(f,0x1f,sizeof(f));
    FOR(i,1,n)
    {
        cin>>x>>y;
        x+=1000;y+=1000;
        q.push(ii(x,y));
        c[x][y]=0;
    }
    BFS();
    cin>>x>>y;
    x+=1000;y+=1000;
    q.push(ii(x,y));
    BFSS();
    //cout<<np();
}
