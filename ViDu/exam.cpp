#include<bits/stdc++.h>
using namespace std;
#define ll long long
pair<ll,ll> a[5];
ll n,c[5];
bool sorting(pair<ll> & a , pair<ll> &b) 
{ 
    return (a.second < b.second); 
} 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort (a+1,a+1+n, sorting);
    //for (int i = 1 ; i <= 3 ; i++)
    //{
 //       c[a[i].second] =  min(a[i].first,d);
  //      d -= min(d, a[i].first);
    for (int i = 1 ; i <= n ; i++) cout << a[i].second << " ";
}