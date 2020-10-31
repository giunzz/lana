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
const int N=4010;
int n,a[N],b[N],res,kq[N],tt[30],alp;
void ktra()
{
    int vt[30]; int top=0,cc=1;
    forinc(i,1,n) if(tt[i])
    {
        vt[++top]=a[i];
        if(top!=1 && abs(vt[top]-vt[top-1])>alp) return;
    }
    forinc(i,1,n)
    {
        if(b[i]==vt[cc]) cc++;
        if(cc>top) break;
    }
    if(cc!=top+1) return;
    if(top==res)
    {
        forinc(i,1,top)
        {
            if(kq[i]>vt[i]) return;
            if(kq[i]<vt[i]) break;
        }
        forinc(i,1,top) kq[i]=vt[i];
    }
    else if(top>res) {forinc(i,1,top) kq[i]=vt[i]; res=top;}
}
void duyet(int i)
{
    if(i==n+1) ktra();
    else forinc(j,0,1) tt[i]=j,duyet(i+1);
}
int main()
{
    //freopen("d.inp","r",stdin);
    freopen("liondance.inp","r",stdin); freopen("liondance.out","w",stdout);
    read(n); read(alp);
    forinc(i,1,n) read(a[i]);
    forinc(i,1,n) read(b[i]);
    if(n<=20)
    {
        duyet(1);
        cout<<res<<"\n";
        forinc(i,1,res) cout<<kq[i]<<" ";
    }
}
