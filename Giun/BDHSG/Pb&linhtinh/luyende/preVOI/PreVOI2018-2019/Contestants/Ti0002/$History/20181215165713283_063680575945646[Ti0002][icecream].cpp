#include <bits/stdc++.h>
inline int in()
{
    int x=0;char c=getchar();bool neg=0;
    while(('0'>c||c>'9') && c!='-') c=getchar();
    if(c=='-') neg=1,c=getchar();
    while('0'<=c&&c<='9') x=10*x+c-'0',c=getchar();
    if(neg) x=-x;
    return x;
}
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define task "icecream"
#define forinc(a,b,c) for(int a=b,__key=c;a<=__key;++a)
#define fordec(a,b,c) for(int a=b,__key=c;a>=__key;--a)
#define forv(a,b) for(auto&a:b)
#define ii pair<int,int>
#define i3 pair<int,ii>
#define fi first
#define se second
#define nd second.first
#define rd second.second
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define mt make_tuple
#define bit(x,i) ((x>>(i-1))&1)
#define on(x,i) (x|(1<<(i-1)))
#define off(x,i) (x&~(1<<(i-1)))
#define reset(f,x) memset(f,x,sizeof(f))
#define all(a) a.begin(),a.end()
#define F(a,b) (a=(a+b)%M)
const int M=1e9+7;
int n,m,kq,sum;
int f[10010][10010];
int g[10010][10010];
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>m;
    int m5=in(),m1=in(),m2=in();
    sum=5*m5+10*m1+20*m2;
    f[m5][m1]=1;
    forinc(i,0,n-1)
    {
        forinc(t1,0,m) forinc(t2,0,m) if(f[t1][t2])
        {
            int t3 =(sum-5*t1-10*t2)/20;
            int cur=f[t1][t2];
            /// 5
            if(t1<m)          F(g[t1+1][t2],cur);
            /// 10
            if(t1 && t2<m)    F(g[t1-1][t2+1],cur);
            /// 20
            if(t3<m)
            {
                if(t1 && t2)  F(g[t1-1][t2-1],cur);
                else if(t1>2) F(g[t1-3][t2],cur);
            }
        }
        forinc(t1,0,m) forinc(t2,0,m) f[t1][t2]=g[t1][t2],
                                      g[t1][t2]=0;
        sum+=5;
    }
    forinc(t1,0,m) forinc(t2,0,m)  F(kq,f[t1][t2]);
    cout<<kq;
}

