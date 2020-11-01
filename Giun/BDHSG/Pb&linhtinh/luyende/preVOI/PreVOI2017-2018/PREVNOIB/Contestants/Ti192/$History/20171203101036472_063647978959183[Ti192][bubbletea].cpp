#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a; i<=b; i++)
const int N=5e4+5;
typedef pair<int,int>pii;
int n,k,x[N];
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
    }
}
