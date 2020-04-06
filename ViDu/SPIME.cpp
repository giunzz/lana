#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e7+7; 
int n , x = 0 , y = 0 ;
int k = 1 , d = 0 , cc = 1 ,  meo;
    
bool sang[maxn]={0};

void  ss(int n )
{
    int i , j ;
    sang[0] = 1 , sang[1] = 1;
    for (  i = 2; i*i<= n ; i++)
    {
         if  (sang[i]== 0 ) 
        {
            for (  j = i*i ; j<= n ; j+=i )
            {
                sang[j] = 1;
            }
        }
     }
}

int main()
{
    ios_base :: sync_with_stdio (false);
	cin.tie (0);
	freopen ("SPIME.INP", "r", stdin);
	freopen ("SPIME.OUT", "w", stdout);
    /*freopen ("giun.INP", "r", stdin);
	freopen ("giun.OUT", "w", stdout);*/
    cin >> n ;
    ss(n);
    vector <int> giun ;
    for (int i = 1 ; i <= n ; i++)
    {
        if (sang [i] == 0 )giun.push_back(i) , cerr << i << " ";
    }
    meo = giun[k];
    while ( meo <= n )
    {
        meo = giun[k];
        d++; 
        if ( d <= 7 ) 
        {
            if ( d == 1 )  x += cc; 
            if ( d == 3 )  y += cc;
            if ( d == 4 )  x -= cc;
            if ( d == 5 )  x -= cc;
            if ( d == 6 )  y -= cc;
            if ( d == 7 )  x += cc;
            k++;
        }
        else cc++ , d = 0;                    
    }
    cout << x << " " << y;
    return 0;
}