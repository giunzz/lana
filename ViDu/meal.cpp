#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll  n , k  = INT_MAX;
pair<ll,ll> a[(int) 5e5+7];
ll s= 0,ss=0, ans1 = 0 , ans2 = 0;

bool cpr (pair<ll,ll> x , pair <ll,ll> y)
{
    return x.second < y.second;
} 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("meal.inp","r",stdin);
    freopen("meal.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i].first >> a[i].second; 
    sort(a+1,a+1+n,cpr);
    for (int i = 1 ; i <= n ; i++)
    {
        s = 0 , ss= 0 , ans1 = LLONG_MAX , ans2 = LLONG_MAX , k = LLONG_MAX;
        for (int j = 1 ; j <= i ; j++) s+= a[j].second;
        ss = s- a[i].second;
        for (int j = 1 ; j <= i ; j++) ans1 = min(ans1,s-a[j].second+a[j].first);
        for (int j = i ; j <= n ; j++ ) k = min(a[j].first,k);
        ans2 = ss+k;
        cout << min(ans1,ans2) << endl;
    }
    
}