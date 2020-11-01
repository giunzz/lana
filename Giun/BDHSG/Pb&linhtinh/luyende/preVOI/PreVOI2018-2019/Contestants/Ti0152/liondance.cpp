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
int n,k,n1,m1;
int a[maxn],b[maxn];
int f[maxn][maxn],lv[maxn];
int nexta[maxn][maxn];
int nextb[maxn][maxn];
int value[maxn];
int low[maxn];
int high[maxn];
vector <int> g[4001];
set <int> up;
set <int> dw;
map <int, int> M;
bool xd[maxn][maxn];
//int f[maxn][maxn];
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
int tinh(int u, int v)
{
    if(xd[u][v]) return f[u][v];
    xd[u][v]=1;
    for(int x: g[u]) if(nexta[u][x]&&nextb[v][x]) f[u][v]=max(f[u][v], tinh(nexta[u][x], nextb[u][x]));
    f[u][v]++;
    return f[u][v];
}
void xuli2()
{
    foru(i, 1, n) up.insert(a[i]);
    foru(i, 1, n) dw.insert(b[i]);

    for(int x: up) if (dw.find(x)!=dw.end())
    {
        M[x]=M.size();
        value[M[x]]=x;
    }
    foru(i, 1, n)
    if(M.find(a[i])!=M.end())
    {
        n1++;
        a[n1]=M[a[i]];
    }
    foru(i, 1, n)
    if(M.find(b[i])!=M.end()){
        m1++;
        b[m1]=M[b[i]];
    }
    n=M.size();
    foru(i, 1,n)
    {
        low[i]=high[i]=i;
        while((low[i]>1)&&(value[i]-value[low[i]-1]<=n)) low[i]--;
        while((high[i]<n)&&(value[high[i]+1]-value[i]<=n)) high[i]++;
    }
    ford(i, n1-1, 0){
    foru(j, 1, n) nexta[i][j]=nexta[i+1][j];
        nexta[i][a[i+1]]=i+1;
    }
    ford(i, m1-1, 0){
    foru(j, 1,n) nextb[i][j]=nextb[i+1][j];
        nextb[i][b[i+1]]=i+1;
    }
    foru(i, 1, n1) ford(j, high[a[i]], low[a[i]]) if(nexta[i][j]) g[i].pb(j);
    int kq=0;
    foru(i, 1, n) kq=max(kq, tinh(nexta[0][i], nextb[0][i]));
    cout << kq << endl;
    int u=0, v=0;
    while(kq>0){
        ford(i, n, 1) if(nexta[u][i]&&nextb[v][i]) if(tinh(nexta[u][i], nextb[v][i])==kq){
            kq--;
            u=nexta[u][i];
            v=nextb[v][i];
            cout << value[i] <<' ';
            break;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("liondance.inp", "r", stdin);
    freopen("liondance.out", "w", stdout);
    read(n);read(k);
    foru(i,1,n) read(a[i]);
    foru(i,1,n) read(b[i]);
    if (n<=500) xuli1(); else
    xuli2();
}
