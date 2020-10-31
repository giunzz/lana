#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define name "sequence"

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll oo = 1e9+7;
const int nmax = 1e3+5;
int m,n,k;
int a[nmax],b[nmax];

int f[105][105][205];
int l[105][105][205];
int kq[2*nmax];

void trau()
{
    memset(f,63,sizeof(f));
    a[0]=f[1][1][1];
    b[0]=f[1][1][1];
    for(int i=0;i<=m;++i)
        for(int j=0;j<=n;++j)
            for(int t=1;t<=min(i+j,k);++t)
    {
        if(f[i][j][t]>f[i][j-1][t])
            {f[i][j][t]=f[i][j-1][t];l[i][j][t]=1;}
        if(f[i][j][t]>f[i-1][j][t])
            {f[i][j][t]=f[i-1][j][t];l[i][j][t]=2;}
        if(f[i][j][t]>a[i])
            {f[i][j][t]=a[i];l[i][j][t]=3;}
        if(f[i][j][t]>b[j])
            {f[i][j][t]=b[j];l[i][j][t]=4;}
    }
    int cnt=0;
    int i=m,j=n;
    while(k>0)
    {
        if(l[i][j][k]==1)
            --j;
        if(l[i][j][k]==2)
            --i;
        if(l[i][j][k]==3)
        {
            kq[++cnt]=a[i];
            --i;
            --k;
        }
        if(l[i][j][k]==4)
        {
            kq[++cnt]=b[j];
            --j;
            --k;
        }
    }
    for(k=cnt;k>=1;--k)
        cout << kq[k]<<" ";
}

int main()
{
	ios_base::sync_with_stdio(0);
	freopen(name".inp","r",stdin);
	freopen(name".out","w",stdout);
    scanf("%d%d%d",&m,&n,&k);
    for(int i=1;i<=m;++i) scanf("%d",&a[i]);
    for(int i=1;i<=n;++i) scanf("%d",&b[i]);
    trau();
	return 0;
}



//void chuanbi()
//{
//    int cnt=0;
//    for(int i=1;i<=m;++i)
//        c[++cnt]=a[i];
//    for(int i=1;i<=n;++i)
//        c[++cnt]=b[i];
//    sort(c+1,c+cnt+1);
//    c[0]=c[1]-1;
//    int dem=0;
//    for(int i=1;i<=cnt;i++)
//        if(c[i]!=c[i-1])
//            M[c[i]]=++dem;
//    for(int i=1;i<=m;++i)
//        a[i]=M[a[i]];
//    for(int i=1;i<=n;++i)
//        b[i]=M[b[i]];
//}
