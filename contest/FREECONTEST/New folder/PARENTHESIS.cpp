#include<bits/stdc++.h>
using namespace std;
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)
string st;
int t , d = 0;

int main()
{
    //balabalo;
    giuncute;
    cin >> t;
    for (int i = 1 ; i <= t ; i++)
    {
        cin >> st;
        d = 0;
        for (int i = 0 ; i < (int) st.length() ; i++)
        {
            if ( st[i] == '(' ) d ++;
            else if ( st[i] == ')' ) d--;
                else if ( st[i] == '*' ) 
                {
                    if ( d >= 1 ) d --;
                    else if ( d <= 0 ) d ++;
                }
        }
        if ( d == 0 ) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}