#include <bits/stdc++.h>
using namespace std;
const int nm=(1<<19);
struct pt { string s; long long d; };
bool cmp(pt a,pt b) { return a.d<b.d; }
long long c,b,n,k,nmax,d,h[2],de[2],i,j,l;
pt a[2][nm+1];
void vet(int id,int i,int n,string s)
{
    if(i>n) { de[id]++; a[id][de[id]]={ s,d }; return; }
    for(int j=0;j<=1;j++)
    {
        long long x=h[j],l=d; d=(d*10%nmax+x)%nmax;
        vet(id,i+1,n,s+char(x+'0'));
        d=l;
    }
}
string bs(long long b)
{
    int l=1,r=de[1];
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(a[1][mid].d>=b) r=mid; else l=mid+1;
    }
    if(a[1][l].d==b) return a[1][l].s; else return "!";
}
void cv()
{
    sort(a[1]+1,a[1]+de[1]+1,cmp);
    for(i=1;i<=de[0];i++)
    {
        d=a[0][i].d;
        for(j=l;j<=n;j++) d=(d*10)%nmax;
        if(d<k) b=(d-k+nmax)%nmax;
        else b=(d-k)%nmax;
        string x=bs(nmax-b);
        if(x!="!")
        {
            cout<<a[0][i].s<<x;
            exit(0);
        }
    }
}
int main()
{
    freopen("modulo.inp","r",stdin);
    freopen("modulo.out","w",stdout);
    cin>>c>>b>>n>>k;
    if(n>38) { cout<<-1; return 0; }
    nmax=1;
    for(i=1;i<=n;i++) nmax*=2;
    h[0]=c; h[1]=b;
    vet(0,1,n/2,""); vet(1,n/2+1,n,"");
    l=n/2+1;
    cv();
    swap(a[1],a[0]); swap(de[1],de[0]); l+=n%2; cv();
    cout<<-1;
}
