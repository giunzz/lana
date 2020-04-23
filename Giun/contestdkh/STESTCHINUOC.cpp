#include <bits/stdc++.h>
using namespace std;
long long d[1000 + 7], t;

long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

void pri(){

    int i = 1;
    long long j = Rand(1000, 1000000000000);
    while (d[i] != 0 && d[i] != j && i <= 1000) i++;
    if (d[i] == 0) {
        cout << j << endl;
        d[i] = j;
    } 
    else pri();
}

int main(){
    freopen("CHINUOC.INP", "w", stdout);
    //t = Rand(100, 1000);
    t = 1;
    cout << t << endl;
    cout << 1000000000000;
    //for (int i = 1; i <= t; i++){
      //  pri();
    //}
    return 0;
}