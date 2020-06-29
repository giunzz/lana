#include<bits/stdc++.h>
using namespace std;
int n , t , a[1008];

int UCLN (int x , int y )
{
    int  t;
    while (y != 0 )
    {
        t = x % y;
        x = y;
        y = t;
    }
    return x;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << UCLN(0,3) << endl;
    cout << 1000000000 / 2 << endl;
    cout << log(8) <<" " << log2(8);

}
