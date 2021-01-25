#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
// #define Fname "caersar"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

ll n;
string s, t;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n >> s >> t;
    s += s;
    lp(i, 0, 26){
        for(char &c : s){
            c = (c - 'a' + 26 - i) % 26 + 'a';    
        }
        size_t it = s.find(t);
        if(it != string::npos){
            cout << "Possible\n" << it << ' '  << i;
            return 0;
        } 
    }
    cout << "Impossible";
}   