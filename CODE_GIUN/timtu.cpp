#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
using namespace std;
string s ;
char c = 'z';
ll dd[(int) 1e4+7]={0} , ans = 0 , n;
int main()
{
    giuncute;
    //freopen("giun.inp","r",stdin);
    //freopen("g.out","w",stdout);
    cin >> n;
    while (n--)
    {
        cin >> s;
        ans = 0 , c = 'z';
        for (int i = 'a' ; i < 'z' ; i++) dd[i] = 0;
        for (int i = 0 ; i < s.length() ; i++) dd[s[i]]++;
        for (int i = 'a' ; i < 'z' ; i++)
        {
            if (ans < dd[i] ) ans = dd[i] , c = i;
        }
        cout << c << endl;
    }
    /*string t = "";
    for (int i = 0 ; i < s1.size() ; i++)
    {
        if (s1[i] == ' ') a.push_back(t) , t =""  ;
        else  t += s1[i];
    }
    string ans = a[0] ;
    int dem = a[0].size();
    for (int i = 1 ; i < a.size() ; i++)
    {
        if (dem < a[i].size()) ans = a[i] , dem = a[i].size();
    }
    cout << ans;*/
}
