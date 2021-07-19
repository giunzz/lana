#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
const ll maxn = 3e3 +  7;
using namespace std;
ll t  , n , k , sing , dance , s[maxn] , d[maxn] , c[maxn] , ans = 0;
pair <ll,ll> p[maxn];

void quaylui (ll vt )
{
    if (vt == n + 1)         
    {
        vector<ll> group1 , group2;
        for (int i = 1 ; i <= n ; i++)
        {
            if (c[i] == 1)
            {
                if (p[i].first == 1) 
                {
                    if (group1.empty() == true)  group1.push_back(i);
                    else 
                    {
                        for (int i = 0 ; i < group1.size() ; i++)
                        {
                            if ( abs(i - group1[i]) <= k) 
                            {
                                group1.push_back(i);
                                break;
                            }
                        }
                    }
                }
                else if (p[i].second == 1) 
                {
                    if (group2.empty() == true)  group2.push_back(i);
                    else 
                    {
                        for (int i = 0 ; i < group2.size() ; i++)
                        {
                            if ( abs(i - group2[i]) <= k) 
                            {
                                group2.push_back(i);
                                break;
                            }
                        }
                    }
                }
            }
        }
        if (group1.empty() == false && group2.empty() == false) ans++;
    }
    else
    {
        for (int i = 0 ; i <= 1 ; i++)
        {
            c[vt] = i ;
            quaylui(vt+1);
        }
    }
}
int main()
{
    giuncute;
    freopen("giun.inp" ,"r",stdin);
    freopen("giun.out", "w" ,stdout);
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        cin >> sing ;
        for (int i = 1 ; i <= sing ; i++) 
        {
            cin >> s[i];
            p[s[i]].first = 1;
        }
        cin >> dance;
        for (int i = 1 ; i <= dance; i++) 
        {
            cin >> d[i] ;
            p[s[i]].second = 1;
        }
        for (int i = 1 ; i <= n ; i++) 
            cerr << i << " " << p[s[i]].first << " " << p[s[i]].second << endl;
        ans = 0;
        for (int i = 1 ; i <= n ; i++) c[i] = 0;
        quaylui(1);
        cout << ans%998244353 << endl;
    }
}
