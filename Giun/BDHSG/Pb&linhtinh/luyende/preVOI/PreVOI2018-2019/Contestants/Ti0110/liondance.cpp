#include <bits/stdc++.h>
using namespace std;
vector < pair < int , int > > f[4001];
vector < pair < int , int >  > F[4001];
int n,k;
int a[4001],b[4001];
int ans[4001];
int slans;
int ans2[4001];
void dfs(int sl , int ua , int ub)
{
    if (ua==n+1 || ub== n+1)
    {
        if (sl > slans)
        {
            slans= sl;
            for (int i=1;i<=slans;i++) ans2[i]=ans[i];
        }
        if (sl == slans)
        {
             bool kt = false;
    for (int i=1;i<=slans;i++)
    if (ans[i] != ans2[i])
    {
        kt = ans[i] < ans2[i];
        break;
    }
    if (kt == false)  for (int i=1;i<=slans;i++) ans2[i]=ans[i];
        }
        return ;
    }

    int j;
    for (int i = 0;i < f[ua].size();i++)
        for (int j = 0 ; j < F[ub].size() ;j++)
            if ( f[ua][i].first == F[ub][j].first )
            {
                ans[ sl ] = f[ua][i].first;
                dfs( sl+1 , f[ua][i].second , F[ub][j].second );
            }
        return ;
}
bool cmp( pair < int , int > a , pair < int , int > b )
{
    if (a.first == b.first) return a.second > b.second ;
    return a.first < b.first;
}
int main()
{
    freopen("liondance.inp","r",stdin);
    freopen("liondance.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];

    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<i;j++)
            if( abs( a[i] - a[j] ) <= k)
                {
                    f[j].push_back( make_pair( a[i] , i ) );
                }
    }

    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<i;j++)
            if (abs( b[i] - b[j] ) <= k)
                {
                    F[j].push_back( make_pair( b[i] , i ) );
                }
    }

    for (int i=1;i<=n;i++)
    {
        f[0].push_back( make_pair ( a[i] , i) );
        f[i].push_back( make_pair (1e9 , n+1 ) );
        F[0].push_back( make_pair ( b[i] , i) );
        F[i].push_back( make_pair (1e9 , n+1 ) );
    }
    dfs(1 , 0 , 0);
    cout<<slans-2<<endl;
    for (int i=1;i<slans-1;i++) cout<<ans2[i]<<" ";
    return 0;
}
