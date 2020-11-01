#include <bits/stdc++.h>

using namespace std;
ifstream fi ("modulo.inp");
ofstream fo ("modulo.out");
int a,b;
int64_t MOD;
int n,k;
int64_t x=0;
int s[65];

void nhap()
{
    fi>>a>>b;
    fi>>n>>k;
}
int dem=0;

void kq()
{
    for (int i=1;i<=n;i++)
        fo<<s[i];
}
void TRY(int v)
{

    for (int j=0; j<2; j++)
    {
        int64_t y = x;
        if(j == 0)
        {
            x=(x*10%MOD+a)%MOD;
            s[v]=a;
        }
        else
        {
            x=(x*10%MOD+b)%MOD;
            s[v]=b;
        }
        if(v == n)
        {
            if(x == k)
            {
                kq();
                return;
            }
        }
        else TRY(v+1);
        x = y;
    }
}
int main()
{
    nhap();
    MOD=1;
    for (int i=1;i<=n;i++)
        MOD=MOD*2;
    TRY(1);
    return 0;
}
