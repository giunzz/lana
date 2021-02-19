#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll change (ll x) {
    ll p = 0,d = 0;
    while (x > 0){
        d += (x % 10) * pow (8, p);
        p++;
        x /= 10;
    }
    return d;
}

vector<ll> np;
vector<char> he;
ll a,d1,d;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("octoa.inp","r",stdin);
    freopen("octoa.out","w",stdout);
    cin >> a;
    if (a == 0)
    {
        cout << 0 << endl << 0;
        return 0;
    }
    else 
    {
        a = change(a),d = a ,d1 = a;
    
        while (d){np.push_back(d%2), d/=2;}   
        reverse(np.begin(), np.end());
        for (ll i = 0 ; i < np.size() ; i++) cout << np[i];
        cout << endl;

        while (d1)
        {
            char x = d1 % 16 + '0';
		    if (x > 57) x = char (x - 58 + 'A');
		    he.push_back (x);
		    d1 /= 16;
        }   
        reverse(he.begin(), he.end());
        for (ll i = 0 ; i < he.size() ; i++) cout << he[i];
    }   
    
}
