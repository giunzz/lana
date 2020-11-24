#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
using namespace std;
ll n ;
struct giuncutenhatvutru{
    ll first, second, id;
} a[(int)1e3 +  7];

bool giun(giuncutenhatvutru &a, giuncutenhatvutru &b)
{
    return (a.second < b.second);
}
int main()
{
    giuncute;
    freopen("chonhd.inp","r",stdin);
    freopen("chonhd.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) 
    {
        cin >> a[i].first >> a[i].second;
        a[i].id = i;
    }
    sort(a+1,a+1+n,giun);
    ll f[(int) 1e3 + 7] = {0}, ma, ans = 0, vt; //fi tuc la so luong hoat dong nhieu nhat ket thuc tai ai.second
    // fi = max(fi - 1, f(j thoa man la aj.second <= ai.first))
    // aj.second lon nhat ma <= ai.first
    for (int i = 1 ; i <= n ; i++)
    {
        ma = 0;
        for (int j = 1 ; j <= i-1 ; j++)
        {
            if (a[i].first >= a[j].second) ma = max(ma,f[j]);
        }
        f[i] =  ma + 1;
        if(f[i] > ans) ans = f[i], vt = i;
    }
    cout << ans << endl;
    ll i = vt;
    vector<ll> trace;
    trace.push_back(a[vt].id);
    while (1)
    {
        bool ok = 0;
        for (int j = 1; j <= i-1 ; j++){
            if(f[j] == f[i] - 1){ 
                trace.push_back(a[j].id);
                i = j;
                ok = 1;
                break;
            }
        }
        if(!ok) break;
    }
    sort(trace.begin() , trace.end());
    for(auto v : trace) cout << v << ' ';
}`