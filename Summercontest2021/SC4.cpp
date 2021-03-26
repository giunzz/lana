#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define pl pair<ll,ll>
#define giuncute  ios_base::sync_with_stdio(0),cin.tie(0); cout.tie(0);
cll maxn = 100007;
using namespace std;
ll n , k , c, type[maxn] ,  t   , cost[maxn] , test = 0;
struct giun
{
    int first , second;
};
bool cmp (giun &a , giun &b)
{
    return (a.first < b.first);
}
int main()
{
    giuncute;
    giun need[100];
    ll dd[maxn] = {0};
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> t;
    while (t--)
    {
        cin >> n >> k >> c;
        test = 0;
        for (int i = 1 ; i <= 50 ; i++) need[i].first = INT_MAX;
        for (int i = 1 ; i <= n ; i++) cin >> type[i] , test = max(test,type[i]);
        for (int i = 1 ; i <= n ; i++) 
        {
            cin >> cost[i] ;
            if (need[type[i]].first > cost[i] ) need[type[i]].first = cost[i] , need[type[i]].second = i;
        }
        sort(need+1,need+1+50,cmp);
        for (int i = 1 ; i <= k ; i++) 
            if (need[i].first != INT_MAX) c-= need[i].first , dd[need[i].second] = 1;
        if (c < 0 || test < k) cout << "FRIENDSHIP" << endl;
        else if (c == 0) cout << "NOT FRIENDSHIP BUT NOT LOVE" << endl;
        else if (c > 0)
        {
            ll ok = 0 ;
            for (int i = 1 ; i <= n ; i++)
            {
                if (dd[i] == 0) 
                {
                    c -= cost[i];
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