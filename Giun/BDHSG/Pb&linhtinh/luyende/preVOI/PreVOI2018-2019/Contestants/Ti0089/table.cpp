#include <bits/stdc++.h>
#define maxn 400
#define base 1000000007
#define oo 3000000000
using namespace std;
int m,n,k,a[maxn][maxn];
long long  f[40][40];
long long getf(int u,int v,int p,int q){
    long long kk=oo;
    for (int i1=u;i1<=p;i1++)
        for (int j1=v;j1<=q;j1++)
            if (i1!=u || j1!=v)
            if (i1!=p || j1!=q){
            for (int i=u-1;i<=p;i++)
            for (int j=v-1;j<=q;j++) f[i][j]=0;
            for (int i=u;i<=p;i++)
            for (int j=v;j<=q;j++) if (i!=i1 || j!=j1)
                f[i][j]=max(f[i-1][j],f[i][j-1])+a[i][j];
            if (f[p][q]==0) f[p][q]=max(f[p-1][q],f[p][q-1]);
            kk=min(kk,f[p][q]);
        }
    return kk;
}
void xl1(){
    for (int i=1;i<=k;i++){
        int u,v,p,q;
        cin>>u>>v>>p>>q;
        cout<<getf(u,v,p,q)<<endl;
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);
    cin>>m>>n>>k;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++) cin>>a[i][j];
    if (m<40 && n<40 && k<40) xl1();
    return 0;
}
