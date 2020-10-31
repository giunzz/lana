#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
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
#define pi pair<int,int>
#define f first
#define s second
#define pow2(x) (1ll<<x)
#define bit(x,i) ((x>>(i-1))&1ll)
#define on(x,i) (x|(1ll<<(i-1)))
#define off(x,i) (x&(1ll<<(i-1)))
/////////////////////////////////// PXH612
int A,B,n,K,MOD;
int ans[100];
int pw[100];
int cal[2][100];
int xuoi[3000000];
void COUT(int tt,int len)
{
    ROF(i,1,len)
    {
        if(!bit(tt,i)) cout<<A;
        else cout<<B;
    }
}
void XUOI(int id,int goal,int sum,int tt,int o)
{
    if(id==goal+1)
    {

        if(o==1) xuoi[sum]=tt;
        if(o==2)
        {
            int ned=K-sum;
            while(ned<0) ned+=MOD;
            if(xuoi[ned]!=-1)
            {
                COUT(tt,n-n/2);
                COUT(xuoi[ned],n/2);
                exit(0);
            }
        }
        return;
    }
    XUOI(id+1,goal,(sum+cal[0][id-1])%MOD,tt,o);
    if(o==1) XUOI(id+1,goal,(sum+cal[1][id-1]%MOD)%MOD,on(tt,id),o);
             else XUOI(id+1,goal,(sum+cal[1][id-1]%MOD)%MOD,on(tt,id-n/2),o);
}
void SUB2()
{
    memset(xuoi,-1,sizeof(xuoi));
    XUOI(1,n/2,0,0,1);
    XUOI(n/2+1,n,0,0,2);
    cout<<-1;
}
void SUB3()
{
    cout<<-1;
}

int CAL(int x,int y)
{
    int res=0;
    FOR(i,1,63) if(bit(x,i)) FOR(j,1,63) if(bit(y,j))
    {
        int ij=i+j-1;
        if(n<ij) continue;
        res+=pow2(ij-1);
        res%=MOD;
    }
    return res;
}
void BUILD()
{
    pw[0]=1%MOD;
    FOR(i,1,62) pw[i]=pw[i-1]*10%MOD;
    FOR(i,0,62)
    {
        cal[0][i]=CAL(A,pw[i]);
        cal[1][i]=CAL(B,pw[i]);
    }

}
main()
{
    freopen("modulo.inp","r",stdin);
    freopen("modulo.out","w",stdout);
    A=in(),B=in(),n=in(),K=in();
    MOD=pow2(n);

    BUILD();
    if(n<=40) SUB2();
    else SUB3();
}

