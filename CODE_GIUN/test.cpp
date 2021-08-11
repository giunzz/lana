#include <bits/stdc++.h>
using namespace std;
int n, m, k , res = INT_MAX;
string a , b ;
int main() 
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> k;
    cin >> a;
    while (k--) 
    {
        cin >> b;
        for (int i = 0 ; i < n; i++) 
        {
            int j = i , dis = 0;
            for (int z = 0 ; z < m ; z++) 
            {
                if (j == n) j = 0;
                dis += (a[j] != b[z]) ;
                j++;
            }
            res = min(res,dis);
        }
    }
    cout << res;
    return 0;
}