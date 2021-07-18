#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+7 ;
int a[maxn][maxn] ,  m ,n , b[maxn][maxn] = {0};
int dx[] = {1, -1 , 0 , 0};
int dy[] = {0 , 0 , 1 , -1};
int num[] ={0 ,2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 29 , 31 , 37 , 41 , 43 , 47 , 53 };
int k[maxn] , c = 0;

bool check (int b[maxn][maxn])
{
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
        {
            for (int u = 1 ; u <= n ; u++)
                if (b[i][u] == b[i][j] && u != j) return false;
            for (int u = 1 ; u <= n ; u++)
                if (b[u][j] == b[i][j] && u != i) return false;
        }
    }
    return true;
}
int ok = 0 ;
void quaylui(int x )
{
    if (x == c + 1)
    {
        int z = 0  ;
        for (int i = 1 ; i <= n ; i++)
        {
            for (int j = 1 ; j <= n ; j++)
            {
                if (a[i][j] == 0) b[i][j] =  k[++z] ;
            }
        }
        if (check(b) == true)
        {
            ok = 1;
            for (int i = 1 ; i <= n ; i++)
            {
                for (int j = 1 ; j <= n ; j++) cout << b[i][j] << " ";
                cout << endl;
            }
            cout << endl;
        }
    }
    else
    {
        for (int i = 1 ; i <= n ; i++)
        {
            k[x]= num[i];
            quaylui(x + 1);
            if (ok == 1) return ;
        }
    }
}
int main()
{
    ios_base :: sync_with_stdio (false);
	cin.tie (0);
	freopen("MTNGTO.inp","r",stdin);
    freopen("MTNGTO.out","w",stdout);
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