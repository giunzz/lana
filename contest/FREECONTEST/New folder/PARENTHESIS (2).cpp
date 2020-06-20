#include<bits/stdc++.h>
using namespace std;
//const string tenfile = "giun";//
//#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
string st;
int t , dm = 0 ;

int main()
{
    //balabalo;
    ios_base::sync_with_stdio(0) , cin.tie(0);
    cin >> t;
    for (int i = 1 ; i <= t ; i++)
    {
        cin >> st;
        dm = 0 ;
        if ( st[0] == ')')
        {
            cout << "NO" << endl;
            continue;
        }
        else
        {
            for (int i = 0 ; i < (int) st.length() ; i++)
            {
                if ( st[i] == '(' ) {++dm;}
                else if ( st[i] == ')') {--dm;}
            }
        if ( dm == 0 ) cout << "YES" << endl;
        else cout << "NO" << endl;
        }
    }
    return 0;
}