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
const int N=310;
int ma,m1,m2,m3,n,res;
int tt[20];
inline void ktra()
{
    int dem1=m1,dem2=m2,dem3=m3;
    forinc(i,1,n)
    {
        if(tt[i]==1)
        {
            dem1++;
            if(dem1>ma) return;
        }
        else if(tt[i]==2)
        {
            dem2++; if(dem2>ma) return;
            if(dem1==0) return;
            dem1--;
        }
        else if(tt[i]==3)
        {
            dem3++; if(dem3>ma) return;
            if(dem2>0 && dem1>0) {dem2--,dem1--; continue;}
            else if(dem1>=3) {dem1-=3; continue;}
            return;
        }
    }
    res++;
}
inline void duyet(int i)
{
    if(i==n+1) ktra();
    else forinc(j,1,3) tt[i]=j,duyet(i+1);
}
struct kp
{
    int sl,x1,x2,x3;
};
queue<kp> q;
void sub2()
{
    q.push({0,m1,m2,m3});
    while(!q.empty())
    {
        kp cc=q.front(); q.pop();
        if(cc.sl==n) {res++; continue;}
        if(cc.x1<ma) q.push({cc.sl+1,cc.x1+1,cc.x2,cc.x3});
        if(cc.x1>0 && cc.x2<ma) q.push({cc.sl+1,cc.x1-1,cc.x2+1,cc.x3});
        if(cc.x1>0 && cc.x2>0 && cc.x3<ma) q.push({cc.sl+1,cc.x1-1,cc.x2-1,cc.x3+1});
        else if(cc.x1>2 && cc.x3<ma) q.push({cc.sl+1,cc.x1-3,cc.x2,cc.x3+1});
    }
    cout<<res;
}
int main()
{
    //freopen("d.inp","r",stdin);
    freopen("icecream.inp","r",stdin); freopen("icecream.out","w",stdout);
    read(n); read(ma); read(m1); read(m2); read(m3);
    if(n<=15) {duyet(1); cout<<res;}
    else sub2();
}
