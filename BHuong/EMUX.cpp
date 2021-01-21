#include<bits/stdc++.h>
using namespace std;
long long x,n;

int main(){
    freopen("EMUX.INP","r",stdin);
    freopen("EMUX.OUT","w",stdout);
    cin >> x >> n;
    double s=1,b=1;
    for(int i=1;i<=n;i++) {
        b*=i;
        s+=pow(x,i)/b;
        }
    cout << setprecision(5) << fixed << s;
    return 0;
    }
