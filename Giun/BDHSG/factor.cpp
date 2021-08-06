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

cll mxn = 1e7 + 5;
ll sang[mxn] = {0}, m;

void sol(){
    cin >> m;
    if(m < 2) cout << m << '\n';
    else{
        string s;
        ll tmp = sqrt(m);
        for(ll i = 2; i <= tmp && m != 1; i++)
            while(m % i == 0){
                s += to_string(i) + "*";
                m /= i;
            }
        if(m > 1) s += to_string(m);
        else s.pop_back();
        cout << s << '\n';
    }
}

int main(){
    giuncute();
    #ifdef PMQ
    OF();
    #endif
    // for(ll i = 2; i * i <= 1e7; ++i){
    //     if(!sang[i]) for(ll j = i * i; j <= 1e7; j += i){
    //         if(!sang[j]) sang[j] = i;
    //     }
    // }
    EACHCASE sol();
}