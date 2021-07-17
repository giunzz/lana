#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
using namespace std;
const ll maxn = 1e6 + 7 ;
ll n , k , a[maxn] , d[maxn] ={0};

int main()
{
    giuncute;
    freopen("maso.inp","r",stdin);
    freopen("maso.out","w",stdout);
    cin >> n >> k;
    int count = 0;
    for (int i = 1 ; i <= n ; i++) cin >> a[i] , d[a[i]] = 1;
    for (int i = 1 ; i <= 80000 ; i++)
    {
        if (d[i] == 0) cout << i << endl , count ++;
        if (count == k) {break;}
    }
}