#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
unsigned ll a , b, c , d;

int main()
{
    giuncute;
    //freopen("giun.inp","r",stdin);
    //freopen("giun.out","w",stdout);
    cin >> a >> b >> c >> d;
    if ( max({a,b,c}) - min({a,b,c}) > d ) 
    {
        cout << "NO";
        return 0;
    }
    cout << "YES";
}