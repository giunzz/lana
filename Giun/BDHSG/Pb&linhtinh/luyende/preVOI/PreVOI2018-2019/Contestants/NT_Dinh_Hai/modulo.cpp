#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
using namespace std;

long long n, k, a, b, tmp[45], MOD, mul, have[4200000];
string res, str[4200000];

void cal1(int i){
    if(i == n + 1){
        if(tmp[i - 1] == k) {cout << res << "\n"; exit(0);}
        return ;
    }
    tmp[i] = (tmp[i - 1] * 10 + a) % MOD;
    res[i - 1] = (char)(a + '0');
    //cerr << i << " " << res << " " << tmp[i] << "\n";
    cal1(i + 1);
    tmp[i] = (tmp[i] + b - a + MOD) % MOD;
    res[i - 1] = (char)(b + '0');
    //cerr << i << " " << res << " " << tmp[i] << "\n";
    cal1(i + 1);
}

void sub1(){
    res = "";
    tmp[0] = 0;
    for(int i = 1; i <= n; i++) res = res + '0';
    MOD = 1 << n;
    cal1(1);
    cout << "-1";
}

void cal2l(int i){
    if(i == (n / 2) + 1){
        str[(tmp[i - 1] * mul) % MOD] = res;
        have[(tmp[i - 1] * mul) % MOD] = 1;
        //cerr << "found " << (tmp[i - 1] * mul) % MOD << " " << res << "\n";
        return;
    }
    tmp[i] = (tmp[i - 1] * 10 + a) % MOD;
    res[i - 1] = (char)(a + '0');
    //cerr << i << " " << res << " " << tmp[i] << "\n";
    cal2l(i + 1);
    tmp[i] = (tmp[i] + b - a + MOD) % MOD;
    res[i - 1] = (char)(b + '0');
    //cerr << i << " " << res << " " << tmp[i] << "\n";
    cal2l(i + 1);
}

void cal2r(int i){
    if(i == n + 1){
        if(have[(k - tmp[i - 1] + MOD) % MOD]) {cout << str[(k - tmp[i - 1] + MOD) % MOD] << res; exit(0);}
        return;
    }
    tmp[i] = (tmp[i - 1] * 10 + a) % MOD;
    res[i - (n / 2) - 1] = (char)(a + '0');
    //cerr << i << " " << res << " " << tmp[i] << "\n";
    cal2r(i + 1);
    tmp[i] = (tmp[i] + b - a + MOD) % MOD;
    res[i - (n / 2) - 1] = (char)(b + '0');
    //cerr << i << " " << res << " " << tmp[i] << "\n";
    cal2r(i + 1);
}

void sub2(){
    memset(have, 0, sizeof have);
    ///First half
    res = "";
    tmp[0] = 0;
    for(int i = 1; i <= n / 2; i++) res += '0';
    MOD = 1 << n;
    mul = 1;
    for(int i = n / 2 + 1; i <= n; i++) mul = (mul * 10) % MOD;
    cal2l(1);
    ///Second half
    res = "";
    tmp[n / 2] = 0;
    for(int i = n / 2 + 1; i <= n; i++) res += '0';
    cal2r(n / 2 + 1);
    cout << "-1";
}

int main(){
    freopen("modulo.inp", "r", stdin);
    freopen("modulo.out", "w", stdout);
    cin >> a >> b >> n >> k;
    if(n <= 20) sub1();
    else{
        if(n <= 45) sub2();
        else {cout << ":("; return 0;}
    }
    //sub2();
}
