#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define FFOR(i, j, k) for(int i=j; i<k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
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
#define taskname "MINSUM"
ll a, b;
void fact(ll x, vector <int> &s){
    s.clear();
    int cnt=0;
    while(x%2==0){
        cnt++;
        x/=2;
    }
    if(cnt%2) s.pb(2);
    int i=3;
    while(i*i<=x){
        cnt=0;
        while(x%i==0){
            x/=i;
            cnt++;
        }
        if(cnt%2) s.pb(i);
        i+=2;
    }
    if(x>1) s.pb(x);
}
ll n;
ll best;
void backtrack(vector <int> v, int pos, ll s){
    if(s*s>n) return;
    if(pos==v.size()) best=max(best, s);
    else{
        backtrack(v, pos+1, s);
        backtrack(v, pos+1, s*v[pos]);
    }
}
void solve(){
    read(a);
    read(b);
    vector <int> sa;
    vector <int> sb;
    fact(a, sa);
    fact(b, sb);
    set <int> s;
    vector <int> v;
    for(int x: sa) if(s.find(x)==s.end()) s.insert(x); else s.erase(x);
    for(int x: sb) if(s.find(x)==s.end()) s.insert(x); else s.erase(x);
    n=1;
    for(int x: s){
        v.pb(x);
        n*=x;
    }
    best=1;
    reverse(v.begin(), v.end());
    backtrack(v, 0, 1);
    write(best);
    putchar(' ');
    writeln(n/best);
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    int t;
    read(t);
    while(t--) solve();
}