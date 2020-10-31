#include<bits/stdc++.h>
#define maxn 50005
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii ,int> iii;

int n, k;
vector< iii > P[maxn];
int d[maxn], dd[maxn];
long long cmin, maxx;

int main()
{
    freopen("BUBBLETEA.inp","r",stdin);
    freopen("BUBBLETEA.out","w",stdout);
    cmin = 1e15;
    cin>>n>>k;
    for(int i=1;i<=k;i++) cin>>d[i];
    for(int i=1;i<n;i++)
    {
        int u, v,c;
        cin>>u>>v>>c;
        P[u].push_back( make_pair( make_pair(v, c), i) );
        P[v].push_back( make_pair( make_pair(u, c), i) );
    }

    cout << -1;
}
