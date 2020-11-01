#include <bits/stdc++.h>
#define MAXN 50005
#define pb push_back
#define Pii pair<int,long long>
#define fi first
#define se second

using namespace std;

int n,k,b[MAXN],dd[MAXN];
vector<Pii> a[MAXN],e;
vector<long long> d,dk[MAXN];
vector<int> c;
long long mi=1e15;

void dijkstra(int s){
    set<Pii> mp;
    d.assign(n+1,1e9);
    mp.insert(Pii(0,s));
    d[s]=0;
    for(int i=0; i<a[s].size(); i++){
        int v=a[s][i].fi, w=a[s][i].se;
        d[v]=w, mp.insert(Pii(w,v));
    }
    while(!mp.empty()){
        int u=mp.begin()->se;
        long long dd=mp.begin()->fi;
        mp.erase(mp.begin());
        if(dd>d[u]) continue;
        for(int i=0; i<a[u].size(); i++){
            int v=a[u][i].fi;
            long long w=a[u][i].se;
            if(d[v]>dd+w){
                d[v]=dd+w;
                mp.insert(Pii(d[v],v));
            }
        }
    }
}

long long xuly(){
    long long ma=0;
    for(int i=0; i<e.size(); i++){
        int x=e[i].fi, y=e[i].se;
        long long w=dk[x][y];
        ma=max(ma,w);
    }
    return ma;
}

void solve(int cnt){
    if(cnt==k/2){
        mi=min(mi,xuly());
        return;
    }
    for(int i=0; i<c.size(); i++){
        if(dd[i]!=0) continue;
        for(int j=0; j<c.size(); j++){
            if(j==i) continue;
            if(dd[j]==1) continue;
            int x=c[i], y=c[j];
            dd[i]=1;
            dd[j]=1;
            e.pb(Pii(x,y));
            solve(cnt+1);
            dd[i]=0;
            e.pop_back();
        }
    }
}

int main()
{
    ifstream cin("BUBBLETEA.inp");
    ofstream cout("BUBBLETEA.out");
    cin >> n >> k;

    for(int i=1; i<=k; i++){
        int x;
        cin >> x;
        b[x]=1;
        c.pb(x);
    }
    for(int i=1; i<n; i++){
        int x,y;
        long long z;
        cin >> x >> y >> z;
        a[x].pb(Pii(y,z));
        a[y].pb(Pii(x,z));
    }

    for(int i=1; i<=n; i++){
        if(b[i]==1){
            dijkstra(i);
            dk[i]=d;
        }
    }
    if(k==n){
        long long mii=1e15,q1;
        dijkstra(c[0]);
        for(int i=0; i<c.size(); i++){
            int x=c[i];
            if(mii>d[x]){mii=d[x];q1=x;};
        }
        dijkstra(q1);
        mii=0;
        for(int i=0; i<c.size(); i++){
            int x=c[i];
            mii=min(mii,d[x]);
        }
        cout << mii;
        return 0;
    }
    solve(0);
    cout << mi;
    return 0;
}
