#include <bits/stdc++.h>
#define pb push_back
#define ii pair<int,int>
#define x first
#define y second

using namespace std;

const int N=5e3+2;
const int M=500;
const int MOD=1e9+7;
const int bm=1;
int n,m,k,X,Y,Z,MAX;
int d[N],dd[N];
int x[N],y[N],z[N],r[N];

void sinh()
{
    freopen(".inp","w",stdout);
    srand(time(0));
}

int tinh(int h)
{
    int p=h,dem=0;
    for(int i=1;i<=m;i++)
        d[x[i]+r[i]+M]++,d[x[i]-r[i]+M]++;
    for(int i=X+M;i>0;i--)
    {
        if ( h >= d[i] )
        {
            h-=d[i];
            for(int j=1;j<=m;j++)
                if ( x[j]+r[j]+M == i ) d[x[j]-r[j]+M]--;
                else if ( x[j]-r[j]+M == i ) d[x[j]-r[j]+M]--;
        }
        else break;
        dem+=dd[i];
    }
    h=k-p;
    for(int i=X+M;i<=M+M;i++)
    {
        if ( h >= d[i-1] )
        {
            h-=d[i-1];
            for(int j=1;j<=m;j++)
                if ( x[j]+r[j]+M == i ) d[x[j]-r[j]+M]--;
                else if ( x[j]-r[j]+M == i ) d[x[j]-r[j]+M]--;
        }
        else break;
        dem+=dd[i];
    }
    return dem;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //sinh();
    freopen("TEAWORLD.inp","r",stdin);
    freopen("TEAWORLD.out","w",stdout);
    cin>>m>>n>>k;
    for(int i=1;i<=m+n;i++)
        cin>>x[i]>>y[i]>>z[i]>>r[i];
    cin>>X>>Y>>Z;
    for(int i=m+1;i<=m+n;i++) dd[x[i]+M]=r[i];
    for(int i=0;i<=k;i++)
        MAX=max(MAX,tinh(i));
    cout<<MAX;
}
