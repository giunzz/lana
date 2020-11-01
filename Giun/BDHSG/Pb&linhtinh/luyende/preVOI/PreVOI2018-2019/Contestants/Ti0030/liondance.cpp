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
const int N=110;
int n,k,kq;
int x[N];
int a[N];
int b[N];
int ans[N];
int f[N][N];
string res;
vector<pii> ke[N][N];
vector<int>nho[N][N];
void check()
{
    vector<int> luu={};
    foreinc(i,1,n) if(x[i]) luu.push_back(i);
    bool ok=true,ok1=false;
    foreinc(i,1,luu.size()-1)
    {
        if(abs(a[luu[i]]-a[luu[i-1]])>k) ok=false;
    }
    int j=0;
    foreinc(i,1,n)
    {
        if(b[i]==a[luu[j]]) j++;
        if(j==luu.size()) {ok1=true;break;}
    }
    if(ok&&ok1)
    {
        if(kq==luu.size())
        {
            foreinc(i,1,kq)
            {
                if(ans[i]<a[luu[i-1]])
                {
                    foreinc(j,1,kq) ans[j]=a[luu[j-1]];
                    break;
                }
                if(ans[i]>a[luu[i-1]]) break;
            }
        }
        if(kq<luu.size())
        {
            kq=luu.size();
            foreinc(i,1,kq) ans[i]=a[luu[i-1]];
        }
    }
}
void duyet(int i)
{
    if(i==n+1) check();
    else foreinc(j,0,1) x[i]=j,duyet(i+1);
}
string ma(string a,string b)
{
    if(a.size()<b.size()) return b;
    if(a.size()>b.size()) return a;
    int n=a.size();
    foreinc(i,0,n-1)
    {
        if(a[i]<b[i]) return b;
        if(a[i]>b[i]) return a;
    }
    return a;
}
main()
{
    freopen("liondance.inp","r",stdin);
    freopen("liondance.out","w",stdout);
    n=read(),k=read();
    foreinc(i,1,n) a[i]=read();
    foreinc(i,1,n) b[i]=read();
    if(n<=20)
    {
        x[1]=1;
        duyet(2);
        cout<<kq<<"\n";
        foreinc(i,1,kq) cout<<ans[i]<<" ";
        return 0;
    }
        foreinc(i,1,n)
            foreinc(j,1,n) if(a[i]==b[j])
                foreinc(ii,i+1,n)
                    foreinc(jj,j+1,n) if(a[ii]==b[jj])
                    {
                        ke[i][j].push_back({ii,jj});
                    }

        f[1][1]=1;
        foreinc(i,1,n) foreinc(j,1,n) if(f[i][j])
        {kq=max(kq,f[i][j]);
            forv(v,ke[i][j])
            {
                if(f[v.fi][v.se]<f[i][j]+1)
                {
                    f[v.fi][v.se]=f[i][j]+1;
                    nho[v.fi][v.se].clear();
                    forv(vv,nho[i][j]) nho[v.fi][v.se].push_back(vv);
                    nho[v.fi][v.se].push_back(a[v.fi]);
                }
                if(f[v.fi][v.se]==f[i][j]+1)
                {
                    foreinc(tt,1,nho[v.fi][v.se].size()-1)
                    {
                        if(nho[v.fi][v.se][tt-1]>nho[i][j][tt]) break;
                        if(nho[v.fi][v.se][tt-1]<nho[i][j][tt])
                        {
                            foreinc(tt1,1,nho[v.fi][v.se].size()-1) nho[v.fi][v.se][tt]=nho[i][j][tt];
                            break;
                        }
                    }
                }
            }
        }
        cout<<kq;
}
