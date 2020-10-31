#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

const int maxN=5e4+11;
const int maxK=5e4+11;

typedef pair<int, int> pii;

int n, k, a[maxK];
long long d[maxN];
vector<pii> vt[maxN];

void Visit(int x, int parx)
{
    for (int i=0; i<vt[x].size(); i++)
    {
        int y=vt[x][i].F;
        long long xy=vt[x][i].S;
        if (y==parx) continue;
        d[y]=d[x]+xy;
        Visit(y, x);
    }
}

int main()
{
    freopen("BUBBLETEA.INP", "r", stdin);
    freopen("BUBBLETEA.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for (int i=1; i<=k; i++) cin>>a[i];
    for (int i=1; i<=n-1; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        vt[u].push_back(pii(v, w));
        vt[v].push_back(pii(u, w));
    }
    if (k==2)
    {
        Visit(a[1], a[1]);
        cout<<d[a[2]];
    }
    else cout<<-1;
    return 0;
}
