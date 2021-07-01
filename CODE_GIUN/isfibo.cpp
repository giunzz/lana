#include <bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long 
ll n , t , f0 = 0 , f1 = 1;
unordered_map <ll , bool> dd;
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    ll tmp = 0;
    while (tmp <= 1e10) {tmp = f0 + f1, f0 = f1, f1 = tmp, dd[tmp] = 1;}
    cin >> t;
    while (t--)
    {
        cin >> n ;
        if (dd[n] == 1) cout << "IsFibo" << endl;
        else cout << "IsNotFibo" << endl;
    }
}