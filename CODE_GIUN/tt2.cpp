#include<bits/stdc++.h>
using namespace std;
string s ;
vector<int> a;
int t = 0,ma;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("giun.inp","r",stdin);freopen("giun.out","w",stdout);
    while (cin >> s)
    {
        if (s[0] == '+' && a.size() < 15000) 
        {
            s.erase(0,1);
            t = stoi(s);
            a.push_back(t);
        }
        else if (s[0] == '-' && !a.empty() )
        {
            ma = 0;
            for (int i = 0 ; i < (int) a.size() ; i++) ma = max (ma,a[i]);
            for (int i = 0 ; i < (int) a.size() ; i++)
            {
                if (ma == a[i]) a.erase(a.begin() + i),i--;
            }
        }
    }
    sort(a.rbegin(),a.rend());
    for (int i = 1 ; i < (int) a.size() ; i++) if (a[i] == a[i-1])  a.erase(a.begin() + i);
    cout << a.size() << endl;
    for (int i = 0 ; i < (int) a.size() ; i++) cout << a[i] << endl;
}
