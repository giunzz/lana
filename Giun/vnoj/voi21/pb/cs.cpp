#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "pb"

void gene(){
    ofstream co(Fname".inp");

    co.close();
    system(Fname);
    system(Fname"_bruce");
}

bool check(){
    ll stt = system("fc " Fname ".out " Fname ".ans /w");
    return stt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    lp(i, 1, 1){
        gene();
        if(check()) break;
    }
}
