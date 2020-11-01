#include <bits/stdc++.h>
#define fto(i,a,b) for (int i=a; i<=b; i++)
#define fdto(i,a,b) for (int i=a; i>=b; i--)
#define pii pair<int,int>
#define st first
#define nd second

using namespace std;

typedef long long ll;

int getbit(int i,int j)
{
    return ((i>>j)&1);
}

ll a, b, n, k, m;
ll hmu[65];

void sub1()
{
    fto(i,0,hmu[n]-1)
    {
        ll tg=0;
        fdto(j,n-1,0)
        {
            if (getbit(i,j)) tg=(tg*10+a)%m;
            else tg=(tg*10+b)%m;
        }
        if (tg==k)
        {
            fdto(j,n-1,0)
            if (getbit(i,j)) cout << a;
            else cout << b;
            return;
        }
    }
    cout << -1;
    return;
}

/*void sub2()
{
    pii top;
    int tg;
    queue<pii> qu;
    qu.push({1,1});qu.push({1,2});
    so[1]=a;so[2]=b;du[1]=a%m;du[2]=b%m;tg=2;
    while (1)
    {
        top=qu.front();
        qu.pop();
        du[tg]=(du[top.nd]*10+a)%m;
        fto(i,1,2)
        {
            lv[++tg]=top.nd;
            if (i==1)
            {
                so[tg]=a;
                lv[++tg]=top.nd;
                du[tg]=(du[top.nd]*10+a)%m;
            }
            if (i==2)
            {
                so[tg]=b;
                lv[++tg]=top.nd;
                du[tg]=(du[top.nd]*10+b)%m;
            }
            if (top.st==n-1)
            {
                if (du[tg]==k)
                {
                    int q=tg;
                    while (q)
                    {
                        res[++sl]=so[q];
                        q=lv[q];
                    }
                }
                return;
            }
            else qu.push({top.st+1,tg});
        }
    }
}*/

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("modulo.inp", "r", stdin);
    freopen("modulo.out", "w", stdout);
    cin >> a >> b >> n >> k;
    hmu[0]=1;
    fto(i,1,63) hmu[i]=hmu[i-1]*2;
    m=hmu[n];
    if (n<=20) sub1();
    else cout << -1;
    return 0;
}
