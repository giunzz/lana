#include<iostream>
#include<stdio.h>
using namespace std;

long long n , dem = 0 , s = 0;

void xuat ()
{
    cout << dem << " " << s; 
}

void solve(long long  q )
{   
    long long x ;
    if (q == 0 ) xuat();
    else 
    {
        x = q % 10 ;
        s = s + x;
        dem++;
        solve (q / 10);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.inp","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n ;
    solve(n);
}
