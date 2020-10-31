#include <bits/stdc++.h>
#define foreinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define forv(a,b) for(auto&a:b)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
inline int read()
{
    int x=0; bool ok=false; char c=getchar();
    while(!isdigit(c)) ok=(c=='-'),c=getchar();
    while(isdigit(c)) x=x*10+c-'0',c=getchar();
    if(ok) return -x; return x;
}
const int s1=110;
string f[s1][s1][2*s1];
string mi(string &a,string &b)
{
    if(a.size()==0) return b;
    int n=a.size();
    foreinc(i,0,n-1)
    {
        if(a[i]>b[i]) return b;
        if(a[i]<b[i]) return a;
    }
    return a;
}
int m,n,k;
string kq;
int a[s1];
int b[s1];

main()
{
    freopen("sequence.inp","r",stdin);
    freopen("sequence.out","w",stdout);
    m=read();n=read();k=read();
    foreinc(i,1,m) a[i]=read();
    foreinc(i,1,n) b[i]=read();
    if(m<=100&&n<=100)
    {
        foreinc(i,1,m) f[i][0][1]=char(a[i]+'0');
        foreinc(i,1,n) f[0][i][1]=char(b[i]+'0');
        foreinc(i,0,m)
            foreinc(j,0,n)
                foreinc(t,1,k) if(f[i][j][t].size())
                {
                    if(t==k)
                    {
                        kq=mi(kq,f[i][j][t]);
                        continue;
                    }
                    if(i<m)
                    {
                        string tg=f[i][j][t]+char(a[i+1]+'0');
                        f[i+1][j][t+1]=mi(f[i+1][j][t+1],tg);
                        f[i+1][j][t]=mi(f[i+1][j][t],f[i][j][t]);
                    }
                    if(j<n)
                    {
                        string tg=f[i][j][t]+char(b[j+1]+'0');
                        f[i][j+1][t+1]=mi(f[i][j+1][t+1],tg);
                        f[i][j+1][t]=mi(f[i][j+1][t],f[i][j][t]);
                    }
                }
        foreinc(i,0,k-1) cout<<kq[i]<<" ";
    }
}
