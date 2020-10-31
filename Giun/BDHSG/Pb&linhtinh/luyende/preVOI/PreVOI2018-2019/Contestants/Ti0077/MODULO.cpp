#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define maxn 10005
#define ll long long
#define fi first
#define se second
#define maxdigit 40
using namespace std;

typedef int big_num [maxdigit+1];
big_num a,b,c,r,x,k1,bp;
int t[3],n,k;

void print(big_num a){
    int i;
    for(i=1;i<=maxdigit-1;i++)
        if(a[i]!=0) break;
    for(;i<=maxdigit;i++)
        printf("%d",a[i]);
    cout<<'\n';
}

int sosanh(big_num a,big_num b){
    for(int i=1;i<=maxdigit;i++)
        if(a[i]<b[i]) return -1;
            else if(a[i]>b[i]) return 1;
                return 0;
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

void chia(big_num a,big_num b,big_num c,big_num r){
    fill(c+1,c+1+maxdigit,0);
    fill(r+1,r+1+maxdigit,0);
    for(int i=1;i<=maxdigit;i++){
        for(int j=1;j<=maxdigit;j++) r[j]=r[j+1];
        r[maxdigit]=a[i];
        while(sosanh(r,b)>=0){
            c[i]++;
            tru(r,b,r);
        }
    }
}

void trans(int v,big_num a) {
    int p=maxdigit;
    while (v>0) {
        int u=v%10;
        a[p]=u;
        p--;
        v/=10;
    }
}

void IO() {
    freopen("MODULO.inp","r",stdin);
    freopen("MODULO.out","w",stdout);
}

void dfs(int i) {
    if (i<maxdigit-n+1) {
        chia(x,bp,b,c);
        if (sosanh(c,k1)==0) {
            print(x);
            exit(0);
        }
        return;
    }
    For(j,1,2) {
        x[i]=t[j];
        dfs(i-1);
    }
}


int main() {
    IO();
    scanf("%d%d%d%d",&t[1],&t[2],&n,&k);
    trans(k,k1);
    trans((1<<n),bp);
   dfs(maxdigit);
   cout<<"-1";
    return 0;
}
