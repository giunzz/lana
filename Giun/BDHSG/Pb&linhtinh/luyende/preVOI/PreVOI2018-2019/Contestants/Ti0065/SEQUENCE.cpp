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
#define NMAX 3005
#define pb push_back
int m,n,k;
int a[NMAX];
int b[NMAX];
int X[2*NMAX],Y[2*NMAX];
inline void GetA(int A){
    for(int i=1;i<=A;i++) X[i]=1e9;
    for(int i=1;i<=m;i++){
        for(int j=max(1,A-(m-i+1)+1);j<=A;j++){
            if(X[j]>a[i]){
                X[j]=a[i];
                for(int t=j+1;t<=A;t++){
                    X[t]=1e9;
                }
                break;
            }
        }
    }
}
inline bool operator < (const vector <int> &x, const vector <int> &y){
    for(int i=0;i<x.size();i++){
        if(x[i]!=y[i]){
            return x[i]<y[i];
        }
    }
    return false;
}
inline void GetB(int B){
    for(int i=1;i<=B;i++) Y[i]=1e9;
    for(int i=1;i<=n;i++){
        for(int j=max(1,B-(n-i+1)+1);j<=B;j++){
            if(Y[j]>b[i]){
                Y[j]=b[i];
                for(int t=j+1;t<=B;t++){
                    Y[t]=1e9;
                }
                break;
            }
        }
    }
}
int main(){
    freopen("SEQUENCE.inp","r",stdin);
    freopen("SEQUENCE.out","w",stdout);
    read(m);read(n);read(k);
    for(int i=1;i<=m;i++){
        read(a[i]);
    }
    for(int j=1;j<=n;j++){
        read(b[j]);
    }
    vector <int> res;
    for(int i=1;i<=k;i++) res.pb(1e9);
    for(int A=0;A<=k;A++){
        int B=k-A;
        if(A>m||B>n) continue;
        GetA(A);
        GetB(B);
        int i=1,j=1;
        vector <int> cur;
        while(1){
            if(cur.size()==k) break;
            if(i>A) X[i]=1e9;
            if(j>B) Y[j]=1e9;
            if(X[i]<=Y[j]){
                cur.pb(X[i]);
                i++;
                continue;
            }
            if(X[i]>Y[j]){
                cur.pb(Y[j]);
                j++;
                continue;
            }
        }
        if(cur<res) res=cur;
    }
    for(int v:res) cout<<v<<" ";
    return 0;
}
