#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5;
int test, A, B, a[N];
int Solve(int x)
{

    int tmp, i;
    memset(a, 0, sizeof(a));
    tmp = x; i = 2;
    while (tmp > 1 && i * i <= x) {
        if (tmp % i == 0) {
            while (tmp % i == 0) {
                a[i]++;
                tmp /= i;
            }
        }
        i++;
    }
    int res = tmp;
    for(int i = 1; i <= sqrt(x); ++i) {
        res = res * ((a[i] % 2 == 0) ? 1 : i);
    }
    return res;
}
int main()
{
    #define file "MINSUM"
    freopen(file".INP" ,"r" ,stdin);
    freopen(file".OUT" ,"w" ,stdout);
    scanf("%d", &test);
    while (test--) {
        scanf("%d%d", &A, &B);
        int g = __gcd(A, B);
        A /= g; B /= g;
        printf("%d %d\n", Solve(A), Solve(B));
    }
    return 0;
}
