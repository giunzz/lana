#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
typedef pair <long long ,long long > p1;
long long n,m,k,t;
p1 c[3005][14];
p1 d[3005][14];
void dauvao()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("sequence.inp","r",stdin);
    freopen("sequence.out","w",stdout);
}
void nhap()
{
    cin>>n>>m>>k;
    for (long long i=1;i<=n;i++)
    {
        long long u;
        cin>>u;
    c[i][0].fi=u;
    c[i][0].se=i;
    }
    n++;
    c[n][0].fi=1000000007;
    c[n][0].se=n;
    for (long long j=1;j<=m;j++)
    {
        long long u;
        cin>>u;
        d[j][0].fi=u;
        d[j][0].se=j;
    }
        m++;
    d[m][0].fi=1000000007;
    d[m][0].se=m;
    for (long long i=1;i<=12;i++)
    {
        for (long long j=1;j+(1LL<<i)-1<=n;j++)
        {
           c[j][i].fi=min(c[j][i-1].fi,c[j+(1<<(i-1))][i-1].fi);
           c[j][i].se=c[j][i-1].se;
           if (c[j][i-1].fi>c[j+(1<<(i-1))][i-1].fi)
           {
                c[j][i].se=c[j+(1<<(i-1))][i-1].se;
           }
        }
         for (long long j=1;j+(1LL<<i)-1<=m;j++)
        {
           d[j][i].fi=min(d[j][i-1].fi,d[j+(1<<(i-1))][i-1].fi);
           d[j][i].se=d[j][i-1].se;
           if (d[j][i-1].fi>d[j+(1<<(i-1))][i-1].fi)
           {
                d[j][i].se=d[j+(1<<(i-1))][i-1].se;
           }
        }
    }
    long long vt1=1,vt2=1;
    while (k>0)
    {
        long long vt3=n-(k-1-m+vt2)-1;
        long long vt4=m-(k-1-n+vt1)-1;
        if (vt3<vt1) vt3=vt1;
        if (vt3>n) vt3=n;
        if (vt4<vt2) vt4=vt2;
        if (vt4>m) vt4=m;
        long long tam1=log2(vt3-vt1+1);
        long long tam2=log2(vt4-vt2+1);
        p1 tam3,tam4;
        if (c[vt1][tam1].fi<=c[vt3-(1LL<<tam1)+1][tam1].fi)
        {
            tam3.fi=c[vt1][tam1].fi;
            tam3.se=c[vt1][tam1].se;
        }
        else
        {
            tam3.fi=c[vt3-(1LL<<tam1)+1][tam1].fi;
            tam3.se=c[vt3-(1LL<<tam1)+1][tam1].se;
        }
         if (d[vt2][tam1].fi<=d[vt4-(1LL<<tam1)+1][tam1].fi)
        {
            tam4.fi=d[vt2][tam2].fi;
            tam4.se=d[vt2][tam2].se;
        }
        else
        {
            tam4.fi=d[vt4-(1LL<<tam2)+1][tam1].fi;
            tam4.se=d[vt4-(1LL<<tam2)+1][tam1].se;
        }
        if (tam3.fi<tam4.fi) {cout<<tam3.fi<<" ";vt1=tam3.se+1;}
        else
        {
            if (tam3.fi>tam4.fi) {cout<<tam4.fi<<" ";vt2=tam4.se+1;}
            else
            {
                long long tam5=min(n-tam3.se-1,m-tam4.se-1);
                bool ok=0;
                bool ok1=0;
                for (long long i=1;i<=tam5 &&ok==0;i++)
                {
                    if (c[tam3.se+i][0]!=d[tam4.se+i][0])
                    {
                        ok=1;
                        if (c[tam3.se+i][0]>d[tam4.se+i][0])
                        {
                            ok1=1;
                        }
                    }
                }
                if (ok==0)
                {
                    if (n-tam3.se-1>=m-tam4.se-1)
                    {
                        cout<<tam3.fi<<" ";
                        vt1=tam3.se+1;
                    }
                    else
                    {
                            cout<<tam4.fi<<" ";
                            vt2=tam4.se+1;
                    }
                }
                else
                {
                    if (ok1==0)
                    {
                        cout<<tam3.fi<<" ";
                        vt1=tam3.se+1;
                    }
                    else
                    {
                        cout<<tam4.fi<<" ";
                        vt2=tam4.se+1;
                    }
                }
            }
        }
        k--;
    }
}
int main()
{
    dauvao();
    nhap();
    return 0;
}
//cacccccccccccccccccccccccccccccccc
