#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef pair<int,int >pii;
ll base;
ll a,b,n,k;
int lim;
int x[50];
map <ll,vector <int> > rem;
ll pw[100];
map <ll,bool> done;
inline void Try(int u){
    if(u==lim+1){
        ll cur=0;
        vector <int> tmp;
        for(int i=1;i<=lim;i++){
            tmp.pb(x[i]);
            if(x[i]==0) cur=cur*10+a;
            else cur=cur*10+b;
            cur%=base;
        }
        rem[cur]=tmp;
        done[cur]=1;
        return;
    }
    for(int i=0;i<=1;i++){
        x[u]=i;
        Try(u+1);
    }
}
inline void Go(int u){
    if(u==lim+1){
        ll cur=0;
        for(int i=n/2+1;i<=lim;i++){
            if(x[i]==0) cur=cur*10+a;
            else cur=cur*10+b;
            cur%=base;
        }
        cur=cur*pw[n/2]%base;
        ll mod=((k-cur+base)%base+base)%base;
        if(!done[mod]) return ;
        if(!rem[mod].empty()){
            for(int i=n/2+1;i<=lim;i++){
                if(!x[i]) cout<<a;
                else cout<<b;
            }
            vector <int> need=rem[mod];
            for(int v:need){
                if(!v) cout<<a;
                else cout<<b;
            }
            exit(0);
        }
        return ;
    }
    for(int i=0;i<=1;i++){
        x[u]=i;
        Go(u+1);
    }
}
int main(){
    freopen("MODULO.inp","r",stdin);
    freopen("MODULO.out","w",stdout);
    cin>>a>>b;
    cin>>n>>k;
    base=(1LL<<n);
    pw[0]=1;
    for(int i=1;i<=n;i++) pw[i]=pw[i-1]*10%base;
    lim=n/2;
    Try(1);
    lim=n;
    Go(n/2+1);
    cout<<-1;
}
