#include<bits/stdc++.h>
#define N 1000006
#define llong long long
using namespace std;
int n,k;
llong a[N], mx1[N], mx2[N];
llong M=100000000000000001;
int read()
    {
        int d=1;
        char c;
        do
            {
                c=getchar();
                if (c == '-')
                    d=-1;
            }
          while ((c < '0')||(c > '9'));
        int res=0;
        for (;(c >= '0')&&(c <= '9');c=getchar())
            res=res*10 + c-'0';
        return res*d;
    }
void write(llong x)
    {
        if (x >= 10)
            write(x/10);
        putchar(char(x%10 + '0'));
    }
int main()
{
    freopen("GIFTS.inp","r",stdin);
    freopen("GIFTS.out","w",stdout);
    ios::sync_with_stdio(0);
    n=read(), k=read();
    for (int i=1; i <= n; i++){
        int x; x=read();
        a[i]=a[i-1]+x;
    }
    for (int i=1; i <= n-k+1; i++){
        int j=i+k-1;
        mx1[i]=max(mx1[i-1],a[j]-a[i-1]);
    }
    for (int i=n-k+1; i >= 1; i--){
        int j=i+k-1;
        mx2[i]=max(mx2[i+1],a[j]-a[i-1]);
    }
    llong res=M;
    for (int i=1; i <= n-k+1; i++){
        llong rs1=-M;
        if (i > k) rs1=mx1[i-k];
        llong rs2=-M;
        if (i <= n-2*k+1) rs2=mx2[i+k];
        res=min(res,max(rs1,rs2));
    }
    write(res);
    return 0;
}
