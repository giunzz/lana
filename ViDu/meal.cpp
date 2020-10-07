#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll  n , mi = INT_MAX;
pair<ll> a[(int) 5e5+7];
ll s= 0,ss=0, ans1 = 0 , ans2 = 0;
bool cpr (pair<ll> x , pair <ll> y)
{
    return (x.second < y.second)
} 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i].first >> a[i].second; 
    sort(a+1,a+1+n,cpr);
    for (int i = 1 ; i <= n ; i++)
    {
        s = 0 , ss= 0 , ans1 = 0 , ans2 = 0 , k = INT_MAX;
        for (int j = 1 ; j <= i ; j++) s+= a[i].second;
        ss -= a[i-1].second;
        for (int j = 1 ; j <= i ; j++) ans1 = min(ans1,s-a[i].second+a[i].first);
        ll k = i;
        for (int j = i+1 ; j <= n ; j++ ) 
        {
            k = min(a[i],k);
            ss = ss-k;
        }
        cout << min(s,ss) << endl;
    }
    
}