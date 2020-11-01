#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define name "liondance"

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll oo = 1e18;
const int nmax = 4e3+5;
int n,m;
int a[nmax],b[nmax],kq[nmax],thu[nmax];
int l[nmax][nmax],lv[nmax][nmax];

void trau()
{
    int cnt=0,sl=0;
    for(int x=1;x<=((1<<n)-1);x++)
    {
        if(x==105)
            int z=0;
        int vt=0;sl=0;
        int j=1;
        for(int i=1;i<=n;i++)
            if(((x>>(i-1)) & 1) ==1)
        {
            while(j<=n && b[j]!=a[i]) ++j;
            if(j>n) break;
            ++j;
            if(vt==0)
            {
                vt=i;
                thu[++sl]=a[i];
            }
            else
                if(abs(a[i]-thu[sl])<=m)
            {
                thu[++sl]=a[i];
            }
        }
        if(sl>cnt)
        {
            for(int i=1;i<=sl;i++)
                kq[i]=thu[i];
            cnt=sl;
        }
        if(sl==cnt)
        {
            for(int i=1;i<=sl;i++)
                if(kq[i]>thu[i]) break;
                else
                if(kq[i]<thu[i])
                {
                    for(int j=1;j<=sl;j++)
                        kq[j]=thu[j];
                    break;
                }
        }
    }
    cout << cnt<<'\n';
    for(int i=1;i<=cnt;i++)
        cout << kq[i]<<" ";
}

void xuli()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
    {
        if(a[i]==b[i])
        {
            l[i][j]=l[i-1][j-1]+1;
            lv[i][j]=1;
        }
        else
        {
            l[i][j]=l[i-1][j];
            l[i][j]=max(l[i][j],l[i][j-1]);
        }
    }
    cout << l[n][n];
    int cnt=l[n][n];
}

int main()
{
	ios_base::sync_with_stdio(0);
	freopen(name".inp","r",stdin);
	freopen(name".out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    for(int i=1;i<=n;++i) scanf("%d",&b[i]);
    if(n<=20) trau();
    else
    xuli();
	return 0;
}
