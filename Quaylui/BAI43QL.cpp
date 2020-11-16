#include<bits/stdc++.h>
using namespace std;
const string tenfile = "bai43QL";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);

string s , ans;
int a[300] ={0};

void huhu( int vt )
{
    for (int i = 0 ; i < (int) s.length()  ; i++)
    {
        if ( a[s[i]]  == 0)
        {
            ans.push_back(s[i]);
            a[s[i]] = 1;
            if ( vt == s.length() - 1 ) cout << ans << endl;
            else huhu ( vt + 1);
            //ans.pop_back();
            a[s[i]] = 0;
        }
    }
}

int main()
{
    //balabalo;
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> s;
    //sort ( s.begin() , s.end());
    huhu(0);
}