#include <bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(nega) x=-x;
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define NMAX 305
#define pb push_back
int n,m,k;
int dx[]={0,1};
int dy[]={1,0};
ll a[NMAX][NMAX];
ll done[NMAX][NMAX];
ll F[NMAX][NMAX];
pii trace[NMAX][NMAX];
ll cnt;
int p,q,u,v;
inline bool ingrid(int x,int y,int p,int q,int s,int t){
    return (x>=p&&x<=s&&y>=q&&y<=t);
}
int main(){
    freopen("TABLE.inp","r",stdin);
    freopen("TABLE.out","w",stdout);
    read(n);read(m);read(k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            read(a[i][j]);
        }
    }
    while(k--){
        read(u);read(v);read(p);read(q);
        queue <pii> Q;
        ++cnt;
        Q.push({u,v});
        memset(trace,0,sizeof(trace));
        done[u][v]=cnt;
        F[u][v]=a[u][v];
        while(!Q.empty()){
            pii top=Q.front();Q.pop();
            int x=top.first,y=top.second;
            for(int i=0;i<2;i++){
                int xx=x+dx[i],yy=y+dy[i];
                if(ingrid(xx,yy,u,v,p,q)){
                    if(done[xx][yy]!=cnt){
                        F[xx][yy]=0;
                        done[xx][yy]=cnt;
                        Q.push({xx,yy});
                    }
                    if(F[xx][yy]<=F[x][y]+a[xx][yy]){
                        F[xx][yy]=F[x][y]+a[xx][yy];
                        trace[xx][yy]={x,y};
                      //  cout<<xx<<" "<<yy<<" "<<F[xx][yy]<<'\n';
                    }
                }
            }
        }
       // return 0;
        vector <pii> rem;
        int nowx=p,nowy=q;
        while(1){
            rem.pb({nowx,nowy});
            int u=trace[nowx][nowy].first;
            if(u==0) break;
            int v=trace[nowx][nowy].second;
            nowx=u,nowy=v;
        }
        ll res=1e16;
        for(auto P:rem){
            if(P.first==u&&P.second==v) continue;
            if(P.first==p&&P.second==q) continue;
            queue <pii> Q;
            ++cnt;
            F[u][v]=a[u][v];
            done[u][v]=cnt;
            Q.push({u,v});
            while(!Q.empty()){
                pii top=Q.front();Q.pop();
                int x=top.first,y=top.second;
                for(int i=0;i<2;i++){
                    int xx=x+dx[i],yy=y+dy[i];
                    if(ingrid(xx,yy,u,v,p,q)){
                        if(xx==P.first&&yy==P.second) continue;
                        if(done[xx][yy]!=cnt){
                            F[xx][yy]=0;
                            done[xx][yy]=cnt;
                            Q.push({xx,yy});
                        }
                        if(F[xx][yy]<F[x][y]+a[xx][yy]){
                            F[xx][yy]=F[x][y]+a[xx][yy];
                        }
                    }
                }
            }
            res=min(res,F[p][q]);
            //return 0;
        }
        writeln(res);
       // return 0;
    }
}
