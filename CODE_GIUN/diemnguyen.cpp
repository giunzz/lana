#include<bits/stdc++.h>
#define ll long long 
#define cll const long long 
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0)
using namespace std;
ll x,y,x2,y2;
int main()
{
    giuncute;
    cin >> x >> y >> x2 >> y2;
    cout << abs(__gcd(x-x2,y-y2)) - 1;
}