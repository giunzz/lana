#include<bits/stdc++.h>
using namespace std;
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

int n , k ,  a[25] , b[25] , ans = 0 , x[25] = {0} , y[25] ={0} , sum = 0 ;

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

void check_ans()
{
    for (int i = 1 ; i <= n ; i++) sum += x[i]*y[i];
    cerr << sum << " ";
    if ( sum == k ) ans ++;
    sum = 0;
}

void chon ( int vt)
{
    if ( vt == n + 1) check_ans();
    else 
    {
        for (int i = 1 ; i <= n ; i++)
        {
            x[i] = b[i];
            y[i] = a[i]; 
            chon (vt + 1);
        }
    }
}

int main()
{
    balabalo;
    fastscan(n) , fastscan(k);
    for (int i = 1 ; i <= n ; i++) fastscan(a[i]);
    for (int i = 1 ; i <= n ; i++) fastscan(b[i]);
    chon(1);
    cout << ans;
}