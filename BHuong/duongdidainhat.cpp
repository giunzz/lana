#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
const ll maxn = 1e5;
using namespace std;
ll n , f[maxn+7] = {0},m,d[maxn+7]={0};
vector <ll> b;
struct giun
{
    ll first , second ;
} a[maxn+7];
bool cpr (giun &a , giun &b)
{
    return (a.second <= b.first);
}
void sol ()
{
    ll ans = 1;
    for (int i = 0 ; i < (int) b.size() ; i++)
    {
        f[i] = 0;
        for (int j = 0 ; j < i ; j++)
            if (b[j] < b[i]) f[i] = max(f[i], f[j]+1);
        ans = max (ans,f[i]);
    }
    cout << ans;
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> m ;
    for (int i = 1 ; i <= m ; i++) cin >> a[i].first >> a[i].second;
    sort(a+1,a+1+m,cpr);
    for (int i = 1 ; i <= m ; i++)
    {
        cerr << a[i].first << " " << a[i].second << endl;
        if (!d[a[i].first]) b.push_back(a[i].first) , d[a[i].first] = 1;
        if (!d[a[i].second]) b.push_back(a[i].second) , d[a[i].second] = 1;
    }
    sol();
}