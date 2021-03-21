#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long
const ll maxn = 506;
ll n  , f[maxn][maxn]={{0}} ;
char s[maxn];
int main()
{
    giuncute;
   // freopen("giun.inp","r",stdin);
   // freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> s[i] ;
    for (int i = 1 ; i <= n ; i++) f[i][i] = 1;
    for (int len = 2 ; len <= n ; len++)
    {
        for (int i = 1 ; i <= n ; i++)
        {
            int j = i+len-1; // j-i+1 = len
            if (j > n ) break;
            f[i][j] = f[i+1][j]+1;
            for (int x = i+1 ; x <= j ; x++)
                if (s[i] ==  s[x]) f[i][j] = min (f[i][j] , f[i+1][x-1] + f[x][j]);
        }
    }
    cout << f[1][n];
}
