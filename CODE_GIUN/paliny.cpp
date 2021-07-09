// #include <bits/stdc++.h>
// #define ll long long
// #define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
// const ll base = 17;
// const ll MOD = 1e9+9;
// const ll maxn = 1e6 + 7 ;
// using namespace std;
// ll n , hash_a[maxn] , p_a[maxn] , hash_b[maxn] , p_b[maxn];
// string a;
// inline mod (ll v)
// {
//     return (((v % MOD) + MOD ) % MOD );
// }
// ll get_a (ll i , ll j)
// {
//     if (i ==  0) return (mod(hash_a[j]));
//     return (mod  (hash_a[j] - hash_a[i-1])  );
// }
// ll get_b (ll i , ll j)
// {
//     if (i == 0) return (mod (hash_b[j]));
//     return (mod (hash_b[j] - hash_b[i-1]));
// }
// inline bool check (ll x)
// {
//     for (int i = 0 ; i <= a.size() - x ; i++)
//     {
//         cerr << get_a(i , i + x + 1) << " " << get_b(i , i + x + 1) << endl;
//         if (get_a (i , i + x + 1 ) == get_b (i , i + x + 1) ) return true;
//     }
//     return false;
// }
// int main()
// {
//     freopen("giun.inp" , "r",stdin);
//     freopen("giun.out", "w" , stdout);
//     cin >> n >> a;
//     string b = a ;
//     reverse(b.begin() , b.end());
//     cerr << a << " " << b << endl;
//     hash_a[a[0]] = (a[0] - 'a' + 1) % MOD;
//     p_a[0] = 1;
//     hash_b[b[0]] = (b[0] - 'a' + 1) % MOD;
//     p_b[0] = 1;
//     for (int i = 1 ; i < (int) a.length() ; i++)
//     {   
//         p_a[i] = (p_a[i-1] * base) % MOD;
//         hash_a[i] = (hash_a[i-1] + (a[i] - 'a' + 1) * p_a[i]) % MOD;
//     }
//     for (int i = 1 ; i < (int) b.length() ; i++)
//     {
//         p_b[i] = (p_b[i-1] * base) % MOD;
//         hash_b[i] = (hash_b[i-1] + (b[i] - 'a' + 1) * p_b[i]) % MOD;
//     }
//     for (int i = 0 ; i < (int) b.length() ; i++)
//     {
//         cerr << hash_b[i] << " " << hash_a[i] << endl;
//     }

//     ll l = 1 , r = n , mid_c = (l+r)/2 , mid_l = (l+r)/2 , ans_c = 1 , ans_l = 1 , l_c = 2;
//     if (mid_l % 2 == 0) mid_l++;
//     if (mid_c % 2 == 1) mid_c--;
//     while (l_c <= r)
//     {
//         if (check(mid_c) == true) ans_c = mid_c , l_c = mid_c + 2 ;
//         else r = mid_c - 2;
//         mid_c = (l_c + r) / 2;
//     }
//     cerr << mid_l << endl;
//     while (l <= r)
//     {
//         if (check(mid_l) == true) ans_l = mid_l , l = 2 * (mid_l/2+1) + 1 ;
//         else r = 2 * (mid_l/2+1) - 1 ;
//         mid_l = (l + r) / 2;
//         cerr << mid_l << " ";
//     }
//     cout << max (ans_c , ans_l);
// }
// ll a[maxn] , b[maxn] , p , n  , ans = 0 ;
// string s ;
// int main()
// {
//     freopen("giun.inp" , "r",stdin);
//     freopen("giun.out", "w" , stdout);
//     cin >> n >> s;
//     a[0] = 0  , p = 1 , b[0] = 0 ;
//     s = " " + s;
//     int i;
//     // for (int i = 1 ; i <= n  ; i++)
//     //     a[i] = a[i-1]* base  + (s[i] - 'a' + 1);
//     // for (int i = 1 ; i <= n ; i++)
//     //     b[i] = b[i-1] + (s[i] - 'a' + 1)* p , p *= base;
    
//     for (int i = 1 ; i <= n ; i++)
//     {
//         cerr << a[i] << " " << b[i] << endl;
//         if (a[i] == b[i]) ans++;
//     }
//     cout << ans;
// }
#include <bits/stdc++.h>
long long a[100010], b[100010], p;
char c[100010];
#define t 17
using namespace std;
int main() {
         freopen("giun.inp" , "r",stdin);
     freopen("giun.out", "w" , stdout);

    int i, n, ans=0;
    while(scanf("%s", c+1) != EOF) {
        n = strlen(c+1);
        for (i = 1 ; i  <= n ; i++) cerr << c[i] ;
        cerr << endl;
        for (i = n ; i  >= 1 ; i--) cerr << c[i] ;
        cerr << endl;
        
        for(a[0]=0,i=1; i<=n; i++)
            a[i] = a[i-1]*t + (c[i]-'a';
        for(b[0]=0,p=1,i=1; i<=n; i++)
            b[i] = b[i-1] + (c[i]-'a')*p, p*=t;
        int ans = 0;
        for(i=1; i<=n; i++)
        {
            cerr <<a[i] << " " << b[i] << endl;
            if(a[i] == b[i])
                ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}