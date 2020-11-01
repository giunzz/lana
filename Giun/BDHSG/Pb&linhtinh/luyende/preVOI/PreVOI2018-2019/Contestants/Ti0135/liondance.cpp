#include<bits/stdc++.h>

#define maxn 4004

#define fi first
#define se second

using namespace std;

int n, a[maxn], b[maxn], u, x1[22], a1[22], kq[22], ds = 0;
int f[maxn][maxn];

typedef pair<int, int> II;
II vt, tr[maxn][maxn];
int x[maxn], c[maxn];
vector<int> g[maxn];

map<int, int> nho1, nho2;

void xuli()
{
    int sl = 0;
    for(int i = 1; i <= n; ++i) if(x1[i]) a1[++sl] = a[i];
    for(int i = 2; i <= sl; ++i) if(abs(a1[sl] - a1[sl - 1]) > u) return;
    int j = 1, dem = 0;
    for(int i = 1; i <= sl ; ++i)
    {
        while(b[j] != a1[i] && j <= n) ++j;
        if(j == n + 1) break;
        if(b[j] == a1[i]) dem++;
        j++;
    }
    if(dem != sl) return;
    if(ds < dem){ds = dem;
    for(int j = 1; j <= sl; ++j) kq[j] = a1[j];}
    else if(ds == dem){
        int ok = 0;
        for(int j = 1; j <= sl; ++j) if(a1[j] > kq[j]) {ok = 1;break;}
                                     else if(a[j] < kq[j]) {ok = 2;break;}
        if(ok == 1){
            for(int j = 1 ; j <= sl; ++j) kq[j] = a[j];
        }

    }
}

void thu(int k )
{
    if(k > n){xuli(); return;}
    for(int i = 0; i <= 1; ++i)
    {
        x1[k] = i;
        thu(k + 1);
    }
}
void sub1()
{
    thu(1);

    printf("%d\n", ds);
    for(int i = 1; i <= ds; ++i) printf("%d ", kq[i]);
}

void sub2()
{
    int m = n;
     for(int i=1;i<=m;i++) x[i]=a[i];
    sort(x+1,x+1+m);
    for(int i=1;i<=n;i++)
    {
        int u=lower_bound(x+1,x+1+m,b[i])-x;
        if(u<=m&&x[u]==b[i]) g[u].push_back(i);
    }
    for(int i=0;i<=m;i++)
        for(int k=0;k<=m;k++) f[i][k]=n+1;
    for(int i=0;i<=m;i++) f[i][0]=0;
    for(int i=1;i<=m;i++)
        for(int k=1;k<=i;k++){
        f[i][k]=f[i-1][k];
        int u=f[i-1][k-1]+1;
        int r=lower_bound(x+1,x+1+m,a[i])-x;
        int j=lower_bound(g[r].begin(),g[r].end(),u)-g[r].begin();
        if(j < g[r].size()) {int ne = g[r][j];
        f[i][k]=min(f[i][k],ne);}}
    int ds=0,u=0;
    for(int k=1;k<=m;k++)
        for(int i=1;i<=m;i++) if(f[i][k]<n+1&&ds<k) ds=k,u=i;
     printf("%d\n",ds);
    for(int v=ds;v>=1;v--){
        while(f[u][v]==f[u-1][v]) u--;
        c[v]=a[u--];
    }
    for(int i=1;i<=ds;i++) printf("%d ",c[i]);


}

int main()
{
    freopen("liondance.inp", "r", stdin);
    freopen("liondance.out", "w", stdout);
    scanf("%d %d", &n, &u);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for(int j = 1; j <= n; ++j) scanf("%d", &b[j]);
    if(n <= 20) sub1();
    else sub2();
}
