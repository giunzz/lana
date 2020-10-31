#include <bits/stdc++.h>
using namespace std;
int m,n,k,u,v,p,q;
int a[304][304];
bool b[304][304];
int F[304][304];
int kq1[304][304],kq[304][304];
int main()
{
    ifstream cin("TABLE.inp");
    ofstream cout("TABLE.out");
    cin>>m>>n>>k;
    for(int i(1);i<=m;++i)
        for(int j(1);j<=n;++j) cin>>a[i][j];
    for(int i(1);i<=k;++i)
    {
        memset(F,-60,sizeof(F));
        memset(kq,60,sizeof(kq));
        memchr(kq1,-60,sizeof(kq1));
        cin>>u>>v>>p>>q;
        F[u][v]=a[u][v];
        for(int j(v+1);j<=q;++j) F[u][j]=F[u][j-1]+a[u][j];
        for(int j(u+1);j<=p;++j) F[j][v]=F[j-1][v]+a[j][v];
        for(int j(u+1);j<=p;++j)
            for(int l(v+1);l<=q;++l) F[j][l]=max(F[j][l-1],F[j-1][l])+a[j][l];
        int j=p,l=q;
        while(true)
        {
            if(j<=u&&l<=v) break;
            if(F[j][l]==F[j-1][l]+a[j][l]) {--j;b[j][l]=1;}
            else {--l;b[j][l]=1;}
            cout<<"";
        }
        b[u][v]=0;
        for(j=u;j<=p;++j)
        {
            for(l=v;l<=q;++l)
            {
                if(j==u&&l==v) {kq1[j][l]=a[j][l];continue;}
                kq1[j][l]=max(kq1[j-1][l],kq1[j][l-1])+a[j][l];
                if(kq[j-1][l]<1e8) kq[j][l]=kq[j-1][l]+a[j][l];
                if(kq[j][l-1]<1e8) kq[j][l]=min(kq[j][l],kq[j-1][l]+a[j][l]);
                if(kq[j-1][l]<1e8) kq[j][l]=max(kq[j][l],kq1[j][l-1]+a[j][l]);
                if(kq[j][l-1]<1e8) kq[j][l]=max(kq[j][l],kq1[j-1][l]+a[j][l]);
                if(b[j-1][l]==1) kq[j][l]=min(kq[j][l],kq1[j][l-1]+a[j][l]);
                if(b[j][l-1]==1) kq[j][l]=min(kq[j][l],kq1[j-1][l]+a[j][l]);
                cerr<<"";
            }
        }
        cout<<kq[p][q]<<endl;
    }
}
