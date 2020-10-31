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
#define NMAX 5005
#define pb push_back
typedef long long ll;
typedef pair<ll,ll> pll;
int n,res;
int a[NMAX];
vector <int> adj[NMAX];
int hasc[NMAX];
int h[NMAX];
int pw[NMAX];
int fa[NMAX];
void enter(){
    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<n;i++){
        int u,v;
        read(u);read(v);
        adj[u].pb(v);
        adj[v].pb(u);
        hasc[u]++;
        fa[v]=u;
    }
}
bool flag;
vector <int> leaf;
bool check(int u){
    if(flag) return false;
    int cur=0;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(v!=fa[u]){
            cur+=a[v];
        }
    }
    if(a[u]!=cur){
        flag=true;
        return false;
    }
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(v!=fa[u]){
            check(v);
        }
    }
    return true;
}
void dfs(int u){
    if(hasc[u]==0) return ;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(v!=fa[u]){
            dfs(v);
            h[u]=max(h[u],h[v]+1);
        }
    }
}
bool visit[NMAX];
void progress(){
    dfs(1);
    pw[0]=1;
    for(int i=1;i<=30;i++) pw[i]=pw[i-1]*2;
    for(int i=1;i<=n;i++){
        if(!hasc[i]) leaf.pb(i);
    }
    for(int i=0;i<leaf.size();i++){
        int start=leaf[i];
    //    cout<<start<<'\n';
        while(start!=0){
           // cout<<start<<" "<<a[start]<<" "<<pw[h[start]]<<'\n';
            if(h[start]<=30&&a[start]>pw[h[start]]){
                res=res+(a[start]-pw[h[start]]);
                a[start]=pw[h[start]];
              //  cout<<res<<" "<<a[start]<<'\n';
            }
            start=fa[start];
        }
    }
  //  exit(0);
    if(n==2){
        cout<<a[1]-a[2];
        exit(0);
    }
    if(check(1)){
        cout<<res;
        exit(0);
    }
    else{
        for(int i=0;i<leaf.size();i++){
            int start=leaf[i];
            start=fa[start];
            while(start!=0&&!visit[start]){
                int cur=0;
                for(int i=0;i<adj[start].size();i++){
                    int v=adj[start][i];
                    if(v!=fa[start]){
                        cur+=a[v];
                    }
                }
                if(a[start]!=cur){
                  //  cout<<start<<" "<<a[start]<<" "<<cur<<'\n';
                    res=res+abs(cur-a[start]);
                  // cout<<res<<'\n';
                    a[start]=cur;
                    visit[start]=true;
                }
                start=fa[start];
            }
        }
        cout<<res;
        exit(0);
    }
}
int main(){
    freopen("TREE.inp","r",stdin);
    freopen("TREE.out","w",stdout);
    enter();
    progress();
}
