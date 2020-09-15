#include<bits/stdc++.h>
using namespace std;
long long n,a[1000010],dem[100];
long long Min(long long a,long long b)
{
    if(a>b) return b;
    return a;
}
int main()
{
    freopen("MANGDEP.inp","r",stdin);
    freopen("MANGDEP.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==4) a[i]=1;
        if(a[i]==8) a[i]=2;
        if(a[i]==15) a[i]=3;
        if(a[i]==16) a[i]=4;
        if(a[i]==23) a[i]=5;
        if(a[i]==42) a[i]=6;
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1) dem[a[i]]++;
        else
        {
            if(dem[a[i]-1]>dem[a[i]]) dem[a[i]]++;
            else ans++;
        }
    }
    /*long long tmp=INT_MAX;
    for(int i=1;i<=6;i++)
    {
        tmp=Min(tmp,dem[i]);
    }
    for(int i=1;i<=6;i++)
    {
        ans=ans+dem[i]-tmp;
    }*/
    cout<<n-dem[6]*6<<endl;
}
