#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a); i<=(b); ++i)
#define FORR(i,a,b) for (int i=(a); i>=(b); --i)
#define REP(i,b) for (int i=0; i<(b); ++i)
#define input stdin
#define output stdout
#define assign freopen
#define endl '\n'
#define sz(x) (int) x.size()
#define div /
#define mod %
#define fillchar(x,y,z) memset(x,z,y)
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define sqr(x) ((x)*(x))
typedef long long int64;
typedef unsigned long long qword;
using namespace std;
const int maxn=305;
int m,n,k;
int a[maxn][maxn];
int f[4][maxn][maxn];
void Input()
{
    cin >> m >> n >> k;
    FOR(i,1,m)
        FOR(j,1,n)
            cin >> a[i][j];
}
int calc(int botx, int topx, int boty, int topy)
{
    fillchar(f,sizeof(f),128);
    f[0][botx-1][boty]=0;
    FOR(i,botx,topx)
        FOR(j,boty,topy)
            f[0][i][j]=max(f[0][i-1][j],f[0][i][j-1])+a[i][j];
    f[1][topx+1][topy]=0;
    FORR(i,topx,botx)
        FORR(j,topy,boty)
            f[1][i][j]=max(f[1][i+1][j],f[1][i][j+1])+a[i][j];
    FOR(i,botx,topx)
        FOR(j,boty,topy)
            f[2][i][j]=max(f[2][i][j-1],f[0][i][j]+f[1][i][j]-a[i][j]);
    FORR(i,topx,botx)
        FORR(j,topy,boty)
            f[3][i][j]=max(f[3][i][j+1],f[0][i][j]+f[1][i][j]-a[i][j]);
    int res=1e9;
    FOR(i,botx,topx)
        FOR(j,boty,topy) {
            if (mp(i,j)==mp(botx,boty)||mp(i,j)==mp(topx,topy)) continue;
            res=min(res,max(f[2][i+1][j-1],f[3][i-1][j+1]));
        }
    return res;
}
void Solve()
{
    int u,v,p,q;
    FOR(i,1,k) {
        cin >> u >> v >> p >> q;
        cout << calc(u,p,v,q) << endl;
    }
}
int main()
{
    assign("TABLE.inp","r",input);
    #ifndef meomeomeooooo
        assign("TABLE.out","w",output);
    #endif // meomeomeooooo
    iostream::sync_with_stdio(false);
    cin.tie(0);
    Input();
    Solve();
    return 0;
}
