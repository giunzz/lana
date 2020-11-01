#include <bits/stdc++.h>
#define ft first
#define sd second
#define mn
#define mod
#define PI 3.14159265
#define MP make_pair
#define PB push_back
#define heap priority_queue
#define Bjerg "BUBBLETEA"
using namespace std;
long n,k,maxc;
void nhap()
{
    cin >> n >> k;
    for(long i=1;i<=k;++i)
    {
        long u;
        cin >> u;
    }
    for(long j=1;j<n;++j)
    {
        long u,v,c;
        cin >> u >> v >> c;
        maxc=max(maxc,c);
    }
    cout << maxc;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Bjerg".inp","r",stdin);
    freopen(Bjerg".out","w",stdout);
    nhap();
    return 0;
}
