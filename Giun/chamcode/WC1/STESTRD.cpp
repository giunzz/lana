//DA HOAN CHINH
#include <bits/stdc++.h>
#define finame "test02\\wc1.inp" //file inp
using namespace std;
const long long miN = 10000, maN = 100000, ma = 100000; //limit
long long n;

long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

int main(){
    srand((int) time(0));
    freopen(finame, "w", stdout);
    cout << 20 << endl;
    for (int i = 1; i <= 20; i++)
    {       
        if (i <= 5) n = Rand(2000, 10000);
        else n = Rand(20000, 100000);
        cout << n << endl;
        for (int i = 1; i <= n; i++){
            cout << Rand(2, ma) << " ";
        }
        cout << endl;
    }
    return 0;
}