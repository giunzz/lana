#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
using namespace std;
int t ;
string s;
ll mod = 1000000007;
int main()
{
    giuncute;
    freopen("SPC5.inp","r",stdin);
    freopen("SPC5.out","w",stdout);
    cin >> t;
    while (t--)
    {
        int dt = 0 , ok = 1 ;
        cin >> s;
        if (s[0] == '_' || s[(int)s.length()-1] == '_') 
        {
            cout << 0 << endl;
            ok = 0;
        }
        if (ok == 1)
        {
            for (int i = 0 ; i < (ll) s.size() ; i++)
            {
                if (s[i] == 'T' )dt++;
            }
            cerr << dt << " ";
            if (dt == 1 || dt == 3) cout << 0 << endl;
            else if (dt == 2) cout << 1 << endl;
            else if (dt == 4) cout << 2 << endl;
        }
    }
}