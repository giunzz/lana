#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxx = 1e6 ;
const ll mod = 68718952446;
ll t, T, n, m, k, tong, r, ans;
string s;
ll a[maxx], b[maxx], c[maxx];
void sol()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)cin >> a[i];
    b[1] = 1;
    for(int i = 2; i <= n; i ++)
    {
        b[i] = b[i-1] * a[i-1];
        b[i] %= mod;
    }
    c[n] = 1;
    for(int i = n - 1; i > 0; i --)
    {
        c[i] = c[i+1] * a[i+1];
        c[i] %= mod;
    }
    for(int i = 1; i <= n; i ++)
    {
        cout << b[i] * c[i] % mod<<" ";
    }
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    freopen("WC1.inp", "r", stdin);
    freopen("WC1.out", "w", stdout);
    cin >> T;
    while(T -- > 0)
    {
    sol();    
    cout << '\n';
    }

}