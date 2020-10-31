#include <bits/stdc++.h>
#define NaMe "table"
#define pii pair<int,int>
#define se second
#define fi first
#define mp make_pair
#define pb push_back
#define gb(i,j) ((i>>j)&1)
#define fto(i,a,b) for(int i=a; i<=b; ++i)
#define fdto(i,a,b) for(int i=a; i>=b; --i)
#define ll long long
using namespace std;
ll l[309][309];
int a[309][309],n,m,q;
pii lv[309][309];
void reset(int x, int y, int u, int v){
    fto(i,x,u)
        fto(j,y,v)l[i][j]=0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(NaMe".inp","r", stdin);
    freopen(NaMe".out","w", stdout);
    cin >> n >> m >> q;
    fto(i,1,n)
        fto(j,1,m) cin >> a[i][j];
    fto(test,1,q){
        //cout << test << endl;
        int x,y,u,v;
        cin >> x >> y >> u >> v;
        fto(i,x,u)
            fto(j,y,v){
                if(l[i-1][j]<l[i][j-1]){
                    lv[i][j]=mp(i,j-1);
                }
                else lv[i][j]=mp(i-1,j);
                l[i][j]=max(l[i-1][j],l[i][j-1])+a[i][j];
            }
        reset(x,y,u,v);
        int tg1=u, tg2=v;
        vector<pii> vec;
        while(tg1!=x || tg2!=y){
            pii tg=lv[tg1][tg2];
            //cout << tg.fi <<' '<< tg.se << endl;
            if(tg!=mp(u,v) && tg!=mp(x,y))vec.pb(tg);
            tg1=tg.fi;
            tg2=tg.se;
        }
        ll res=1e15;
        for(int t=0; t<vec.size(); ++t){
            pii tg=vec[t];
            l[tg.fi][tg.se]=-1;
            l[x][y]=a[x][y];
            fto(i,x,u)
                fto(j,y,v)
                if(l[i][j]!=-1){
                    if(l[i-1][j]>0)l[i][j]=l[i-1][j]+a[i][j];
                    if(l[i][j-1]>0)l[i][j]=max(l[i][j],l[i][j-1]+a[i][j]);
                }
            //cout << tg.fi <<' '<< tg.se <<' '<< l[u][v] << endl;
            res=min(res,l[u][v]);
            reset(x,y,u,v);
        }
        cout << res << '\n';
    }
    return 0;
}
