#include <bits/stdc++.h>
using namespace std;
int a,b,n,k;
bool getbit(int x ,int y)
{
    return (x>>y) & 1;
}
long long mu[21];
map < long long , long long > m;
void sub_1()
{
    mu[1]=1;
    long long mun=pow( 2 , n);
    for (int i=2;i<=n;i++) mu[i]=mu[i-1]*10;
    int n1 = n/2;
    int n2 = n - n1;
    long long t,tt,z;
    for (int i=0;i<(1<<n1);i++)
    {
        t = 0;
        for (int j=0;j<n1;j++)
            {
                t = t *10;
                if (getbit(i , j )==1) t+= a ;
                else t += b ;
                t=t % mun;
            }
        t = t * mu[n2+1];
         t=t % mun;
         m[t]=i+1;
    }
    for (int i=0;i<(1<<n2);i++)
    {
        t=0;
        for (int j=0;j<n2;j++)
            {
                t=t*10;
                if (getbit(i , j )==1) t+= a;
                else t += b ;
               t=t % mun;
            }
        t = t % mun;
        z = mun - t + k ;
        z = z % mun;
        if (m[ z ] > 0 )
        {
            tt = m[ z ] -1;
            for (int j=0;j<n1;j++)
            {
                if (getbit(tt,j)==1) cout<<a;
                else cout<<b;
            }
            for (int j=0;j<n2;j++)
            {
                if (getbit(i,j)==1) cout<<a;
                else cout<<b;
            }
            return ;
        }
    }
    cout<<-1;
}
int main()
{
    freopen("modulo.inp","r",stdin);
    freopen("modulo.out","w",stdout);
    cin>>a>>b>>n>>k;
    sub_1();
    return 0;
}
