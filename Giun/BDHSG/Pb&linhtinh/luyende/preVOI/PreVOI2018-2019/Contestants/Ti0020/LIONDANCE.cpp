#include <bits/stdc++.h>
using namespace std;
#define maxn 4005
int n,K,res=0;
int a[maxn],b[maxn];
int A[25],B[25],cnt;
int f[maxn][maxn],d[maxn][maxn];

void kt(){
    for(int i=1;i<cnt;i++) if(abs(B[i]-B[i+1])>K) return;
    int h[21][21]={0};
    for(int i=1;i<=cnt;i++){
        for(int j=1;j<=n;j++){
            h[i][j]=max(h[i-1][j],h[i][j-1]);
            if(B[i]==b[j]) h[i][j]=h[i-1][j-1]+1;
        }
    }
    if(h[cnt][n]<cnt) return;
    if(!d[cnt][1]){
        res=max(res,cnt);
        for(int i=1;i<=cnt;i++) d[cnt][i]=B[i];
        return;
    }
    for(int i=1;i<=cnt;i++) if(d[cnt][i]>B[i]) return;
    for(int i=1;i<=cnt;i++) d[cnt][i]=B[i];
}

void sub1(){
    for(int i=1;i<=n;i++){
        for(int j=n;j>n-i;j--) A[j]=1;
        for(int j=n-i;j>=1;j--) A[j]=0;
        do{
            cnt=0;
            for(int j=1;j<=n;j++){
                if( A[j]==1) B[++cnt]=a[j];
            }
            if(cnt==1) res=1,d[1][1]=max(d[1][1],B[1]);
            else{
                kt();
            }
        }while(next_permutation(A+1,A+n+1));
    }
    cout<<res<<"\n";
    for(int i=1;i<=res;i++) cout<<d[res][i]<<' ';
}

int main(){
    freopen("LIONDANCE.INP","r",stdin);
    freopen("LIONDANCE.OUT","w",stdout);
    scanf("%d%d",&n,&K);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    if(n<=20) sub1();
}
