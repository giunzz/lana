#include <bits/stdc++.h>
#define maxn 4005
#define oo 1e9+5
#define foru(a,b,c) for (int a=b;a<=c;a++)
#define ford(a,b,c) for (int a=b;a>=c;a--)
#define mp make_pair
#define pb push_back
#define ii pair<int,int>
#define ll long long
#define forv(a,b) for(auto&a:b)
using namespace std;
int n,k;
int a[maxn],b[maxn];
int f[maxn][maxn],lv[maxn];
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
void xuli1()
{
    int vt1=0,vt2=0,kq=0;
    foru(i,1,n)
    foru(j,1,n)
    if (a[i]==b[j])
    {
        f[i][j]=1;
        int tg=0;
        foru(u,1,i-1)
        foru(v,1,j-1) if (a[u]==b[v] && abs(a[i]-a[u])<=k && (f[u][v]+1>f[i][j] || (f[u][v]+1==f[i][j] && a[u]>tg)))
        {
            f[i][j]=f[u][v]+1;
            luu[i][j]=ii(u,v);
            tg=a[u];
            if (f[i][j]>kq) {vt1=i;vt2=j;kq=f[i][j];}
        }
     }
     int sl=0;
     while (vt1 && vt2)
     {
        ii tg=luu[vt1][vt2];
        lv[++sl]=a[vt1];
        vt1=tg.first;
        vt2=tg.second;
     }
     put(sl);putchar('\n');
     ford(i,sl,1) {put(lv[i]);putchar(' ');}
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("liondance.inp", "r", stdin);
    freopen("liondance.out", "w", stdout);
    read(n);read(k);
    foru(i,1,n) read(a[i]);
    foru(i,1,n) read(b[i]);
    if (n<=200) xuli1();
    //else xuli2();
}
