#include<bits/stdc++.h>
#define For(i,a,b) for(int i =a;i<=b;i++)
#define Forr(i,a,b) for(int i = a;i>=b;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define maxn 10005
#define INF 1e18
#define ll long long
#define ull unsigned long long
#define Bit(x,i) ((x>>i) & 1)
using namespace std;

int a,b,n;
ull k,mod = 1,lt10[63];
map<ull,pair<string,bool> > mp;

void Io()
{
    freopen("MODULO.INP","r",stdin);
    freopen("MODULO.OUT","w",stdout);
}

void Read()
{
    cin>>a>>b>>n>>k;
}

ull mul_mod(ull a,ull b){
    if(b == 0) return 0;
    ull t = mul_mod(a,b/5);
    return(5*t+a*(b%5))%mod;
}

void dfs(int i,ull r,string s)
{
    if(i > n/2){
        mp[mul_mod(r,lt10[n-(n/2)])] = {s,true};
        return;
    }
    dfs(i+1,((r*10)%mod + a)%mod,s+char('0'+a));
    dfs(i+1,((r*10)%mod + b)%mod,s+char('0'+b));
}

void dfs2(int i,ull r,string s)
{
    if(i > n){
        if(k >= r){
            if(mp.count(k-r) == 0) return;
                string ans = mp[k - r].fi + s;
                cout<<ans;
                exit(0);
        }
        else{
            if(mp.count(mod+k-r) == 0) return;
                string ans = mp[mod + k - r].fi + s;
                cout<<ans;
                exit(0);
        }
        return;
    }
    dfs2(i+1,((r*10)%mod + a)%mod,s+char('0'+a));
    dfs2(i+1,((r*10)%mod + b)%mod,s+char('0'+b));
}


void Subtask2()
{
    lt10[0] = 1;
    For(i,1,n) lt10[i] = (lt10[i-1] * 10)%mod;
    dfs(1,0,"");
    dfs2(n/2+1,0,"");
    printf("-1\n");
}

void Solve()
{
    For(i,1,n) mod = mod * 2;
    Subtask2();
}

int main()
{
    Io();
    Read();
    Solve();
}
