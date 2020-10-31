#include<bits/stdc++.h>

#define mod 1000000009

using namespace std;

int n, mmax, m50, m1, m2, x[55], ds = 0 ;

void xuli()
{
    int n1 = m50;
    int n2 = m1;
    int n3 = m2;
    for(int i = 1; i <= n; ++i)
    {
        if(x[i] == 1)
        {
            if(n1 >= mmax) return;
            else n1++;
        }
        else{
            if(x[i] == 2)
            {
                if(n2 >= mmax) return;
                else{
                    if(n1 == 0) return;
                    else n1--, n2++;
                }
            }
            else{
                if(n3 >= mmax) return;
                else if(n2 == 0 && n1 < 3) return;
                else if(n1 == 0) return;
                else if(n2 == 0 && n1 >= 3) n3++, n1-=3;
                else n2--, n1--, n3++;
            }

        }
    }

    ds = (ds + 1) % mod;
}

void thu(int u )
{
    if(u > n){xuli(); return ;}
    for(int i = 1; i <= 3; ++i)
    {
        x[u] = i;
        thu(u + 1);
    }
}

void sub1()
{
    thu(1);

    printf("%d", ds);
}

int main()
{
    freopen("icecream.inp", "r", stdin);
    freopen("icecream.out", "w", stdout);

    scanf("%d %d", &n, &mmax);
    scanf("%d %d %d", &m50, &m1, &m2);

    sub1();
}
