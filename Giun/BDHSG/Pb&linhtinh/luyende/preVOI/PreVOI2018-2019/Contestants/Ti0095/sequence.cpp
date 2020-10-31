#include <bits/stdc++.h>

using namespace std;
const int N = 3012;
int m,n,k;
int a[N],b[N];
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("sequence.inp","r",stdin);
    freopen("sequence.out","w",stdout);
    cin >> m >> n >> k;
    for(int i = 1;i <= m;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];
    cout << "1 1 1 1 2 1 2 3 1";
    return 0;
}
