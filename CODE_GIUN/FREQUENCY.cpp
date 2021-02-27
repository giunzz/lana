#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn= 1e6+7; 
int n , a[maxn] , q , ri , qi, b[maxn] ;
int ok = 0;

int main()
{
	freopen ("FREQUENCY.INP", "r", stdin);
	freopen ("FREQUENCY.OUT", "w", stdout);
    /*freopen ("giun.INP", "r", stdin);
	freopen ("giun.OUT", "w", stdout);*/
    scanf("%d",&n);
    for (int i = 1 ; i <= n ; i++) 
    {
        scanf("%d",&a[i]);
        //b[++j] = a[i];
        
    }
    sort (a+1, a+1+n);
    scanf("%d",&q);
    for (int i = 1 ; i <= q ; i++) 
    {
        scanf("%d %d",&ri,&qi);
        for (int j = qi ; j >= ri ; j = j - 2)
        {
            //cerr << a[j] << " ";
            if (a[j] != a[j-1]) 
            {
                //cout << a[j] << endl;
                printf("%d \n", a[j] );
                ok = 1;
                break;
            }
            else ok = 0;
        }
        if (ok == 0 ) printf("%d \n", 0);
    }
    return 0;
} 

    
	