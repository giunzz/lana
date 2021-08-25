#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define x first
#define y second
#define pl pair<ll,ll>
const ll MOD = 1e9 + 7;
const ll maxn = 4e6 + 7;
using namespace std;

ll n , ans = 0 , u , v;
vector<pl> a;

int main()
{
    giuncute;
    freopen("dientich.inp","r",stdin);
    freopen("dientich.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> u >> v , a.push_back({u,v});
    sort(a.begin() , a.end() , greater<pl>());
    u = a[0].x , v = a[0].y ;
    for (int i = 1 ; i < a.size() ; i++)
    {
        if (u >= a[i].x && v >= a[i].y) a[i].x = -1;
        else u = a[i].x , v = a[i].y ;
    }
    vector<pl> b;
    for (int i = 0 ; i < a.size() ; i++) 
        if(a[i].x != -1) b.push_back({a[i].x ,a[i].y});
    ans  = b[0].x * b[0].y;
    for (int i = 1 ; i < b.size() ; i++) 
        ans += (b[i].x * b[i].y) - (b[i].x * b[i-1].y);
    cout << ans ;
}