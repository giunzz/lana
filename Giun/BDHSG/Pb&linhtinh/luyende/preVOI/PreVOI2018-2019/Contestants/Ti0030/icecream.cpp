#include <bits/stdc++.h>
#define foreinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define forv(a,b) for(auto&a:b)
#define pii pair<int,int>
#define fi first
#define se second
#define int long long
using namespace std;
inline int read()
{
    int x=0; bool ok=false; char c=getchar();
    while(!isdigit(c)) ok=(c=='-'),c=getchar();
    while(isdigit(c)) x=x*10+c-'0',c=getchar();
    if(ok) return -x; return x;
}
const int N=310,mod=1e9+9;
int n,m,kq;
int x[N];
int sl[5],tg[5];
int f[55][50*4+10][50*2+10][50+10];
void check()
{
    bool ok=true;
    foreinc(i,1,3) tg[i]=sl[i];
    foreinc(i,1,n)
    {
        if(x[i]==1)
        {
            if(tg[1]==m) {ok=false;break;}
            tg[1]++;
        }
        if(x[i]==2)
        {
            if(tg[2]==m) {ok=false;break;}
            if(tg[1]<1) {ok=false;break;}
            else tg[1]--,tg[2]++;
        }
        if(x[i]==3)
        {
            if(tg[3]==m) {ok=false;break;}
            if(tg[1]&&tg[2]) tg[1]--,tg[2]--,tg[3]++;
            else
            {
                if(tg[1]>=3) tg[1]-=3,tg[3]++;
                else {ok=false;break;}
            }
        }
    }
    if(ok) kq++;
}
void duyet(int i)
{
    if(i==n+1) check();
    else foreinc(j,1,3) {x[i]=j;duyet(i+1);}
}
main()
{
    freopen("icecream.inp","r",stdin);
    freopen("icecream.out","w",stdout);
    n=read();m=read();
    foreinc(i,1,3) sl[i]=read();
    if(n<=15&&m<=10)
    {
        duyet(1);
        cout<<kq<<"\n";
        return 0;
    }
    else
    {
        f[0][min(150ll,sl[1])][min(50ll,sl[2])][min(0ll,sl[3])]=1;
        foreinc(i,0ll,n)
            foreinc(c50,0,150+min(n,m-sl[1]))
                foreinc(c1,0,50+min(n,m-sl[2]))
                    foreinc(c2,0,min(n,m-sl[3])) if(f[i][c50][c1][c2])
                    {
                        if(i==n)
                        {
                            kq+=f[i][c50][c1][c2];
                            continue;
                        }
                        if(c50<m) f[i+1][c50+1][c1][c2]=(f[i+1][c50+1][c1][c2]+f[i][c50][c1][c2])%mod;
                        if(c1<m&&c50) f[i+1][c50-1][c1+1][c2]=(f[i+1][c50-1][c1+1][c2]+f[i][c50][c1][c2])%mod;
                        if(c2<m)
                        {
                            if(c50&&c1) f[i+1][c50-1][c1-1][c2+1]=(f[i+1][c50-1][c1-1][c2+1]+f[i][c50][c1][c2])%mod;
                            else if(c50>=3) f[i+1][c50-3][c1][c2+1]=(f[i+1][c50-3][c1][c2+1]+f[i][c50][c1][c2])%mod;
                        }
                    }
        cout<<kq%mod;
    }//999025476
}
