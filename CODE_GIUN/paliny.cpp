// HASH Onlogn
//----------------------
// #include <bits/stdc++.h>
// #define ll long long
// #define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
// const ll base = 27;
// const ll MOD = 1e9+9;
// const ll maxn = 1e6 + 7 ;
// using namespace std;
// ll n  , p[maxn] , ans = 0 ;
// vector<ll> A , B;
// string a , b;

// vector<ll> Hash(string s)
// {
//     vector<ll> h( (int) s.size() , 0);
//     h[0] = s[0] -'a' + 1;
//     for (int i = 1 ; i < (int) s.size() ; i++ ) h[i] = (h[i-1] * base + s[i] -'a' + 1) % MOD;
//     return h;
// }
// ll mod (ll v)
// {
//     return (((v % MOD) + MOD ) % MOD);
// }
// ll getB (ll l , ll r)
// {
//     if (l == 0) return (mod(B[r]));
//     return ( mod (B[r] - B[l-1] * p[r-l + 1]));
// }
// ll getA (ll l , ll r)
// {
//     if (l == 0) return (mod(A[r]));
//     return ( mod (A[r] - A[l-1] * p[r-l + 1]));
// }
// bool check(ll x)
// {
//     for (int i = 0 ; i <= n - x ; i++)
//     {
//         ll j = i + x - 1;
//         if (getA(i,j) == getB(n-j-1 , n-i-1)) return true;
//     }
//     return false;
// }
// void solve (ll l , ll r , ll k )
// {
//     while ( l <= r)
//     {
//         ll mid = (l+r) / 2 , len = 2*mid+ k;
//         if (check(len) == true) ans = max(ans,len) , l = mid + 1;
//         else r = mid -1;
//     }
// }
// int main() 
// {
//     giuncute;
//     freopen("giun.inp","r",stdin);
//     freopen("giun.out","w",stdout);
//     cin >> n >> a;
//     b = a ;
//     reverse(b.begin() , b.end());
//     p[0] = 1;
//     for (int i = 1 ; i <= n ; i++ ) p[i] = (p[i-1] * base) % MOD;
//     A = Hash(a);
//     B = Hash(b);
//     solve(0 , (n-1)/2 , 1); // 2*k+1;
//     solve(1 , n/2 , 0); // 2*k
//     cout << ans;
// }
//----------------------

// Manacher o(n)

#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
const ll base = 27;
const ll MOD = 1e9+9;
const ll maxn = 1e6 + 7 ;
using namespace std;
