#include <iostream>
#include <math.h>
using namespace std;
int a,b,d=0;
int sumUoc(int n) {
    int t=1;
    for (int i=2;i<=sqrt(n);i++) {
        if (n%i==0) {
            if (i!=n/i) t=t+i+n/i;
            else t=t+i;
        }
    }
    return t;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie();
   freopen("richnum.inp","r",stdin);
   freopen("richnum.out","w",stdout);
    cin >> a >> b;
    for (int i=a;i<=b;i++) {

            if (sumUoc(i) > i) d+=1;

    }
    cout << d;
}