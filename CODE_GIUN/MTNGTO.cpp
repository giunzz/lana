#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+7 ;
const string tenfile = "giun";
#define fi freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
int a[maxn][maxn] ,  m ,n , b[maxn][maxn] = {0};
int dx[] = {1, -1 , 0 , 0};
int dy[] = {0 , 0 , 1 , -1};
int num[] ={0 ,2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 29 , 31 , 37 , 41 , 43 , 47 , 53 };
int k[maxn] , c = 0;
void quaylui(int x )
{
    if (x == c)
    {
        int z = 0;
        for (int i = 1 ; i <= n ; i++)
        {
            for (int j = 1 ; j <= n ; j++)
            {
                if (b[i][j] == 0) cout << k[++z] << " ";
                else cout << b[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    else
    {
        for (int i = 1 ; i <= n ; i++)
        {
            cerr << k[i] << " ";
            k[i]= num[i];
            quaylui(x);
        }
    }
}


int main()
{
    ios_base :: sync_with_stdio (false);
	cin.tie (0);
	fi;
    cin >>  n ; 
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= n ; j++) 
        {
            cin >> a[i][j];
            
            if (a[i][j] == 0) c++;
            b[i][j] = a[i][j];
        }
    }
    quaylui(1);
}