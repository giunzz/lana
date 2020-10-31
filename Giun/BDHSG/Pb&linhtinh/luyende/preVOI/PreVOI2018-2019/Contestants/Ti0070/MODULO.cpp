#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define For(i,a,b) for(int i=a;i<=b;i++)
const int maxdigit=26;
typedef int big_num [maxdigit+5];
int a,b;
int n,k;
int mod;
big_num pan;
void print(big_num a){
    int i;
    for(i=1;i<=maxdigit-1;i++)
        if(a[i]!=0) break;
    for(;i<=maxdigit;i++)
        printf("%d",a[i]);
    printf("\n");
}
void tru(big_num a,big_num b,big_num c){
    int nho=0;
    for(int i=maxdigit;i>=1;i--){
        c[i]=a[i]-b[i]-nho;
        if(c[i]<0) {
            c[i]+=10;
            nho=1;
        }
        else nho=0;
    }
}
int sosanh(big_num a,big_num b){
    for(int i=1;i<=maxdigit;i++)
        if(a[i]<b[i]) return -1;
            else if(a[i]>b[i]) return 1;
                return 0;
}
void chia(big_num a,big_num b,big_num c,big_num r){
    memset(c,0,sizeof(c));
    memset(r,0,sizeof(r));
    for(int i=1;i<=maxdigit;i++){
        for(int j=1;j<=maxdigit;j++) r[j]=r[j+1];
        r[maxdigit]=a[i];
        while(sosanh(r,b)>=0){
            c[i]++;
            tru(r,b,r);
        }
    }

}
void gan(int L,big_num c){
    int j=maxdigit;
    while(L>0){
        c[j]=L%10;
        L/=10;
        j--;
    }
}
big_num MOD,tmp,K,r;
void input(){
    freopen("MODULO.INP","r",stdin);
    freopen("MODULO.OUT","w",stdout);
    cin>>a>>b>>n>>k;
    mod=(1<<n);
    gan(mod,MOD);
    gan(k,K);

    //print(MOD);
}
int x[65];
long long h=0;
void dfs(int i){
    if(i>n){
        if(n<=18){
            h=0;
            for(int j=1;j<=n;j++)
                h=h*10+x[j];
            if(h%mod==k){
                cout<<h<<endl;
                exit(0);
            }
        }
        else {
            memset(pan,0,sizeof(pan));
            for(int j=1;j<=n;j++){
                pan[maxdigit-n+j]=x[j];
            }
            chia(pan,MOD,tmp,r);
            if(sosanh(r,K)==0) {
                print(pan);
                exit(0);
            }
        }
        return;
    }
    x[i]=a;
    dfs(i+1);
    x[i]=b;
    dfs(i+1);
}
void sub1(){
    dfs(1);
    cout<<-1;
}
void sub2(){
    cout<<-1;
}
int main(){
    input();
    if(n<=25) sub1();
    else sub2();
}
