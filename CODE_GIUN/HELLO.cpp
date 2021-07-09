#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
const ll maxn = 1e6 + 7 ;
using namespace std;
ll cnt = 0 ;
string s;

int main()
{
    freopen("giun.inp" , "r",stdin);
    freopen("giun.out", "w" , stdout);
    cin >> s;
    string a = "hello";
    for (int i = 0 ; i < s.size() ; i++)
        if (s[i] >='A' && s[i] <= 'Z') s[i] += 32;
    cerr << s << " " << a << endl;
    for (int i = 0 ; i < s.size() ; i++)
    {
        int k = 0;
        if (s[i] == a[k])
        {
            cnt = 1;
            k++;
            for (int j = i + 1 ; j < s.size() ; j++)
            {
                if (s[j] == a[k]) 
                {
                    cnt ++;
                    cerr << s[j] << " " << a[k] << endl;
                    k++;
                }
                else 
                {
                    break;
                }
            }
            cerr << a.size() << " " << cnt << endl;
            if (cnt == a.size()) 
            {
                
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}