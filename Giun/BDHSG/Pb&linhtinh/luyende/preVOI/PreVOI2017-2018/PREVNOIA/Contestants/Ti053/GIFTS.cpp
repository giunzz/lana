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
#define NMAX 1500005
typedef long long ll;
ll n,k;
ll a[NMAX],sum[NMAX];
ll maxL[NMAX],maxR[NMAX];
void enter(){
    read(n);read(k);
    for(int i=1;i<=n;i++){
        read(a[i]);
        sum[i]=sum[i-1]+a[i];
    }
}
void progress(){
    for(int i=k;i<=n;i++){
        maxL[i]=max(maxL[i-1],sum[i]-sum[i-k]);
    }
    for(int i=n-k+1;i>=1;i--){
        maxR[i]=max(maxR[i+1],abs(sum[i-1]-sum[i+k-1]));
    }
    ll res=1e16;
    for(int i=1;i<=n;i++){
        res=min(res,max(maxL[i-1],maxR[i+k]));
    }
    writeln(res);
}
int main(){
    freopen("GIFTS.inp","r",stdin);
    freopen("GIFTS.out","w",stdout);
    enter();
    progress();
}

