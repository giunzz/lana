#include<bits/stdc++.h>
#define ll long long 
#define cll const long long 
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll n ,x,y,ans = INT_MAX;
vector <int> a_duong , a_am;
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ; 
    for (int i = 1 ; i <= n ; i++) 
    {
        cin >> x;
        if (x >= 0) a_duong.push_back(x);
        else a_am.push_back(x);
    }
    sort(a_duong.begin() , a_duong.end());
    sort(a_am.begin() , a_am.end());
    for (int i = 1  ; i <= n ; i++)
    {
        cin >> y;
        if (y >= 0)
        {
            ll  j = lower_bound(a_am.begin() , a_am.end() , -y) - a_am.begin();
            if (a_duong.size()) ans = min(y + a_duong[0] , ans )  ;
            if (j >= 1 ) ans = min(abs(y + a_am[j-1]),ans);
            if (j != a_am.size()) ans = min(ans, abs(y + a_am[j]));
        }
        else 
        {
            ll  j = lower_bound(a_duong.begin() , a_duong.end() , -y) - a_duong.begin();
            if (a_am.size())ans = min(abs(y + a_am.back()),ans);
            if (j >= 1 ) ans = min(abs(y + a_duong[j-1]),ans);
            if (j != a_duong.size()) ans = min(ans, abs(y + a_duong[j]));
        }
    }
    cout << ans;
}
