#include <bits/stdc++.h>
#define ll long long
#define cll const ll
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
unsigned ll n , t , f[(ll)2e5+7]={0} ;

void fibo()
{
    f[1] = 1 , f[2] = 2;
    for (ll i = 3 ; i <= 100 ; i++) f[i] = f[i-1]+f[i-2];
}
int main()
{
    giuncute;
    // freopen("giun.inp","r",stdin);
    // freopen("giun.out","w",stdout);
    cin >> t;
    fibo();
    for (int i = 1 ; i <= t ; i++) cin >> n , cout << f[n] << endl;
}
