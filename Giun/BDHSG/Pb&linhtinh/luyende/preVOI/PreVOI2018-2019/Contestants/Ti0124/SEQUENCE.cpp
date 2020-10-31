#include <bits/stdc++.h>
using namespace std;
const int maxn = 3010;
int m,n,k, a[maxn], b[maxn];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("SEQUENCE.inp","r",stdin); freopen("SEQUENCE.out","w",stdout);
    cin >> m >> n >> k;
    for(int i = 1; i <= m; i++)
    {
        int x; cin >> x;
        cout << x << ' ';
    }
    for(int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        cout << x << ' ';
    }
}
