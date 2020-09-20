#include <cstdio>
using namespace std;
//const string file = "giun";
const int maxn = 1e5+7;
#define balabolo(a) freopen((a + ".inp").c_str(), "r", stdin) ,freopen((a + ".out").c_str(), "w", stdout)
int n , t , a[maxn] , b[maxn] ;
long long  sa = 0 , sum ;


void fastscan(int &num)
{
    bool neg = false;
    register int c;
    num = 0;
    c = getchar();
    if (c == ' ' || c == '\n') fastscan(num);
    if (c=='-')
    {
        neg = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        num = num *10 + c - 48;
    if (neg)
        num *= -1;
}

int main()
{
    balabolo(file);
    fastscan(n) ; fastscan(t);
    int i = 0 ;
    //lalalalala
    for (int i = 1 ; i <= n ; i++)
    {
        fastscan(a[i]) ; fastscan(b[i]) ;
        sa += a[i];
        a[i] -= b[i];
    }
    printf("%I64d\n", sa);
    for (int i = 1 ; i <= t ; i++)
    {
        sum = 0;
       for (int j = 1 ; j <= n ; j++)
       {
           if ( a[j] > 0) sum += a[j];
           a[j] -= b[j];
       }
        printf("%I64d\n", sum);
    }
    return 0;
}
