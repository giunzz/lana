#include<bits/stdc++.h>
using namespace std;

long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}
int main()
{
    freopen("giun.inp","w",stdout);
    cout << 40 << endl;
    int t = 40;
    while (t--)
    {
        int n = Rand(1,100000 );
        cout << n << " ";
        int k = Rand(1,5);
        cout << k << endl;
        
}
}