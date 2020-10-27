#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e8; 
int  n , sang[maxn+7] ={0} ; 


void ss()
{
    memset(sang, 0, sizeof(sang));
    sang[1] = 1 , sang[0] = 1 ;
    for (int i = 2  ; i*i <= maxn ; i++)
        if (!sang[i])
            for (int j = i*2 ; j <= maxn ; j +=i) sang[j] = 1;
}
bool kt (int x)
{
    for (int i = 2 ; i*i <= x ; i++)
        if ( x % i == 0) return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("giun.inp","r",stdin);freopen("giun.out","w",stdout);
    freopen("SNTNN.inp","r",stdin);freopen("SNTNN.out","w",stdout);
    cin >> n;
    ss();
    int k = n ;
    if ( n <= (int) 1e6 ) while ( sang[k] == 1) k++;
    else while ( kt(k) == false) k++;
    
    cout << k;
    return 0;
}

