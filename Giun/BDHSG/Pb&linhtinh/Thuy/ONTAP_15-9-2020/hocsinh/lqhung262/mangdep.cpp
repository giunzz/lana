#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int a[1000000],dem[1000000],n;
int main()
{
    freopen("mangdep.inp","r",stdin);
    freopen("mangdep.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        dem[a[i]]++;
        if (a[i]==8 && dem[8]>dem[4])
        {
            dem[a[i]]--;
            a[i]=0;
        }
        else if (a[i]==15 && dem[15]>dem[8])
        {
            dem[a[i]]--;
            a[i]=0;
        }
        else if (a[i]==16 && dem[16]>dem[15])
        {
            dem[a[i]]--;
            a[i]=0;
        }
        else if (a[i]==23 && dem[23]>dem[16])
        {
            dem[a[i]]--;
            a[i]=0;
        }
        else if (a[i]==42 && dem[42]>dem[23])
        {
            dem[a[i]]--;
            a[i]=0;
        }
    }
    int x=0;
    for (int i=1;i<=n;i++)
        if (a[i]==0) x++;
    x+=abs(dem[42]*5-dem[23]-dem[4]-dem[8]-dem[15]-dem[16]);
    if ((n-x)%6==0) cout<<x;
    else cout<<n;
    return 0;
}
