#include <bits/stdc++.h>

using namespace std;
int n,x[15],mmax,m50,m1,m2,tong,mx,my,mz;
const int mod = 1e9+9;
void check()
{
    m50=mx;
    m1=my;
    m2=mz;
    for (int i=1; i<=n; i++)
    {
        if (m1>mmax || m2>mmax || m50>mmax)
            return;
        if (x[i]==0)
            {
                m50++;
                continue;
            }
        if (x[i]==1)
        {
            if (m50==0)
                return;
            m50--;
            m1++;
        }
        if (x[i]==2)
        {
            if (m1>0&&m50>0)
            {
                m1--;
                m50--;
                continue;
            }
            if (m50>2)
            {
                m50=m50-3;
                continue;
            }
            return;
        }
    }
    if (m50>mmax || m1>mmax || m2>mmax)
        return;
    tong++;
    tong=tong%mod;
}
void back1(int i)
{
    if (i>n)
    {
        check();
        return;
    }
    else
    {
        for (int j=0; j<=2; j++)
        {
            x[i]=j;
            back1(i+1);
        }
    }
}
int main()
{
    freopen("ICECREAM.inp","r",stdin);
    freopen("ICECREAM.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    tong=0;
    cin>>n>>mmax;
    cin>>mx>>my>>mz;
    back1(1);
    cout<<tong%mod;
}
