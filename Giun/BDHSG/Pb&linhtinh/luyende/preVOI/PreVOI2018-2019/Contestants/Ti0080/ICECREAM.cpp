#include<bits/stdc++.h>
using namespace std;
#define fi(i,x,y) for(int i=x; i<=y; ++i)
#define fd(i,x,y) for(int i=x; i>=y; --i)
#define N 16

int n,m,a,b,c;
int lt[N];

void io()
{
    freopen("ICECREAM.inp", "r", stdin);
    freopen("ICECREAM.out", "w", stdout);
}

int main()
{
    io();
    cin >> n >> m >> a >> b >> c;
    lt[0] = 1;
    fi(i,1,n) lt[i] = lt[i-1]*3;
    int cnt=0;
    fi(i,0,lt[n]-1)
    {
        int x=a,y=b,z=c;
        fi(j,0,n-1)
        {
            if ((i/lt[j])%3 == 0)
            {
                if (x + y + z >= m) break;
                else x++;
            }
            if ((i/lt[j])%3 == 1)
            {
                if (x > 0)
                {
                    x--;
                    y++;
                }
                else break;
            }
            if ((i/lt[j])%3 == 2)
            {
                z++;
                if (x >= 3) x-=3;
                else
                {
                    if (x >= 1 && y >= 1)
                    {
                        x--;
                        y--;
                    }
                    else break;
                }
            }
            if (j == n-1) cnt++;
        }
    }
    cout << cnt;
}
