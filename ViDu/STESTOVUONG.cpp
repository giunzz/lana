#include <bits/stdc++.h>
#define finame "EWE.inp" //file inp
using namespace std;
const long long maxt = 1, mint = 1, mi = 1, ma = 12 ;//limit
long long d[maxt + 3], t, k;

long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

void pri(){

    int i = 1;
    long long j = Rand(mi, ma);
    //sinh so khac nhau
    /*while (d[i] != 0 && d[i] != j && i < maxt) i++;
    if (d[i] == 0) {
        cout << j << " ";
        d[i] = j;
    }
    else pri();*/
    //sinh so co the khac hoac giong nhau
    cout << j << " ";
}

int main(){
    srand((int) time(0));
    freopen(finame, "w", stdout);
    t = Rand(mint, maxt);
    //k = Rand(mint,maxt);
    cout << t << endl;
    //cout << k << endl;
    for (int i = 1; i <= t ; i++){
        pri();
        if (i % 10 == 0) cout << endl;
        if (i % t == 0) cout << endl;
    }
    /*for (int j=1 ; j<=  k ; j++ ){
        pri();
        if (j % k == 0) cout << endl;
    }*/
    return 0;
}
