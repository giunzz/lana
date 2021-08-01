#define _total 50
#define _seed 38832
#define _require_skip 5

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

void init(){
    cout << "Chao mung Kem lam toan\n";
    cout << "=========================================\n";
}

bool gen(ll counter){
    system("clear");
    init();
    cout << "Day la cau hoi thu " << counter << '\n';
    ll phep = randll(0, 3);
    if(phep == 0){ // +
        ll num1 = randll(1, 1e5), num2 = randll(1, 1e5), ans = num1 + num2, res;
        cout << num1 << " + " << num2 << " = ";
        cin >> res;
        if(res == ans) return 1;
        else return 0;
    } else if(phep == 1){
        ll num1 = randll(1, 1e5), num2 = randll(1, num1), ans = num1 - num2, res;
        cout << num1 << " - " << num2 << " = ";
        cin >> res;
        if(res == ans) return 1;
        else return 0;
    } else if(phep == 2){
        ll num1 = randll(0, 1000), num2 = randll(0, 9), ans = num1 * num2, res;
        cout << num1 << " * " << num2 << " = ";
        cin >> res;
        if(res == ans) return 1;
        else return 0;
    } else{
        ll num1 = randll(0, 1000), num2 = randll(1, 9), ans_thuong = num1 / num2, ans_du = num1 % num2, res_thuong, res_du;
        cout << num1 << " / " << num2 << "\n";
        cout << "Thuong = ";
        cin >> res_thuong;
        cout << "Du = ";
        cin >> res_du;
        if(res_thuong == ans_thuong && res_du == ans_du) return 1;
        else return 0;
    }
}

void cong(ll wa){
    system("clear");
    cout << "Chuc mung Kem thui da vuot qua bai thi voi " << wa << " cau sai!!!\n";
}

int main(){
    ll wa = 0, total_ac = 0;
    lp(i, 1, _total){
        bool ok = 1;
        while(!gen(i)){
            ++wa, ok = 0, total_ac = 0;
            cout << "Saiiii\n";
            usleep(1000000);
        }
        if(++total_ac == _require_skip) i += 2;
        cout << "Dunggg\n";
        usleep(1000000);
    }
    cong(wa);
}