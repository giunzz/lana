#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
#define ballolo freopen("giun.inp","r",stdin),freopen("giun.out","w",stdout);
#pragma GCC optimize("Ofast")
ll n,  d[25]={0};
string x[25];
vector <ll> v;

void giun (int vt)
{
    if (vt == n + 1 ) 
    {
        for (int i = 0 ; i < v.size(); i++) cout << v[i] << endl;
    }
    else 
    {
        for (int i = 1 ; i <= n ; i++)
        {
            if ( i == vt ) continue;
            else if (d[i] <= 2)
            {
                if (x[vt].find(x[i])  != string::npos) 
                {
                    v.push_back(vt); 
                    v.push_back(i);
                    d[i]++;
                    d[vt]++;
                    cerr << i << " " << vt << endl;
                }
                 giun(vt+1);
            }
           
            //cerr << x[i] << " " << x[vt] << endl;
        }
    }
}


int main()
{
    giuncute;
    ballolo;
    cin >> n;
    for (ll i = 1 ; i <= n ; i++) cin >> x[i];
    giun(1);    
    
}


