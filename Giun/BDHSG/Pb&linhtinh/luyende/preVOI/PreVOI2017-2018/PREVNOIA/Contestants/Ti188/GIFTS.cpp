#include <bits/stdc++.h>

using namespace std;

void pool(){
    freopen("GIFTS.INP","r",stdin);
    freopen("GIFTS.OUT","w",stdout);
    return;
}

int n,k;
const int MAXN=1e6+7;
int a[MAXN];

void ip(){
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    return;
}

long long b[MAXN];
int m=0;
long long IT[MAXN];
const long long oo=(long long)1e15+7;

void CAY(int d,int c,int x){
    if (d>c) return;
    if (d==c) {IT[x]=b[d];return;}
    int g=(d+c)/2;
    CAY(d,g,x*2);CAY(g+1,c,x*2+1);
    IT[x]=max(IT[x*2],IT[x*2+1]);
    return;
}

long long get(int d,int c,int l,int r,int x){
    if (d>r||c<l) return 0;
    if (d>=l&&c<=r) return IT[x];
    int g=(d+c)/2;

    return max(get(d,g,l,r,x*2),get(g+1,c,l,r,x*2+1));
}

void NIX(){
    for (int i=1;i<=k;i++) b[1]+=a[i];
    m=1;
    for (int i=k+1;i<=n;i++){
        ++m;
        b[m]=b[m-1]+a[i]-a[i-k];
    }

    CAY(1,m,1);

    long long minx=oo;
    for (int i=1;i<=m;i++){
        long long maxx=0;
        if (i-k>=1) maxx=max(maxx,get(1,m,1,i-k,1));
        if (i<m) maxx=max(maxx,get(1,m,i+1,m,1));
        minx=min(minx,maxx);
    }

    printf("%lld",minx);

    return;
}

int main()
{
    pool();
    ip();
    NIX();

    return 0;
}
