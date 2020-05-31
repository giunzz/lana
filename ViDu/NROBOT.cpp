#include<bits/stdc++.h>
using namespace std;
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);

int n , k , mid , ans[107] ={0};
pair <int , int > r[108];

int main()
{
    balabalo;
    giuncute;
    cin >> n >> k;

    mid = (n / 2) + 1;
    for (int i = 1 ; i <= k ; i++)
    {
        for (int j = 1 ; j <= k ; j++)
            cin >> a[i][j];
    }
    for (int i = 1 ; i <= n / 2 ; i++)
    {
        for (int j = 1 ; j <= n / 2; j++)
        
    }



    lấy min đi tới từ 3 ô i-1,j or i,j-1 mất 10 hoặc i-1,j-1 mất 15
    mid = ( n / 2 ) + 1 ;
    for (int i = 1 ; i <= n ; i++)
        {
            if ( i % 2 == 0 ) ans[i] = min( ans[i-1] + a , ans[i / 2] + b );
            else ans[i] = ans[i-1] + a;
        }
    for (int d = 1 ; d <= k; i++ )
    {
        cin >> a[i][j] ;
        for (int u = )
        {
            if (a[i - 1][j] )
        }
        cin >> r[i].first >> r[i].second;
        while (r[i].first != mid && r[i].second != mid)
        {
            if (r[i].first < mid )
            {
                if (r[i].first + r[i].second == mid ) ans += 15;
                else ans += 10;
            }
            else 
            {
                if (r[i].first - r[i].second == mid ) ans += 15;
                else ans += 10;  
            }
            if (r[i].second > mid )
            {
                if (r[i].first - r[i].second == mid ) ans += 15;
                else ans += 10;  
            }
            else 
            {
                if (r[i].first + r[i].second == mid ) ans += 15;
                else ans += 10;  
            }
        }
    }
    cout << ans ;
    return 0; 

}
