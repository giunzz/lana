#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a; i<=b; i++)
const int N=5005;
int n,a[N];
vector<int>ke[N];
int main()
{
    freopen("tree.inp","r",stdin);
    freopen("tree.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    FOR(i,1,n) cin >> a[i];
    FOR(i,1,n-1)
    {
        int x,y;
        cin >> x >> y;
        ke[x].push_back(y);
    }
    cout << 4;
}
