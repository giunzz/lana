#include<bits/stdc++.h>
#define pii pair<int, int>
#define ppii pair<pii, pii>
#define vi vector<int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define F1(i, a, b) for(int i=(int)a; i<=(int)b; i++)
#define F2(i, a, b) for(int i=(int)a; i>=(int)b; i--)
#define maxm 300
#define maxk 300
#define oo 100000000000000000
using namespace std;
template<typename T>
void read(T& x)
{
    x = 0; T f = 1;
    char ch = getchar();
    while (!isdigit(ch)) f = ch == '-' ? - f : f, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    x *= f;
}
int m, n, k, a[maxm+1][maxm+1], u, v, p, q, dx[2]={-1, 0}, dy[2]={0, -1}, cnt[maxm+1][maxm+1];
ll dp[maxm+1][maxm+1], tmax, tmax1;
pii trace[maxm+1][maxm+1], res;
queue<pii> qu;
void input()
{
    cin>>m>>n>>k;
    F1(i, 1, m)
    {
        F1(j, 1, n)
        {
            cin>>a[i][j];
        }
    }
}
bool check(int x2, int y2)
{
    return (u<=x2&&x2<=p&&v<=y2&&y2<=q);
}
void solve()
{
    int x2, y2, x3, y3;
    dp[u][v]=a[u][v];
    cnt[u][v]=0;
    trace[u][v]={-1, -1};
    F1(i, u+1, p)
    {
        cnt[i][v]=0;
        dp[i][v]=dp[i-1][v]+(ll)a[i][v];
        trace[i][v].fi=0;
        trace[i][v].se=-1;
    }
    F1(i, v+1, q)
    {
        cnt[u][i]=0;
        dp[u][i]=dp[u][i-1]+(ll)a[u][i];
        trace[u][i].fi=1;
        trace[u][i].se=-1;
    }
    F1(i, u+1, p)
    {
        F1(j, v+1, q)
        {
            cnt[i][j]=0;
            dp[i][j]=-oo;
            trace[i][j]={-1, -1};
            F1(i1, 0, 1)
            {
                x2=i+dx[i1]; y2=j+dy[i1];
                if(!check(x2, y2)) continue;
                if(dp[x2][y2]+(ll)a[i][j]==dp[i][j])
                {
                    if(trace[i][j].fi==-1) trace[i][j].fi=i1;
                    else trace[i][j].se=i1;
                }
                if(dp[x2][y2]+(ll)a[i][j]>dp[i][j])
                {
                    dp[i][j]=dp[x2][y2]+(ll)a[i][j];
                    trace[i][j].fi=i1;
                    trace[i][j].se=-1;
                }
            }
        }
    }
    cnt[p][q]=1;
    while(!qu.empty()) qu.pop();
    qu.push({p, q});
    while(!qu.empty())
    {
        x2=qu.front().fi;
        y2=qu.front().se;
        qu.pop();
        if(trace[x2][y2].fi!=-1)
        {
            x3=x2+dx[trace[x2][y2].fi];
            y3=y2+dy[trace[x2][y2].fi];
            if(x3!=u||y3!=v)
            {
                cnt[x3][y3]=min(2, cnt[x3][y3]+cnt[x2][y2]);
                qu.push({x3, y3});
            }
        }
        if(trace[x2][y2].se!=-1)
        {
            x3=x2+dx[trace[x2][y2].se];
            y3=y2+dy[trace[x2][y2].se];
            if(x3!=u||y3!=v)
            {
                cnt[x3][y3]=min(2, cnt[x3][y3]+cnt[x2][y2]);
                qu.push({x3, y3});
            }
        }
    }
    res={-1, -1};
    tmax=-oo;
    F1(i, u, p)
    {
        F1(j, v, q)
        {
            if(i==u&&j==v) continue;
            if(i==p&&j==q) continue;
            if(cnt[i][j]==1)
            {
                if((ll)a[i][j]>tmax)
                {
                    tmax=(ll)a[i][j];
                    res={i, j};
                }
            }
        }
    }
    if(res.fi==-1&&res.se==-1)
    {
        cout<<dp[p][q]<<endl;
    }
    else
    {
        dp[u][v]=a[u][v];
        F1(i, u, p)
        {
            F1(j, v, q)
            {
                if(i==u&&j==v) continue;
                dp[i][j]=-oo;
                F1(i1, 0, 1)
                {
                    x2=i+dx[i1];
                    y2=j+dy[i1];
                    if(!check(x2, y2)) continue;
                    if(x2==res.fi&&y2==res.se) continue;
                    if(dp[x2][y2]==-oo) continue;
                    dp[i][j]=max(dp[i][j], dp[x2][y2]+a[i][j]);
                }
            }
        }
        cout<<dp[p][q]<<endl;
    }
}
main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("TABLE.inp", "r", stdin);
    freopen("TABLE.out", "w", stdout);
    input();
    F1(i, 1, k)
    {
        cin>>u>>v>>p>>q;
        solve();
    }
}

