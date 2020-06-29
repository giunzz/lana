#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e8+300;
int  n , sang[maxn + 9] ={0};
void  ss()
{
    int i , j ;
    sang[0] = 1 , sang[1] = 1;
    for (  i = 2; i*i<= maxn ; i++)
    {
         if  (sang[i]== 0 )
        {
            for (  j = i*2 ; j<= maxn ; j+=i )
            {
                sang[j] = 1;
            }
        }
     }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("giun.inp","r",stdin);freopen("giun.out","w",stdout);
    freopen("SNTNN.inp","r",stdin);freopen("SNTNN.out","w",stdout);
    cin >> n;
    int k = n ;
    ss();
    while ( sang[k] != 0 ) k++;
    cout << k;
    return 0;
}

