#include <bits/stdc++.h>
#define finame "input.txt" //file inp
using namespace std;
const long long maxt = 25 , mint = 1, mi = 1000, ma = 1000 ;//limit
long long d[maxt + 3], t, b;

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
    while (d[i] != 0 && d[i] != j && i < maxt) i++;
    if (d[i] == 0) {
        cout << j << " ";
        d[i] = j;
    }
    else pri();
    //sinh so co the khac hoac giong nhau
    cout << j << " ";
}

int main(){
    srand((int) time(0));
    freopen(finame, "w", stdout);
    t = Rand(1000, 1000);
    //k = Rand(mint,10);
    //int d0 = 0, d1 = 0, b = 0;
    cout << t << endl;
    //cout << k << endl;
   // for (int i = 1; i <= t ; i++){
     //   b = pri();
     //   cout << b << " ";
    }
    /*   if (b && d1 < t){
            cout << b;
            ++d1;
        } 
        else if (d0 < t){
            cout << b;
            ++d0;
        }
        else cout << 1;
    }
    for (int j=1 ; j<=  k ; j++ ){
        pri();
        if (j % k == 0) cout << endl;
    }*/
    for (int i = 1 ; i <= t ; i++) pri();
    return 0;
}
