#include<bits/stdc++.h>
#define ll long long 
#define cll const long long 
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0)
using namespace std;
char a[30][30] , x = 64;
string s1 , s;
int main()
{
    giuncute;
    cin >> s >> s1;
    for (int i = 0 ; i < 26 ; i++)
    {
        char c = 'A' + i;
        for (int j = 0 ; j < 26 ; j++)   
        {
            a[i][j] = c;
            c = (c % 26) + 'A';
        }
    }
    for (int i = 0 ; i <= 26 ; i++)
    {
        for (int j = 0 ; j <= 26 ; j++) cerr << a[i][j] << " ";
        cerr << endl;
    }
    int k = s.size() / s1.size();
    string tmp = s1;
    for (int i = 1 ; i <= k ; i++) s1 += tmp;
 //   cerr << s1 << endl << s << endl;
    for (int i = 0 ; i < s.size() ; i++) 
    {
        for (int j = 0 ; j < 26 ; j++)
        {
            char x = 'A'+j;
            if (a[s1[i] -'A'][j] == s[i]) cout << x;
        }
    }
}