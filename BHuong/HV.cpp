#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
using namespace std;
string s, ans;
vector<string > b;
int n ;

void TRYYY (int vt )
{
    for (int i = s[0] ; i <= s[n-1] ; i++ )
    {
        int ok = 0;
        for (int j = 0 ; j < ans.length() ; j++) 
        {
            if (ans[j] == i) 
            {
                ok = 1 ;
                break;
            }
        }
        if (ok == 1) continue;
        ans.push_back(i);
        if ( (int) ans.length() == n )  b.push_back(ans);
        else TRYYY (vt + 1);
        ans.pop_back();
    }
}
int main()
{

    giuncute;
    freopen("HV.inp","r",stdin);
    freopen("HV.out","w",stdout);
    cin >> s;
    string l = s;
    reverse(l.begin() , l .end());
    sort(s.begin() , s.end());
    n = s.length();
    cerr << s << " " << l;
    TRYYY(0);
    for (int i = 0 ; i < b.size() ; i++)
    {
        if (b[i] == l) 
        {cout << i+1;
            return 0;
        }
    }
}    
