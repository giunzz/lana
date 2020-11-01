#include<bits/stdc++.h>
#define For(i,a,b) for(int i =a;i<=b;i++)
#define Forr(i,a,b) for(int i = a;i>=b;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define maxn 10005
#define INF 1e18
#define ll long long
#define Bit(x,i) ((x>>i) & 1)
using namespace std;

const int mod = 1e9 + 7;
int n,Mmax,M50,M1,M2;
ll ans = 0,f[51][101][101][101];

void Io()
{
    freopen("ICECREAM.INP","r",stdin);
    freopen("ICECREAM.OUT","w",stdout);
}

void dfs(int i,int m50,int m1,int m2)
{
    //cerr<<i<<' '<<m50<<' '<<m1<<' '<<m2<<endl;
    if(m50 > Mmax || m1 > Mmax || m2 > Mmax) return;
    if(i > n){
        ans++;
        return;
    }
    dfs(i+1,m50+1,m1,m2);
    if(m50 > 0) dfs(i+1,m50-1,m1+1,m2);
    if(m1 > 0 && m50 > 0) dfs(i+1,m50-1,m1-1,m2+1);
    else if(m50 >=3) dfs(i+1,m50-3,m1,m2+1);
}

void Subtask1()
{
    ans = 0;
    dfs(1,M50,M1,M2);
    printf("%lld\n",ans);
    exit(0);
}

void Read()
{
    scanf("%d%d%d%d%d",&n,&Mmax,&M50,&M1,&M2);
}

void Subtask2()
{
    f[0][M50][M1][M2] = 1;
    For(i,0,n-1)
    For(j,0,Mmax)
    For(k,0,Mmax)
    For(l,0,Mmax){
        if(!f[i][j][k][l]) continue;
        if(j+1 <= Mmax) f[i+1][j+1][k][l] = (f[i+1][j+1][k][l]+f[i][j][k][l])%mod;
        if(j > 0 && k+1<=Mmax) f[i+1][j-1][k+1][l]=(f[i+1][j-1][k+1][l]+f[i][j][k][l])%mod;
        if(l+1 > Mmax) continue;
        if(j > 0 && k > 0){
            f[i+1][j-1][k-1][l+1]=(f[i+1][j-1][k-1][l+1]+f[i][j][k][l])%mod;
        }
        else if(j >=3) f[i+1][j-3][k][l+1]=(f[i+1][j-3][k][l+1]+f[i][j][k][l])%mod;
    }
    ll ans = 0;
    For(j,0,Mmax)
    For(k,0,Mmax)
    For(l,0,Mmax)
        ans = (ans + f[n][j][k][l])%mod;
    printf("%lld\n",ans);
}

void Solve()
{
    if(n <= 19) Subtask1();
    if(1ll * n * Mmax * Mmax * Mmax <= 100000000) Subtask2();
}

int main()
{
    Io();
    Read();
    Solve();
}
