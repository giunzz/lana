#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll oo = 1e18 ;
const ll maxn = 3e6 + 7;
using namespace std;
ll n , k , a[maxn] , dd[maxn] = {0} , f[maxn];

int main()
{
    giuncute;
    freopen("BGAMES.inp","r",stdin);
    freopen("BGAMES.out","w",stdout);
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++) cin >> a[i] ,  ++dd[a[i]], a[i] -= k;
    cerr << endl;
    memset(f , -1 , sizeof f);
    for (int i = 1 ; i <= n ; i++)
    {
        if (a[i] < 0 ) {cout << 0 << " "; continue;}
        if (f[a[i]] != -1) {cout << f[a[i]]<< " " ; continue;}
        f[a[i]] = 0 ;
        --dd[a[i] + k];
        if (a[i] == 0)
        {
            for (int j = 1 ; j <= n ; j++)
                if (a[j] > a[i]) ++f[a[i]];
        }
        else 
            for (ll j = 1 ; j*j <= a[i] ; j++) 
            {
                if (a[i] % j == 0)
                {
                    if(j > k) f[a[i]] += dd[j];
                    if (j != a[i]/j && a[i]/j > k) f[a[i]] += dd[a[i] / j];
                }
            }
        ++dd[a[i] + k];
        cout << f[a[i]] << " ";
    }
}