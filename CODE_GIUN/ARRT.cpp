/*#include<bits/stdc++.h>

using namespace std;

long  t , a , b , ans1 = LONG_MAX;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.inp","r",stdin);
    freopen("output.txt","w",stdout);
    //freopen("Arrt.inp","r",stdin);
    //freopen("Arrt.out","w",stdout);

    cin >> t;
    for (int  i = 0 ;   i <= t / 2   ; i++)
    {
        if ( ( (2 * t) % (i + 1) ) == 0)
        {
            //i = t / (i + 1) - 1;
            a =  ( 2 * t /( i + 1) - i ) / 2 ;
            if (a < 0 ) break;
            else  ans1 = a , b = a + i; 
            //cerr << a << " " << b << endl;
            //return 0;
        } 
    }
    cout << ans1 << " " << b;
    return 0;
}*/

#include <bits/stdc++.h>
using namespace std;
int t, a, n, b = INT_MIN;

void sol(int i)
{
    int s = t / i + 1 - i;
    if (s % 2 || s < 0) return;
    else if (i > (b - a + 1)) {
        a = s / 2;
        b = a + i - 1;
    }
}

int main(){
    freopen("arrt.inp", "r", stdin);
    freopen("arrt.out", "w", stdout);
    cin >> t;
    t *= 2;
    for (int i = 1; i * i <= t; i++){
        if (!(t % i)){
            sol(i);
            sol (t / i);
            
        }
    }
    cout << a << " " << b;
    return 0;
}