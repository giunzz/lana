#include <bits/stdc++.h>

using namespace std;
int64_t d;
int n,mmax,m0,m1,m2;
void xuli(int i)
{
    for (int j=1;j<=3;j++)
    {
        if (j==1)
        {
            if (m0<mmax)
            {
                if (i==n) d++;
                else{ m0++;xuli(i+1);m0--;}
            }
        }
        if (j==2)
        {
            if (m0>0 & m1<mmax)
            {
                 if (i==n) d++;
                 else {m0--;m1++; xuli(i+1);m0++;m1--;}
            }
        }

        if (j==3)
        {
            if (m2<mmax)
            {
                if(m0>0)
                {
                    if(m1>0)
                    {
                        if (i==n) d++;
                        else {m0--;m1--;m2++;xuli(i+1);m0++;m1++;m2--;}
                    }
                    else
                    {
                        if (m0>2)
                        {
                            if (i==n) d++;
                            else {m0=m0-3;m2++;xuli(i+1);m0=m0+3;m2--;}
                        }
                    }
                }

            }
        }
    }
}

int main()
{
    freopen("ICECREAM.INP","r",stdin);
    freopen("ICECREAM.OUT","w",stdout);
    cin>>n>>mmax;
    cin>>m0>>m1>>m2;
    xuli(1);
    cout<<d;
}
