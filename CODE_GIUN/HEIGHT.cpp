#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
using namespace std;
const ll maxn = 1e5 + 7;
ll n ,a[maxn] , b[maxn];
unordered_map <ll,ll> d1 , d2;
int main()
{
    giuncute;
 //   freopen("giun.inp","r",stdin);
 //   freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i] , d1[a[i]]++ , b[i] = a[i] , d2[a[i]]++;
    sort (a+1 , a+1+n);
    for (int i = 2 ; i <= n ; i++)
    {
        if (a[i] == a[i-1]) continue;
        d1[a[i]] += d1[a[i-1]];
    }
    for (int i = 1 ; i <= n ; i++ ) cout << d1[b[i]] - d2[b[i]] << " ";
}