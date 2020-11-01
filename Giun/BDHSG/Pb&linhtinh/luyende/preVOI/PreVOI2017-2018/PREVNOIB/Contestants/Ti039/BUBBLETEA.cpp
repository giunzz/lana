#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int n,k,a[100000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("BUBBLETEA.INP","r",stdin);
    freopen("BUBBLETEA.OUT","w",stdout);
    cin >> n >> k;
    for (int i=1;i<=k;i++) cin >> a[i];
    long long kq=0;
    for (int i=1;i<n;i++)
    {
        int u,v;long long w;
        cin >> u >> v >> w;
        kq=max(kq,w);
    }
    cout << kq;
}
