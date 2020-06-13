/*#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
using namespace std;
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);

int  a , b , n , dem[12] ;

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

int main()
{
    balabalo;
    for (int giun = 1 ; giun <= 500 ; giun++)
    {
        fastscan(a) ; 
        fastscan(b);
        //cin >> a >> b ;
        cerr << a << " " << b << endl;
        if ( a == 0 && b == 0 ) return 0;
        else 
            {
                for (int i = 0 ; i <= 10 ; i++) dem[i] = 0;
                int i = min(a,b);
                while ( i <= max(a,b) )
                {  
                    int j = i;
                    while (j != 0 )
                    {
                        dem[j % 10 ]+= 1;
                        j = j / 10;
                    }
                    i++;  
                }
                for (int i = 0 ; i < 10 ; i++) cout << dem[i] << " ";
                cout << endl;
            }
    }
}*/

#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e6;

int n , sang[maxn + 9]={0};

void ss()
{
    sang[0] = 1 , sang[1] = 1;
    for ( int i = 2 ; i <= maxn ; i++)
        if (!sang[i])
            for (int j = i+i ; j <= maxn ; j += i ) sang[j] = 1;
}

int main()
{
    ss();
    for( int i = 1 ; i <= 100 ; i ++ )
        if(sang[i] == 0 ) cout << i << " ";
    return 0;
}