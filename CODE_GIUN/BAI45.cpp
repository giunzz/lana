#include<bits/stdc++.h>
using namespace std;
const string tenfile = "BAI45";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);

string st;
int ans ;

int main()
{
    balabalo;
    giuncute;
    cin >> st ;
    int giun = 1;
    for (int i = 0 ; i < (int) st.length() ; i++)
    {
        if (st[i] == 'C') ans += giun , giun ++ ;
        else ans += 0 , giun = 1;
    }
    cout << ans;
}