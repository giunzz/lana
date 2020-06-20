#include<bits/stdc++.h>
using namespace std;
string st;
int t , d = 0;

int main()
{
    ios_base::sync_with_stdio(0) , cin.tie(0);
    cin >> t;
    for (int i = 1 ; i <= t ; i++)
    {
        cin >> st;
        d = 0;
        if ( st[0] == '*') st[0] ='(' ;
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