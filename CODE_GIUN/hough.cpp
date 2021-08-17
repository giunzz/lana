#include <bits/stdc++.h>
#define ll int 
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
const ll maxn = 1e5 + 7;
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
        while (id >= 0 && (a[id] >= x || id == a.size()) )  id--;
        printf("%d\n", id+1);
    }
}
