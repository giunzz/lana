#include <bits/stdc++.h>
#define maxn 305
#define oo 1e9+5
#define foru(a,b,c) for (int a=b;a<=c;a++)
#define ford(a,b,c) for (int a=b;a>=c;a--)
#define mp make_pair
#define pb push_back
#define ii pair<int,int>
#define ll long long
#define forv(a,b) for(auto&a:b)
using namespace std;
int n,m,t;
int a[maxn][maxn];
ii q[1005];
int f[maxn][maxn],g1[maxn][maxn],g2[maxn][maxn],f2[maxn][maxn],f1[maxn][maxn];
ii luu[maxn][maxn];
void read(int &n) {
    n = 0;
    int ch = getchar(), sign=1;
    while( ch < '0' || ch > '9' ){
        if (ch == '-') sign = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        n = n * 10 + ch - '0';
        ch = getchar();
    }
    n *= sign;
}
void put(int x)
{
    if (x > 9) put(x / 10);
    putchar(x % 10 + 48);
}

int tinh(int x,int y,int u,int v,int p,int q)
{
    foru(i,x-1,u+1)
    foru(j,y-1,v+1) f[i][j]=0;
    foru(i,x,u)
    foru(j,y,v)
    {
        if (i==p && j==q) {f[i][j]=-oo;continue;}
        f[i][j]=max(f[i-1][j],f[i][j-1])+a[i][j];
    }
    return f[u][v];
}
void xuli1()
{
    while (t--)
    {
        int x,y,u,v;
        read(x);read(y);read(u);read(v);
        foru(i,x-1,u+1)
        foru(j,y-1,v+1) {f[i][j]=0;luu[i][j]={0,0};}
        foru(i,x,u)
        foru(j,y,v)
        {
            if (f[i-1][j]>f[i][j-1])
            {
                luu[i][j]=ii(i-1,j);
                f[i][j]=f[i-1][j]+a[i][j];
            }
            else
            {
                luu[i][j]=ii(i,j-1);
                f[i][j]=f[i][j-1]+a[i][j];
            }
        }
        int sl=0;
        int vt1=u,vt2=v;
        while (vt1>=x && vt2>=y)
        {
            q[++sl]=ii(vt1,vt2);
            ii tg=luu[vt1][vt2];
            vt1=tg.first;
            vt2=tg.second;
        }
        int kq=oo;
        foru(i,2,sl-1) kq=min(kq,tinh(x,y,u,v,q[i].first,q[i].second));
        put(kq);putchar('\n');
    }
}
int tinh2(int x,int y,int u,int v,int p,int q)
{
    int res=-oo;
    g2[p][q]=-oo;
    g1[p][q]=-oo;

    int j=q;
    ford(i,p-1,x)
    {
        g2[i][j]=max(g2[i+1][j],g2[i][j+1])+a[i][j];
        res=max(res,g2[i][j]+f1[i][j]-a[i][j]);
    }
    ford(i,p-1,x) g2[i][j]=f2[i][j];

    foru(i,p+1,u)
    {
        g1[i][j]=max(g1[i-1][j],g1[i][j-1])+a[i][j];
        res=max(res,g1[i][j]+f2[i][j]-a[i][j]);
    }
    foru(i,p+1,u) g1[i][j]=f1[i][j];
    int i=p;
    ford(j,q-1,y)
    {
        g2[i][j]=max(g2[i+1][j],g2[i][j+1])+a[i][j];
        res=max(res,g2[i][j]+f1[i][j]-a[i][j]);
    }
    ford(j,q-1,y) g2[i][j]=f2[i][j];

    foru(j,q+1,v)
    {
        g1[i][j]=max(g1[i-1][j],g1[i][j-1])+a[i][j];
        res=max(res,g1[i][j]+f2[i][j]-a[i][j]);
    }

    foru(j,q+1,v) g1[i][j]=f1[i][j];
    g1[p][q]=f1[p][q];
    g2[p][q]=f2[p][q];
    return res;
}
void xuli2()
{
    while (t--)
    {
        int x,y,u,v;
        read(x);read(y);read(u);read(v);
        foru(i,x-1,u+1)
        foru(j,y-1,v+1) {f1[i][j]=0;f2[i][j]=0;luu[i][j]={0,0};g1[i][j]=0;g2[i][j]=0;}
        foru(i,x,u)
        foru(j,y,v)
        {
            if (f1[i-1][j]>f1[i][j-1])
            {
                luu[i][j]=ii(i-1,j);
                f1[i][j]=f1[i-1][j]+a[i][j];
            }
            else
            {
                luu[i][j]=ii(i,j-1);
                f1[i][j]=f1[i][j-1]+a[i][j];
            }
        }
        int sl=0;
        int vt1=u,vt2=v;
        while (vt1>=x && vt2>=y)
        {
            q[++sl]=ii(vt1,vt2);
            ii tg=luu[vt1][vt2];
            vt1=tg.first;
            vt2=tg.second;
        }
        ford(i,u,x)
        ford(j,v,y)
        {
            f2[i][j]=max(f2[i+1][j],f2[i][j+1])+a[i][j];
            g1[i][j]=f1[i][j];
            g2[i][j]=f2[i][j];
        }
        int kq=oo;
        foru(i,2,sl-1) kq=min(kq,tinh2(x,y,u,v,q[i].first,q[i].second));
        put(kq);putchar('\n');
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("table.inp", "r", stdin);
    freopen("table.out", "w", stdout);
    read(m);read(n);read(t);
    foru(i,1,m)
    foru(j,1,n) read(a[i][j]);
    if (m<=100 && n<=100 && t<=100) xuli1(); else
    xuli2();
}
