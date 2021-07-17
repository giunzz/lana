#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+7 ;
const string tenfile = "giun";
#define fi freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
int a[maxn][maxn] ,  m ,n  , b[maxn][maxn];
int dx[] = {1, -1 , 0 , 0};
int dy[] = {0 , 0 , 1 , -1};
int main()
{
    ios_base :: sync_with_stdio (false);
	cin.tie (0);
	fi;
    cin >> m >> n ; // m hàng n cột
    for (int i = 1 ; i <= m ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
        {
            cin >> a[i][j];
            int c = 0 ;
            if 
            for (int z = 1 ; z <= 4 ; z++)
            {
                if (b[i+dx[z]][j+dy[z]] == 0) b[i+dx[z]][j+dy[z]] = 1;
                c++;
                if (c == a[i][j]) {break;}
                cerr << b[i+dx[z]][j+dy[z]] << " ";
            }
        }
        cerr << endl;
    }
    for (int i = 1 ; i <= m ; i++)
    {
        for (int j = 1 ; j <= n ; j++) cout << b[i][j] << " ";
        cout << endl;
    }
}