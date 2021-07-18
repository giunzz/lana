#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "f"
using namespace std;

template <typename T> inline void Read(T &x){
    x = 0; char c;
    while(!isdigit(c = getchar()));
    do
    {
        x = x * 10 + c - '0';
    } while (isdigit(c = getchar()));
}

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll mxn = 5e4 + 7;
ll n;
string s;
ll odd[mxn] = {0}, even[mxn] = {0}, ans = 0, l, r;

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> s;
    l = 0, r = -1;
    lp(i, 0, s.size() - 1){
        ll k = (i > r) ? 1 : min(odd[r - i + l], r - i + 1);
        // left = i - k + 1, right = i + k - 1
        while(0 <= i - k && i + k < s.size() && s[i - k] == s[i + k]) ++k;
        ans = max(ans, (odd[i] = k) * 2 - 1);
        ll nl = i - k + 1, nr = i + k - 1;
        if(nr > r) r = nr, l = nl;
    }
    l = 0, r = -1;
    // 1 2 3 4 5 6 7 8
    lp(i, 1, s.size() - 1){
        if(s[i] != s[i - 1]) continue;
        ll k = (i > r) ? 1 : min(even[r - i + l + 1], r - i + 1);
        // left = i - k, right = i + k - 1
        while(0 <= i - k - 1 && i + k < s.size() && s[i - k - 1] == s[i + k]) ++k;
        ans = max(ans, (even[i] = k) * 2);
        ll nl = i - k, nr = i + k - 1;
        if(nr > r) r = nr, l = nl;
    }
    cout << ans;
}


//#include <bits/stdc++.h>
//#define ll long long
//#define cll const ll
//#define lp(a, b, c) for(ll a = b; a <= c; ++a)
//#define lpd(a, b, c) for(ll a = b; a >= c; --a)
//#define vec(a) vector<a>
//#define pp(a, b) pair<a, b>
//#define EACHCASE lpd(cs, read(), 1)
//#define Fname "f"
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
//cll mxn = 1e5 + 7;
//ll n;
//string s, t;
//ll odd[mxn] = {0}, even[mxn] = {0}, ans = 0, l, r;
//
//int main(){
//    giuncute();
//    #ifndef ONLINE_JUDGE
//    OF();
//    #endif
//    cin >> n >> t;
//    for(char c : t) s += '.', s += c;
//    l = 0, r = -1;
//    lp(i, 0, s.size() - 1){
//        ll k = (i > r) ? 1 : min(odd[r - i + l], r - i + 1);
//        while(0 <= i - k && i + k < s.size() && s[i - k] == s[i + k]) ++k;
//        if(s[i - k + 1] == '.') --k;
//        ans = max(ans, (odd[i] = k) * 2 - 1);
//        ll nl = i - k + 1, nr = i + k - 1;
//        if(nr > r) r = nr, l = nl;
//    }
////    l = 0, r = -1;
////    lp(i, 1, s.size() - 1){
////        if(s[i] != s[i - 1]) continue;
////        ll k = (i > r) ? 1 : min(even[r - i + l + 1], r - i + 1);
////        while(0 <= i - k - 1 && i + k < s.size() && s[i - k - 1] == s[i + k]) ++k;
////        ans = max(ans, (even[i] = k) * 2);
////        ll nl = i - k, nr = i + k - 1;
////        if(nr > r) r = nr, l = nl;
/
///    }
//    cout << ans / 2 + 1;
//}
