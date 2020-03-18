#include<bits/stdc++.h>

using namespace std;

int n ;

int Sum(int k)
{
    int s = 0;
    while (k > 0)
    {
        s  = s + (k % 10);
        k  = k / 10;
    }
    return s;
}

long UCLN(long x , long y){
        long t = 0 ;
        while ( y  != 0 ){
            t = x % y ;
            x = y;
            y = t;
        }
        return x;
}

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("bai47.inp","r",stdin);
    //freopen("bai47.out","w",stdout);
    freopen("input.inp","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= sqrt(n)  ; i++)
    {
        if ( n % i == 0 ) d[i] ++;
    }
            
}