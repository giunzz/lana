#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll  d = 0,d1 ;
string a;

void tp (string a)
{
    reverse(a.begin(), a.end()); 
    for (ll i = 0 ; i < a.size() ; i++)
    {
        d +=  (a[i]-'0')*pow(8,i);
        cerr << d << endl;
    }
}
vector<ll> np,he;
ll ok = 0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> a;
    tp(a);
    d1 = d;
    if (d == 0)
    {
        cout << 0 << endl << 0;
        return 0;
    }
    else 
    {
        while (d){np.push_back(d%2), d/=2;}   
        reverse(np.begin(), np.end());
        for (ll i = 0 ; i < np.size() ; i++) cout << np[i];
        cout << endl;

        while (d1){he.push_back(d1%16), d1/= 16;}   
        reverse(he.begin(), he.end());
        for (ll i = 0 ; i < he.size() ; i++) 
        {
            if(he[i]<10) cout<<he[i];
            else cout<<char(he[i]%10+65);
        }
    }   
    
}
