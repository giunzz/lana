#include <bits/stdc++.h>
using namespace std;
const long maxn=1e7+5;
long n,a[maxn];
long long t1,t2;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CAPSOMAX.INP", "r", stdin);
    freopen("CAPSOMAX.OUT", "w", stdout);
    cin>>n;
    for (long i=1; i<=2; i++){
    for (long j=i+1; j<=n ; j++){
    if (a[i]>a[j]) swap(a[i],a[j]);
    }
}
    t1=a[1]*a[2];
    for (long i=n; i>=n-1; i--){
    for (long j=n-1; j>=1 ; j++){
    if (a[i]<a[j]) swap(a[i],a[j]);
    }
    }
    t2=a[n]*a[n-1];
    cout<<max(t1,t2);
    return 0;
}

