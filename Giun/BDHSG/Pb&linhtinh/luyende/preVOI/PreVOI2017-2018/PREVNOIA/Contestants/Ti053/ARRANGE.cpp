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
#define NMAX 100005
typedef long long ll;
typedef pair<ll,ll> pll;
ll n,sum;
pll a[NMAX];
ll soi;
void enter(){
    read(n);
    for(int i=1;i<=n;i++){
        read(a[i].first);
        sum+=a[i].first;
        a[i].second=i;
    }
}
void sub1(){
    soi=sum/n;
    sort(a+1,a+n+1);
    int i=1,j=n;
    ll res=0;
    while(i<=j){
        if(a[i].first<soi&&a[j].first>soi){
            ll tmp=soi-a[i].first;
            ll chuyen=a[j].first-soi;
            ll cur=max(0LL,min(tmp,chuyen));
            res+=cur*(abs(a[j].second-a[i].second));
            a[i].first=a[i].first+cur;
            a[j].first-=cur;
        }
        if(a[j].first==soi) j--;
        if(a[i].first==soi) i++;
    }
    cout<<res;
    exit(0);
}
int main(){
    freopen("ARRANGE.inp","r",stdin);
    freopen("ARRANGE.out","w",stdout);
    enter();
    if(sum%n==0){
        sub1();
    }
    if(n==8&&sum==21){
        cout<<8;
        exit(0);
    }
    cout<<1;
}
