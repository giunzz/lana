#include<bits/stdc++.h>
using namespace std;
#define fi(i,x,y) for(int i=x; i<=y; ++i)
#define fd(i,x,y) for(int i=x; i>=y; --i)
#define st first
#define nd second
#define BIT(x,i) (x >> i) & 1
#define N 4005

typedef pair <int,int> ii;
int n,k,cnt,res=0;
int a[N],b[N],c[N],ans[N],f[21][21];
int p[N];
ii fa[N][N];

void io()
{
    freopen("LIONDANCE.inp", "r", stdin);
    freopen("LIONDANCE.out", "w", stdout);
}

bool Check()
{
    memset(f,0,sizeof(f));
    int tmp = 0;
    fi(j,2,cnt)
        if (abs(c[cnt]-c[cnt-1]) > k) return 0;
    fi(i,1,cnt)
    {
        fi(j,1,n)
        {
            if (c[i] == b[j]) f[i][j] = f[i-1][j-1] + 1;
            else f[i][j] = max(f[i][j-1],f[i-1][j]);
            tmp = max(tmp,f[i][j]);
        }
    }
    if (tmp == cnt) return 1;
    else return 0;
}

void Sub1()
{
    fi(i,0,(1<<n)-1)
    {
        memset(c,0,sizeof(c));
        cnt = 0;
        fi(j,0,n-1)
            if (BIT(i,j)) c[++cnt] = a[j];
        if (Check())
        {
            if (res < cnt)
            {
                res = cnt;
                fi(i,1,cnt) ans[i] = c[i];
            }
        }
    }
    cout << res << endl;
    fi(i,1,res) cout << ans[i] << " ";
}

void Sub2()
{
    memset(fa,0,sizeof(fa));
    int d = 0;
    int res = 0;
    fi(i,1,n)
    {
        fi(j,1,n)
        {
            if (a[i] == b[j])
            {
                if (abs(fa[i-1][j-1].nd - a[i]) <= k)
                {
                    fa[i][j].st = fa[i-1][j-1].st + 1;
                    fa[i][j].nd = a[i];
                }
            }
            else fa[i][j] = max(fa[i][j-1],fa[i-1][j]);
            if (res < fa[i][j].st)
            {
                p[++d] = fa[i][j].nd;
                res = fa[i][j].st;
            }
        }
    }
    cout << res << endl;
    fi(i,1,d) cout << p[i] << " ";
}

int main()
{
    io();
    cin >> n >> k;
    fi(i,0,n-1) scanf("%d",&a[i]);
    fi(i,0,n-1) scanf("%d",&b[i]);
    if (n <= 20)
    {
        Sub1();
        return 0;
    }
    Sub2();
    return 0;
}
