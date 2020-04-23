#include <bits/stdc++.h>
#define finame "minsum.inp" //file inp
using namespace std;
const long long maxt = 1e5, mint = 1e5 / 2, mi = -1 * 1e9, ma = 1e9; //limit
long long d[maxt + 3], t, m, n; 

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
    m = t;
    t = Rand(mint, maxt);
    n = t;
    cout << m << " " << n << endl;
    for (int i = 1; i <= m; i++){
        pri();
    }
    cout << endl;
    for (int i = 1; i <= n; i++){
        pri();
    }
    return 0;
}