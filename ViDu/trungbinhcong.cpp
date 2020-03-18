#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const long long maxn=1e7;
long n,b[maxn],s=0,a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    b[0]=0;
    for (long i=1; i<=n; i++){
        cin>>b[i];
        b[i]=b[i]*i;
        a[i]=b[i]-s;
        s+=a[i];
    }
    for (long i=1; i<=n ; i++) cout<<a[i]<<" ";
    return 0;
}

