//DA HOAN CHINH
#include <bits/stdc++.h>
#define finame "test.inp" //file inp
using namespace std;
const long long maxt = 15, mint = 5, mi = 1, ma = 20; //limit
long long d[maxt + 3], t; 

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
    cout << 10 << " " << 9 << endl;
    cout << Rand(6, 10) << " " << Rand(1, 10) << endl;
    cout << Rand(1, 4) << " " << Rand(1, 10) << endl;
    for (int i = 1; i <= 10; i++){
        for (int j = 1; j <= 9; j++){
            if (Rand(1,100000) % 3) cout << "*";
            else cout << "#";
        }
        cout << endl;
    }
    return 0;
}