#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
const ll base = 31;
const ll MOD = 1e9+9;
const ll maxn = 1e6 + 7 ;
using namespace std;
ll n , hash_a[maxn] , p_a[maxn] , hash_b[maxn] , p_b[maxn];
string a;
inline mod (ll v)
{
    return (((v % MOD) + MOD ) % MOD );
}
ll get_a (ll i , ll j)
{
    if (i ==  0) return (mod(hash_a[j]));
    return (mod  (hash_a[j] - hash_a[i-1])  );
}
ll get_b (ll i , ll j)
{
    if (i == 0) return (mod (hash_b[j]));
    return (mod (hash_b[j] - hash_b[i-1]));
}
inline bool check (ll x)
{
    for (int i = 0 ; i <= a.size() - x ; i++)
    {
        cerr << get_a(i , i + x + 1) << " " << get_b(i , i + x + 1) << endl;
        if (get_a (i , i + x + 1 ) == get_b (i , i + x + 1) ) return true;
    }
    return false;
}
int main()
{
    freopen("giun.inp" , "r",stdin);
    freopen("giun.out", "w" , stdout);
    cin >> n >> a;
    string b = a ;
    reverse(b.begin() , b.end());
    cerr << a << " " << b << endl;
    hash_a[a[0]] = (a[0] - 'a' + 1) % MOD;
    p_a[0] = 1;
    hash_b[b[0]] = (b[0] - 'a' + 1) % MOD;
    p_b[0] = 1;
    for (int i = 1 ; i < (int) a.length() ; i++)
    {   
        p_a[i] = (p_a[i-1] * base) % MOD;
        hash_a[i] = (hash_a[i-1] + (a[i] - 'a' + 1) * p_a[i]) % MOD;
    }
    for (int i = 1 ; i < (int) b.length() ; i++)
    {
        p_b[i] = (p_b[i-1] * base) % MOD;
        hash_b[i] = (hash_b[i-1] + (b[i] - 'a' + 1) * p_b[i]) % MOD;
    }
    for (int i = 0 ; i < (int) b.length() ; i++)
    {
        cerr << hash_b[i] << " " << hash_a[i] << endl;
    }

    ll l = 1 , r = n , mid_c = (l+r)/2 , mid_l = (l+r)/2 , ans_c = 1 , ans_l = 1 , l_c = 2;
    if (mid_l % 2 == 0) mid_l++;
    if (mid_c % 2 == 1) mid_c--;
    while (l_c <= r)
    {
        if (check(mid_c) == true) ans_c = mid_c , l_c = mid_c + 2 ;
        else r = mid_c - 2;
        mid_c = (l_c + r) / 2;
    }
    cerr << mid_l << endl;
    while (l <= r)
    {
        if (check(mid_l) == true) ans_l = mid_l , l = 2 * (mid_l/2+1) + 1 ;
        else r = 2 * (mid_l/2+1) - 1 ;
        mid_l = (l + r) / 2;
        cerr << mid_l << " ";
    }
    cout << max (ans_c , ans_l);
}