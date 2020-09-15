#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int n , a[7];
int cnt[7];
int tmax = 0;
int res = 0,x;
int main()
{
    freopen("MANGDEP.INP","r",stdin);
    freopen("MANGDEP.OUT","w",stdout);
    a[1] = 4 ; a[2] = 8 ; a[3] = 15 ; a[4] = 16 ; a[5] = 23 ; a[6] = 42;
    scanf("%d",&n);
    memset(cnt,0,sizeof(cnt));
    for(int i = 1;  i <= n ;i++)
    {
        bool check = false;
        scanf("%d",&x);
        for (int i = 1 ; i <= 6 ;i++)
            if (a[i] == x)
        {    if (a[i] == 4)
            cnt[1]++;
            if (a[i] == 8)
            cnt[2]++;
            if (a[i] == 15)
            cnt[3]++;
            if (a[i] == 16)
            cnt[4]++;
            if (a[i] == 23)
            cnt[5]++;
            if (a[i] == 42)
            cnt[6]++;
            check = true;
            break;
        }
        if (check == false ) res++;
    }

    int tam = 999999;
    tmax = 0;
    for(int i  = 1 ; i <= 6 ;i++) tam = min(tam,cnt[i]);
    for(int i = 1 ; i <= 6 ;i++)  tmax+= cnt[i] - tam;
    cout  << res + tmax;
    return 0;
}
