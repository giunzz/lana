#include<bits/stdc++.h>
using namespace std;
const int maxn = 305;

int n, NMAX;
int M50,M1,M2;
int p[maxn];
int lt[maxn];
int ans = 0;

void io()
{
    freopen("ICECREAM.INP","r",stdin);
    freopen("ICECREAM.OUT","w",stdout);
}

void Enter()
{
    scanf("%d%d",&n,&NMAX);
    scanf("%d%d%d",&M50,&M1,&M2);
}

bool check()
{
    int m50 = M50;
    int m1 = M1;
    int m2 = M2;
    for(int i = 1; i<=n; ++i)
    {
        if(p[i] == 0)
        {
            if(m50 + 1 > NMAX) return 0;
            m50++;
        }
        if(p[i] == 1)
        {
            if(m1 + 1 > NMAX) return 0;
            if(m50 == 0) return 0;
            m1++;
            m50--;
        }
        if(p[i] == 2)
        {
            if(m2 + 1 > NMAX) return 0;
            if(m50 == 0 || (m50 < 3 && m1 == 0)) return 0;
            if(m50 >=1 && m1 >=1)
            {
                m2++;
                m50--;
                m1--;
            }
            else
            {
                m50 -=3;
                m2++;
            }
        }
    }
    return 1;
}

void Solve1()
{
    lt[0] = 1;
    lt[1] = 3;
    for(int i = 2; i<=16; ++i)
        lt[i] = lt[i-1] * 3;
    for(int i=0; i<(lt[n]);++i)
    {
        for(int j = 0; j<n ; ++j)
        {
            p[j+1] = i / lt[j] % 3;
        }
        if(check())
        {
            ans++;
        }
    }
    cout<<ans;
}

void Solve2()
{
    cout<<0;
}

int main()
{
    io();
    Enter();
    if(n <= 16) Solve1();
    else Solve2();
}
