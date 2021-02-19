#include <bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long 
string s ,t;
ll k;
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> k;
    while (cin >> s)
    {
        t = t + s+' ';
    }
    for (int i = 0 ; i < (int)t.length() ; i++)
    {
        if ((t[i] >= 'a' && t[i] <= 'z') || (t[i] >= 'A' && t[i] <= 'Z'))
            if (t[i] !=' ' ) t[i] +=  k;
        cout << t[i] % 26 ;
    }
}