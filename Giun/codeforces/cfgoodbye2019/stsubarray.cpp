#include <bits/stdc++.h>
#define finame "subarray.inp" //file inp
using namespace std;
const long long maxt = 1e4, mint = 1e3, mi = 0, ma = 1e9, minn = 2, maxn = 2e5; //limit
long long d[maxt + 3], t, n; 

long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

void pri(){

    //int i = 1;
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
    cout << t << endl;
    for (int i = 1; i <= t; i++){
        n = Rand(minn, maxn);
        cout << n << endl;
        for (int i = 1; i <= n; i++) pri();
        cout << endl;
    }
    cerr << "done!";
    return 0;
}