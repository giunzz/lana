#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

// int Phi(int n) { // = n (1-1/p1) ... (1-1/pn)
//     if (n == 0) return 0;
//     int ans = n;
//     for (int x = 2; x*x <= n; ++x) {
//         if (n % x == 0) {
//             ans -= ans / x;
//             while (n % x == 0) n /= x;
//         }
//     }
//     if (n > 1) ans -= ans / n;
//     return ans;
// }

struct quang{
    ll a, b;
    bool operator<(quang const &x) const{
        return a < x.a || (a == x.a && b > x.b);
    }
    bool operator>(quang const &x) const{
        return x < *this;
    }
};

ll cnt(ll x, ll y){
    ll tmp = 0;
    while(x / y){
        tmp += x / y;
        y *= y;
    }
    return tmp;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // priority_queue<quang, vec(quang), greater<quang>> q;
    // // OF();
    // // lp(i, 1, 75){
    // //     if(75 % i == 0) cout << i << ' ';
    // // }
    // q.push(quang{1, 3});
    // q.push(quang{2, 3});
    // q.push(quang{1, 4});
    // q.push(quang{1, 1});
    // while(q.size()){
    //     cerr << q.top().a << ' ' << q.top().b << '\n';
    //     q.pop();
    // }
    cerr << cnt(100, 5);
}