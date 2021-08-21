#include<stdio.h>
using namespace std;

const int  maxn = 1e6 +2;
long n , w[maxn] , h[maxn] , mh1 = -1 , mh = -1 ;
long long  mw = 0 ; 

int main()
{
    freopen("photo.inp","r",stdin);
    freopen("photo.out","w",stdout);
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; i++) 
    {
        scanf("%d%d", &w[i] , &h[i]);            
        mw += w[i];
        if( mh < h[i] ) mh1 = mh , mh = h[i];
        else if( mh1 < h[i] )  mh1 =  h[i];               
    }
    for  ( int i = 1 ; i <= n ; i++ ) 
    {
        if ( h[i] != mh ) printf("%lld ", ( mw - w[i] ) * mh); 
        else printf("%lld ", (mw - w[i]) * mh1 );    
    }   
    return 0;
}
