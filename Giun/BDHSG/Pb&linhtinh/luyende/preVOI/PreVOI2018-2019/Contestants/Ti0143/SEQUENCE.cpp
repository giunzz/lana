#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define setbit(s, i) (s|=(1LL<<(i)))
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
using ll=int;
using ld=long double;
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
#define taskname "SEQUENCE"
int n, m, k;
ll a[3000];
ll b[3000];
deque <ll> ans;
deque <ll> cA;
deque <ll> cB;
deque <ll> res;
ll hs[3000];
ll hA[3000];
ll hB[3000];
void set_up_cmp(){
    hA[0]=cA[0];
    FFOR(i, 1, cA.size()) hA[i]=hA[i-1]*10007+cA[i];
    hB[0]=cB[0];
    FFOR(i, 1, cB.size()) hB[i]=hB[i-1]*10007+cB[i];
}
ll get_hash_A(int l, int r){
    return hA[r]-hA[l]*hs[r-l];
}
ll get_hash_B(int l, int r){
    return hB[r]-hB[l]*hs[r-l];
}
bool compare(int u, int d){
    FFOR(i, 0, 2){
        if((u>=cA.size())||(d>=cB.size())) break;
        if(cA[u]!=cB[d]) return cA[u]<cB[d];
        u++;
        d++;
    }
    if(u>=cA.size()) return 1;
    if(d>=cB.size()) return 0;
    if(cA[u]!=cB[d]) return cA[u]<cB[d];
    int l=1, r=min(cA.size()-u, cB.size()-d)-1, m, res=0;
    while(l<=r){
        m=(l+r)/2;
        if(get_hash_A(u, u+m)==get_hash_B(d, d+m)){
            res=m;
            l=m+1;
        }
        else r=m-1;
    }
    u+=res+1;
    d+=res+1;
    if(u>=cA.size()) return 1;
    if(d>=cB.size()) return 0;
    return cA[u]<cB[d];
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #else
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    #endif // Uiharu
    hs[0]=1;
    FFOR(i, 1, max(n, m)) hs[i]=hs[i-1]*10007;
    read(n);
    read(m);
    read(k);
    FFOR(i, 0, n) read(a[i]);
    FFOR(i, 0, m) read(b[i]);
    FFOR(i, 0, k) ans.pb(4e18);
    FOR(x, 0, k){
        if(x>n) break;
        int y=k-x;
        if(y<0) break;
        if(y>m) continue;
        cA.clear();
        cB.clear();
        FFOR(i, 0, n){
            while((!cA.empty())&&((cA.size()+n-i-1>=x)&&(a[i]<cA.back()))) cA.pop_back();
            if(cA.size()<x) cA.pb(a[i]);
        }
        FFOR(i, 0, m){
            while((!cB.empty())&&((cB.size()+m-i-1>=y)&&(b[i]<cB.back()))) cB.pop_back();
            if(cB.size()<y) cB.pb(b[i]);
        }
        res.clear();
        set_up_cmp();
        int u=0, d=0;
        while((u<cA.size())&&(d<cB.size())){
            if(compare(u, d)){
                res.pb(cA[u]);
                u++;
            }
            else{
                res.pb(cB[d]);
                d++;
            }
            if(res[res.size()-1]>ans[res.size()-1]) break;
        }
        while(u<cA.size()){
            res.pb(cA[u]);
            u++;
        }
        while(d<cB.size()){
            res.pb(cB[d]);
            d++;
        }
        ans=min(ans, res);
    }
    for(ll x: ans){
        write(x);
        putchar(' ');
    }
}