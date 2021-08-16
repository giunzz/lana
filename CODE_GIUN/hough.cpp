#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 4e5 + 7;
using namespace std;

ll n , m , x;
vector<ll> a;
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) cin >> x , a.push_back(x);
    sort (a.begin() , a.end());
    for (int i = 1 ; i <= m ; i++)
    {
        cin >> x;
        ll id = lower_bound(a.begin() , a.end() , x) - a.begin();
        cerr << id << " ";
        while (id >= 0 && (a[id] >= x || id == a.size()) )  id--;
        cout << id + 1 << endl;
    }
}
