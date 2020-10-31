#include<bits/stdc++.h>
using namespace std;
#define NAME "MINSUM"
const int maxn = 1e6 + 5;
int A,B,T;
int p,t;
int f[maxn];
int a[maxn];
int b[maxn];
bool ok[maxn];
int pr[maxn];
int pr_C[maxn];

void io()
{
    freopen(NAME".inp","r",stdin);
    freopen(NAME".out","w",stdout);
}

void SSNT()
{
    for(int i = 2; i <= 1e6; ++i)
    {
        if(ok[i] == 1) continue;
        t++;
        pr[t] = i;
        for(long long j = 1LL*i*i; j <= 1e6; j+= (long long) i)
            ok[j] = 1;
    }
}

void Solve()
{
    int a = A;
    A /= __gcd(A,B);
    B /= __gcd(a,B);
    p = 0;
    for(int i = 1; i <= t; ++i)
    {
        if(A % pr[i] != 0) continue;
        int h = 0;
        while(A % pr[i] == 0)
        {
            A /= pr[i];
            h++;
        }
        if(h % 2 == 0) continue;
        p++;
        pr_C[p] = pr[i];
    }
    for(int i = 1; i <= t; ++i)
    {
        if(B % pr[i] != 0) continue;
        int h = 0;
        while(B % pr[i] == 0)
        {
            B /= pr[i];
            h++;
        }
        if(h % 2 == 0) continue;
        p++;
        pr_C[p] = pr[i];
    }
    sort(pr_C + 1,pr_C + p + 1);
    if(p == 1)
    {
        printf("%d %d\n",1,pr_C[1]);
        return;
    }
    if(p == 2)
    {
        printf("%d %d\n",pr_C[1],pr_C[2]);
        return;
    }
    int ans_b = 1;
    int ans_a = 1;
    int f = 1;
    int t = 0;
    for(int i = 1; i <= p; ++i) f *= pr_C[i];
    for(int i = 1; i <= p; ++i)
    {
        ans_a = ans_a * pr_C[i]*pr_C[p - i + 1];
        t+=2;
        if(t >= p/2) break;
    }
    ans_b = f/ans_a;
    if(ans_b > ans_a) swap(ans_a,ans_b);
    if(p%2 == 1) ans_b*pr_C[p/2 + 1];
    printf("%d %d\n",ans_a,ans_b);
}

int main()
{
    io();
    scanf("%d",&T);
    SSNT();
    for(int i = 1; i <= T; ++i)
    {
        scanf("%d%d",&A,&B);
        Solve();
    }
}
