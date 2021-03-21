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

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    vec(ll) a{1, 3, 2, 5, 2, 4, 3, 2, 1};
    vec(ll)::iterator it;
    // it = remove(a.begin(), a.end(), 2);
    // a.resize(distance(a.begin(), remove(a.begin(), a.end(), 2)));
    a.erase(remove(a.begin(), a.end(), 2), a.end());
    for(auto i : a) cerr << i << ' ';
    // for(vec(ll)::iterator i = a.begin(); i != it; i++) cerr << *i << " ";
}