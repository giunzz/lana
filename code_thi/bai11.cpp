#include<bits/stdc++.h>
using namespace std;

int n , a[107][107] ;

void xuat(int x[107][107])
{
    for (int i = 1 ; i <=  n ;i++)
    {
        for (int j = 1 ; j <= n ; j++) cout << x[i][j] << " ";
        cout << endl;
    }
}

void luonleo (int n ,int a[107][107])
{
    int tmp = 1;
    int ok = 1;
    for (int i = 1 ; i <= n ;i++)
    {
        if (ok == 1 )
        {
            for (int j = 1 ; j <= n ; j++)
            {
                a[i][j] = tmp;
                tmp++;
            }
            ok = 2;
        }
        else
        {
            for (int j = n ; j >= 1 ; j--)
            {
                a[i][j] = tmp;
                tmp++;
            }
            ok = 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    cout << "a)" << endl;
    luonleo(n , a);
    xuat(a);
    return 0;
}
