#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a; i<=b; i++)
const int N=5e4+5;
typedef pair<int,int>ii;
int n,k,x[N],u,v,c,kq;
vector<pii>ke[N];
int main()
{
    freopen("bubbletea.inp","r",stdin);
    freopen("bubbletea.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    FOR(i,1,k) cin >> x[i];
    FOR(i,1,n-1)
    {
        cin >> u >> v >> c;
        ke[u].push_back(ii(v,c));
        ke[v].push_back(ii(u,c));
        kq=max(kq,c);
    }
    if (k==n)
    {
        cout << kq;
        return 0;
    }
}
