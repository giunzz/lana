#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define name "table"

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll oo = 1e18;
const int nmax = 3e2+5;
int m,n,k,x,y,u,v;
int a[nmax][nmax];
ll f[nmax][nmax];
int xd[nmax][nmax];
ll ans,kq;

void chuanbi()
{
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
            f[i][j]=max(f[i-1][j],f[i][j-1])+a[i][j];
}

ll l[nmax][nmax];

ll tinh(int x,int y,int u,int v)
{
    for(int i=x-1;i<=u;++i)
        for(int j=y-1;j<=v;++j)
            l[i][j]=0;
    for(int i=x;i<=u;++i)
        for(int j=y;j<=v;++j)
    {
        if(xd[i][j]==-1) continue;
        l[i][j]=max(l[i-1][j],l[i][j-1]) +a[i][j];
    }
    return l[u][v];
}

void lanvet(int i,int j)
{
    if(i==x && j==y) return;
    //if(j<v-1)
    {
        xd[i][j]=-1;
        ll tg=tinh(x,y,u,v);
        xd[i][j]=0;
        kq=min(kq,tg);
    }
//    if(i<u-1)
//    {
//        xd[i][j]=-1;
//        ll tg=tinh(x,y,u,v);
//        xd[i][j]=0;
//        ans=min(ans,tg);
//    }
    if(a[i-1][j]>a[i][j-1]) lanvet(i-1,j);
    else if(a[i-1][j]<a[i][j-1]) lanvet(i,j-1);
    else {lanvet(i-1,j);lanvet(i,j-1);}
}

void xuli()
{
    for(int o=1;o<=k;++o)
    {
        scanf("%d%d%d%d",&x,&y,&u,&v);
        ans=a[x][y]+a[u][v];
        kq=oo;
        if(a[u-1][v]>a[u][v-1]) lanvet(u-1,v);
        else if(a[u-1][v]<a[u][v-1]) lanvet(u,v-1);
        else {lanvet(u-1,v);lanvet(u,v-1);}
        cout << kq<<'\n';
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
	freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    scanf("%d%d%d",&m,&n,&k);
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
                scanf("%d",&a[i][j]);
    chuanbi();
    xuli();
	return 0;
}
