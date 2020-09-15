#include <iostream>
#include <stdio.h>
using namespace std;
#define N_MAX (int)1e6+6
int f[50];
int n,a[N_MAX],dem=0;
int s[10];
bool check[7],vi[N_MAX];

int main()
{
    freopen("mangdep.inp","r",stdin);
    freopen("mangdep.out","w",stdout);
    f[4]=1;
    f[8]=2;
    f[15]=3;
    f[16]=4;
    f[23]=5;
    f[42]=6;
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        a[i]=f[a[i]];
    }
    /*
    check[1]=true;
    for (int i=1;i<=n;i++)
        if (check[a[i]])
        {
            check[a[i]+1]=true;
            vi[i]=true;
            if (a[i]!=1)
                check[a[i]]=false;
        }
    dem=n;
    for (int i=1;i<=n;i++)
    {
        if (a[i]==6 && vi[i]==true)
            dem-=6;
        cerr << vi[i] << " ";
    }
    */
    dem=0;
    int MIN=(int)1e9+1;
    for (int i=1;i<=n;i++)
        s[a[i]-1]++;
    for (int i=0;i<=5;i++)
        MIN=min(MIN,s[i]);
    for (int i=0;i<=5;i++)
        dem+=s[i]-MIN;
    cout << dem;
    return 0;
}
