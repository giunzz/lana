#include<bits/stdc++.h>
using namespace std;
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);

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

int n , a[55][55] ;

int main()
{
    balabalo;
    giuncute;
    cin >> n ;
    
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= n ; j++) 
        {
            if ( j == n) cout << endl;
            else cout 
        }
    return 0;
}

