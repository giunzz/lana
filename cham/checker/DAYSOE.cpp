#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
// ll n , x  , a[(int) 1e6+7];
// map<ll,ll> d;
// ll masl = INT_MIN , mas = INT_MIN;
// int main()
// {
//     giuncute;
//     freopen("DAYSOE.inp","r",stdin);
//     freopen("DAYSOE.out","w",stdout);
//     scanf("%lld", &n);
//     for (int i = 1 ; i <= n ; i++) 
//     {
//         scanf("%lld", &a[i]);
//         d[a[i]]++;
//         if (masl < d[a[i]] ) masl = d[a[i]] , mas = a[i];
//         if (masl == d[a[i]] && mas > a[i]) masl = d[a[i]] , mas = a[i];
//     }
//     for (int i = 1 ; i <= n ; i++)
//         if (mas == a[i]) printf("%lld ", i);
// }
ll n , x ;
pair<ll,ll> dd[(int) 1e6+7];

int main()
{
    freopen("daysoe.inp","r",stdin);
    freopen("daysoe.out","w",stdout);
    scanf("%lld", &n);
    for (int i = 1 ; i <= n ; i++)
    {
        scanf("%lld", &x);
        dd[i].first = x , dd[i].second = i;
    }
    dd[n+1].first = 1e9+7;
    sort(dd+1,dd+1+n);
    ll slt = 1 , sl =  0 , ma = dd[1].first , ma1 = dd[1].first ;
    for (int i = 2 ; i <= n+1 ; i++)
    {
        if (ma == dd[i].first) slt++;
        else 
        {
            if (slt > sl) sl = slt , ma1 = ma ;
            ma = dd[i].first;
            slt = 1 ;
        }
    }
    for (int i = 1 ; i <= n ; i++)
        if (dd[i].first == ma1) printf("%lld ", dd[i].second);
}
