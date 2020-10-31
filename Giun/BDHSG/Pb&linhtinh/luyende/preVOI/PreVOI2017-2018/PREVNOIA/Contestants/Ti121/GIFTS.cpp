#include<bits/stdc++.h>
#define maxn 1000005
#define Task "GIFTS"
#define ft first
#define se second

using namespace std ;

int n,k,a[maxn],s[maxn],maxt,maxt1,ds;

void getin(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
}

void solve(){
for(int i=1;i<=n;++i) s[i]=s[i-1]+a[i];
for(int i=1;i<=n-k+1;++i){
    if(maxt<s[i+k-1]-s[i-1]) {maxt1=maxt;maxt=s[i+k-1]-s[i-1];ds=i;} else{
        if(maxt1<s[i+k-1]-s[i-1] && (ds>i || ds+k-1<i)) maxt1=s[i+k-1]-s[i-1];
    }
};
printf("%d",maxt1);
}


int main()
{
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
    getin();
    solve();
    }
