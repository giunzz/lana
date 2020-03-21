/*#include<stdio.h>
#include<algorithm>
using namespace std;

int n , a[22] , ans[22] = {0} , k , d[(int(1e6+8))] = {0};

void xuat()
{
    for (int i= 1 ; i <= k ; i++) printf("%d ",ans[i]);
    printf("\n");
}

void quaylui(int vt)
{
    if( vt == k + 1) xuat();
    else 
    {
        for (int i = 1 ; i <= n ; i++)
        {
            if (ans[vt - 1] <= a[i]) 
            {
                ans[vt] = a[i];
                quaylui(vt+1);
            }
        }
    }
}

int main()
{
    freopen("input.inp","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d %d",&n,&k);
    for (int i = 1 ; i <= n ; i++) 
    {
        scanf("%d",&a[i]);
        d[a[i]]++;
    }
    sort(a+1,a+1+n);
    ans[0] = -1;
    quaylui(1);
    return 0;
}*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a[6]={1,2,3,4,5,6};
    cout << a[4] << " " << 4[a] << endl ;
    cout << *(a+4) << " " << *(4+a);
    return 0;
}