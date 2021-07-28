#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
const ll maxn = 3e3 +  7;
using namespace std;
ll  t;
string s;
ll p[] ={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};

ll calc (ll x , ll y)
{
    if (x > y) swap(x, y);
    return min (p[y] - p[x] , 26 + p[x] - p[y] );
}
int main()
{
    giuncute;
    freopen("ac5.inp" ,"r",stdin);
    freopen("ac5.out", "w" ,stdout);
    cin >> t;
    while (t--)
    {
        ll ans1 = INT_MAX , ans2 = INT_MAX, tmp1 = 0 , tmp2 = 0 ;
        vector<char> a , b;
        ll dd[30] = {0};
        cin >> s;
        for (int i = 0 ; i < (int) s.size() ; i++) dd[s[i] - 'a' + 1]++;
        for (char c = 'a' ; c <= 'z' ; c++)
        {
            if (dd[c - 'a' + 1] != 0)
                if (dd[c - 'a' + 1] % 2 != 0) a.push_back(c);
        }
        if (a.size() > 1)
        {
            sort(a.begin() , a.end());
            //for (int i = 0 ; i < (int) a.size() ; i ++) cerr << a[i] << " ";
            //cerr << endl;
            if (a.size() % 2 == 0)
            {
                ans1 = 0 , ans2 = 0 ;
                for (int i = 0 ; i < (int) a.size() ; i += 2) ans1 += calc(a[i] - 'a' + 1 ,a[i + 1] - 'a' + 1);
                a.push_back(a[0]);
                for (int i = 1 ; i < (int) a.size() ; i += 2) ans2 += calc(a[i] - 'a' + 1 ,a[i + 1] - 'a' + 1);
                cout << min(ans1 , ans2) << endl;
            }
            else 
            {
                for (int j = 0 ; j < (int) a.size() ; j++)
                {
                    b = a;
                    b.erase(b.begin() + j );
                    //for (int i = 0 ; i < (int) b.size() ; i ++) cerr << b[i] << " ";
                    //cerr << endl;
                    for (int i = 0 ; i < (int) b.size() ; i += 2 )  tmp1 += calc(b[i] - 'a' + 1 ,b[i + 1] - 'a' + 1);
                    ans1 = min(ans1 , tmp1);
                }
                a.push_back(a[0]);
                for (int j = 1 ; j < (int) a.size() ; j++)
                {
                    b = a;
                    b.erase(b.begin() + j );
                   // for (int i = 1 ; i < (int) b.size() ; i ++) cerr << b[i] << " ";
                   // cerr << endl;
                    for (int i = 1 ; i < (int) b.size() ; i += 2 )  tmp2 += calc(b[i] - 'a' + 1 ,b[i + 1] - 'a' + 1);
                    ans2 = min(ans2, tmp2);
                }
                cout << min(ans1 , ans2) << endl;
            }
        }
        else cout << 0 << endl;
    }
}
