#include<bits/stdc++.h>
using namespace std;
const string tenfile = "Bai47QL";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);

int n ;
string ans;
char a[] = {'(' ,')' };

bool kt ( string ans)
{
    int d = 0;
    for (int i = 0 ; i < 2*n ; i++)
    {
        if ( ans[i] == '(') d++;
        else d--;
        if ( d < 0 ) return false;
    }
     return ( d == 0 );
}

void quayyyvongvong ( int vt )
{
    for (int i = 0 ; i < 2 ; i++)
    {
        ans.push_back( a[i] );
        if ( vt == 2*n - 1)
        {
            if ( kt (ans)  == true ) cout << ans << endl;
        }
        else quayyyvongvong(vt + 1);
        ans.pop_back();
    }
}

int main()
{
    balabalo;
    giuncute;
    cin >> n;
    quayyyvongvong(0);
}
