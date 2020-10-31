#include <bits/stdc++.h>

using namespace std;
ifstream fi("icecream.inp");
ofstream fo("icecream.out");
int n;
int mmax;
int m[4];//m[1]=50;m[2]=1;m[3]=2;
int kq=0;
void xuli1(int x)
{
    if (x==n+1) {kq++;return;}
    if (m[1]<mmax)
    {
        m[1]++;
        xuli1(x+1);
        m[1]--;
    }
    if (m[2]<mmax && m[1]>0)
    {
        m[1]--;m[2]++;
        xuli1(x+1);
        m[1]++;m[2]--;
    }
    if (m[3]<mmax)
    {
        if (m[2]>0 && m[1]>0)
        {
            m[3]++;m[2]--;m[1]--;
            xuli1(x+1);
            m[3]--;m[2]++;m[1]++;
        }
        else if (m[1]>=3)
        {
            kq++;m[3]++;m[1]-=3;
            xuli1(x+1);
            m[1]+=3;m[3]--;
        }
    }
}
int main()
{
    fi>>n>>mmax;
    for (int i=1;i<=3;i++)
        fi>>m[i];
    if (n<=15)
    {
        xuli1(1);
        fo<<kq;
    }
    return 0;
}
