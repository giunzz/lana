#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
const ll maxn = 3e3 +  7;
using namespace std;
ll  t , d[200];
string s ,  a;

ll calc (ll i , ll j)
{
    ll x = i - 'a' + 1 , y = j - 'a' + 1;
    if (x > y ) swap(x,y);
    return min( y - x , 26 + x - y );
}
ll pro()
{
    ll sum = 0 ;
    for (int i = 0 ; i < a.size() ; i+=2) sum += calc(a[i] , a[i+1]);
    return sum ;
}

ll make()
{
    a.clear();
    for (char i = 'a' ; i <= 'z'; i++)
        if(d[i] == 1) a += i;
    if (a.size() == 0) return 0;
    ll tmp = pro();
    a.push_back(a[0]);
    a.erase(a.begin());
    return min(tmp , pro());
}
int main()
{
    giuncute;
    freopen("giun.inp" ,"r",stdin);
    freopen("giun.out", "w" ,stdout);
    cin >> t;
    while (t--)
    {
        cin >> s;
        ll  ans = INT_MAX , num = 0 ;
        for (char i = 'a' ; i <= 'z'; i++) d[i] = 0 ;
        for (char c : s) d[c]  = (d[c] + 1) % 2 ;
        for (char i = 'a' ; i <= 'z'; i++) num += d[i];
        if (num % 2 == 1)
        {
            for (char i = 'a' ; i <= 'z'; i++)
            {
                if(d[i] == 1)
                {
                    d[i] = 0;
                    ans = min(ans , make());
                    d[i] = 1;
                }
            }
        }
        else ans = min(ans , make());
        cout << ans << endl;
    }
}
