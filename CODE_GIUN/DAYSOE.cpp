#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long
ll n , x  , a[(int) 1e6+7];
map<ll,ll> d;
ll masl = INT_MIN , mas = INT_MIN;
int main()
{
    giuncute;
    freopen("DAYSOE.inp","r",stdin);
    freopen("DAYSOE.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) 
    {
        cin >> a[i] ;
        d[a[i]]++;
        if (masl < d[a[i]] ) masl = d[a[i]] , mas = a[i];
        if (masl == d[a[i]] && mas > a[i]) masl = d[a[i]] , mas = a[i];
    }
    for (int i = 1 ; i <= n ; i++)
    {
        if (mas == a[i]) cout << i << " ";
    }
}
