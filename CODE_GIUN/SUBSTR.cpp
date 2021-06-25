// vnoi - hash
#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
const ll base = 31;
const ll MOD = 1e9+9;
const ll maxn = 1e6 + 7 ;
using namespace std;
string a , b ;
ll p_b = 1 , hash_b = 0 , hash_a[maxn] , p_a[maxn];
ll mod (ll v)
{
    return (((v % MOD) + MOD ) % MOD);
}
ll get (ll i , ll j)
{
    cerr << i << " " << j << " " << hash_b * p_a[i] << " " << mod  (hash_a[j] - hash_a[i-1]) << endl  ;
    if (i ==  0) return (mod(hash_a[j]));
    return (mod  (hash_a[j] - hash_a[i-1])  );
}
int main() 
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> a >> b ;
    for (char c : b)
    {
        hash_b = (hash_b + (c - 'a' + 1) * p_b) % MOD;
        p_b = (p_b * base) % MOD;
    }
    hash_a[0] = (a[0] - 'a' + 1 ) % MOD , p_a[0] = 1 ;
    for (int i = 1 ; i < a.length() ; i++)
    {
        p_a[i] = (p_a[i-1] * base) % MOD;
        hash_a[i] = (hash_a[i-1] + (a[i] - 'a' + 1) * p_a[i]) % MOD;
    }
    for (int i = 0 ; i < a.length() ; i++) cerr << hash_a[i] << " ";
    for (int i = 0 ; i <= a.length() - b.length() ; i++)
        if (hash_b * p_a[i] == get(i , i + b.length() - 1)) cout << i+1 << " ";
} 