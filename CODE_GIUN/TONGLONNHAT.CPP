#include<bits/stdc++.h>
using namespace std; 
const string tenfile = "TONGLONNHAT";
const int maxn = 6e6 + 7;
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
long long  ans , mi , a[maxn], n;

void fs(long long &number) 
{ 
    bool negative = false; 
    register int c; 
  
    number = 0; 
    c = getchar(); 
    if (c == ' ') fs(number);
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
    balabalo;
    fs(n);
    a[0] = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        fs(a[i]);
        a[i] += a[i-1];
    }
    mi = a[1] , ans = a[1];
    for (int i = 2 ; i <= n ; i++)
    {
        ans = max(ans, max(a[i] - mi, a[i]));
        mi = min(mi , a[i]);
    }
    printf("%I64d",ans);
    return 0;
}
