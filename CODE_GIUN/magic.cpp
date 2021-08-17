#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 1e3 +7;
using namespace std;
ll n , m , b , c , vt ;
string s , s1 ;
char a[maxn][maxn];
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> m ;
    vt = 2*n;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> s ;
        s1 = s , reverse(s1.begin() , s1.end());
        s += s1;
        ll id = 0 ;
        for(int j = 1 ; j <= 2*m ; j++) a[i][j] = s[id] , a[vt][j] = s[id] , id++;
        vt--;
    }
    cin >> b >> c;
    if (a[b][c] == '.' ) a[b][c] = '#';
    else a[b][c] = '.'; 
    for (int i = 1 ; i <= 2*n ; i++)
    {
        for (int j = 1 ; j <= 2*m ; j++) cout << a[i][j];
        cout << endl;
    }
}