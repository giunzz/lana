#define _total 20
#define _seed 38832

#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
using namespace std;

mt19937 rng(_seed);

ll randll(ll a, ll b){
    return uniform_int_distribution<ll>(a, b)(rng);
}

bool gen(ll counter){
    system("clear");
    cout << "Day la cau hoi thu " << counter << '\n';
    ll phep = randll(0, 1);
    if(phep){ // +
        ll num1 = randll(1, 1e5), num2 = randll(1, 1e5), ans = num1 + num2, res;
        cout << num1 << " + " << num2 << " = ";
        cin >> res;
        if(res == ans) return 1;
        else return 0;
    } else{
        ll num1 = randll(1, 1e5), num2 = randll(1, num1), ans = num1 - num2, res;
        cout << num1 << " - " << num2 << " = ";
        cin >> res;
        if(res == ans) return 1;
        else return 0;
    }
}

void cong(ll wa){
    system("clear");
    cout << "Chuc mung Kem thui da vuot qua bai thi voi " << wa << " cau sai!!!\n";
}

int main(){
    ll wa = 0;
    lp(i, 1, _total){
        while(!gen(i)){
            ++wa;
            cout << "Saiiii\n";
            usleep(1000000);
        }
        cout << "Dunggg\n";
        usleep(1000000);
    }
    cong(wa);
}