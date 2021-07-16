#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0)

const ll maxn = 1e5+7;
ll  x , y , u = 0 , v = 0;
ll dx[] = {-1 , -1, -1 , 0 , 0 , 0 , 1 , 1 ,1 };
ll dy[] = { 1 , 0 , -1 , 1 , 0 , -1 , 1 , 0 , -1};
string s;
vector<ll> res;
inline bool check (ll a , ll b)
{
    for (int i = 0 ; i <= 8 ; i++)
        if (x + dx[i] == a && y + dy[i] == b) return true;
    return false;
}
int main()
{ 
    giuncute;
    freopen("giun.inp", "r", stdin);
    freopen("giun.out", "w", stdout);
    cin >> x >> y >> s ;
    s = '.' + s;
    if (check(u,v) == true) res.push_back(0);
    for (int i = 1 ; i < (int) s.size() ; i++)
    {
        if (s[i] == 'U') v++;
        else if (s[i] == 'D') v--;
        else if (s[i] == 'L') u--;
        else if (s[i] == 'R') u++;
        if (check(u,v) == true) res.push_back(i);
    }
    if ( (int)res.size() == 0) cout <<-1;
    else for (int i = 0 ; i < (int) res.size() ; i++) cout << res[i] << endl;
}