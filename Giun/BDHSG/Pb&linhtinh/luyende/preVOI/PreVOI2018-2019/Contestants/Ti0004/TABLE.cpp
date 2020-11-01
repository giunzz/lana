#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define LL long long
using namespace std;
template <typename T> inline void read(T &x)
{
    bool Neg = false;
    char c;
    for(c=getchar();c<'0' || c>'9';c=getchar())
        if(c=='-') Neg = true;
    x = c-'0';
    for(c=getchar();c>='0' && c<='9';c=getchar())
        x = x*10 + c-'0';
    if(Neg) x=-x;
}
//------------------------------------------------------
const int N = 300+5;
typedef pair<int,int> ii;
int n,m,k;
int A[N][N] ,trace[N][N];
LL dp[N][N] ;
int u,v,p,q;
LL Cam(int x,int y)
{
   //  memset(trace,0,sizeof(trace)) ;
     if(x==u&&y==v) return 1e18;
     if(x==p&&y==q) return 1e18;
     FOR(i,0,m) FOR(j,0,n) dp[i][j] = 0;
     dp[x][y] = -1e18;
     FOR(i,u,p)
     FOR(j,v,q) {
          if(i==x&&j==y) continue;
          dp[i][j]  = max(dp[i-1][j] , dp[i][j-1] ) + A[i][j] ;
     }
     return dp[p][q] ;

}
void sub1()
{
     LL kq = 1e18;
     FOR(i,u,p)
     FOR(j,v,q) kq = min(kq,Cam(i,j)) ;
     cout << kq <<'\n';
}
void sub2()
{
     Cam(0,0) ;
     LL mx = dp[p][q] ;
     vector<ii> Block ;
     for(int i=p;i>=u;i--)
     for(int j=q;j>=v;j--) {
             if(dp[i][j] == mx) {
             Block.push_back({i,j}) ;
             mx -=A[i][j] ;
         }
     }
     LL kq  = 1e18;
     for(auto o:Block) kq = min(kq,Cam(o.first,o.second)) ;
     cout << kq <<'\n';
}
int main()
{
     ios::sync_with_stdio(0) ;
     cin.tie(0) ; cout.tie(0) ;
     freopen("TABLE.INP","r",stdin);
     freopen("TABLE.OUT","w",stdout);
     read(m) ; read(n) ; read(k);
     FOR(i,1,m)  FOR(j,1,n) read(A[i][j]) ;
     if(m<=30 && n<=30) {
        FOR(i,1,k){
               read(u) ; read(v) ; read(p) ; read(q) ;
               sub1();
        }
        return 0;
     }
     FOR(i,1,k){
               read(u) ; read(v) ; read(p) ; read(q) ;
               sub2();
     }

}
