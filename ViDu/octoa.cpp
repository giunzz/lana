#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll  d = 0,d1 ;
string a;

void tp (string a)
{
    reverse(a.begin(), a.end()); 
//    cerr << a << endl;
    for (ll i = 0 ; i < a.size() ; i++)
    {
        d +=  (a[i]-'0')*pow(8,i)  ;
//        cerr  <<  a[i]-'0' << " " << pow(8,i) << " " << d << endl; 
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
//    cerr << d1 << endl;
    
    while (d){np.push_back(d%2), d/=2;}   
    reverse(np.begin(), np.end());
    for (ll i = 0 ; i < np.size() ; i++) cout << np[i];
    cout << endl;

    while (d1){he.push_back(d1%16), d1/= 16;}   
    reverse(he.begin(), he.end());
    for (ll i = 0 ; i < he.size() ; i++) 
    {
        if (he[i] == 10) cout << 'A';
        else  if (he[i] == 11) cout << 'B';
        else  if (he[i] == 12) cout << 'c';
        else  if (he[i] == 13) cout << 'D';
        else  if (he[i] == 14) cout << 'E';
        else  if (he[i] == 14) cout << 'F';
        else cout << he[i];
    }
}