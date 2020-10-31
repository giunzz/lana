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
const int N=4e3;
int n,d,A[N+2],B[N+2],DP[N+2][N+2];
ii Pre[N+2][N+2];
void input(){
    cin >> n >> d;
    finc(i,1,n) cin >> A[i];
    finc(i,1,n) cin >> B[i];
}
vector<int> get(ii a){
    vector<int> ans;
    while (a.x&&a.y){
        ans.pb(A[a.x]);
        a=Pre[a.x][a.y];
    }
    reverse(all(ans));
    return ans;
}
void solve(){
    finc(i,1,n) finc(j,1,n) if (A[i]==B[j]){
        DP[i][j]=1;
        Pre[i][j]={0,0};
        finc(x,1,i-1) if (abs(A[i]-A[x])<=d)
            fdec(y,j-1,1) if (A[x]==B[y]){
                if (DP[x][y]+1==DP[i][j]){
                    if (A[x]>A[Pre[i][j].x]) Pre[i][j]={x,y};
                } else if (DP[x][y]+1>DP[i][j]){
                    DP[i][j]=DP[x][y]+1;
                    Pre[i][j]={x,y};
                } else break;
            }
    }
    int res=0;
    finc(i,1,n)
        finc(j,1,n)
            res=max(res,DP[i][j]);
    vector<int> ans;
    finc(i,1,res) ans.pb(0);
    finc(i,1,n)
        finc(j,1,n)
            if (res==DP[i][j]) ans=max(ans,get({i,j}));
    cout << res << '\n';
    for(auto &v:ans) cout << v << ' ';
}
int main(){
    fast_io;
    freopen("liondance.inp","r",stdin);
    freopen("liondance.out","w",stdout);
    input();
    solve();
    return 0;
}







