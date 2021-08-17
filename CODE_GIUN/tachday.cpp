#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define p vector <ll>  :: iterator
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 4e5 + 7;
using namespace std;

ll n , x;
vector <ll>  vt ;
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> x ;
        //cerr << x << " ";
        p a = lower_bound(vt.begin() , vt.end() , x , greater<ll>() ); // tra ve con
        if (a == vt.end()) vt.push_back(x);
        else *a = x; // vt x 
        //for (int &k : a) cerr << k << " ";
    }
    cout << vt.size();
}