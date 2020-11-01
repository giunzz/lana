#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int n,tracex[10000][10000],tracey[10000][10000] ;
long long d, l[10000],r[10000],dp [10000][10000] ;
int maxi =-1;
int resx=0;
int resy=0;
void go (int i,int j)
{
    for (int x=i-1; x>= 1 ; x--)
    {
        for (int y = j-1; y >=1 ; y-- )

        {
            if (l[x] == r[y] && abs (l[i] - l[x]) < d )
            {
                if (dp [x][y]+1  > dp [i][j])
                {
                 dp [i][j] = dp[x][y] +1;
                 tracex [i][j] = x;
                 tracey [i][j] =y ;
                }else
                    if (dp [x][y]+1  == dp [i][j] && l[x] > l[i])
                    {
                     tracex [i][j] = x;
                     tracey [i][j] =y ;
                    }
                if (maxi < dp [i][j])
                {
                    maxi = dp[i][j];
                    resx = i;
                    resy = j ;
                }
                else
                    if (maxi == dp [i][j])
                {
                    if (l[resx] < l[i])
                    {
                        resx=i;
                        resy =j;
                    }
                }
            }
        }
    }
}
void xuat (int i , int j )
{
    int l1=i; int r1=j;
    int t,t1;
    while (l1 >0 && r1>0)
    {
        cout << l[l1] <<" ";
        t=l1;
        t1=r1;
        l1= tracex[t][t1];
        r1=tracey[t][t1];
    }
}
int main()
{
    freopen("liondance.inp","r",stdin);
    freopen("liondance.out","w",stdout);
    cin >>n >> d ;
    for (int j =1 ; j <= n ; j++)
    {
        cin >> l[j];
    }
    for (int i = 1 ; i <= n ; i++)
    {
     cin >> r[i] ;
    }
    for (int i=1 ; i <= n ;i++)
    {
        for (int j=1 ; j <= n ; j ++)
        {   dp[i][j] = 0 ;
            if (l[i] == r[j])
            go (i,j);
        }
    }
    cout <<maxi<<endl;
    xuat(resx,resy);
    return 0;
}
