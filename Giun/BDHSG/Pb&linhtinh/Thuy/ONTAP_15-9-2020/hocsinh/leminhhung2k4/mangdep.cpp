#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
//4,8,15,16,23,42
int n,a[1000001],f[43];
int main()
{
    freopen("mangdep.inp","r",stdin);
    freopen("mangdep.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[a[i]]++;
        if(a[i]==8 && f[8]>f[4])
        {
            f[a[i]]--;
            a[i]=0;
        }
        else if(a[i]==15 && f[15]>f[8])
        {
            f[a[i]]--;
            a[i]=0;
        }
        else if(a[i]==16 && f[16]>f[15])
        {
            f[a[i]]--;
            a[i]=0;
        }
        else if(a[i]==23 && f[23]>f[16])
        {
            f[a[i]]--;
            a[i]=0;
        }
        else if(a[i]==42 && f[42]>f[23])
        {
            f[a[i]]--;
            a[i]=0;
        }
    }
    int d=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)
            d++;
    }
    d+=abs(f[42]*5-f[4]-f[8]-f[15]-f[16]-f[23]);
    if((n-d)%6==0)
        cout<<d;
    else cout<<n;
    return 0;
}
