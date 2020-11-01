#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define in() ({ll x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
#define inchar() ({char c=getchar();while(c==' '||c=='\n') c=getchar();c;})
#define pc putchar
inline void cc(ll x)
{
    if(x<0) pc('-'),x=-x;
    if(x>9) cc(x/10);
    pc(x%10+'0');
}
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=b;a<=i;i--)
#define VEC(i,a) for(auto&i:a)
#define rr(x) " "<<#x<<'='<<x<<" "
#define pb push_back
#define mt make_tuple
#define pi pair<ll,int>
#define fi first
#define se second
#define f(i,a,b,c) f[i%2][a+150][b+50][c+50]
/////////////////////////////////// PXH612
const int MOD=1e9+9;
int n,MX,A,B,C;
pi f[2][300][300][300];int F;

bool tman(int x)
{
    return (0<=x&&x<=MX);
}
void UDT(int id,int a,int b,int c,ll val)
{
    if(tman(A+a)&&tman(B+b)&&tman(C+c))
    {
        if(f(id,a,b,c).se==F+1) f(id,a,b,c).fi+=val;
        else f(id,a,b,c)={val,F+1};

        f(id,a,b,c).fi%=MOD;
    }
}
void SUB2()
{
    f(0,0,0,0)={1,++F};
    FOR(i,0,n-1)
    {
        FOR(a,-3*n,n) FOR(b,-n,n) FOR(c,-n,n) if(f(i,a,b,c).se==F)
        {
            UDT(i+1,a+1,b,c,f(i,a,b,c).fi);
            UDT(i+1,a-1,b+1,c,f(i,a,b,c).fi);

            if(B+b>0) UDT(i+1,a-1,b-1,c+1,f(i,a,b,c).fi);
            else UDT(i+1,a-3,b,c+1,f(i,a,b,c).fi);
        }
        ++F;
    }

    ll res=0;
    FOR(a,-3*n,n) FOR(b,-n,n) FOR(c,-n,n) if(f(n,a,b,c).se==F)
    {
        res+=f(n,a,b,c).fi;
        res%=MOD;
    }
    cout<<res;
}
main()
{
    freopen("icecream.inp","r",stdin);
    freopen("icecream.out","w",stdout);
    n=in();MX=in();
    A=in(),B=in(),C=in();
    SUB2();
}
