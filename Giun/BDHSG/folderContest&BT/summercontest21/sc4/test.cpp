#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define giuncute  ios_base::sync_with_stdio(0),cin.tie(0); cout.tie(0);
cll maxn = 100007;
using namespace std;
ll n , k , c, type[maxn] ,  t  , test = 0  , cost[maxn];
int main()
{
    giuncute;
    freopen("sc4.inp","r",stdin);
    freopen("sc4.out","w",stdout);
    cin >> t;
    while (t--)
    {
        cin >> n >> k >> c;
        ll dd[55] ={0};
        pair<ll,ll> need[55];
        test = 0;
        for (int i = 1 ; i < 55 ; i++) need[i].first = INT_MAX;
        for (int i = 1 ; i <= n ; i++) cin >> type[i],test = max(test,type[i]);
        for (int i = 1 ; i <= n ; i++) 
        {
            cin >> cost[i] ;
            if (need[type[i]].first > cost[i])
            {
            need[type[i]].first= cost[i];
            need[type[i]].second = i;
            }
        }
        sort(need+1,need+1+50);
        for (int i = 1 ; i <= k ; i++) {
        cerr << need[i].first <<" ",c-= need[i].first;
        dd[need[i].second]=1;
        }
        cout << c << " ";
        if (c < 0 || test < k) cout << "FRIENDSHIP" << endl;
        else if (c == 0) cout << "NOT FRIENDSHIP BUT NOT LOVE" << endl;
        else if (c > 0)
        {
            ll ok = 0 ;
            for (int i = 1 ; i <= n ; i++)
            {
                if (dd[i] == 0) 
                {c -= cost[i];
        
                if (c >= 0)
                { 
                    ok = 1;
                    cout << "LOVE" << endl ;
                    break;
                }
                else c += cost[i];
                }
            }
            if (ok == 0) cout << "NOT FRIENDSHIP BUT NOT LOVE" << endl;
        }
    }
}