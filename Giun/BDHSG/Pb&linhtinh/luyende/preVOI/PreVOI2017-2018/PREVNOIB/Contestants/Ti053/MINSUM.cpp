#include <bits/stdc++.h>
using namespace std;
#define NMAX 100005
#define pb push_back
int divisorA[NMAX],divisorB[NMAX];
long long a,b;
vector <int> divA;
vector <int> divB;
vector <int> v;
int siz;
long long tich=1;
long long tong=1e16;
long long x,y;
int q[15];
void solve(){
    long long trai=1,phai=1;
    for(int i=0;i<siz;i++){
        if(q[i]){
            trai=trai*v[i];
        }
    }
    phai=tich/trai;
    if(tong>phai+trai){
        tong=phai+trai;
        x=trai,y=phai;
    }
}
void Try(int i){
    if(i==siz){
        solve();
        return ;
    }
    for(int j=0;j<=1;j++){
        q[i]=j;
        Try(i+1);
    }
}
void get(vector <int> u){
    siz=u.size();
    Try(0);
}
void solve(long long a,long long b){
    x=0,y=0,tich=1;tong=1e16;
    v.clear();divA.clear();divB.clear();
    memset(divisorA,0,sizeof(divisorA));
    memset(divisorB,0,sizeof(divisorB));
    int g=__gcd(a,b);
    a/=g;
    b/=g;
    long long cur=0,tmp=0;
    for(int i=2;i<=sqrt(a);i++){
        if(a%i==0){
            divA.pb(i);
            while(a%i==0){
                divisorA[i]++;
                a/=i;
            }
        }
    }
    if(a!=1){
        cur=a;
        a=1;
        v.pb(cur);
        tich*=cur;
    }
    for(int i=2;i<=sqrt(b);i++){
        if(b%i==0){
            divB.pb(i);
            while(b%i==0){
                divisorB[i]++;
                b/=i;
            }
        }
    }
    if(b!=1){
        tmp=b;
        v.pb(tmp);
        b=1;
        tich*=tmp;
    }
    for(int i=0;i<divA.size();i++){
        int p=divA[i];
        divisorA[p]%=2;
        if(divisorA[p]){
            v.pb(p),tich*=p;
        }
    }
    for(int i=0;i<divB.size();i++){
        int p=divB[i];
        divisorB[p]%=2;
        if(divisorB[p]){
            v.pb(p),tich*=p;
        }
    }
    get(v);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("MINSUM.inp","r",stdin);
    freopen("MINSUM.out","w",stdout);
    int test;
    cin>>test;
    while(test--){
        cin>>a>>b;
        solve(a,b);
        cout<<x<<" "<<y<<'\n';
    }
}
