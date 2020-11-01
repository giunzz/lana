#include <bits/stdc++.h>
#define nmax 4007

using namespace std;

struct data
{
    long long sl,id;
};

long long m,n,k,dx[nmax],x1,yy1,z1,xx[20],ans=-1,xts[nmax],dxt[nmax];
data ts[nmax];
map <long,long> dau,cuoi,M;

void giam(long h, long q)
{
    if (dau[h]<=dx[x1] && dx[x1]<=cuoi[h]) dx[x1]-=q;
    long v1,v2;
    v1=lower_bound(xts+1,xts+n+1,dau[h])-xts;
    v2=upper_bound(xts+1,xts+n+1,cuoi[h])-xts-1;
    for (long i=v1; i<=v2; i++)
       dx[ts[i].id]-=q;
}

void gn()
{
    for (long i=999; i<=3001; i++) dx[i]=dxt[i];
    long long th=0,tong=0;
    for (long i=1; i<=n; i++)
       if (xx[i]==1)
       {
            if (dx[ts[i].id]==dx[x1]) continue;
            if (dx[ts[i].id]>dx[x1]) {giam(dx[ts[i].id],dx[ts[i].id]-dx[x1]); th+=(dx[ts[i].id]-dx[x1]);}
            else if (dx[ts[i].id]<dx[x1]) {giam(dx[x1],dx[x1]-dx[ts[i].id]); th+=(dx[x1]-dx[ts[i].id]);}
       }
    if (th<=k)
    {
        for (long i=1; i<=n; i++)
           if (xx[i]==1) tong+=ts[i].sl;
        ans=max(ans,tong);
    }
}

void tryy_(long i)
{
    for (long j=0; j<=1; j++)
    {
        xx[i]=j;
        if (i==n) gn();
        else tryy_(i+1);
    }
}

bool cmp(data q, data p)
{
    return q.id < p.id;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("teaworld.inp","r",stdin);
    freopen("teaworld.out","w",stdout);
    cin >> m >> n >> k;
    for (long i=1; i<=m; i++)
    {
        long x,y,z,r;
        cin >> x >> y >> z >> r;
        for (long j=x+2000-r; j<=x+2000+r; j++) dx[j]++;
    }

    for (long i=0; i<=4000; i++) dxt[i]=dx[i];

    dx[0]=-1;
    long j=4000;
    for (long i=1; i<=4000; i++)
        if (dx[i]!=dx[i-1])
        {
            if (M[dx[i]]==1) continue;
            while (dx[j]!=dx[i]) j--;
            dau[dx[i]]=i;
            cuoi[dx[i]]=j;
            M[dx[i]]=1;
        }

    for (long i=1; i<=n; i++)
    {
        long x,y,z,e;
        cin >> x >> y >> z >> e;
        ts[i].id=x+2000;
        ts[i].sl=e;
    }
    sort(ts+1,ts+n+1,cmp);
    for (long i=1; i<=n; i++) xts[i]=ts[i].id;
    cin >> x1 >> yy1 >> z1;
    /*for (long i=1995; i<=2005; i++) cout << dx[i] << " "; cout << endl;
    giam(1,1);
    cout << dx[xts[1]]<< " " << dx[xts[2]]<< " "<<dx[x1];*/
    x1+=2000;
    tryy_(1);
    cout <<ans;
}
