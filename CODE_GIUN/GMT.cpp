#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pd pair<double,double>
#define fi first
#define se second
const ll MOD = 1e18;
const ll maxn = 4e5 + 7;
using namespace std;

ll h , m , a , b;

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> h >> m >> a >> b;
    cout << (h + (b - a) + 24 ) % 24 << " " << m ;
}