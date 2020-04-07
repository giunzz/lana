#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+7 ; // điền giớ hạn 
const string tenfile = "giun";
#define fi freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
// nhập file nếu muốn
int a[maxn][maxn] , ma = INT_MIN , m ,n ;
vector <int> giun;
int main()
{
    ios_base :: sync_with_stdio (false);
	cin.tie (0);
	fi;
    cin >> m >> n ; // m hàng n cột
    for (int i = 0 ; i < m ; i++)
    {
        for (int j = 0 ; j < n ; j++)
            cin >> a[i][j];
    }

    for(int i = 0 ; i < n ; i++)
    {
        for(int  j = 0 ; j < m ;j++)
        {
            ma = max (ma , a[j][i]);
        }
        giun.push_back(ma) ;
        ma = INT_MIN;
    }
    sort(giun.begin() , giun.end());
    for (int i = 0; i < (int)giun.size() ; i++)
        cout << giun[i] << " ";
}