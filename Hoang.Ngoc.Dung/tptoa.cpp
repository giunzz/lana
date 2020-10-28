#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b;
vector<ll> ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> a >> b;
    while (a != 0) ans.push_back(a%b),a/=b;
    reverse(ans.begin(), ans.end()); 
    for (ll i = 0 ; i < ans.size() ; i++) 
    {
        cout << ans[i];
    }
}