#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define giuncute  ios_base::sync_with_stdio(0),cin.tie(0); cout.tie(0);
cll maxn = 100007;
using namespace std;
ll n , k , c, type[maxn] ,  t  , test = 0 , need[maxn] , cost[maxn];
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> t;
    while (t--)
    {
        cin >> n >> k >> c;
        for (int i = 1 ; i <= k ; i++) need[i] = INT_MAX;
        for (int i = 1 ; i <= n ; i++) cin >> type[i];
        for (int i = 1 ; i <= n ; i++) 
        {
            cin >> cost[i] ;
            need[type[i]] = min(need[type[i]], cost[i]);
        }
        for (int i = 1 ; i <= k ; i++) 
            if (need[i] != INT_MAX) c-= need[i];
        cerr << c << " ";
        if (c < 0 ) cout << "FRIENDSHIP" << endl;
        else if (c == 0) cout << "NOT FRIENDSHIP BUT NOT LOVE" << endl;
        else if (c > 0)
        {
            ll ok = 0 ;
            for (int i = 1 ; i <= n ; i++)
            {
                if (need[type[i]] != cost[i]) c -= cost[i];
                if (cost >= 0)
                {
                    ok = 1;
                    cout << "LOVE" << endl ;
                    break;
                }
                else c += cost[i];
            }
            if (ok == 0) cout << "NOT FRIENDSHIP BUT NOT LOVE" << endl;
        }
    }
}