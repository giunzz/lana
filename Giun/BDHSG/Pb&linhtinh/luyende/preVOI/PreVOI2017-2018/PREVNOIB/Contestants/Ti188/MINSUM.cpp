#include <bits/stdc++.h>

using namespace std;

void pool(){
    freopen("MINSUM.INP","r",stdin);
    freopen("MINSUM.OUT","w",stdout);
    return;
}

long long t,A,B;

void ip(){
    scanf("%lld",&t);
    for (int i=1;i<=t;i++){
        scanf("%lld%lld",&A,&B);
        if (A<B) swap(A,B);
        long long tam=__gcd(A,B);
        A/=tam;B/=tam;

        long long dx=sqrt(A),dy=sqrt(B);
        for (int j=dx;j>=2;j--) if (A%(j*j)==0){
            A/=(j*j);break;
        }
        for (int j=dy;j>=2;j--) if (B%(j*j)==0){
            B/=(j*j);break;
        }

        while (1){
            bool zz=0;
            if (A<B) swap(A,B);
            for (int j=2;A/j>B;j++)
            if (A%j==0){
                zz=1;A/=j;B*=j;break;
            }
            if (zz==0) break;
        }
        swap(A,B);
        printf("%lld %lld\n",A,B);
    }

    return;
}

int main()
{
    pool();
    ip();

    return 0;
}
