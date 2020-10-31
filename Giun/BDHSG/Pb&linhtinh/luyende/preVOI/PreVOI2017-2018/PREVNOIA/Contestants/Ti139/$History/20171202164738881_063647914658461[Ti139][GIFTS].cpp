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
#define taskname "GIFTS"
ll a[1000001];
ll l[1000001];
ll r[1000002];
int n, k;
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    read(n);
    read(k);
    FOR(i, 1, n){
        read(a[i]);
        a[i]+=a[i-1];
    }
    FOR(i, k, n){
        l[i]=max(l[i], l[i-1]);
        l[i]=max(l[i], (a[i]-a[i-k]));
    }
    DFOR(i, n-k+1, 1){
        r[i]=max(r[i], r[i+1]);
        r[i]=max(r[i], a[i+k-1]-a[i-1]);
    }
    ll ans=1LL<<60;
    FOR(i, k, n) ans=min(ans, max(r[i+1], l[i-k]));
    writeln(ans);
}