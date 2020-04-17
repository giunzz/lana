#include<bits/stdc++.h>
using namespace std;
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

string a , b;
int n , m , t;

int main()
{
    balabalo;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> b >> n >> m;
    a = b;
    reverse(b.begin() , b.end());
    
    cerr << a << " " << b << endl;

    t = m / a.size() + m % a.size();
    cerr << t;
    if ( a.size() % 2 == 0 )
    {
        if ( t % 2 != 0 ) cout << a[ m % a.size()];
        else cout << b[ m % b.size()];
    }
    else
    {
        if ( t % 2 != 0 ) cout << a[t % a.size() ];
        else cout << b[t % b.size() ];    
    }
    return 0;
}

