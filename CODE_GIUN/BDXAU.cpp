#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
const ll maxn = 1e3 + 7;
using namespace std;
string s, s1 ;
ll f[maxn][maxn] = {0};
int main()
{
    giuncute;
    freopen("bdxau.inp" ,"r",stdin);
    freopen("bdxau.out", "w" ,stdout);
    cin >> s >> s1;
    s = '0' + s ;
    s1 ='0' + s1;
    for (int i = 1 ; i < s.length() ; i++) f[i][0] = i;
    for (int i = 1 ; i < s1.length() ; i++) f[0][i] = i , cerr << f[0][i] << " ";
    cerr << endl;
    for (int i = 1 ; i < s.length() ; i++)
    {
        for (int j = 1 ; j < s1.length() ; j++)
        {
            if (s[i] == s1[j]) f[i][j] = f[i-1][j-1];
            else f[i][j] = min ({f[i-1][j-1] , f[i-1][j] , f[i][j-1]}) + 1;
        //    cerr << f[i][j] <<  " ";
        }
        //cerr << endl;
    }
    cout << f[s.length()-1][s1.length()-1];
}

