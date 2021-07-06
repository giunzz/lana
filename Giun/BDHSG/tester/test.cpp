#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "bitree"
using namespace std;

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    system("g++ "Fname".cpp -o "Fname);
    system("g++ checker_"Fname".cpp -o checker_"Fname);
    lp(i, 1, 15){
        cerr << "Test " << i << ": ";
        ofstream putInp(Fname".inp");
        putInp << i;
        putInp.close();
        system("bitree");
        system("checker_bitree");
        cerr << '\n';
    }
}