#include<bits/stdc++.h>
#define oo 5000
using namespace std;
typedef pair<int,int> II;
typedef pair<int,II> III;
II x[3005];
III c[3005],d[3005];
III rest[3005];
int A[3005],a[3005],h[3005],f[3005],tr[3005],nho[3005],m,n,k,b[3005],dda[3005],ddb[3005];
void sub1()
{
    for(int i=1;i<=m;i++) x[i]=II(a[i],i);
    sort(x+1,x+m+1);
    for(int i=1;i<=m;i++) A[i]=x[i].second;
    for(int i=1;i<=m;i++) {
        f[i]=1;
        for(int j=1;j<i;j++) if(A[i]>A[j]&&f[i]<f[j]+1) f[i]=f[j]+1, tr[i]=j;
    }
    int M=0;
    for(int i=1;i<=m;i++) if(f[i]>f[M]) M=i;
    int sl1=0;
    while(M>0) {
        c[++sl1]=III(a[A[M]],II(A[M],1));
        dda[A[M]]=1;
        M=tr[M];
    }
    reverse(c+1,c+sl1+1);
    for(int i=1;i<=n;i++) x[i]=II(b[i],i);
    sort(x+1,x+n+1);
    for(int i=1;i<=n;i++) A[i]=x[i].second;
    memset(f,0,sizeof(f));
    memset(tr,0,sizeof(tr));
    for(int i=1;i<=n;i++) {
        f[i]=1;
        for(int j=1;j<i;j++) if(A[i]>A[j]&&f[i]<f[j]+1) f[i]=f[j]+1, tr[i]=j;
    }
    M=0;
    for(int i=1;i<=m;i++) if(f[i]>f[M]) M=i;
    int sl=0;
    while(M>0) {
        d[++sl]=III(b[A[M]],II(A[M],2));
        ddb[A[M]]=1;
        M=tr[M];
    }
    reverse(d+1,d+sl+1);
    while(sl1+sl>k) {
        if(c[sl1].first>d[sl].first) --sl1;
        else --sl;
    }
    for(int i=1;i<=sl;i++) {
        int u=lower_bound(c+1,c+sl1+1,d[i])-c;
        if(u<=sl1) {
            ++sl1;
            for(int j=sl1;j>u;j--) c[j]=c[j-1];
            c[u]=d[i];
        }
        else c[++sl1]=d[i];
    }
    int cnt=0;
    for(int i=1;i<=m;i++) if(!dda[i]) rest[++cnt]=III(a[i],II(-i,1));
    for(int i=1;i<=n;i++) if(!ddb[i]) rest[++cnt]=III(b[i],II(-i,2));
    sort(rest+1,rest+cnt+1);
    int pos=0;
    while(sl1<k) {
        ++pos;
        bool ok=false;
        for(int i=1;i<=sl1;i++) {
            if(c[i].second.second==rest[pos].second.second&&c[i].second.first>-rest[pos].second.first) {
                ++sl1;
                for(int j=sl1;j>i;j--) c[j]=c[j-1];
                c[i]=rest[pos];
                ok=true;
                break;
            }
        }
        if(!ok) c[++sl1]=rest[pos];
    }
    for(int i=1;i<=k;i++) printf("%d ",c[i].first);
}
#define LO "SEQUENCE"
int main ()
{
    freopen(LO".inp","r",stdin);
    freopen(LO".out","w",stdout);
    scanf("%d%d%d",&m,&n,&k);
    for(int i=1;i<=m;i++) scanf("%d",&a[i]);
    for(int j=1;j<=n;j++) scanf("%d",&b[j]);
    sub1();
    return 0;
}
