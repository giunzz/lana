#include<bits/stdc++.h>
#define maxn 1000005
#define Task "ARRANGE"
#define ft first
#define se second

using namespace std ;

int n,a[maxn],kq1,kq2,s[maxn];

void sub1(){
    int ds=0;
for(int i=1;i<=n;++i) ds+=abs(kq1-a[i]);
printf("%d",ds/2);
}

void sub2(){
    int ds=0;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i){
        if(a[i]<=kq1) ds+=kq1-a[i];else{
            if(kq2>0){
            ds+=a[i]-kq1-1;
            kq2--;} else ds+=a[i]-kq1;
        }
    };
    ds=ds/2+kq2;
    printf("%d",ds);
}

void getin(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i) {scanf("%d",&a[i]);
    s[i]=s[i-1]+a[i];
    }
}

void solve(){
kq1=s[n]/n;
kq2=s[n]%n;
//cout<<kq1<<" "<<kq2<<endl;
if(kq2==0)sub1();else sub2();
}


int main()
{
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
    getin();
    solve();
    }
