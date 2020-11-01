#include <bits/stdc++.h>

using namespace std;

#define fi "modulo.inp"
#define fo "modulo.out"
#define For(i,a,b) for(int i=a;i<=b;i++)
#define maxn 65

int a,b,n;
uint64_t tg,tg2,k;
int x[maxn];
bool ok=false;

void lam() {
    tg=0;tg2=1;
    for(int i=n;i>0;i--) {
        tg+=tg2*x[i];
        tg2*=10;
    }
    if (tg % (1<<n)==k) {
        cout<<tg;
        ok=true;
        return;
    }
}

void try1(int i)  {
    For(j,0,1) {
        if (j==0) x[i]=a; else x[i]=b;
        if (i==n) lam();
        else try1(i+1);
    }
}

int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    scanf("%d%d",&a,&b);
    cin>>n>>k;
    if (n<=20) {
        try1(1);
        if (ok==false) cout<<"-1";
    }
    else cout<<"-1";


    return 0;
}
