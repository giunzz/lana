#include<bits/stdc++.h>
#define maxn 100000005
#define Task "MINSUM"

using namespace std ;

int T,a[maxn],b[maxn],E[maxn],slx,s[maxn],maxab=0;

void sangNT(int n){
for(int i=1;i<=n;++i) E[i]=i;
for(int i=2;i<=n;++i){
    if(E[i]==i){
        int j=1;
        while(i*j<=n){
            E[i*j]=i;
            j++;
        };
    };
};
}

int GCD(int a,int b){
int r;
while(b>0){
    r=a%b;
    a=b;
    b=r;

};
return a;
}

void getin(){
    scanf("%d",&T);
    for(int i=1;i<=T;++i) {scanf("%d%d",&a[i],&b[i]);
    maxab=max(maxab,max(a[i],b[i]));
    }
}

void solve(){
    sangNT(maxab);

    for(int i=1;i<=T;++i){
        slx=0;
        int tich=1;
        int t=GCD(a[i],b[i]);
        a[i]/=t;b[i]/=t;
        int l=max(E[a[i]],E[b[i]]);
        for(int j=2;j<=l;++j){
            int sl=0;
            if(a[i]%j==0){
                while(a[i]%j==0){
                    sl++;
                    a[i]/=j;
                }
            };
            if(b[i]%j==0){
                while(b[i]%j==0){
                    sl++;
                    b[i]/=j;
                };
            };
            if(sl%2!=0) {s[++slx]=j;tich*=j;};
            //cout<<sl<<" ";
        };
        int p=sqrt(tich);
        while(tich%p!=0) ++p;
        printf("%d %d\n",p,tich/p);
    }
}


int main()
{
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
    getin();
    solve();
    }
