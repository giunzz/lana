#include<bits/stdc++.h>
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)
using namespace std;
int t , oxh1;
string s , name1;
struct giun
{
    string name ;
    int num ;
    int oxh;
};
vector<giun>a;
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> t;
    while (t--)
    {
        a.clear();
        int l = -1 , r = -1;
        cin >> s;
        for (int i = 0 ; i < s.length() ; i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z') 
            {
                string ten ="";
                ten += s[i];
                a.push_back((giun) {ten,1,100});
            }
            else if (s[i] >= 'a' && s[i] <= 'z') a.back().name += s[i];
            else if (s[i] >= '0' && s[i] <= '9')
            {
                int so = s[i] -'0';
                if ( l == -1 || r == -1) a.back().num = so;
                else for (int j = l ; j <= r ; j++) a[j].num *= so;
            }
            else if (s[i] == '(') l = (int) a.size();
            else r = (int) a.size()-1;
        }
        for (int i = 0 ; i < a.size() ; i++) cout << a[i].name << " " <<  a[i].num << " " << a[i].oxh << endl;
        int ans = 0;
        for (int i = 1 ; i < a.size() ; i++)
        {
            cin >> name1 >> oxh1;
            name1.pop_back();
            for (int j = 0 ; j < a.size() ; j++)
                if (a[j].name == name1) a[j].oxh = oxh1;
        }
        int ok = -1;
        for (int i = 0 ; i < a.size() ; i++)
        {
            if (a[i].oxh == 100)
            {
                ok = i ;
                continue;
            }
            ans -= a[i].oxh * a[i].num;
        }
        ans /= a[ok].num;
        cout << ans << endl;
    }

}