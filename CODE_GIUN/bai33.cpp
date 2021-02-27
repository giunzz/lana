#include<bits/stdc++.h>
using namespace std;
const string tenfile = "bai33";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define fi first
#define se second
int n  ;
pair <int, int> f[18];

int main()
{
    balabalo;
    giuncute;
    cin >> n ; 
    f[1].first = 2;
    f[1].second = 1;
    for (int i = 2 ; i <= n ; i++)
    {
        f[i].fi = f[i - 1].fi + f[i - 1].se;
        f[i].se = f[i - 1].se * 2;
        cerr << f[i].first << " " << f[i].second << endl;
    }
    cout << f[n].fi * f[n].fi;
    return 0;
}
