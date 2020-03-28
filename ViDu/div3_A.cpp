#include<bits/stdc++.h>
//#define giuncute freopen("input.inp", "r", stdin) , freopen("output.txt", "w", stdout)
using namespace std;
int a , b , t , ans = 0;

int main()
{
    //giuncute;
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> t;
    for (int i = 1 ; i <= t ; i++)
    {
        cin >> a >> b;
        if (a % b != 0)  ans =  ( ( (a / b) + 1 ) * b ) - a; 
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}