#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
#pragma GCC optimize("Ofast")
ll n , d, a[10008], dd[10008] = {0}, ans = 0;
using namespace std;
int main()
{
    giuncute;
    freopen("trip.inp","r",stdin);
    freopen("trip.out","w",stdout);
    cin >> n >> d;
    //ll tmp ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    sort (a+1 , a+1+n);
    int j = 1 ;
    for (int i = n ; i >= 1 ; i--)
    {
        if (dd[i] == 0)
        {
            dd[i] = 1;
            if (a[j] + a[i] > d) ans++;
            else dd[j] = 1 , ans++ , j++;
        } 
    }
    cout << ans;
}