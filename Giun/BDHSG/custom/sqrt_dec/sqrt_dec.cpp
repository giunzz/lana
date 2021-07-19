#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
const ll maxn = 1e5 + 7 ;
using namespace std;
ll ans = 0 , n , l , r , block , cnt[320][maxn] , q , k , a[maxn];
string s;
int main()
{
    giuncute;
    freopen("sqrt_dec.inp","r",stdin);
    freopen("sqrt_dec.out","w",stdout);
    cin >> n >> q;
    ll b = sqrt(n);
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> a[i] ;
        cnt[i / b][a[i]]++;
    }
    for (int i = 1 ; i <= q ; i++)
    {
        ans = 0 ;
        cin >> l >> r >> k;
        block = r/b;
        for (int j = l ; j <= block * b-1 ; j++)
            if (j != (j/b) * b) ans += (a[j] == k);
            else ans += cnt[j/b][k] , j = (j/b + 1 ) * b -1;
        for (int j = max(l , block * b) ; j <= r ; j++) ans += (a[j] == k);
        cout << ans << endl;
    }
}

//#include <bits/stdc++.h>
//#define ll long long
//#define cll const ll
//#define lp(a, b, c) for(ll a = b; a <= c; ++a)
//#define lpd(a, b, c) for(ll a = b; a >= c; --a)
//#define vec(a) vector<a>
//#define pp(a, b) pair<a, b>
//#define EACHCASE lpd(cs, read(), 1)
//#define Fname "sqrt_dec"
//using namespace std;
//
//template <typename T> inline void Read(T &x){
//    x = 0; char c;
//    while(!isdigit(c = getchar()));
//    do
//    {
//        x = x * 10 + c - '0';
//    } while (isdigit(c = getchar()));
//}
//
//ll read(){
//    ll tmp;
//    cin >> tmp;
//    return tmp;
//}
//
//void giuncute(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//}
//
//void OF(){
//    freopen(Fname".inp", "r", stdin);
//    freopen(Fname".out", "w", stdout);
//}
//
//cll mxn = 1e5 + 7, mxv = 1e5 + 7, mxblock = 320;
//ll n, q, a[mxn], b, l, r, k, ans;
//int cnt[mxblock][mxv] = {{0}};
//
//int main(){
//    giuncute();
//    #ifndef ONLINE_JUDGE
//    OF();
//    #endif
//    cin >> n >> q;
//    b = sqrt(n);
//    lp(i, 1, n){
//        cin >> a[i];
//        ++cnt[i / b][a[i]];
//    }
//    while(q--){
//        ans = 0;
//        cin >> l >> r >> k;
//        ll first_block = l / b, final_block = r / b;
//        lp(i, l, final_block * b - 1){
//            if(i != (i / b) * b) ans += (a[i] == k);
//            else ans += cnt[i / b][k], i = (i / b + 1) * b - 1;
//        }
////        lp(i, max(final_block * b, l), r) ans += (a[i] == k);
//        ans += count(a + max(final_block * b, l), a + r + 1, k);
//        cout << ans << '\n';
//    }
//}
