#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
using namespace std;

ll t ;
string s;

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> t ;
    while (t--)
    {
        string u= "";
        vector<string> a;
        cin >> s;
        int i = 0 , j = 0;
        while (i < s.length())
        {
            if ((s[i] >= '1' && s[i] <= '9') && (s[i+1] >= 'A' && s[i+1] <='Z') || (i+1 == s.length()-1)) 
            {
                u ="";
                cerr << i << endl;
                for (int z = j ; z <= i ; z++) u+=s[z];
                cerr << u << " "; 
                if (i+1 == s.length()-1) u += s[s.length()-1];
                a.push_back(u);
                j = i + 1;
            }
            else if (s[i] >= 'A' && s[i] <= 'Z' && s[i] >= 'A' && s[i] <= 'Z')
            {
                u ="";
                cerr << i << endl;
                for (int z = j ; z <= i ; z++) u+=s[z];
                u += '1';
                a.push_back(u);
                j = i + 1;
            }
            i++;
        }
        for (int i = 0 ; i < a.size() ; i++) cout << a[i] << " ";
        cout << endl;
    }
}