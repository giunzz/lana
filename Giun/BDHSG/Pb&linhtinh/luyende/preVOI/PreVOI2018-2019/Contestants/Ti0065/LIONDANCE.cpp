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
#define NMAX 4005
#define pb push_back
int n,w;
int a[NMAX];
int b[NMAX];
int x[22];
int best;
vector <int> res;
inline bool operator < (const vector <int> &x, const vector <int> &y){
    for(int i=0;i<x.size();i++){
        if(x[i]!=y[i]){
            return x[i]<y[i];
        }
    }
    return false;
}
inline void Try(int u){
    if(u==n+1){
        int now=1;
        int had=0,dem=0;
        vector <int> tmp;
        for(int i=1;i<=n;i++) if(x[i]) tmp.pb(a[i]);
        for(int i=1;i<=n;i++){
            if(x[i]){
                ++dem;
                while(now<=n){
                    if(a[i]!=b[now]) ++now;
                    else{
                        ++now;
                        ++had;
                        break;
                    }
                }
            }
        }
        if(dem==had){
            if(best<=dem){
                if(best<dem){
                    best=dem;
                    res.clear();
                    for(int i=1;i<=n;i++) if(x[i]) res.pb(a[i]);
                }
                else{
                    vector <int> cur;
                    for(int i=1;i<=n;i++) if(x[i]) cur.pb(a[i]);
                    if(res<cur) res=cur;
                }
            }
        }
        return ;
    }
    for(int i=0;i<=1;i++){
        x[u]=i;
        Try(u+1);
    }
}
int main(){
    freopen("LIONDANCE.inp","r",stdin);
    freopen("LIONDANCE.out","w",stdout);
    read(n);read(w);
    for(int i=1;i<=n;i++){
        read(a[i]);
    }
    for(int i=1;i<=n;i++){
        read(b[i]);
    }
    Try(1);
    cout<<best<<'\n';
    for(int v:res) cout<<v<<" ";
}
