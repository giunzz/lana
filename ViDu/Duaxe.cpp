#include <cstdio>
#define giuncute freopen("duaxe.inp", "r", stdin) , freopen("duaxe.out", "w", stdout)
long  n;

void sol()
{
    long vl, vl1, ans = 0, d;
    bool c = 0;
    scanf("%ld %ld",&vl1 , &vl);
    d = vl1;
    if (vl > vl1) ans = vl - vl1, c = 1, d = vl;
    vl1 = vl;
    for (int i = 1; i < n - 1; i++)
    {
        scanf("%ld",&vl);
        if(vl > vl1)
        {
            if(!c) c = 1;
            if (vl > d) ans += vl - vl1;
        }
        else if (vl < vl1) 
        {
            if(c) c = 0 , d = vl1;   
        }
        vl1 = vl;
    }
    printf("%ld",ans);
}

int main()
{
    giuncute;
    scanf("%ld",&n);
    sol();
    return 0;
}