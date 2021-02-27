#include<bits/stdc++.h>

using namespace std;

long y , x ;

int Sum(long k)
{
    int  s = 0;
    while (k > 0)
    {
        s  = s + (k % 10);
        k  = k / 10;
    }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("bai54.inp","r",stdin);
    freopen("bai54.out","w",stdout);
    //freopen("input.inp","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> y ;
    //x = y - 1;
    int i = 1;
    while ( y != x + Sum(x) )
    {
        x = y - i;
        i++;
    }
    cout << x  ;
    //cerr << clock() << " ms ";
    return 0;
}