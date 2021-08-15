#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 4e5 + 7;
using namespace std;

ll n , k , c , d ;

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ; 
    ll ans = 0 ;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> k;
        vector <ll> a1 , a2 , a3;  
        for (int j = 1 ; j <= k ; j++)
        {
            cin >> c >> d;
            if (c == 1) a1.push_back(d);
            if (c == 2) a2.push_back(d);
            if (c == 3) a3.push_back(d);
        }
        ll s1 = 0 , s2 = 0 , s3 = 0;
        for (int i = 0 ; i < (int) a1.size() ; i++) 
        {
            if (a1[i] % 10 == 0 && a1[i] != 10) s1 += (a1[i] * 2 );
            else s1 += a1[i];
        }
        for (int i = 0 ; i < (int) a2.size() ; i++) 
        {
            if (a2[i] % 10 == 0 && a2[i] != 10) s2 += (a2[i] * 2 );
            else s2 += a2[i];
        }
        for (int i = 0 ; i < (int) a3.size() ; i++)
        {
            if (a3[i] % 10 == 0 && a3[i] != 10 ) s3 += (a3[i] * 2 );
            else s3 += a3[i];
        }
        if (a1.size() == 1 && a2.size() == 1 && a3.size() == 1){
            ans += max({s1+s2,s1+s3,s2+s3});
        }
        else ans += max({s1,s2,s3});
        cerr << ans << " ";
    }
    cout << ans;
}