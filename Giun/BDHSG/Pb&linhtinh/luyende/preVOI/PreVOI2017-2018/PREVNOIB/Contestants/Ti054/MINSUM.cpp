#include<bits/stdc++.h>

using namespace std;

int t;

int gcd(int a,int b){
    int r;
    while(b>0){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int lt(int a,int b){
    if(b==0) return 1;
    if(b>0){
        int r=lt(a,b/2);
        if(b%2==0) return r*r;
        return r*r*a;
    }
}

bool ktNT(int u){
    if(u==2 || u==3 || u==5 || u==7 || u==11 || u==17 || u==19 || u==23 || u==29 || u==31 || u==37
    || u==41 || u==43 || u==47 || u==49) return true;
    return false;
}

int main(){
    freopen("MINSUM.inp","r",stdin);
    freopen("MINSUM.out","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;++i){
        int x=0,y=0;
        int a,b;
        scanf("%d%d",&a,&b);
        x=a/gcd(a,b);
        y=b/gcd(a,b);
        if(ktNT(x)==true && ktNT(y)==true) x=x,y=y;
        if(x==1 && y!=1) x=1,y=y;
        if(x!=1 && y==1) x=x,y=1;
        if(x==1 && y==1) x=1,y=1;
        for(int i=2;i<=8;++i) if(x%i==0){
            int t=51;
            t=min(t,i);
        for(int j=2;j<=6;++j){
        for(int i1=2;i1<=8;++i1) if(y%i1==0){
            int t1=51;
            t1=min(t1,i1);
        for(int j1=2;j1<=6;++j1){
            if(lt(t,j)==x && lt(t1,j1)==y){
                if(x=max(x,y)){
                    if(j%2==0) x=1,y=y;
                    else if(j%2!=0) x=1,y=y*t;
                }
                if(y=max(x,y)){
                    if(j1%2==0) x=x,y=1;
                    else if(j1%2!=0) x=x*t1,y=1;
                }
            }
            if(lt(t,j)==x && lt(t1,j1)!=y){
                if(j%2==0) x=1,y=y;
                else if(j%2!=0) x=1,y=y*t;
            }
            if(lt(t,j)!=x && lt(t1,j1)==y){
                if(j1%2==0) x=x,y=1;
                else if(j1%2!=0) x=x*t1,y=1;
            }
            if(lt(t,j)!=x && lt(t1,j1)!=y) x=x,y=y;
        }
        }
        }
        }
        printf("%d %d\n",x,y);
    }
}
