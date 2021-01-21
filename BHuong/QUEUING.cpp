#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long 
string s ;
int dd[300]={0} ;
char c ; 
int main()
{
    giuncute;
    freopen("QUEUING.inp","r",stdin);
    freopen("QUEUING.out","w",stdout);
    cin >> s;
    for (int i = 0 ; i < s.length() ; i++)
    {
        if (s[i+1] < s[i]) 
        {
            c = s[i];
            break;
        }
    }
    if (c == '') c=s[s.length()-1];
    for (int i = 0 ; i < s.length() ; i++)
    {
        if (s[i] != c) cout << s[i];
    }
}