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
#define taskname "MODULO"
int a, b;
using ll=uint64_t;
ll re;
ll k;
int n;
//ll time10(ll x){
//    ll x2=(x+x)%k;
//    ll x4=(x2+x2)%k;
//    return ((x4+x4)%k+x2)%k;
//}
ll multi(ll x, ll y){
    if(y==0) return 0;
    ll t=multi(x, y/2);
    t=(t+t)%k;
    if(y%2) t=(t+x)%k;
    return t;
}
map <ll, ll> M;
void backtrack0(int u, ll x, ll ms){
//    bug(x);
    if(u>=min(20, n)){
        M[x]=ms;
        bug(x);
    }
    else{
        ll temp=multi(x, 10);
        backtrack0(u+1, (temp+a)%k, ms);
        backtrack0(u+1, (temp+b)%k, ms|mask(u));
    }
}
ll t20=1;
vector <int> ans;
void answer(ll x){
    FFOR(i, 0, n) if(bit(x, i)) ans.pb(b); else ans.pb(a);
    reverse(ans.begin(), ans.end());
    for(int x: ans) write(x);
    exit(0);
}
void backtrack1(int u, ll x, ll ms){
    if(u>=n){
        ll temp=multi(x, t20);
        temp=re+k-temp;
        temp%=k;
        if(M.find(temp)!=M.end()){
            answer(M[temp]|ms);
        }
    }
    else{
        ll temp=multi(x, 10);
        backtrack1(u+1, (temp+a)%k, ms);
        backtrack1(u+1, (temp+b)%k, ms|mask(u));
    }
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #else
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    #endif // Uiharu
    read(a);
    read(b);
    read(n);
    k=mask(n);
    read(re);
    FOR(i, 1, 10) t20=multi(t20, 10);
    backtrack0(0, 0, 0);
    backtrack1(0, 0, 0);
    puts("-1");
}