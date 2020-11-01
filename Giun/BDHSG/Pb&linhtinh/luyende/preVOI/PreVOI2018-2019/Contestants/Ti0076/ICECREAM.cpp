#include <bits/stdc++.h>
#define P 1000000009
using namespace std;
int kq,n,mm,m[3],x[301];

void Try(int i)
{
    if (i>n) ++kq;
    else for (int j=0;j<3;++j)
        if (m[j]<mm)
    {
        if (j==0) { x[i]=0; m[0]++; Try(i+1); --m[0];}
        if (j==1)
            if (m[0]>0) { x[i]=1; --m[0]; ++m[1]; Try(i+1); ++m[0]; --m[1];}
        if (j==2)
        {
            if (m[0]>0 && m[1]>0) { x[i]=2; --m[0]; --m[1]; ++m[2]; Try(i+1); ++m[0]; ++m[1]; --m[2];}
            else if (m[0]>2) { x[i]=2; m[0]-=3; ++m[2]; Try(i+1); m[0]+=3; --m[2];}
        }
    }
}

int main()
{
    freopen("ICECREAM.inp","r",stdin);
    freopen("ICECREAM.out","w",stdout);
    scanf("%d%d",&n,&mm);
    scanf("%d%d%d",&m[0],&m[1],&m[2]);
    Try(1);
    printf("%d",kq);
}
