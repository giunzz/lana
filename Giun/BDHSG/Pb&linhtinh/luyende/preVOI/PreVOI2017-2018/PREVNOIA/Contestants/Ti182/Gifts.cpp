#include <bits/stdc++.h>
using namespace std;
FILE *fi;
//ifstream fi("Gifts.inp");
ofstream fo("Gifts.out");
long long n,k,sum[1000005],num,group[1000005];
long long max1[1000005],maxn[1000005],kq=1e18;
long long getsum(int x,int y)
{
    return sum[y]-sum[x-1];
}
void process()
{
    for (int i=1; i+k-1<=n; ++i)
    {
        group[++num]=getsum(i,i+k-1);
        max1[i]=max(max1[i-1],group[i]);
    }
    for (int i=num;i>0;--i)
        maxn[i]=max(maxn[i+1],group[i]);
    for (int i=1;i<=num;++i)
    {
        long long fron=i-k,behi=i+k,tmp=0;
        if (fron>=1) tmp=max(tmp,max1[fron]);
        if (behi<=num) tmp=max(tmp,maxn[behi]);
        kq=min(kq,tmp);
    }
    fo<<kq;
}
int main()
{
    int x;
    fi=fopen("Gifts.inp","r");
    fscanf(fi,"%lld%lld",&n,&k);
    for (int i=1; i<=n; ++i)
    {
        fscanf(fi,"%d",&x);
        sum[i]=sum[i-1]+x;
    }
    process();
}
