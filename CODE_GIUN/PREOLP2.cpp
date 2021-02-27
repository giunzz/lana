#include<bits/stdc++.h>
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define ll long long 
using namespace std;
ll n  , m , t , ans = 0 , f[100]={0} , ft[100]={0};
char  a[100][100] ;
void blablalolo()
{
    freopen("PREOLP1.INP","r",stdin);
    freopen("PREOLP1.OUT","w",stdout);
}
int main()
{
    giuncute;
    blablalolo();
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<pair<ll, ll>> vt;
        for (int i = 0 ; i <= 50 ; i++) f[i] = 0 , ft[i] = 0;
        for (int i = 1 ; i <= n ; i++)
        {
            for (int j = 1 ; j <= m ; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == 'M') vt.push_back( make_pair(i,j) );
                if (a[i][j] == 'E') f[i] = 1 , ft[j] = 1;
            }
        }
        if (vt.size() == 0) cout << 0 << endl;
        else 
        {
            ans = 0;
            for (int i = 0 ; i < (int) vt.size() ; i++)
            {
                //cerr << vt[i].first << " " << vt[i].second << endl;

                int x = vt[i].first , y = vt[i].second;
                if ((a[x-1][y] == 'R') && (a[x+1][y] == 'R')&&(a[x][y+1] == 'R') &&(a[x][y+1] == 'R')) continue;
                else while ( (x != n && y != m) || (x != 0 && y != 0) )
                {
                    if (a[x-1][y] == 'M') x--;
                    else if (a[x+1][y] == 'M') x++;
                    else if (a[x][y+1] == 'M') y++;
                    else if (a[x][y+1] == 'M') y--;
                    if (a[x][y] == 'M')
                    {
                        f[vt[i].first] = x;
                        ft[vt[i].second] = y; 
                        ans++;
                        break;
                    }
                    if (a[x][y] == 'R') break;
                }
            }
            cout << ans << endl;
        }
    }
}
