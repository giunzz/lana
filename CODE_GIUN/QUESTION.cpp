#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 4e5 + 7;
using namespace std;
ll n , a , b , x , ans , du[maxn] = {0} , t;

int main()
{
    giuncute;
    freopen("QUESTION.inp","r",stdin);
    freopen("QUESTION.out","w",stdout);
    cin >> t ;
    while (t--)
    {   cin >> n >> a >> b ; 
        ans = 0 ;
        for (int i = 0 ; i <= b ; i++) du[i] = -1 ;
        for (int i = 0 ; i <= n ; i++)
        {
            ll r = (i*a) % b;
            if (du[r] == -1) ans += n-i+1;
            else x = (i*a - du[r])/b , ans += min(x,n-i+1);
            du[r] = i*a;
        }
        cout << ans << endl;
    }
}