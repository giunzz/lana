#include<cstdio>
using namespace std;
const int maxn = 1e6+7;
long long a[maxn] , sum = 0 , n;

void fastscan(long long &number) 
{ 
    bool negative = false; 
    register int c; 
  
    number = 0; 
    c = getchar(); 
    if (c == ' ') fastscan(number);
    if (c=='-') 
    { 
        negative = true; 
        c = getchar(); 
    } 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
    if (negative) 
        number *= -1; 
} 
int main()
{
    freopen("TCHIAHET.inp","r",stdin); 
    freopen("TCHIAHET.out","w",stdout);
    fastscan(n);
    for (int i = 1 ; i <= n ; i++)
    {
        fastscan(a[i]);
        sum += a[i] % n ;
    }
    if ( sum % n == 0 ) printf("YES");
    else printf("NO");
    return 0;
}