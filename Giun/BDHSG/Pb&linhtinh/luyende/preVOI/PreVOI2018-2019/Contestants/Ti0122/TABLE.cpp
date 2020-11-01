#include <bits/stdc++.h>
#define FOR(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define FORE(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define FF(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define FFE(i,a,b) for(int (i)=(a);(i)>(b);(i)--)
#define F first
#define S second
#define TT top()
#define FR front()
#define pb push_back
#define sz size()
#define reset(x,n,a) fill((x),(x)+(n)+1,(a))
#define mp make_pair
#define mt make_tuple
#define minimize(a,b) if(a>b) a=b;
#define maximum(a,b) if(a<b) a=b;
#define sc scanf
#define pr printf
#define ll long long
#define llmx 9223372036854775807
#define llmn -9223372036854775808
#define lmx 2147483647
#define lmn -2147483648
#define TASK "TABLE"
using namespace std;
typedef pair<int,int> pii;
const int maxn=310;
void R(int &val)
{
    val=0;char c;
    do{c=getchar();} while(!isdigit(c));
    while(isdigit(c)) {val=val*10+c-48;c=getchar();}
}
ll a[maxn][maxn];
ll t[maxn][maxn];
ll b[maxn][maxn];
int n,m,k;
void inp()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
    cin>>n>>m>>k;
    FOR(i,1,n)
        FOR(j,1,m) cin>>a[i][j];
}
void cal()
{
    FOR(i,0,n)
        FOR(j,0,m) t[i][j]=lmn;
    FOR(i,0,n)
        FOR(j,0,m) b[i][j]=lmn;
    int u,v,p,q;
    int ires,jres;
    while(k--){
        cin>>u>>v>>p>>q;
        ll res=1e15;
        FOR(i,u,p) FOR(j,v,q) t[i][j]=max(t[i][j-1],t[i-1][j])+a[i][j];
        b[u-1][v]=b[u][v-1]=0;
        int ii=p,jj=q;
        while(true){
            if(t[ii][jj]==t[ii-1][jj]+a[ii][jj]) ii--;
            else jj--;
            if(ii==u&&jj==v) break;
            ll tmp=a[ii][jj];
            a[ii][jj]=lmn;
            FOR(i,u,p)
                FOR(j,v,q)
                    b[i][j]=max(b[i][j-1],b[i-1][j])+a[i][j];
            a[ii][jj]=tmp;
            res=min(res,b[p][q]);
        }
        FOR(i,u,p) FOR(j,v,q) t[i][j]=lmn;
        FOR(i,u,p) FOR(j,v,q) b[i][j]=lmn;
        b[u-1][v]=b[u][v-1]=lmn;
        cout<<res<<"\n";
    }
}
int main()
{
    inp();
    cal();
    return 0;
}
