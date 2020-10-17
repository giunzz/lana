#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)
#pragma GCC optimize("Ofast")
#define ballolo freopen("PARTY.inp","r",stdin),freopen("PARTY.out","w",stdout)
using namespace std;
string a[22];
ll ans[22] = {0}, n;
bool d[22] = {0}, ok = 0;
vector<ll> pos[200];

void giun (ll vt )
{
    if(ok) return;
    if (vt == 1 )
    {
        for (int i = 1 ; i <= n ; i++)
        {
            ans[vt] = i, d[i] = 1;
            giun(vt + 1);
            d[i] = 0;
        }
    }
    else if (vt <= n )
    {
        for (int i = 1 ; i <= n ; i++)
        {
            if(d[i]) continue;
            for (char &c : a[i])
            {
                ll k = binary_search(pos[c].begin() , pos[c].end() , ans[vt-1]);
          //      cerr << k << endl;
                if (k)
                {
                    ans[vt] = i , d[i] = 1;
                    giun(vt + 1);
                    d[i] = 0;
                    break;
                }
            }
        }
    }
    else
    {
        for (char&c : a[ans[1]])
        {
            ll k = k = binary_search(pos[c].begin() , pos[c].end(), ans[vt-1]);
            if (k)
            {
                for (int i = 1 ; i <= n ; i++) cout << ans[i] << endl ;
                ok = 1;
                break;
            }
        }
    }
}



int main()
{
    giuncute;
    ballolo;
    cin >> n ;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        for (char &c : a[i])
        {
        //cerr << c << " " << a[i] << endl;
        pos[c].push_back(i);
        }
    }
    giun(1);
    if (ok == 0) cout << "NO SOLUTION";

}
