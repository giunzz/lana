#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int n,
    f[50], a[50];

int main(){
    freopen("MANGDEP.INP","r",stdin);
    freopen("MANGDEP.OUT","w",stdout);
    scanf("%d",&n);
    for (int i = 0; i<n; i++){
        scanf("%d",&a[i]);
    }
    for (int i = 0;i<=50;i++) f[i]=0;
    for (int i = 0;i<n;i++){
        if (a[i]==4) f[4]++;
        else if (a[i]==8 && f[4]>0) {f[8]++;f[4]--;}
        else if (a[i]==15 && f[8]>0) {f[15]++;f[8]--;}
        else if (a[i]==16 && f[15]>0) {f[16]++;f[15]--;}
        else if (a[i]==23 && f[16]>0) {f[23]++;f[16]--;}
        else if (a[i]==42 && f[23]>0) {f[42]++;f[23]--;}
    }
    printf("%d",n-f[42]*6);
    return 0;
}
