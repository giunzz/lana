#include <bits/stdc++.h>
#define ll int
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "f"
using namespace std;

void process(ofstream &cout, ifstream &cin){
    ll n, x, r;
    cin >> n;
    cout << n << '\n';
    lp(i, 1, n){
        cin >> x >> r;
        cout << x << ' ' << r << '\n';
    }
}

int main(){
    lp(i, 1, 10){
        char file_inp[128], file_out[128];
        sprintf(file_inp, "exam/kruznice.in.%d", i);
        sprintf(file_out, "input.%03d", i + 9);
        cerr << file_inp << ' ' << file_out << '\n';
        ofstream co(file_out);
        ifstream ci(file_inp);
        process(co, ci);
        co.close(); ci.close();
    }
}