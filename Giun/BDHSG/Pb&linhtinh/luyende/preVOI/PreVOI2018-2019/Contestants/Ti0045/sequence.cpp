#include <bits/stdc++.h>
#define maxn 6005
#define maxc
#define PB push_back
#define MP make_pair
#define ft first
#define sd second
#define DH "sequence"
using namespace std;
long n,m,k;
long a[maxn],b[maxn],c[maxn],st[maxn];
long nex1[maxn],nex2[maxn],d[maxn];
long kq[maxn];
vector < long > v;
void ganmin()
{
    long ok=1;
    for(long i=1;i<=k;++i)
    {
        if(kq[i]>c[i])
        {
            ok=2;
            break;
        }
        if(kq[i]<c[i]) break;
    }
    if(ok==2)
    {
        for(long i=1;i<=k;++i) kq[i]=c[i];
    }
}
void update(long x,long val)
{
    for(;x<maxn;x+=(x&-x)) d[x]=min(d[x],val);
}
long get(long x)
{
    long res=1e9;
    for(;x>0;x-=(x&-x)) res=min(res,d[x]);
    return res;
}
void nhap()
{
    memset(kq,60,sizeof(kq));
    cin >> n >> m >> k;
    for(long i=1;i<=n;++i)
    {
        cin >> a[i];
    }
    for(long i=1;i<=m;++i)
    {
        cin >> b[i];
    }
}
vector < long > v1, v2;
void lam()
{
    for(long id=1;id<=k;++id)
    {
        long x=n-id;
        long y=m-k+id;
        if(x<0 || y<0 ) continue;
        v1.clear();
        v2.clear();
        long top=0;
        for(long i=1;i<=n;++i)
        {
            while(top>0 && x >0 && a[st[top]]>a[i])
            {
                top--;
                x--;
            }
            st[++top]=i;
        }
        while(x>0)
        {
            x--;
            top--;
        }
        for(long i=1;i<=top;++i) v1.PB(a[st[i]]);
        top=0;
        for(long i=1;i<=m;++i)
        {
            while(top>0 && y >0 && b[st[top]]>b[i])
            {
                top--;
                y--;
            }
            st[++top]=i;
        }
        while(y>0)
        {
            y--;
            top--;
        }
        for(long i=1;i<=top;++i) v2.PB(b[st[i]]);
        memset(d,60,sizeof(d));
        for(long i=v1.size()-1;i>=0;--i) nex1[i]=get(v1[i]-1),update(v1[i],i);
        memset(d,60,sizeof(d));
        for(long i=v2.size()-1;i>=0;--i) nex2[i]=get(v2[i]-1),update(v2[i],i);
        long cnt=0;
        long id1=0,id2=0;
        while(id1 < v1.size() || id2 <v2.size())
        {
            if(id1==v1.size())
            {
                c[++cnt]=v2[id2++];
                continue;
            }
            if(id2==v2.size())
            {
                c[++cnt]=v1[id1++];
                continue;
            }
            if(v1[id1]<v2[id2])
            {
                c[++cnt]=v1[id1++];
            }
            if(v1[id1]>v2[id2]) c[++cnt]=v2[id2++];
            if(v1[id1]==v2[id2])
            {
                if(nex1[id1]-id1<nex2[id2]-id2)
                {
                    c[++cnt]=v1[id1++];
                }
                else c[++cnt]=v2[id2++];
            }
        }
        ganmin();
    }
    for(long i=1;i<=k;++i) cout << kq[i]<<" ";
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(DH".inp","r",stdin);
    freopen(DH".out","w",stdout);
    nhap();
    lam();
    return 0;
}
