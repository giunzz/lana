#include<iostream>
#include<algorithm>
using namespace std;

long long  a , b , n , dem[12] ;

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
    for (int giun = 1 ; giun <= 500 ; giun++)
    {
        fastscan(a) ; fastscan(b);
        if ( a == 0 && b == 0 ) return 0;
        else 
            {
                for (int i = 0 ; i <= 10 ; i++) dem[i] = 0;
                long long i = min(a,b);
                while ( i <= max(a,b) )
                {  
                    long long j = i;
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
}