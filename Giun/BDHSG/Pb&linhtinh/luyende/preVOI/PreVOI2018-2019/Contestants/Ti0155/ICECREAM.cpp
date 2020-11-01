#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
using namespace std;
const int mod=1e9+9;
int n,m,m50,m1,m2,ans=0,x[16],sum=0;
ll f[51][81][81][81];
void Io()
{
    freopen("ICECREAM.inp","r",stdin);
    freopen("ICECREAM.out","w",stdout);
}
void Read()
{
    scanf("%d%d",&n,&m);
    scanf("%d%d%d",&m50,&m1,&m2);
    sum=m50+m1+m2;
}
void dfs(int i,int cur50,int cur1,int cur2,int cur_m)
{
    if(i>n)
    {
        ans=(ans+1)%mod;
        return;
    }
    For(j,0,2)
    {
        if(j==0&&cur_m+1<=m)dfs(i+1,cur50+1,cur1,cur2,cur_m+1);
        if(j==1&&cur50-1>=0)dfs(i+1,cur50-1,cur1+1,cur2,cur_m);
        if(j==2)
        {
            bool ok1=false,ok2=false;
            if(cur1-1>=0&&cur50-1>=0)ok1=true;
            if(cur50-3>=0)ok2=true;
            if(ok1&&ok2)dfs(i+1,cur50-1,cur1-1,cur2+1,cur_m-1);
            if(ok1)
                dfs(i+1,cur50-1,cur1-1,cur2+1,cur_m-1);
            if(ok2)
                dfs(i+1,cur50-3,cur1,cur2+1,cur_m-2);
        }
    }
}
void Sub1()
{
    dfs(1,m50,m1,m2,sum);
    cout<<ans;
}
void ExLuck()
{

    int max50,max1,max2;
    max50=max1=max2=80;
    f[0][m50][m1][m2]=1;
    For(i,1,n)
        For(a,0,max50)
                For(b,0,max1)
                {
                    if(a+b>m)break;
                    For(c,0,max2)
                    {
                        if(a-1>=0)f[i][a][b][c]=(f[i][a][b][c]+f[i-1][a-1][b][c])%mod;
                        if(b-1>=0&&a+1<=max50)f[i][a][b][c]=(f[i][a][b][c]+f[i-1][a+1][b-1][c])%mod;
                        if(a+1+b+1+c-1<=m&&a+1<=max50&&b-1>=0)f[i][a][b][c]=(f[i][a][b][c]+f[i-1][a+1][b+1][c-1])%mod;
                        if(a+3+b+c-1<=m&&a+3<=max50&&c-1>=0)f[i][a][b][c]=(f[i][a][b][c]+f[i-1][a+3][b][c-1])%mod;
                    }
                }
    ll ans=0;
    For(a,0,max50)
        For(b,0,max1)
            For(c,0,max2)
                if(a+b+c<=m)ans=(ans+f[n][a][b][c])%mod;
    cout<<ans;
}
int main()
{
    Io();
    Read();
    if(n<=15)Sub1();
    else
        ExLuck();
}
