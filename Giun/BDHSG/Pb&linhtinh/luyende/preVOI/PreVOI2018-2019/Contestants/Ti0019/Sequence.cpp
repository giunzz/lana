#include<bits/stdc++.h>
using namespace std;
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(i,a) for(auto &i:a)
#define pii pair<int,int>
#define fi first
#define se second
void read(int &x)
{
    x=0; char c=getchar(); bool ok=false;
    while((c<'0'||c>'9') && c!='-') c=getchar();
    if(c=='-') ok=true,c=getchar();
    while('0'<=c && c<='9') x=x*10+c-'0',c=getchar();
    if(ok) x=-x;
}
const int N=3010;
int m,n,k,a[3010],b[3010],mia=INT_MAX,mib=INT_MAX,da[N],db[N],topa,topb,kq[N],cnt[N];
bool dd[N],cc[N];
void chose1(int sl)
{
    int dem=0;
    forinc(i,1,m)
    {
        if(a[i]==mia) dd[i]=true,dem++;
        if(dem==sl) return;
    }
    int x=m;
    while(dem<sl)
    {
        //cout<<dem<<endl;
        if(dd[x]==true) {x--;continue;}
        dd[x]=true,dem++,x--;
    }
}
void chose2(int sl)
{
    int dem=0;
    forinc(i,1,n)
    {
        if(b[i]==mib) cc[i]=true,dem++;
        if(dem==sl) return;
    }
    int x=n;
    while(dem<sl)
    {
        if(cc[x]==true) {x--;continue;}
        cc[x]=true,dem++,x--;
    }
}
int main()
{
    //freopen("d.inp","r",stdin);
    freopen("sequence.inp","r",stdin); freopen("sequence.out","w",stdout);
    read(m); read(n); read(k);
    forinc(i,1,k) kq[i]=INT_MAX;
    memset(a,127,sizeof(a));
    memset(b,127,sizeof(b));
    forinc(i,1,m) read(a[i]),mia=min(mia,a[i]);
    forinc(i,1,n) read(b[i]),mib=min(mib,b[i]);
    forinc(kk,max(0,k-n),min(m,k))
    {
        //cout<<12345;
        topa=0; topb=0;
        memset(dd,0,sizeof(dd)); memset(cc,0,sizeof(cc));
        chose1(kk); chose2(k-kk);
        forinc(i,1,m) if(dd[i]) da[++topa]=i;
        forinc(i,1,n) if(cc[i]) db[++topb]=i;
        int vta=1,vtb=1,sl=0;
        while(vta<=topa && vtb<=topb)
        {
            //cout<<vta<<" "<<a[da[vta]]<<endl;
            //cout<<vtb<<" "<<b[db[vtb]]<<endl;
            if(a[da[vta]]<b[db[vtb]]) cnt[++sl]=a[da[vta]],vta++;
            else if(a[da[vta]]>b[db[vtb]]) cnt[++sl]=b[db[vtb]],vtb++;
            else if(a[da[vta]]==b[db[vtb]])
            {
                //cout<<da[vta]<<" "<<a[da[vta]]<<" "<<a[da[vta+1]]<<endl;
                if(a[da[vta+1]]<b[db[vtb+1]]) {cnt[++sl]=a[da[vta]],vta++; continue;}
                cnt[++sl]=b[db[vtb]],vtb++;
            }
        }
        if(vta<=topa) forinc(i,vta,topa) cnt[++sl]=a[da[i]];
        if(vtb<=topb) forinc(i,vtb,topb) cnt[++sl]=b[db[i]];
        //forinc(i,1,k) cout<<cnt[i]<<" ";
        //cout<<endl;
        bool ok=false;
        forinc(i,1,k)
        {
            if(kq[i]<cnt[i]) break;
            else if(kq[i]>cnt[i]) {ok=true; break;}
        }
        if(ok)
        {
            //cout<<kk<<" "<<k-kk<<endl;
            //forinc(i,1,m) cout<<dd[i]<<" ";
            //cout<<endl;
            //forinc(i,1,n) cout<<cc[i]<<" ";
            //cout<<endl;
            forinc(i,1,k) kq[i]=cnt[i];
            //forinc(i,1,k) cout<<cnt[i]<<" ";
            //cout<<endl;
        }
    }
    forinc(i,1,k) cout<<kq[i]<<" ";
}
