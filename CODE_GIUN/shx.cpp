#include <bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long 
ll a,b,c;

int main()
{
    giuncute;
    cin >> a >> b >> c;
    if (a % c == b % c ) cout << "YES";
    else cout << "NO";
}
