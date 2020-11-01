#include <bits/stdc++.h>
#define ll long long
#define fort(i,a,b) for(ll i=(a);i<=(b);++i)
#define oo 1000000000000000
#define N 305
#define F first
#define S second

using namespace std;
typedef pair<ll,ll> II;
typedef pair<ll,II> III;

ll n,m,k,a[N][N],x,y,u,v;
ll d[N][N],d1[N][N];

priority_queue <III,vector <III>,greater<III> > q;
priority_queue <III> he;


/*ll lui(ll i,ll j,ll ok){
    if (i>u || j>v) return -oo;
    if (f[i][j][ok]!=-1) return f[i][j][ok];
    if (i==u && j==v){
            if (ok==0) return -oo;
            return a[i][j];
    }

    ll ans=0;
    ans=max(ans,lui(i+1,j,ok)+a[i][j]);
    ans=max(ans,lui(i,j+1,ok)+a[i][j]);

    if (ok==1)
        return f[i][j][ok]=ans;

    ll tmp=oo;

    if (j+1<=m)
        tmp=min(tmp,lui(i+1,j,1)+a[i][j]);

    if (i+1<=n)
        tmp=min(tmp,lui(i,j+1,1)+a[i][j]);

    if (ans<=0)
        return f[i][j][ok]=tmp;

    if (tmp<=0)
        return f[i][j][ok]=ans;

    return f[i][j][ok]=min(tmp,ans);
}*/

bool ok(ll i,ll j){
    if (i<1 || i>n || j<1 || j>m) return 0;
    return 1;
}

void dij(){
    while (!q.empty()) q.pop();
    fort(i,1,n) fort(j,1,m) d[i][j]=oo;
    d[x][y]=-a[x][y];
    q.push(III(-a[x][y],II(x,y)));

    while (!q.empty()){
        III tmp=q.top();
        q.pop();

        ll w=tmp.F,i=tmp.S.F,j=tmp.S.S;
        if (d[i][j]!=w) continue;
        if (ok(i+1,j) && d[i+1][j]>w-a[i+1][j]){
            d[i+1][j]=w-a[i+1][j];
            q.push(III(w-a[i+1][j],II(i+1,j)));
        }
        if (ok(i,j+1) && d[i][j+1]>w-a[i][j+1]){
            d[i][j+1]=w-a[i][j+1];
            q.push(III(w-a[i][j+1],II(i,j+1)));
        }
    }
}

void dij1(){
    while (!q.empty()) q.pop();
    fort(i,1,n) fort(j,1,m) d1[i][j]=oo;
    d1[u][v]=-a[u][v];
    q.push(III(-a[u][v],II(u,v)));

    while (!q.empty()){
        III tmp=q.top();
        q.pop();

        ll w=tmp.F,i=tmp.S.F,j=tmp.S.S;
        if (d1[i][j]!=w) continue;
        if (ok(i-1,j) && d1[i-1][j]>w-a[i-1][j]){
            d1[i-1][j]=w-a[i-1][j];
            q.push(III(w-a[i-1][j],II(i-1,j)));
        }
        if (ok(i,j-1) && d1[i][j-1]>w-a[i][j-1]){
            d1[i][j-1]=w-a[i][j-1];
            q.push(III(w-a[i][j-1],II(i,j-1)));
        }
    }
}


int main()
{
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    fort(i,1,n) fort(j,1,m) cin>>a[i][j];

    while (k--){
        cin>>x>>y>>u>>v;
        dij();
        dij1();

        while (!he.empty()) he.pop();
        fort(i,x,u) fort(j,y,v){
            he.push(III(d[i][j]+d1[i][j]-a[i][j],II(i,j)));
            if (he.size()>2) he.pop();
        }

        ll kq=oo;
        fort(i,x,u) fort(j,y,v){
            ll tmp=-d[i][j]-d1[i+1][j];
            if (he.top().S==II(i,j+1)){
                III pp=he.top();
                he.pop();
                tmp=max(tmp,he.top().F);
                he.push(pp);
            }
            else tmp=max(tmp,he.top().F);

            if (i+1<=u)
                kq=min(kq,tmp);

            tmp=-d[i][j]-d1[i][j+1];
            if (he.top().S==II(i+1,j)){
                III pp=he.top();
                he.pop();
                tmp=max(tmp,he.top().F);
                he.push(pp);
            }
            else tmp=max(tmp,he.top().F);

            if (j+1<=v)
                kq=min(kq,tmp);
        }

        if (x==1 && y==1 && u==n && v==m) cout<<kq<<"\n";
        else
            cout<<min(kq,-d[u][v])<<"\n";
    }

    return 0;
}
