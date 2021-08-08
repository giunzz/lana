#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0)
const ll maxn = 1e5+7;
ll dx[] = {-1 , -1, -1 , 0 , 0 , 0 , 1 , 1 ,1 };
ll dy[] = { 1 , 0 , -1 , 1 , 0 , -1 , 1 , 0 , -1};
ll n , a[30][30] = {0}, m , b[30][30] ={0};

void getmine (ll i , ll j)
{
    //cerr << i << " " << j << endl;
    for (int t = 0 ; t <= 8 ; t++)
    {
       // cerr << i + dx[t] << " " << j + dy[t] << endl;
        if (a[i + dx[t]][j + dy[t]] == 1) continue;
        b[i + dx[t]][j + dy[t]]++;
    }
    //cerr << endl;
}

int main()
{ 
    giuncute;
    freopen("giun.inp", "r", stdin);
    freopen("giun.out", "w", stdout);
    cin >> n >> m ;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j =  1 ; j <= m ; j++) 
        {
            cin >> a[i][j];
            if (a[i][j] != 1) getmine(i , j);
            else b[i][j] = 1;
        }
    }
    ll sum = 0 ;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j =  1 ; j <= m ; j++) 
        {
    //        cerr << b[i][j] << " ";
            if (b[i][j] != 1) sum += b[i][j];
        }
    //    cerr << endl;
    }
    cerr << sum;
}
