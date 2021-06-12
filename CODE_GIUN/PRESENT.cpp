#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
const ll maxn = 1e3 + 7  ;

ll n , m , t ;

int main()
{
    giuncute;
    //freopen("giun.inp","r",stdin);
    //freopen("giun.out","w",stdout);
    cin >> t ; 
    while (t--)
    {
        cin >> m >> n ;
        if (m == 1) cout << 1  << endl;
        else 
        {
            if (n % 3 == 0) cout << 2 * n/3 << endl;
            else cout << 2 * (n/3) + 1<< endl;
        }
    }
}