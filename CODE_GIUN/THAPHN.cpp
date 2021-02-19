#include<iostream>
#include<stdio.h>
using namespace std;
void Tower(int n , int a , int b , int c )
{
    if (n == 1)
    {
        cout << a << " " << c << endl;
        return;
    }
    Tower(n-1,a,c,b);
    Tower(1,a,b,c);
    Tower(n-1,b,a,c);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("thaphn.inp","r",stdin);
    freopen("thaphn.out","w",stdout);
    int a = 1, b = 2, c = 3;
    int n;
    cin >> n;
    Tower(n,a,b,c);
}