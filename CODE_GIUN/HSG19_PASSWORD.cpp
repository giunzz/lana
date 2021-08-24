#include <bits/stdc++.h>
using namespace std;

string a[(int) 1e4+7],t;
map<string, long long > d;
map<string, bool> check;
int  n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("giun.inp","r",stdin);freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1; i <= n ; i++)
    {
        cin >> a[i];
        ++d[a[i]];
    }
    for (int i = 1; i <= n ; i++)
    {
        int ans = 0;
        check.clear();
        for (int j = 0 ; j < (int) a[i].length() ; j++ )
        {
            t.clear();
            for (int k = j ; k < (int) a[i].length() ; k++)
            {
                t.push_back(a[i][k]);
                if(!check[t]) ans += d[t] ,check[t] = 1;
            }
        }
    cout << (ans - 1) << endl;
    }
}