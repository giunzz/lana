#include <bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long 
string s ,t;
ll k;
int main()
{
    giuncute;
    freopen("mahoa.inp","r",stdin);
    freopen("mahoa.out","w",stdout);
    cin >> k;
    while (cin >> s)
    {
        t = t + s+' ';
    }
    s.pop_back();
    for (int i = 0 ; i < (int)t.length() ; i++)
    {
        if (t[i] >= 'a' && t[i] <= 'z')
        {
            if(t[i]+k > 'z') t[i] = (t[i] + k)%'z' + 'a' - 1;
			else t[i] += k;
        } 
        else if (t[i] >= 'A' && t[i] <= 'Z')
        {
            if(t[i]+k > 'Z') t[i] = (t[i] + k)%'Z' + 'A' - 1;
			else t[i] += k;
        }
        cout << t[i]  ;
    }
}