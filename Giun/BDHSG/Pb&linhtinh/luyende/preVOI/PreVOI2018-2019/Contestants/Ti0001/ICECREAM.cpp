#include <bits/stdc++.h>
#define forinc(i,a,b) for(int i=a , _b=b ; i<=_b ; ++i)
#define task "ICECREAM"
#define getbit(x,i) ((x>>i)&1)
#define onbit(x,i) (x|(1<<i))
#define N 51
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
using namespace std;
void read(int &X)
{
    X=0;
    char ch=getchar();
    bool w=false;
    while(ch<'0' || ch>'9')
    {
        if(ch=='-') w=true;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
    {
        //cout<<X<<" ";
        X=X*10+ch-'0';
        ch=getchar();
    }
    if(w) X=-X;
}
const ll M = 1000000009;
ll f[N][151][101][101];
bool d[N][151][101][101];
int n,mx,s1,s2,s3;
int x,y,z;
bool kt(int a,int b,int c,int tt)
{
    if(tt==1)
    {
        if(a==mx) return false;
        x=a+1;y=b;z=c; return true;
    }
    if(tt==2)
    {
        if(b==mx || !a) return false;
        x=a-1;y=b+1;z=c; return true;
    }
    if(c==mx) return false;
    if(a && b) { x=a-1; y=b-1; z=c+1; return true;}
    if(a>=3) { x=a-3; y=b; z=c+1; return true; }
    return false;
}
ll cal(int s,int g,int h,int k)
{
    if(d[s][g][h][k]) return f[s][g][h][k];
    d[s][g][h][k]=true;
    if(s==n) return f[s][g][h][k]=1;
    int a=s1+(g-100),b=s2+(h-50),c=s3+(k-50);
    ll tg=0;
    forinc(i,1,3) if(kt(a,b,c,i)) tg = (tg+cal(s+1,x-s1+100,y-s2+50,z-s3+50))%M;
    return f[s][g][h][k]=tg;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
    read(n); read(mx); read(s1); read(s2); read(s3);
    cout<<cal(0,100,50,50);

}
