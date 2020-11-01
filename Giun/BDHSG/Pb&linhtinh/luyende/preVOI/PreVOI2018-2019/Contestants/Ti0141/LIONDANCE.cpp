#include <bits/stdc++.h>

using namespace std;
#define TASK "LIONDANCE"
int m,n,l[10007],r[10007] ;
int a[10007] ;
vector<int> res[10007] ;
int maxn = - 1;
void Input()
{
    cin >> n >> m ;
    for(int i=1;i<=n;i++)
        cin >> l[i] ;
    for(int i=1;i<=n;i++)
        cin >> r[i] ;
    return ;
}
void Process()
{
    vector<int> g ;
    for(int i=1;i<=n;i++)
        if(a[i] == 1)
            g.push_back(l[i]) ;
    for(int i=0;i<(int)g.size()-1;i++)
        if(g[i+1]-g[i] >= m || g[i+1] < g[i])
            return ;
    int cnt=0 ;
    for(int i=1;i<=n;i++)
    {
        if(cnt < (int)g.size() && g[cnt] == r[i])
            ++cnt ;
    }
    if(cnt == g.size()){
        if(maxn < cnt)
        {
            maxn=cnt ;
            for(int i=0;i<cnt;i++)
                res[maxn].push_back(g[i]) ;
        }
        if(maxn == cnt)
        {
            for(int i=0;i<cnt;i++)
                if(res[maxn][i] > g[i])
                    return ;
            res[maxn].clear() ;
            for(int i=0;i<cnt;i++)
                res[maxn].push_back(g[i]) ;
        }
    }
}
void Try(int i)
{
    for(int j=0;j<=1;j++)
    {
        a[i]=j ;
        if(i == n)
            Process() ;
        else
            Try(i+1) ;
    }
}
int main()
{
    freopen(TASK".INP","r",stdin) ;
    freopen(TASK".OUT","w",stdout) ;
    ios_base::sync_with_stdio(0) ;
    cin.tie(NULL) ;
    Input() ;
    Try(1) ;
    cout << maxn << "\n" ;
    for(int i=0;i<res[maxn].size();i++)
        cout << res[maxn][i] << " " ;
    return 0;
}
