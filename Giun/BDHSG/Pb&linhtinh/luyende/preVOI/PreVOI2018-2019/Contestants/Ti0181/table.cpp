#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) x.begin(),x.end()
#define rep(i,x) for(int _x=x,i=0;i<_x;++i)
#define finc(i,a,b) for(int _b=b,i=a;i<=_b;++i)
#define fdec(i,a,b) for(int _b=b,i=a;i>=_b;--i)
#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define pb push_back
typedef pair<int,int> ii;
#define x first
#define y second
// -----------------------------------------------------------
const int N=3e2;
const ll oo=1e9*N*N;
int m,n,Q;
ll res,A[N+2][N+2],DP1[N+2][N+2],DP2[N+2][N+2],Z1[N+2][N+2],Z2[N+2][N+2];
ii s,t;
void input(){
    cin >> m >> n >> Q;
    finc(i,1,m)
        finc(j,1,n) cin >> A[i][j];
}
void solve(){
    cin >> s.x >> s.y >> t.x >> t.y;
    finc(i,0,N+1)
        finc(j,0,N+1)
            DP1[i][j]=DP2[i][j]=Z1[i][j]=Z2[i][j]=-oo;
    DP1[s.x][s.y]=A[s.x][s.y];
    finc(i,s.x,t.x)
        finc(j,s.y,t.y){
            if (i<t.x) DP1[i+1][j]=max(DP1[i+1][j],DP1[i][j]+A[i+1][j]);
            if (j<t.y) DP1[i][j+1]=max(DP1[i][j+1],DP1[i][j]+A[i][j+1]);
        }
    DP2[t.x][t.y]=0;
    fdec(i,t.x,s.x)
        fdec(j,t.y,s.y){
            if (i>s.x) DP2[i-1][j]=max(DP2[i-1][j],DP2[i][j]+A[i][j]);
            if (j>s.y) DP2[i][j-1]=max(DP2[i][j-1],DP2[i][j]+A[i][j]);
        }
    finc(i,s.x,t.x)
        finc(j,s.y,t.y){
            Z1[i][j]=max(Z1[i-1][j],DP1[i][j]+DP2[i][j]);
            Z2[i][j]=max(Z2[i][j-1],DP1[i][j]+DP2[i][j]);
        }
    res=oo;
    finc(i,s.x,t.x)
        finc(j,s.y,t.y)
            if ((i!=s.x||j!=s.y)&&(i!=t.x||j!=t.y))
            res=min(res,max(Z1[i-1][j+1],Z2[i+1][j-1]));
    cout << res << '\n';
}
int main(){
    fast_io;
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);
    input();
    while (Q--) solve();
    return 0;
}







