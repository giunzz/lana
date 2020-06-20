#include <bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

int n , w[30] , v[30] , c , k,ans = 0 ,x[30] ={0 };

void fastscan(int &number) 
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

void chon (int vt)
{
    if(vt == n +1)
    {
        int s1 = 0 , s2 = 0;
        for(int i = 1 ; i <= n ; i++) s1 += x[i]*w[i] , s2 += x[i]*v[i];
        if ( s2 == k && s1 <= c) ans++; 
    }
    else 
    {
        for (int i = 0 ; i <= 1 ; i++)
        {
            x[vt] = i;
            chon(vt+1);
        }
    }
}
int main()
{
    balabalo;
    giuncute;
    fastscan (n) ;
    fastscan (c) ;
    fastscan (k) ;
    for (int i = 1 ; i <= n ;  i++) fastscan(w[i]);
    for (int i = 1 ; i <= n ;  i++) fastscan(v[i]);
    chon(1);
    cout << ans;
}