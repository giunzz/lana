#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int n, KQ,
    Count[50], f[50][50], a[50];

int m[10] = {4,8,15,16,23,42};

void process(int k){
    int dem1 = 0, dem2 = 0;
    for (int i = 0; i<n; i++){
        if (a[i]==m[k]) {
            dem1++;
            f[m[k]][dem1]=dem2;
        } else if (a[i]==m[k-1]){
            dem2++;
        }
    }
    if (dem1==0) f[m[k]][1]=-1;
}

int main(){
    freopen("MANGDEP.INP","r",stdin);
    freopen("MANGDEP.OUT","w",stdout);
    scanf("%d",&n);
    Count[4]=Count[8]=Count[15]=Count[16]=Count[23]=Count[42]=0;
    for (int i = 0; i<n; i++){
        scanf("%d",&a[i]);
        Count[a[i]]++;
    }
    for (int i = 1;i<=5;i++)
        process(i);
    KQ = 0;
    for (int i = 5;i>=1;i--){
        int l = m[i],
            o = abs(f[l][Count[l]]-Count[l]);
        if (f[l][1]==-1) {
            printf("%d",n);
            return 0;
        }
        KQ+=o;
        if (f[l][Count[l]]>Count[l]){
            Count[m[i-1]]-=o;
        }
    }
    if (Count[4]<f[8][Count[8]]) KQ+=(n-1);
    else if (Count[4]>f[8][Count[8]]) KQ+=Count[4]-f[8][Count[8]];
    printf("%d",KQ);
    return 0;
}
