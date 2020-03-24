#include <bits/stdc++.h>
#define finame "ngoac.inp" //file inp
using namespace std;
const long long maxt = 1e6, mint = 1e6, mi = 0, ma = 1; //limit
long long d[maxt + 3], t, dm = 0, dn = 0, dmm = 0; 

long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

void pri(){

    int i = 1;
    long long m = Rand(mi, ma);
    //sinh so khac nhau
    /*while (d[i] != 0 && d[i] != j && i < maxt) i++;
    if (d[i] == 0) {
        cout << j << " ";
        d[i] = j;
    } 
    else pri();*/
    //sinh so co the khac hoac giong nhau
    if (m % 2 == 0 && dm <= 500000) {
        cout << "(";
        dm++, dmm++;
    } 
    else if (m % 2 == 1 && dmm > 0 && dn <= 500000){
        cout << ")";
        dn++, dmm--;
    }
    else pri();
}

int main(){
    srand((int) time(0));
    freopen(finame, "w", stdout);
    t = Rand(mint, maxt);
    //cout << t << endl;
    for (int i = 1; i <= t; i++){
        pri();
    }
    return 0;
}