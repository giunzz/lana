/**GreenGrass**/
#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;++i)
#define F first
#define S second
using namespace std;
template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar()))x=x*10+c-48;if(nega)x=-x;}
template <typename T> inline void writep(T x){if(x>9)writep(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);putchar(' ');}
template <typename T> inline void writeln(T x){write(x);putchar('\n');}
void Min(long long &a, long long b) {if(a>b) a=b;}
void Max(int &a, int b) {if(a<b) a=b;}
const int N = 303;
int n, m, k, u, v, p, q, a[N][N];
long long dp[N][N];
long long ans;
pair <int,int> tr[N][N];
vector <pair <int,int>> ch;
void Dp(){
    dp[u][v]=a[u][v];
    For(i,u+1,p){
        dp[i][v]=dp[i-1][v]+a[i][v];
        tr[i][v]={i-1,v};
    }
    For(i,v+1,q){
        dp[u][i]=dp[u][i-1]+a[u][i];
        tr[u][i]={u,i-1};
    }
    For(i,u+1,p)
        For(j,v+1,q)
            if(dp[i-1][j]>dp[i][j-1]){
                dp[i][j]=dp[i-1][j]+a[i][j];
                tr[i][j]={i-1,j};            
            }else{
                dp[i][j]=dp[i][j-1]+a[i][j];
                tr[i][j]={i,j-1}; 
            }
}
void Dp2(){
    For(i,u+1,p) dp[i][v]=dp[i-1][v]+a[i][v];
    For(i,v+1,q) dp[u][i]=dp[u][i-1]+a[u][i];
    For(i,u+1,p)
        For(j,v+1,q)
            if(dp[i-1][j]>dp[i][j-1])
                dp[i][j]=dp[i-1][j]+a[i][j];
            else
                dp[i][j]=dp[i][j-1]+a[i][j];
}
void Trace(int y, int x){
    if(tr[y][x].first&&tr[y][x].second) Trace(tr[y][x].first,tr[y][x].second);
    ch.push_back(make_pair(y,x));
}
int main(){
    freopen("Table.inp" , "r", stdin);
    freopen("Table.out", "w", stdout);
    read(n);read(m);read(k);
    For(i,1,n) For(j,1,m) read(a[i][j]);
    while(k--){
        read(u);read(v);
        read(p);read(q);
        dp[u][v]=a[u][v];
        tr[u][v]={0,0};
        Dp();
        ch.clear();
        Trace(p,q);
        ans=1e17;
        for(auto cek : ch){
            int temp = a[cek.F][cek.S];
            if(cek.F==u&&cek.S==v) continue;
            if(cek.F==p&&cek.S==q) continue;
            a[cek.F][cek.S]=-2e9;
            Dp2();
            Min(ans,dp[p][q]);
            a[cek.F][cek.S]=temp;
        }
        writeln(ans);
    }
}