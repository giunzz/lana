#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
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
int n,A,B,d1,d2;
vector<int> X,Y;
ull k,mod;
map<ull,ull> P[21];
void input(){
    cin >> A >> B >> n >> k;
}
void dfs(int i,ull val,ull pre){
    P[i][val]=pre;
    if (i==d1) X.pb(val);
    if (i==d2) Y.pb(val);
    if (i==max(d1,d2)) return;
    dfs(i+1,(val*10+A)%mod,val);
    dfs(i+1,(val*10+B)%mod,val);
}
void get(ull x,ull y){
    vector<int> R1;
    while (d1){
        int pre=P[d1-1][x];
        if ((pre*10+A)%mod==x) R1.pb(A); else R1.pb(B);
        x=pre;
        --d1;
    }
    d1=n/2;
    fdec(i,d1-1,0) cout << R1[i];
    vector<int> R2;
    while (d2){
        int pre=P[d2-1][y];
        if ((pre*10+y)%mod==y) R2.pb(A); else R2.pb(B);
        y=pre;
        --d2;
    }
    d2=n-d1;
    fdec(i,d2-1,0) cout << R2[i];
}
void solve(){
    mod=pow(2,n);
    d1=n/2;
    d2=n-d1;
    dfs(0,0,0);
    ull p=1;
    finc(i,1,d2) p=p*10%mod;
    for(auto &x:X)
        for(auto &y:Y)
            if ((x*p+y)%mod==k){
                get(x,y);
                return;
            }
    cout << -1;
}
vector<int> Res;
bool dfs1(int i,ull val){
    if (i==n){
        if (val==k) return true;
        return false;
    }
    if (dfs1(i+1,(val*10+A)%mod)){
        Res.pb(A);
        return true;
    }
    if (dfs1(i+1,(val*10+B)%mod)){
        Res.pb(B);
        return true;
    }
    return false;
}
void solve2(){
    mod=pow(2,n);
    dfs1(0,0);
    if (Res.size()==0){
        cout << -1;
        return;
    }
    fdec(i,n-1,0) cout << Res[i];
}

int main(){
    fast_io;
    freopen("modulo.inp","r",stdin);
    freopen("modulo.out","w",stdout);
    input();
    if (n<=20) solve2(); else solve();
    return 0;
}






