#include <bits/stdc++.h>
using namespace std;
ifstream fi("Minsum.inp");
ofstream fo("Minsum.out");
long long t,a,b,kq,kq1,kq2;
void process()
{
    long long tmp=__gcd(a,b);
    a/=tmp;
    b/=tmp;
    tmp=sqrt(a/b);
    kq=a+b,kq1=a,kq2=b;
    for (int i=1;i<=sqrt(max(a,b));++i)
    {
        if (a%i==0)
        {
            //kt(a,b,i);
            //kt(a,b,a/i);
            long long uc=i;
            if (b*uc+a/uc<kq)
            {
                kq=b*uc-a/uc;
                kq1=a/uc;
                kq2=b*uc;
            }
            uc=a/i;
            if (b*uc+a/uc<kq)
            {
                kq=b*uc-a/uc;
                kq1=a/uc;
                kq2=b*uc;
            }
        }
        if (b%i==0)
        {
            long long uc=i;
            if (a*uc+b/uc<kq)
            {
                kq=a*uc+b/uc;
                kq1=a*uc;
                kq2=b/uc;
            }
            uc=b/i;
            if (a*uc+b/uc<kq)
            {
                kq=a*uc+b/uc;
                kq1=a*uc;
                kq2=b/uc;
            }
        }
    }
    fo<<kq1<<" "<<kq2<<"\n";
}
int main()
{
    fi>>t;
    while (t--)
    {
        fi>>a>>b;
        process();
    }
}
