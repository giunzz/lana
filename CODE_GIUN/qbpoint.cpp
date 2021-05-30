#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll> 
#define x first 
#define y second
const ll maxn = 2000+7 ;
ll n , ans = 0 ;
pl a[maxn] , tmp[maxn]  ;

inline void change (pl &c)
{
    if ( (c.y < 0) || (c.y == 0 && c.x < 0) ) c = {-c.x , -c.y};
}
inline bool cmp (pl &a , pl &b)
{
    return (a.x * b.y > a.y * b.x);
}
inline bool check (pl &a , pl &b)
{
    return (a.x * b.y == a.y * b.x);
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> a[i].x >> a[i].y;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = i+1 ; j <= n ; j++) 
        {
            tmp[j] = {a[j].x - a[i].x , a[j].y - a[i].y};
            change(tmp[j]);
        
        }
        sort (tmp + i + 1 , tmp +  1 + n , cmp);
        ll k = i + 1;
        for (int j = i + 2 ; j <= n ; j++)
        {
            if (!check(tmp[j] , tmp[k]))
            {
                ans += (j-k) * (j - k - 1) / 2;
                k = j;
            }
        }
        ans += (n - k + 1) * (n - k) /2;
    }
    cout << ans;
}