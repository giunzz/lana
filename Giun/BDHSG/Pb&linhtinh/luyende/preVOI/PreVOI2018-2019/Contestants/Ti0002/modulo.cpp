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
#define task "modulo"
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
#define int long long
int found,a,b,n,k,M,G,di;
unordered_map<int,int> F;
void FH(int i,int r,int tt)
{
    if(i==n/2+1){F[(r*G)%M]=tt+1;return;}
    forinc(j,0,1) FH(i+1,(r*10 + ((j==0) ? a : b))%M,((j==1) ? on(tt,i):tt));
}
void SH(int i,int r,int tt)
{
    if(found) return;
    if(i==n+1)
    {
        int j=0;
        while(j<2 && !F[j*M+k-r]) j++;
        if(j>1) return;
        int o=F[j*M+k-r]-1;
        forinc(i,1,n/2)   cout<<(bit(o,i)== 0 ? a:b);
        forinc(i,n/2+1,n) cout<<(bit(tt,i)==0 ? a:b);
        found=1;
        return;
    }
    forinc(j,0,1) SH(i+1,(r*10 + ((j==0) ? a : b))%M,((j==1) ? on(tt,i):tt));
}
main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    a=in(),b=in();
    n=in(),k=in();
    M=1ll<<n;
    G=1;
    forinc(i,n/2+1,n) G=G*10%M;
    if(n==1)
    {
        if(a%M==k) return cout<<a,0;
        if(b%M==k) return cout<<b,0;
        return cout<<-1,0;
    }
    FH(1,0,0);
    SH(n/2+1,0,0);
    if(!found) return cout<<-1,0;
}

