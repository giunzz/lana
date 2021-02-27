#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll m , n , ans = 0 , b , t, mau;


void fastscan(ll &number) 
{ 
    //variable to indicate sign of input number 
    bool negative = false; 
    register int c; 
  
    number = 0; 
  
    // extract current character from buffer 
    c = getchar(); 
    if (c=='-') 
    { 
        // number is negative 
        negative = true; 
  
        // extract the next character from the buffer 
        c = getchar(); 
    } 
  
    // Keep on extracting characters if they are integers 
    // i.e ASCII Value lies from '0'(48) to '9' (57) 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
  
    // if scanned input has a negative sign, negate the 
    // value of the input number 
    if (negative) 
        number *= -1; 
} 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PSNGUYEN.inp","r",stdin);freopen("PSNGUYEN.out","w",stdout);
    //freopen("giun.inp","r",stdin);freopen("giun.out","w",stdout);
    fastscan(m);
    fastscan(n);
    //cerr << m << " " << n;
    for (int i = 1 ; i < n ; i++)
    {
        mau = n + i;
        b = mau-(m % mau);
        b = b % mau;
        t = m / mau;
        if(b >= m) continue;
        // cerr << mau << " " << b << " " << t << endl;
        if ( t * mau + b  >= m  )--t;
        if ( b == 0 )--t;
        //cerr << t << " ";
        ans += (t + 1);
    }
    cout << ans;
}