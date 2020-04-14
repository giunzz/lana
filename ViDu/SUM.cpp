/*Bài toán: 
Hãy tìm đường chéo song song với đường chéo chính
có tổng các phần tử trên đường chéo đó là lớn nhất.*/

#include<bits/stdc++.h>
using namespace std; 
const string tenfile = "sum";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
int a[107][107] ,n , j , ans = 0  , sum = 0 ;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    balabalo;
    cin >> n ;
    for (int i = 1 ; i <= n ; i++ )
    {
        for (int j = 1 ; j <= n ; j++)
        {
            cin >> a[i][j];
            if ( i == j ) ans +=a[i][j];
        }
    }
    //cerr << ans << endl;
    for (int z = 1-n ; z <= n-1; z++)
    {
        if (z >= 0 ) j = 1;
        else j = 1 - z;
        sum = 0;
        while (j + z < n || j < n)
        {
            sum += a[j+z][j];
            j++;
        }
        //cerr << sum << " ";
        ans = max(ans , sum);
    }
    cout << ans;
    return 0;
}
