#include <bits/stdc++.h>
using namespace std;
long long a,b,c,n,mmax;
long long kt_sub_1(long long  j , long long m50,long long m1,long long m2)
{
    if (j==1) return 0;

    if (j==2)
    {
        if ( m50> 0) return 1;
        return 4;
    }

    if (j==3)
    {
        if (m1>0 && m50>0) return 2;
        if (m50 > 2 ) return 3;
        return 4;
    }

}
long long  ans;
long long  f[301];
void dequy(long long x,long long y, long long m50,long long m1,long long m2)
{
    if (x>n)
    {
        ans++;
      //  for (long long i=1;i<=n;i++) cout<<f[i]<<" ";cout<<endl;
        return ;
    }
    for (long long i=1;i<=3;i++)
    {
        long long kt = kt_sub_1(i , m50 , m1, m2) ;
        if ( kt == 0)
        {
            m50++;
          //  f[x]=50;
            if (m50 <= mmax) dequy(x+1,i, m50, m1, m2);
            m50--;
        }
        if (kt == 1)
        {
            m1++;
            m50--;
           // f[x]=1;
            if (m1 <= mmax) dequy(x+1,i, m50, m1, m2);
            m1--;
            m50++;
        }
        if (kt == 2)
        {
            m2++;
            m1--;
            m50--;
          //  f[x]=2;
            if (m2 <= mmax) dequy(x+1,i, m50, m1, m2);
            m2--;
            m1++;
            m50++;
        }
        if (kt == 3)
        {
            m2++;
            m50-=3;
           // f[x]=2;
            if (m2 <= mmax) dequy(x+1,i, m50, m1, m2);
            m2--;
            m50+=3;
        }
    }
}
void sub_1()
{
    dequy( 1 ,1, a, b ,c );
    cout<<ans;
    return ;
}
int main()
{
    freopen("icecream.inp","r",stdin);
    freopen("icecream.out","w",stdout);
    cin>>n>>mmax;
    cin>>a>>b>>c;
    if ( n<=50) sub_1();
    return 0;
}
