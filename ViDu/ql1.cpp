#include<bits/stdc++.h>
using namespace std;
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

int n , a[26] , p , t , ans = 0  , dd[26] , V[26];

void answer()
{
    t = 0 ;
    for (int i = 1 ; i <= n ; i++) t += a[i]*dd[i];
    if (t <= p  && t > ans) 
    {
        ans = t;
        for (int j = 1 ; j <= n ; j++) V[j] = dd[j];
    }
}

void quaylui(int vt)
{
    for (int i = 0; i <= 1; i++)
    {
        dd[vt] = i;
        if ( vt  == n ) answer(); 
        else quaylui(vt + 1);
    }
 }
int main()
{
    balabalo;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> p ;
    for ( int i = 1 ; i <= n ; i++) cin >> a[i];
    quaylui(1);
    cout << ans << endl;
    for (int i = 1 ; i <= n ; i++)
    {
        if ( V[i] == 1 ) cout << i << " "; 
    }
    return 0;
}